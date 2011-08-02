#include <gtkmm.h>
#include <lv2gui.hpp>

#include "gen/Flute.peg"
#include "gen/FluteMeta.h"

using namespace sigc;
using namespace Gtk;

class FluteGUI : public LV2::GUI<FluteGUI, LV2::URIMap<true>, LV2::WriteMIDI<false> > {
    public:

        FluteGUI(const std::string& URI) {
            int control_ports = p_n_ports - 3;

            //initialize sliders
            for (int i = 0; i < control_ports; i++) {
                // TODO : make sure max works inclusively
                scales[i] = manage(new HScale(p_port_meta[i].min, p_port_meta[i].max + p_port_meta[i].step, p_port_meta[i].step));
            }

            unsigned char scale_size = 100;
            for (int i = 0; i < control_ports; i++) {
                scales[i]->set_size_request(scale_size, -1);
            }

            //connect widgets to control ports (change control values when sliders are moved)
            for (int i = 0; i < control_ports; i++) {
                slot<void> slot = compose(bind<0>(mem_fun(*this, &FluteGUI::write_control), i + 3),
                mem_fun(*scales[i], &HScale::get_value));
                scales[i]->signal_value_changed().connect(slot);
            }

            //connect all faders to the 'notify' function to inform the plugin to recalculate
            /*for (int i = 0; i < control_ports; i++) {
                scales[i]->signal_value_changed().connect(
            mem_fun(*this, &FluteGUI::notify_param_change));
            }*/

            mainBox.pack_start(*createTable(0, 7), PACK_EXPAND_PADDING);  // physical
            mainBox.pack_start(*createTable(7, 16), PACK_EXPAND_PADDING); // vibrato + envelope
            mainBox.pack_start(*createTable(16, control_ports), PACK_EXPAND_PADDING); // other
            add(mainBox);
        }

        void port_event(uint32_t port, uint32_t buffer_size, uint32_t format, const void* buffer) {
            if (port > 2) { 
                scales[port-3]->set_value(*static_cast<const float*>(buffer));
            }
        }

        Alignment *createTable(int start, int end) {
            Table* table = manage(new Table(2, end - start));
            for (int i = start; i < end; i++) {
                table->attach(*align(manage(new Label(p_port_meta[i].name))), 0, 1, i, i + 1);
                table->attach(*scales[i], 1, 2, i, i + 1);
            }

            return align(table);
        } 

        Alignment* align(Widget* widget) {
            Alignment* alignment = manage(new Alignment(0.0, 0.0, 0.0, 0.0));
            alignment->add(*widget);
            return alignment;
        }

    protected:
        HBox mainBox;
        
        HScale *scales[p_n_ports - 3];
};

static int _ = FluteGUI::register_class("http://www.westkamper.com/lv2/flute/gui");

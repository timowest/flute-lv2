#ifndef FLUTE_H
#define FLUTE_H
//See associated .cpp file for copyright and other info

#include <lv2plugin.hpp>
#include <lv2_event_helpers.h>

#include "FluteCommon.h"
#include "gen/Flute.peg"
#include "gen/FluteMeta.h"

#include "dsp.h"
#include "CollectorUI.h"

class Flute : public LV2::Plugin<Flute, LV2::URIMap<true> > {
    private:
        typedef LV2::Plugin<Flute, LV2::URIMap<true> > Parent;

        float rate;
        int notesPlaying; 
        float *outputs[2];

        float* pitch;
        float* pitchBend;
        float* gain;
        float* gate;
        float* breathControl;

        float *zones[p_n_ports-3];
        
        dsp *synth;
        CollectorUI* synthUI;

    protected:

        uint32_t m_midi_input;
        uint32_t m_midi_type;
   
        template <typename T> T*& p(uint32_t port) {
            return reinterpret_cast<T*&>(Parent::m_ports[port]);
        }
  
        float*& p(uint32_t port) {
            return reinterpret_cast<float*&>(Parent::m_ports[port]);
        }


    public:
        Flute(double rate);
        ~Flute();

        void handle_midi(uint32_t size, unsigned char* data);
        void setPitchBend(float value);
        void setBreathControl(float value);
        void setVolumeControl(float value);
        void run(uint32_t sample_count);
        
        // copied from Voice
        void on(unsigned char key, unsigned char velo);
	void off(unsigned char velocity);
	void render(uint32_t from, uint32_t to);
};
#endif

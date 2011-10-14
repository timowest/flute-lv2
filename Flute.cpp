#include "Flute.h"
#include <iostream>

Flute::Flute(double r) : LV2::Plugin<Flute, LV2::URIMap<true> >(p_n_ports) {
    //license notice
    std::cout << std::endl;
    std::cout << "flute-lv2 v.0.1, Copyright (c) 2011 Timo Westkämper" << std::endl;
    std::cout << "This is free software, and you are welcome to redistribute it" << std::endl;
    std::cout << "under certain conditions; see LICENSE file for details." << std::endl;
    std::cout << std::endl;

    rate = r;
    notesPlaying = 0;
    m_midi_input = 0;
    m_midi_type = Parent::uri_to_id(LV2_EVENT_URI, "http://lv2plug.in/ns/ext/midi#MidiEvent"); 

    synthUI = new CollectorUI();
    synthUI->setOutputs(outputs);

    synth = createDSP();
    synth->init((int)r);
    synth->buildUserInterface(synthUI);
  
    // zones for MIDI data
    pitch = synthUI->getZone("pitch");
    pitchBend = synthUI->getZone("pitchBend");
    gain = synthUI->getZone("gain");
    gate = synthUI->getZone("gate");
    breathControl = synthUI->getZone("breathControl");

    // zones for control ports
    for (int i = 0; i < p_n_ports - 3; i++) {
        zones[i] = synthUI->getZone(p_port_meta[i].symbol);
        if (zones[i] == 0) {
            // TODO Exception
            std::cout << "No zone for " << p_port_meta[i].symbol << std::endl;
        }
    }
}

Flute::~Flute() {
    delete synthUI;
    delete synth;
}

void Flute::setVolumeControl(float value) {
    // TODO	
}

void Flute::setBreathControl(float value) {
    std::cout << "b " << value<< std::endl;
    *breathControl = value;
}

void Flute::setPitchBend(float value) {
     *pitchBend = value;
}

void Flute::on(unsigned char key, unsigned char velo) { 
    std::cout << "on " << (int)key << std::endl;
    *pitch = (float)key;
    *gain = scale_midi_to_f(velo);
    *gate = 1.0f;
    notesPlaying++;
}

void Flute::off(unsigned char velocity) { 
    std::cout << "off" << std::endl;
    if (--notesPlaying == 0) { 
        *gate = 0.0f;
    }
    
}

void Flute::render(uint32_t from, uint32_t to)  {
    // std::cout << "render" << std::endl;    
    // copy control port values to faust zones
    for (int i = 0; i < p_n_ports - 3; i++) {   
        *zones[i] = *p(i + 3);
    }

    // set audio buffers
    outputs[0] = &p(p_audio_l)[from];
    outputs[1] = &p(p_audio_r)[from];

    // render output via FAUST dsp  
    synth->compute(to - from, 0, outputs);    
}
    
void Flute::run(uint32_t sample_count) {
    LV2_Event_Iterator iter;
    lv2_event_begin(&iter, p < LV2_Event_Buffer>(m_midi_input));
      
    uint8_t* event_data;
    uint32_t samples_done = 0;
      
    while (samples_done < sample_count) {
	uint32_t to = sample_count;
	LV2_Event* ev = 0;
	if (lv2_event_is_valid(&iter)) {
	    ev = lv2_event_get(&iter, &event_data);
	    to = ev->frames;
	    lv2_event_increment(&iter);
	}

        if (to > samples_done) {
            render(samples_done, to);
	    samples_done = to;
        }

	/* This is what we do with events:
	   - if it's a MIDI event, pass it to handle_midi()
	   - if it's something else, just ignore it (it's safe)
	*/
        if (ev) {
	    if (ev->type == m_midi_type) {
		handle_midi(ev->size, event_data);
	    }
	    
	}
      }
      
}

void Flute::handle_midi(uint32_t size, unsigned char* data) {
    //discard invalid midi messages
    if (size < 2) {
        return;
    }	

    //receive on all channels
    switch(data[0] & 0xf0) {

        case 0x80: //note off
            {
                //discard invalid midi messages
	        if (size != 3) {
	            return;
	        }				

	        off(data[1]);
	    }
	    break;

	case 0x90: //note on
	    {
	        //discard invalid midi messages
		if (size != 3) {
		    return;
                }

		on(data[1], data[2]);				
	    }
	    break;

        case 0xE0: //pitch bend
	    {
	        //discard invalid midi messages
		if (size != 3) {
		    return;
		}
		
                setPitchBend(scale_pitchbend_to_f(data[1], data[2]));
	    }
	    break;
	
	case 0xB0: //controller
	    //WIP: control preset parameters with assigned controllers
	    {
	        /*signed char param_id = -1;
		param_id = get_param_id_from_controller(data[1]);				
		if (param_id >= 0) {
		    float new_value = scale_midi_to_f(data[2]);
		    setParameter(param_id, new_value);
		}*/
	    }

	    // standard controller stuff
	    switch(data[1])
	    {
	        //mod wheel
		case 0x01: 
		    //discard invalid midi messages
		    if (size != 3) {
		        return;
		    }					
		    //scale the mod value to cover the range [0..1]
		    // DO NOTHING
                    std::cout << "mod " << (int)data[2] << std::endl;		
		    break;

		// breath
		case 0x02:
		    //discard invalid midi messages
		    if (size != 3) {
		        return;
		    }					
		    setBreathControl(scale_midi_to_f(data[2]));
		    break;

		//volume
		case 0x07:
		    //discard invalid midi messages
		    if (size != 3) {
		        return;
		    }					
		
		    setVolumeControl(scale_midi_to_f(data[2]));
		    break;

		default:
		    // TODO
		    break;
	    }
            break;

	default: 
	    break;
    }
}

static int _ = Flute::register_class(p_uri);

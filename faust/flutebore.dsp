// Waveguide based model of a flute bore with twelve finger holes
// mostly based on 'An Improved Digital Waveguide Model of a Flute with Fractional Delay Filters' (1996)

declare name "WaveGuide Flute Bore";
declare author "Timo Westkämper";
declare copyright "Timo Westkämper (timo.westkamper@gmail.com)";

import("effect.lib");
import("instrument.lib");

import("utils.lib");

//toneholeCutoff = 1000;

// delay length in samples for given frequency in Hertz
delayLength(frequency) = SR / frequency;

// delay length in samples for given MIDI pitch
midiToDelay(pitch) = delayLength(midikey2hz(pitch));

//------------------------ TONEHOLE WAVEGUIDE -----------------------------

// waveguide defines the forward and backward flow for a single
// tonehole waveguide
//
// where
//   minPitch = minimum MIDI pitch
//   holestate = state for given hole (0 = open, 1 = closed)
//   delay = delay in samples

tonehole(minPitch, holestate, delay) = (_,_) : (_,fo_delay) : filters : mix : (_,ba_delay) // b,f -> f,b
  with {

    // creates filters
    filters = (_,_) <: (_,_,_,_); // b,f -> b,f,bl,fl
    //lp = lowpass(1, toneholeCutoff);

    // creates outputs
    mix(b, f, bl, fl) = m(f-fl, f) + m(bl, 0), m(b-bl, b) + m(fl, 0); // b,f,bl,fl -> f,b
    m = mix2(holestate);   

    // forward and backward delay
    fo_delay = fdelay(4096, delay);
    ba_delay = fdelay(4096, delay - 1);
};

//------------------------ BORE WITH TWELVE HOLES -----------------------------

// flute bore model with waveguide toneholes
//
// where
//   pitch = current MIDI pitch
//   minPitch = minimum pitch supported by bore
//   holes = number of toneholes
fluteBore(pitch, minPitch, holes) = hole(holes)
  with {

    // first hole
    hole(12) = (th(12, len(12)) ~ hole(11)) : (!,_);
    // last hole
    hole(1) = (th(1, len(1) - len(2)) ~ end) : (!,_);
    // other holes
    hole(n) = (th(n, len(n) - len(n+1)) ~ hole(n-1)) : (!,_);

    // end reflection
    end = fdelay(4096, 2 * (len(0)-len(1)));

    th(i, delay) = tonehole(minPitch, holestate(i), delay);

    // 0 = open, 1 = closed
    holestate(i) = ((pitch - minPitch) > i) : smooth(0.998);  // TODO : smoothen

    len(x) = midiToDelay(minPitch + x) / 2;
};

process = _ : fluteBore(60, 60, 12);

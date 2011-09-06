// WaveGuide Flute
import("math.lib");
import("effect.lib");
import("music.lib");
import("instrument.lib");

import("utils.dsp");

// parameters

pitch = hslider("pitch", 64, 32, 100, 1);

gain = nentry("gain", 1, 0, 1, 0.01); 

gate = button("gate");

pitchBend = hslider("pitchBend", 0, -1, 1, 0.01);

_breathControl = nentry("breathControl", 0, 0, 1, 0.01); 

// derived

smoothGate = max(gate, gate : smooth(0.999));

breathControl = _breathControl : smooth(breathControlSmoothing);

freq = midikey2hz(pitch : max(minPitch) : min(maxPitch));

// ALGORITHM IMPLEMENTATION

vibrato = env * osc(vibratoFreq)
  with {

    env = envVibrato(vibratoBegin, vibratoAttack, 100, vibratoRelease, gate);

};

//Breath pressure is controlled by an Attack / Decay / Sustain / Release envelope
envelopeBreath = pressure * adsr(envAttack, envDecay, 80, envRelease, gate)
  with {

    // keyboard scaling for attack, decay and release
    // positive values : longer times for higher notes
    // negative values : shorter times for higher notes
    // zero: no scaling
    envScaling = (pitch - 60) * envelopeScaling * 0.01;

    // attack 
    envAttack = (pressure * envelopeAttack) + envScaling;

    // decay
    envDecay = envelopeDecay + envScaling;

    // release
    envRelease = envelopeRelease + envScaling;

};

jetDelay = fdelay(4096, SR / freq * jetRatio);

upperDelay = fdelay(4096, SR / freq * 0.5); 

lowerDelay  = fdelay(4096, (SR / freq * 0.5) - 1.0);

// FIXME
reflectionFilter = lowpass(1, reflectionFilterCutoff);
//reflectionFilter(x) = 0.5 * x + 0.5 * x';

// FIXME
boundaryLossFilter = lowpass(1, boundaryLossFilterCutoff);
//boundaryLossFilter(x) = 0.9 * x + 0.1 * x';

envelope = envelopeBreath + envelopeBreath * (vibratoGain * vibrato);

// jet nonlinearity
jetNonlinearity = sigmOut * tanh(sigmOffset + sigmIn * _);

// jetNonlinearity = sigmout * tanh(ampl * sigmoffset - signmin * _)
//   references : [1]

// flute model
//   references : [0], [1]
flute = ( (excitation : jet <: 
    // bore
    (_, ((_,_ : _+_ : upperBore <: reflection,_ <: lowerBore,_,_,!)
    // bore feedback
    ~ (feedbackGain * _)) )) 
    // jet feedback
    ~ (_,_ : directFeedbackGain * _ + _)) : 
    // out
    !,!,_,_ : _ + _
with {

    // TODO : improve
    excitation = voicedGain * _ + (noiseGain * noise) : (envelope * _);

    jet = jetDelay : jetNonlinearity : dcblocker;

    upperBore = boundaryLossFilter : upperDelay;

    lowerBore = lowerDelay;

    reflection = reflectionGain * _ : reflectionFilter;

};

// [0] Waveguide simulation of neolithic chinese flutes (2001)
//     Patricio de la Cuadra, Tamara Smyth, Chris Chafe, Han Baoqiang

// [1] An Improved Digital Waveguide model of a Flute - Implementation issues (1996)
//     Vesa Välimäki, Rami Hänninen, Matti Karjalainen

// [2] On the Oscillations of Musical Instruments (1983)

// [3] A real-time DSP implementation of a flute model (1992)


 

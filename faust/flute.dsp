// Waveguide flute
import("flutelib.dsp");
import("instrument.lib");
import("params.dsp");

process = flute : scale : stereo
with {

   scale = _ * 0.3 * effectiveGain;

   effectiveGain = select3(gainSelect, gain, constantGain, breathControl);

   stereo = stereoizer(SR/freq);

};

 

// same as flute.dsp but instead of GUI elements only default values applied
import("flute.lib");
import("instrument.lib");
import("params2.lib");

process = flute : scale : stereo
with {

   scale = _ * 0.3 * effectiveGain;

   effectiveGain = select3(gainSelect, gain, constantGain, breathControl);

   stereo = stereoizer(SR/freq);

};

 

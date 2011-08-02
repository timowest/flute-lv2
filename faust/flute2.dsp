// same as flute.dsp but instead of GUI elements only default values applied
import("flutelib.dsp");
import("instrument.lib");
import("params2.dsp");

process = flute : scale : stereo
with {

   scale = _ * 0.3 * effectiveGain;

   effectiveGain = select3(gainSelect, gain, constantGain, breathControl);

   stereo = stereoizer(SR/freq);

};

 

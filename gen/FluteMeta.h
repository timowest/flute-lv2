#ifndef FLUTE_META
#define FLUTE_META

typedef struct {
  const char *symbol;
  const char *name;
  float min;
  float max;
  float default_value;
  float step;
} port_meta_t;

static const port_meta_t p_port_meta[] = {
  {"jetRatio", "Jet ratio", 1.0, 8.0, 1.0, 1.0},
  {"noiseGain", "Noise Gain", 0.0, 8.0, 0.05, 0.1},
  {"pressure", "Pressure", 0.0, 1.5, 0.99, 0.01},
  {"vibratoFreq", "Vibrato Freq", 1.0, 15.0, 6.0, 0.5},
  {"vibratoGain", "Vibrato Gain", 0.0, 1.0, 0.05, 0.01},
  {"vibratoBegin", "Vibrato Begin", 0.0, 2.0, 0.05, 0.01},
  {"vibratoAttack", "Vibrato Attack", 0.0, 2.0, 0.5, 0.01},
  {"vibratoRelease", "Vibrato Release", 0.0, 2.0, 0.1, 0.01},
  {"envelopeAttack", "Envelope Attack", 0.0, 2.0, 0.01, 0.01},
  {"envelopeDecay", "Envelope Decay", 0.0, 2.0, 0.01, 0.01},
  {"envelopeRelease", "Envelope Release", 0.0, 2.0, 0.3, 0.01},
  {"envelopeScaling", "Envelope Scaling", -1.0, 1.0, 0.01, 0.01},
  {"breathControlSmoothing", "CC2 smoothing", 0.99, 1.0, 0.99, 0.001},
  {"gainSelect", "Gain select (Velocity/Constant/CC2)", 0.0, 2.0, 0.0, 1},
  {"constantGain", "Constant gain", 0.0, 1.0, 1.0, 0.01},
  {"minPitch", "Min pitch", 0.0, 100.0, 60.0, 1.0},
  {"maxPitch", "Max pitch", 60.0, 127.0, 100.0, 1.0},
  {"reflectionGain", "Reflection gain", -1.0, 1.0, -0.359, 0.01},
  {"feedbackGain", "Feedback gain", -1.0, 1.0, -0.97, 0.01},
  {"directFeedbackGain", "Direct feedback gain", -1.0, 1.0, -0.1, 0.1},
  {"voicedGain", "Voiced gain", 0.0, 1.0, 0.7, 0.01},
  {"sigmOffset", "Sigmoid offset", 0.0, 1.0, 0.0, 0.01},
  {"sigmOut", "Sigmoid out", -8.0, 8.0, -4.0, 0.1},
  {"sigmIn", "Sigmoid in", -8.0, 8.0, 1.0, 0.1},
  {"reflectionFilterCutoff", "Reflection filter cutoff", 500.0, 10000.0, 2000.0, 10.0},
  {"boundaryLossFilterCutoff", "Boundary loss filter cutoff", 500.0, 10000.0, 4000.0, 10.0},
};
#endif
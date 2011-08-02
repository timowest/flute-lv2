#ifndef FLUTE_COMMON_H
#define FLUTE_COMMON_H

#define NOUTS   1             //number of outputs
#define NVOICES 8             //max polyphony
#define SILENCE 0.0001f       //voice choking
#define CONTROL_PORT_OFFSET 2 //number of non-control ports

static float scale_midi_to_f(unsigned char data) {
    return 0.0078f * (float)data;
}

static float scale_pitchbend_to_f(unsigned char data1, unsigned char data2) {
    return 0.000121153f * (float)(data1 * 128 + data2 - 8254);
}

#endif

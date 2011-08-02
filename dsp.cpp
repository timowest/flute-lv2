#include <math.h>

inline float max(float x, float y) {
    return fmaxf(x,y);
}

inline float min(float x, float y) {
    return fminf(x,y);
}


#include "gen/dsp.cpp"

dsp *createDSP() {
    mydsp *ret = new mydsp();
    return ret;
}

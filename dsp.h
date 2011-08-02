/**
 * Faust DSP headers and a function definition for a constructor
 **/    

#ifndef _FAUST_DSP_H
#define _FAUST_DSP_H

class UI {
 public:
    UI() {	}
    virtual ~UI() {	}
    virtual void openFrameBox(const char* label) = 0;
    virtual void openTabBox(const char* label) = 0;
    virtual void openHorizontalBox(const char* label) = 0;
    virtual void openVerticalBox(const char* label) = 0;
    virtual void closeBox() = 0;
    virtual void addButton(const char* label, float* zone) = 0;
    virtual void addToggleButton(const char* label, float* zone) = 0;
    virtual void addCheckButton(const char* label, float* zone) = 0;
    virtual void addVerticalSlider(const char* label, float* zone, float init, float min, float max, float step) = 0;
    virtual void addHorizontalSlider(const char* label, float* zone, float init, float min, float max, float step) = 0;
    virtual void addNumEntry(const char* label, float* zone, float init, float min, float max, float step) = 0;
    virtual void addNumDisplay(const char* label, float* zone, int precision) = 0;
    virtual void addTextDisplay(const char* label, float* zone, const char* names[], float min, float max) = 0;
    virtual void addHorizontalBargraph(const char* label, float* zone, float min, float max) = 0;
    virtual void addVerticalBargraph(const char* label, float* zone, float min, float max) = 0;
    virtual void declare(float* , const char* , const char* ) {}
};

class dsp {
 protected:
    int fSamplingFreq;
 public:
    dsp() {}
    virtual ~dsp() {}

    virtual int getNumInputs() = 0;
    virtual int getNumOutputs() = 0;
    virtual void buildUserInterface(UI* interface) = 0;
    virtual void init(int samplingRate) = 0;
    virtual void compute(int len, float** inputs, float** outputs) 	= 0;
};


dsp *createDSP();

#endif /* _FAUST_DSP_H */

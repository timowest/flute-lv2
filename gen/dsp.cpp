
#ifndef  __mydsp_H__
#define  __mydsp_H__
/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------

	This is sample code. This file is provided as an example of minimal
	FAUST architecture file. Redistribution and use in source and binary
	forms, with or without modification, in part or in full are permitted.
	In particular you can create a derived work of this FAUST architecture
	and distribute that work under terms of your choice.

	This sample code is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 ************************************************************************
 ************************************************************************/

#include <cmath>

#include "gui/GUI.h"
#include "audio/dsp.h"
#include "misc.h"

/******************************************************************************
*******************************************************************************

							       VECTOR INTRINSICS

*******************************************************************************
*******************************************************************************/


/******************************************************************************
*******************************************************************************

			ABSTRACT USER INTERFACE

*******************************************************************************
*******************************************************************************/

//----------------------------------------------------------------------------
//  FAUST generated signal processor
//----------------------------------------------------------------------------

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  

typedef long double quad;
/* link with : "" */
#include <math.h>

float sinf(float dummy0);

class mydspSIG0 {
	
  private:
	
	int iRec10[2];
	
  public:
	int getNumInputs() {
		return 0;
		
	}
	int getNumOutputs() {
		return 1;
		
	}
	int getInputRate(int channel) {
		switch (channel) {
			default: {
				return -1;
				
			}
			
		}
		
	}
	int getOutputRate(int channel) {
		switch (channel) {
			case 0: {
				return 0;
				
			}
			default: {
				return -1;
				
			}
			
		}
		
	}
	
	void instanceInitmydspSIG0(int samplingFreq) {
		for (int i = 0; (i < 2); i = (i + 1)) {
			iRec10[i] = 0;
			
		}
		
	}
	
	void fillmydspSIG0(int count, float* output) {
		for (int i = 0; (i < count); i = (i + 1)) {
			iRec10[0] = (1 + iRec10[1]);
			output[i] = sinf((9.58738e-05f * float((iRec10[0] - 1))));
			iRec10[1] = iRec10[0];
			
		}
		
	}
};

mydspSIG0* newmydspSIG0() { return (mydspSIG0*) new mydspSIG0(); }
void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

float powf(float dummy0, float dummy1);
float tanf(float dummy0);
static float ftbl0mydspSIG0[65536];
float floorf(float dummy0);

class mydsp : public dsp {
	
  private:
	
	float fVec4[4096];
	float fRec18[2];
	float fRec2[4096];
	float fVec3[2];
	float fRec6[2];
	float fVec2[2];
	float fVec1[4096];
	int iRec16[2];
	float fRec15[2];
	float fRec14[2];
	float fRec13[2];
	int iRec12[2];
	float fRec11[2];
	float fRec9[2];
	int iRec8[2];
	int iRec7[2];
	float fRec3[2];
	float fRec5[4096];
	float fVec0[2];
	FAUSTFLOAT fhslider0;
	int fSamplingFreq;
	int iConst0;
	float fConst1;
	FAUSTFLOAT fhslider1;
	FAUSTFLOAT fhslider2;
	FAUSTFLOAT fhslider3;
	float fConst2;
	FAUSTFLOAT fhslider4;
	FAUSTFLOAT fhslider5;
	FAUSTFLOAT fhslider6;
	FAUSTFLOAT fhslider7;
	int IOTA;
	FAUSTFLOAT fhslider8;
	FAUSTFLOAT fhslider9;
	FAUSTFLOAT fhslider10;
	float fConst3;
	FAUSTFLOAT fhslider11;
	FAUSTFLOAT fhslider12;
	FAUSTFLOAT fhslider13;
	FAUSTFLOAT fbutton0;
	FAUSTFLOAT fhslider14;
	FAUSTFLOAT fhslider15;
	FAUSTFLOAT fhslider16;
	float fConst4;
	FAUSTFLOAT fhslider17;
	FAUSTFLOAT fhslider18;
	FAUSTFLOAT fhslider19;
	FAUSTFLOAT fhslider20;
	FAUSTFLOAT fhslider21;
	FAUSTFLOAT fhslider22;
	FAUSTFLOAT fhslider23;
	FAUSTFLOAT fhslider24;
	FAUSTFLOAT fhslider25;
	FAUSTFLOAT fentry0;
	FAUSTFLOAT fhslider26;
	FAUSTFLOAT fhslider27;
	FAUSTFLOAT fentry1;
	FAUSTFLOAT fhslider28;
	
  public:
	
	void static metadata(Meta* m) { 
		m->declare("math.lib/name", "Math Library");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/version", "1.0");
		m->declare("math.lib/license", "LGPL");
		m->declare("effect.lib/name", "Faust Audio Effect Library");
		m->declare("effect.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("effect.lib/copyright", "Julius O. Smith III");
		m->declare("effect.lib/version", "1.33");
		m->declare("effect.lib/license", "STK-4.3");
		m->declare("effect.lib/reference", "https://ccrma.stanford.edu/realsimple/faust_strings/");
		m->declare("filter.lib/name", "Faust Filter Library");
		m->declare("filter.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("filter.lib/copyright", "Julius O. Smith III");
		m->declare("filter.lib/version", "1.29");
		m->declare("filter.lib/license", "STK-4.3");
		m->declare("filter.lib/reference", "https://ccrma.stanford.edu/~jos/filters/");
		m->declare("music.lib/name", "Music Library");
		m->declare("music.lib/author", "GRAME");
		m->declare("music.lib/copyright", "GRAME");
		m->declare("music.lib/version", "1.0");
		m->declare("music.lib/license", "LGPL");
		m->declare("instrument.lib/name", "Faust-STK Tools Library");
		m->declare("instrument.lib/author", "Romain Michon (rmichon@ccrma.stanford.edu)");
		m->declare("instrument.lib/copyright", "Romain Michon");
		m->declare("instrument.lib/version", "1.0");
		m->declare("instrument.lib/licence", "STK-4.3");
	}

	virtual ~mydsp() {
		destroy();
	}

	void destroy() {
		
	}
	virtual int getNumInputs() {
		return 0;
		
	}
	virtual int getNumOutputs() {
		return 2;
		
	}
	virtual int getInputRate(int channel) {
		switch (channel) {
			default: {
				return -1;
				
			}
			
		}
		
	}
	virtual int getOutputRate(int channel) {
		switch (channel) {
			case 0: {
				return 0;
				
			}
			case 1: {
				return 0;
				
			}
			default: {
				return -1;
				
			}
			
		}
		
	}
	
	static void classInit(int samplingFreq) {
		mydspSIG0* sig0 = newmydspSIG0();
		sig0->instanceInitmydspSIG0(samplingFreq);
		sig0->fillmydspSIG0(65536, ftbl0mydspSIG0);
		deletemydspSIG0(sig0);
		
	}
	
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fhslider0 = FAUSTFLOAT(0.6);
		iConst0 = min(192000, max(1, fSamplingFreq));
		fConst1 = (0.00113636f * float(iConst0));
		fhslider1 = FAUSTFLOAT(100);
		fhslider2 = FAUSTFLOAT(60);
		fhslider3 = FAUSTFLOAT(64);
		fConst2 = (3.14159f / float(iConst0));
		fhslider4 = FAUSTFLOAT(4000);
		fhslider5 = FAUSTFLOAT(-0.97);
		fhslider6 = FAUSTFLOAT(2000);
		fhslider7 = FAUSTFLOAT(-0.359);
		for (int i = 0; (i < 2); i = (i + 1)) {
			fVec0[i] = 0.f;
			
		}
		IOTA = 0;
		for (int i = 0; (i < 4096); i = (i + 1)) {
			fRec5[i] = 0.f;
			
		}
		for (int i = 0; (i < 2); i = (i + 1)) {
			fRec3[i] = 0.f;
			
		}
		fhslider8 = FAUSTFLOAT(-4);
		fhslider9 = FAUSTFLOAT(0);
		fhslider10 = FAUSTFLOAT(1);
		fConst3 = (0.00227273f * float(iConst0));
		fhslider11 = FAUSTFLOAT(1);
		fhslider12 = FAUSTFLOAT(0.99);
		fhslider13 = FAUSTFLOAT(0.05);
		fbutton0 = FAUSTFLOAT(0);
		for (int i = 0; (i < 2); i = (i + 1)) {
			iRec7[i] = 0;
			
		}
		for (int i = 0; (i < 2); i = (i + 1)) {
			iRec8[i] = 0;
			
		}
		fhslider14 = FAUSTFLOAT(0.1);
		fhslider15 = FAUSTFLOAT(0.5);
		fhslider16 = FAUSTFLOAT(0.05);
		for (int i = 0; (i < 2); i = (i + 1)) {
			fRec9[i] = 0.f;
			
		}
		fConst4 = (1.f / float(iConst0));
		fhslider17 = FAUSTFLOAT(6);
		for (int i = 0; (i < 2); i = (i + 1)) {
			fRec11[i] = 0.f;
			
		}
		for (int i = 0; (i < 2); i = (i + 1)) {
			iRec12[i] = 0;
			
		}
		fhslider18 = FAUSTFLOAT(0.3);
		fhslider19 = FAUSTFLOAT(0.01);
		fhslider20 = FAUSTFLOAT(0.01);
		fhslider21 = FAUSTFLOAT(0.01);
		for (int i = 0; (i < 2); i = (i + 1)) {
			fRec13[i] = 0.f;
			
		}
		fhslider22 = FAUSTFLOAT(0.7);
		fhslider23 = FAUSTFLOAT(-0.1);
		for (int i = 0; (i < 2); i = (i + 1)) {
			fRec14[i] = 0.f;
			
		}
		for (int i = 0; (i < 2); i = (i + 1)) {
			fRec15[i] = 0.f;
			
		}
		fhslider24 = FAUSTFLOAT(0.05);
		for (int i = 0; (i < 2); i = (i + 1)) {
			iRec16[i] = 0;
			
		}
		for (int i = 0; (i < 4096); i = (i + 1)) {
			fVec1[i] = 0.f;
			
		}
		for (int i = 0; (i < 2); i = (i + 1)) {
			fVec2[i] = 0.f;
			
		}
		for (int i = 0; (i < 2); i = (i + 1)) {
			fRec6[i] = 0.f;
			
		}
		for (int i = 0; (i < 2); i = (i + 1)) {
			fVec3[i] = 0.f;
			
		}
		for (int i = 0; (i < 4096); i = (i + 1)) {
			fRec2[i] = 0.f;
			
		}
		fhslider25 = FAUSTFLOAT(0);
		fentry0 = FAUSTFLOAT(0);
		fhslider26 = FAUSTFLOAT(0.99);
		for (int i = 0; (i < 2); i = (i + 1)) {
			fRec18[i] = 0.f;
			
		}
		fhslider27 = FAUSTFLOAT(1);
		fentry1 = FAUSTFLOAT(1);
		for (int i = 0; (i < 4096); i = (i + 1)) {
			fVec4[i] = 0.f;
			
		}
		fhslider28 = FAUSTFLOAT(0.5);
		
	}
	
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("flute");
		interface->openVerticalBox("Spat");
		interface->addHorizontalSlider("pan angle", &fhslider0, 0.6f, 0.f, 1.f, 0.01f);
		interface->addHorizontalSlider("spatial width", &fhslider28, 0.5f, 0.f, 1.f, 0.01f);
		interface->closeBox();
		interface->addHorizontalSlider("boundaryLossFilterCutoff", &fhslider4, 4000.f, 500.f, 10000.f, 10.f);
		interface->addNumEntry("breathControl", &fentry0, 0.f, 0.f, 1.f, 0.01f);
		interface->addHorizontalSlider("breathControlSmoothing", &fhslider26, 0.99f, 0.99f, 1.f, 0.001f);
		interface->addHorizontalSlider("constantGain", &fhslider27, 1.f, 0.f, 1.f, 0.01f);
		interface->addHorizontalSlider("directFeedbackGain", &fhslider23, -0.1f, -1.f, 1.f, 0.1f);
		interface->addHorizontalSlider("envelopeAttack", &fhslider21, 0.01f, 0.f, 2.f, 0.01f);
		interface->addHorizontalSlider("envelopeDecay", &fhslider20, 0.01f, 0.f, 2.f, 0.01f);
		interface->addHorizontalSlider("envelopeRelease", &fhslider18, 0.3f, 0.f, 2.f, 0.01f);
		interface->addHorizontalSlider("envelopeScaling", &fhslider19, 0.01f, -1.f, 1.f, 0.01f);
		interface->addHorizontalSlider("feedbackGain", &fhslider5, -0.97f, -1.f, 1.f, 0.01f);
		interface->addNumEntry("gain", &fentry1, 1.f, 0.f, 1.f, 0.01f);
		interface->addHorizontalSlider("gainSelect", &fhslider25, 0.f, 0.f, 2.f, 1.f);
		interface->addButton("gate",&fbutton0);
		interface->addHorizontalSlider("jetRatio", &fhslider11, 1.f, 1.f, 8.f, 1.f);
		interface->addHorizontalSlider("maxPitch", &fhslider1, 100.f, 60.f, 127.f, 1.f);
		interface->addHorizontalSlider("minPitch", &fhslider2, 60.f, 0.f, 100.f, 1.f);
		interface->addHorizontalSlider("noiseGain", &fhslider24, 0.05f, 0.f, 8.f, 0.1f);
		interface->addHorizontalSlider("pitch", &fhslider3, 64.f, 32.f, 100.f, 1.f);
		interface->addHorizontalSlider("pressure", &fhslider12, 0.99f, 0.f, 1.5f, 0.01f);
		interface->addHorizontalSlider("reflectionFilterCutoff", &fhslider6, 2000.f, 500.f, 10000.f, 10.f);
		interface->addHorizontalSlider("reflectionGain", &fhslider7, -0.359f, -1.f, 1.f, 0.01f);
		interface->addHorizontalSlider("sigmIn", &fhslider10, 1.f, -8.f, 8.f, 0.1f);
		interface->addHorizontalSlider("sigmOffset", &fhslider9, 0.f, 0.f, 1.f, 0.01f);
		interface->addHorizontalSlider("sigmOut", &fhslider8, -4.f, -8.f, 8.f, 0.1f);
		interface->addHorizontalSlider("vibratoAttack", &fhslider15, 0.5f, 0.f, 2.f, 0.01f);
		interface->addHorizontalSlider("vibratoBegin", &fhslider16, 0.05f, 0.f, 2.f, 0.01f);
		interface->addHorizontalSlider("vibratoFreq", &fhslider17, 6.f, 1.f, 15.f, 0.5f);
		interface->addHorizontalSlider("vibratoGain", &fhslider13, 0.05f, 0.f, 1.f, 0.01f);
		interface->addHorizontalSlider("vibratoRelease", &fhslider14, 0.1f, 0.f, 2.f, 0.01f);
		interface->addHorizontalSlider("voicedGain", &fhslider22, 0.7f, 0.f, 1.f, 0.01f);
		interface->closeBox();
		
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = float(fhslider0);
		float fSlow1 = (0.3f * (1.f - fSlow0));
		float fSlow2 = float(fhslider3);
		float fSlow3 = powf(2.f, float((0.0833333f * (min(float(fhslider1), max(float(fhslider2), fSlow2)) - 69.f))));
		float fSlow4 = (fConst1 / fSlow3);
		int iSlow5 = int(fSlow4);
		float fSlow6 = (fSlow4 - float(iSlow5));
		float fSlow7 = (1.f / tanf((fConst2 * float(fhslider4))));
		float fSlow8 = (1.f + fSlow7);
		float fSlow9 = (0.f - ((1.f - fSlow7) / fSlow8));
		float fSlow10 = (1.f / fSlow8);
		float fSlow11 = float(fhslider5);
		int iSlow12 = int((fSlow4 - 1.f));
		float fSlow13 = ((2.f + float(iSlow12)) - fSlow4);
		float fSlow14 = (1.f / tanf((fConst2 * float(fhslider6))));
		float fSlow15 = (1.f + fSlow14);
		float fSlow16 = (0.f - ((1.f - fSlow14) / fSlow15));
		float fSlow17 = (1.f / fSlow15);
		float fSlow18 = float(fhslider7);
		int iSlow19 = (1 + iSlow5);
		int iSlow20 = int((int(iSlow19) & 4095));
		float fSlow21 = (float(iSlow19) - fSlow4);
		int iSlow22 = int((iSlow5 & 4095));
		int iSlow23 = int((iSlow12 & 4095));
		float fSlow24 = (fSlow4 - (1.f + float(iSlow12)));
		int iSlow25 = int((int((1 + iSlow12)) & 4095));
		float fSlow26 = float(fhslider8);
		float fSlow27 = float(fhslider9);
		float fSlow28 = float(fhslider10);
		float fSlow29 = (fConst3 * (float(fhslider11) / fSlow3));
		int iSlow30 = int(fSlow29);
		int iSlow31 = (1 + iSlow30);
		float fSlow32 = (float(iSlow31) - fSlow29);
		float fSlow33 = float(fhslider12);
		float fSlow34 = float(fhslider13);
		float fSlow35 = float(fbutton0);
		int iSlow36 = int((fSlow35 > 0.f));
		float fSlow37 = float(fhslider14);
		float fSlow38 = (1.f - (1.f / powf(100000.f, float((1.f / (float(int((fSlow37 == 0.f))) + (float(iConst0) * fSlow37)))))));
		int iSlow39 = int((fSlow35 <= 0.f));
		float fSlow40 = float(fhslider15);
		float fSlow41 = (1.f / (float(int((fSlow40 == 0.f))) + (float(iConst0) * fSlow40)));
		float fSlow42 = float(fhslider16);
		float fSlow43 = (float(iConst0) * fSlow42);
		float fSlow44 = (float(int((fSlow42 == 0.f))) + fSlow43);
		float fSlow45 = (fConst4 * float(fhslider17));
		float fSlow46 = (0.01f * (float(fhslider19) * (fSlow2 - 60.f)));
		float fSlow47 = (float(fhslider18) + fSlow46);
		float fSlow48 = (1.f - (1.f / powf(80000.f, float((1.f / (float(int((fSlow47 == 0.f))) + (float(iConst0) * fSlow47)))))));
		float fSlow49 = (float(fhslider20) + fSlow46);
		float fSlow50 = (1.f - powf(80.f, float((1.f / (float(int((fSlow49 == 0.f))) + (float(iConst0) * fSlow49))))));
		float fSlow51 = (fSlow46 + (float(fhslider21) * fSlow33));
		float fSlow52 = (1.f / (float(int((fSlow51 == 0.f))) + (float(iConst0) * fSlow51)));
		float fSlow53 = float(fhslider22);
		float fSlow54 = float(fhslider23);
		float fSlow55 = (4.65661e-10f * float(fhslider24));
		int iSlow56 = int((iSlow30 & 4095));
		float fSlow57 = (fSlow29 - float(iSlow30));
		int iSlow58 = int((int(iSlow31) & 4095));
		int iSlow59 = int(float(fhslider25));
		int iSlow60 = int((iSlow59 == 0));
		int iSlow61 = int((iSlow59 == 1));
		float fSlow62 = float(fhslider26);
		float fSlow63 = (float(fentry0) * (1.f - fSlow62));
		float fSlow64 = float(fhslider27);
		float fSlow65 = float(fentry1);
		float fSlow66 = (0.3f * fSlow0);
		int iSlow67 = int((int((fConst1 * (float(fhslider28) / fSlow3))) & 4095));
		for (int i = 0; (i < count); i = (i + 1)) {
			float fTemp0 = ((fSlow6 * fRec2[((IOTA - iSlow20) & 4095)]) + (fSlow21 * fRec2[((IOTA - iSlow22) & 4095)]));
			float fTemp1 = (fSlow18 * fTemp0);
			fVec0[0] = fTemp1;
			fRec5[(IOTA & 4095)] = ((fSlow16 * fRec5[((IOTA - 1) & 4095)]) + (fSlow17 * (fTemp1 + fVec0[1])));
			fRec3[0] = ((fSlow13 * fRec5[((IOTA - iSlow23) & 4095)]) + (fSlow24 * fRec5[((IOTA - iSlow25) & 4095)]));
			float fRec4 = fRec5[((IOTA - 0) & 4095)];
			iRec7[0] = (iSlow36 & (iRec7[1] | int((fRec9[1] >= 1.f))));
			iRec8[0] = (iSlow36 * (1 + iRec8[1]));
			int iTemp2 = (iSlow39 & int((fRec9[1] > 0.f)));
			fRec9[0] = (((fRec9[1] * (1.f - (fSlow38 * float(iTemp2)))) + (fSlow41 * float((((((iRec7[1] == 0) & iSlow36) & int((fRec9[1] < 1.f))) & int((float(iRec8[1]) > fSlow43))) * (1 - int((float(iRec8[1]) < fSlow44))))))) * float(((iTemp2 == 0) | int((fRec9[1] >= 1e-06f)))));
			float fTemp3 = (fSlow45 + fRec11[1]);
			fRec11[0] = (fTemp3 - floorf(fTemp3));
			iRec12[0] = (iSlow36 & (iRec12[1] | int((fRec13[1] >= 1.f))));
			int iTemp4 = (iSlow39 & int((fRec13[1] > 0.f)));
			fRec13[0] = (((fRec13[1] * (0.f - (((fSlow48 * float(iTemp4)) + (fSlow50 * float((iRec12[1] & int((fRec13[1] > 80.f)))))) - 1.f))) + (fSlow52 * float((((iRec12[1] == 0) & iSlow36) & int((fRec13[1] < 1.f)))))) * float(((iTemp4 == 0) | int((fRec13[1] >= 1e-06f)))));
			fRec14[0] = fRec6[0];
			fRec15[0] = fRec3[0];
			iRec16[0] = (12345 + (1103515245 * iRec16[1]));
			float fTemp5 = (fSlow33 * (((1.f + (fSlow34 * (fRec9[0] * ftbl0mydspSIG0[int((65536.f * fRec11[0]))]))) * fRec13[0]) * ((fSlow53 * ((fSlow54 * fRec14[1]) + fRec15[1])) + (fSlow55 * float(iRec16[0])))));
			fVec1[(IOTA & 4095)] = fTemp5;
			float fTemp6 = (fSlow26 * float(tanhf(float((fSlow27 + (fSlow28 * ((fSlow32 * fVec1[((IOTA - iSlow56) & 4095)]) + (fSlow57 * fVec1[((IOTA - iSlow58) & 4095)]))))))));
			fVec2[0] = fTemp6;
			fRec6[0] = ((fTemp6 + (0.995f * fRec6[1])) - fVec2[1]);
			float fTemp7 = ((fSlow11 * fRec3[1]) + fRec6[0]);
			fVec3[0] = fTemp7;
			fRec2[(IOTA & 4095)] = ((fSlow9 * fRec2[((IOTA - 1) & 4095)]) + (fSlow10 * (fTemp7 + fVec3[1])));
			float fRec1 = fTemp0;
			float fRec0 = fRec1;
			float fRec17 = fRec4;
			fRec18[0] = (fSlow63 + (fSlow62 * fRec18[1]));
			float fTemp8 = ((fRec0 + fRec17) * (iSlow60?fSlow65:(iSlow61?fSlow64:fRec18[0])));
			fVec4[(IOTA & 4095)] = fTemp8;
			output0[i] = FAUSTFLOAT((fSlow1 * fTemp8));
			output1[i] = FAUSTFLOAT((fSlow66 * fVec4[((IOTA - iSlow67) & 4095)]));
			fVec0[1] = fVec0[0];
			IOTA = (IOTA + 1);
			fRec3[1] = fRec3[0];
			iRec7[1] = iRec7[0];
			iRec8[1] = iRec8[0];
			fRec9[1] = fRec9[0];
			fRec11[1] = fRec11[0];
			iRec12[1] = iRec12[0];
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
			fRec15[1] = fRec15[0];
			iRec16[1] = iRec16[0];
			fVec2[1] = fVec2[0];
			fRec6[1] = fRec6[0];
			fVec3[1] = fVec3[0];
			fRec18[1] = fRec18[0];
			
		}
		
	}

	
};


#endif

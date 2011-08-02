#ifndef COLLECTOR_UI_H
#define COLLECTOR_UI_H

#include "dsp.h"

#include <map>
#include <string>

class CollectorUI : public UI {    
    
    private:
    
        float** inputs;
        float** outputs;

        std::map<std::string, float *> labelToZone;

        void addZone(const char* label, float* zone) {
            std::string name(label);
            labelToZone[name] = zone;
        }
        
   public:

        CollectorUI(){
            inputs = 0;
            outputs = 0;
        }    

        virtual void addButton(const char* label, float* zone) { 
            addZone(label, zone); 
        }

        virtual void addToggleButton(const char* label, float* zone) { 
            addZone(label, zone); 
        }

        virtual void addCheckButton(const char* label, float* zone) { 
            addZone(label, zone); 
        }
        
        virtual void addVerticalSlider(const char* label, float* zone, float init, float min, float max, float step) { 
            addZone(label, zone); 
        }

        virtual void addHorizontalSlider(const char* label, float* zone, float init, float min, float max, float step)     { 
            addZone(label, zone); 
        }

        virtual void addNumEntry(const char* label, float* zone, float init, float min, float max, float step) { 
            addZone(label, zone); 
        }
    
        virtual void addNumDisplay(const char* label, float* zone, int precision) { 
            addZone(label, zone); 
        }

        virtual void addTextDisplay(const char* label, float* zone, const char* names[], float min, float max) {
            addZone(label, zone); 
        }

        virtual void addHorizontalBargraph(const char* label, float* zone, float min, float max) { 
            addZone(label, zone); 
        }

        virtual void addVerticalBargraph(const char* label, float* zone, float min, float max) { 
            addZone(label, zone); 
        }

        virtual void declare(float*, const char*, const char*) { }
    
        virtual void openFrameBox(const char* label) { }

        virtual void openTabBox(const char* label) { }

        virtual void openHorizontalBox(const char* label) { }

        virtual void openVerticalBox(const char* label)    { }

        virtual void closeBox() { }
    
        virtual void show() { }

        virtual void run() { }

        float** getInputs() {
            return inputs;
        }

        float** getOutputs() {
            return outputs;
        }    

        void setInputs(float** i) {
            inputs = i;
        }

        void setOutputs(float** o) {
            outputs = o;
        }

        float* getZone(std::string name) {
            return labelToZone[name];
        }

};

#endif

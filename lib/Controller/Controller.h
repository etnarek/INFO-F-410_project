#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <Arduino.h>
#include <BANG.h>


enum ControlType {ON, OFF, FULL};
typedef enum ControlType controlType;

class Controller{
    public:
        controlType control;
        int treshold;
        String name;

        Controller(String name);
        virtual int next_correction(int current_value)=0;
};

class PIDcontroller : public Controller {
    public:
        PIDcontroller(String name);
        int next_correction(int current_value);
};

class BANGcontroller : public Controller {
    public:
        BANGcontroller(String name);
        int next_correction(int current_value);
        void BANG_O_CORRECTION(void* cdata, _integer value);
};

#endif //CONTROLLER_H

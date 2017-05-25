#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <Arduino.h>

extern "C"{
#include <PID.h>
#include <BANG.h>
}

enum ControlType {OFF = 0, ON = 1, FULL = 2};
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
    private:
        _real correction;
        PID_ctx * ctx;
    public:
        PIDcontroller(String name);
        int next_correction(int current_value);
        double kp, ki, kd;
};

class BANGcontroller : public Controller {
    private:
        _integer switch_on;
        BANG_ctx * ctx;
    public:
        BANGcontroller(String name);
        int next_correction(int current_value);
};

#endif //CONTROLLER_H

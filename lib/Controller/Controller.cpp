#include <Controller.h>

Controller::Controller(String name) : name(name), treshold(42), control(ON){}
PIDcontroller::PIDcontroller(String name) : Controller(name){};

int PIDcontroller::next_correction(int current_value){
    // TODO
    return current_value;
}

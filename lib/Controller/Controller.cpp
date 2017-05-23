#include <Controller.h>

Controller::Controller(String name) : name(name), treshold(42), control(ON){}
PIDcontroller::PIDcontroller(String name) : Controller(name){};
BANGcontroller::BANGcontroller(String name) : Controller(name){};

int PIDcontroller::next_correction(int current_value){
    // TODO
    return current_value;
}


int BANGcontroller::next_correction(int current_value){
    _integer value_out;
    _integer value, target;
    value = current_value; // need to test
    target = treshold; 	   //
    struct BANG_ctx *B = BANG_new_ctx((void*)&value_out);
    BANG_I_VALUE(B, value);
    BANG_I_VALUE(B, target);
    BANG_step(B);
    return (int) value_out; // also
}

void BANGcontroller::BANG_O_CORRECTION(void* cdata, _integer value){
	*((int*)cdata) = value;
}

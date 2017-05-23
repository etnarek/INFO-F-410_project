#include <Controller.h>

extern "C"{
void PID_O_CORRECTION(void* cdata, _real r){
  *(_real*)cdata = r;
}
}

Controller::Controller(String name) : name(name), treshold(42), control(ON){}

PIDcontroller::PIDcontroller(String name) : Controller(name), correction(0), ctx(PID_new_ctx((void*)&correction)), kp(0), ki(0), kd(0){};

BANGcontroller::BANGcontroller(String name) : Controller(name){};

int PIDcontroller::next_correction(int current_value){
    PID_I_VALUE(ctx, current_value);
    PID_I_TARGET(ctx, treshold);
    PID_I_KP(ctx, kp);
    PID_I_KI(ctx, ki);
    PID_I_KD(ctx, kd);
    PID_step(ctx);
    return correction;
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

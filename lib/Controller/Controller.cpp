#include <Controller.h>

extern "C"{
void PID_O_CORRECTION(void* cdata, _real r){
  *(_real*)cdata = r;
}
}

Controller::Controller(String name) : name(name), treshold(42), control(ON){}

PIDcontroller::PIDcontroller(String name) : Controller(name), correction(0), ctx(PID_new_ctx((void*)&correction)), kp(0), ki(0), kd(0){};

int PIDcontroller::next_correction(int current_value){
    PID_I_VALUE(ctx, current_value);
    PID_I_TARGET(ctx, treshold);
    PID_I_KP(ctx, kp);
    PID_I_KI(ctx, ki);
    PID_I_KD(ctx, kd);
    PID_step(ctx);
    return correction;
}

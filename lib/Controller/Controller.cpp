#include <Controller.h>

extern "C"{
void PID_O_CORRECTION(void* cdata, _real r){
  *(_real*)cdata = r;
}

void BANG_O_CORRECTION(void* cdata, _integer value){
  *(_integer*)cdata = value;
}
}

Controller::Controller(String name) : name(name), treshold(42), control(ON){}

PIDcontroller::PIDcontroller(String name) : Controller(name), correction(0), ctx(PID_new_ctx((void*)&correction)), kp(0), ki(0), kd(0){};

BANGcontroller::BANGcontroller(String name) : Controller(name), switch_on(0), ctx(BANG_new_ctx((void*)&switch_on)){};

int PIDcontroller::next_correction(int current_value){
    PID_I_VALUE(ctx, (_real)current_value);
    PID_I_TARGET(ctx, (_real)treshold);
    PID_I_KP(ctx, kp);
    PID_I_KI(ctx, ki);
    PID_I_KD(ctx, kd);
    PID_step(ctx);
    return (int)correction;
}


int BANGcontroller::next_correction(int current_value){
    BANG_I_VALUE(ctx, (_integer)current_value);
    BANG_I_VALUE(ctx, (_integer)treshold);
    BANG_step(ctx);
    return (int)switch_on;
}

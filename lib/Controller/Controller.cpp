#include <Controller.h>

Controller::Controller(String name) : name(name), threshold(42), control(ON){}

PIDcontroller::PIDcontroller(String name) : Controller(name), correction(0), ctx(PID_new_ctx((void*)&correction)), pk(0), pi(0), pd(0){};

int PIDcontroller::next_correction(int current_value){
    PID_I_VALUE(ctx, &current_value);
    PID_I_TARGET(ctx, &threshold);
    PID_I_KP(ctx, &kp);
    PID_I_KI(ctx, &ki);
    PID_I_KD(ctx, &kd);
    PID_step(ctx);
    return correction;
}

/********
* ec2c version 0.67
* context   method = HEAP
* ext call  method = PROCEDURES
* c header file generated for node : PID
* to be used with : PID.c
********/
#ifndef _PID_EC2C_H_FILE
#define _PID_EC2C_H_FILE
/*-------- Predefined types ---------*/
#ifndef _EC2C_PREDEF_TYPES
#define _EC2C_PREDEF_TYPES
typedef int _boolean;
typedef int _integer;
typedef char* _string;
typedef double _real;
typedef double _double;
typedef float _float;
#define _false 0
#define _true 1
#endif
/*--------- Pragmas ----------------*/
//MODULE: PID 5 1
//IN: _real VALUE
//IN: _real TARGET
//IN: _real KP
//IN: _real KI
//IN: _real KD
//OUT: _real CORRECTION
#ifndef _PID_EC2C_SRC_FILE
/*--------Context type -------------*/
struct PID_ctx;
/*-------- Input procedures -------------*/
extern void PID_I_VALUE(struct PID_ctx* ctx, _real);
extern void PID_I_TARGET(struct PID_ctx* ctx, _real);
extern void PID_I_KP(struct PID_ctx* ctx, _real);
extern void PID_I_KI(struct PID_ctx* ctx, _real);
extern void PID_I_KD(struct PID_ctx* ctx, _real);
/*-------- Reset procedure -----------*/
extern void PID_reset(struct PID_ctx* ctx);
/*--------Context copy -------------*/
extern void PID_copy_ctx(struct PID_ctx* dest, struct PID_ctx* src);
/*--------Context allocation --------*/
extern struct PID_ctx* PID_new_ctx(void* client_data);
/*-------- Step procedure -----------*/
extern void PID_step(struct PID_ctx* ctx);
#endif
#endif
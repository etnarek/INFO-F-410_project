/********
* ec2c version 0.67
* context   method = HEAP
* ext call  method = PROCEDURES
* c header file generated for node : BANG 
* to be used with : BANG.c 
********/
#ifndef _BANG_EC2C_H_FILE
#define _BANG_EC2C_H_FILE
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
//MODULE: BANG 2 1
//IN: _integer VALUE
//IN: _integer TARGET
//OUT: _integer CORRECTION
#ifndef _BANG_EC2C_SRC_FILE
/*--------Context type -------------*/
struct BANG_ctx;
/*-------- Input procedures -------------*/
extern void BANG_I_VALUE(struct BANG_ctx* ctx, _integer);
extern void BANG_I_TARGET(struct BANG_ctx* ctx, _integer);
/*-------- Reset procedure -----------*/
extern void BANG_reset(struct BANG_ctx* ctx);
/*--------Context copy -------------*/
extern void BANG_copy_ctx(struct BANG_ctx* dest, struct BANG_ctx* src);
/*--------Context allocation --------*/
extern struct BANG_ctx* BANG_new_ctx(void* client_data);
/*-------- Step procedure -----------*/
extern void BANG_step(struct BANG_ctx* ctx);
#endif
#endif

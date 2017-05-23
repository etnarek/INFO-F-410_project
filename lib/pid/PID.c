/********
* ec2c version 0.67
* c file generated for node : PID 
* context   method = HEAP
* ext call  method = PROCEDURES
********/
#include <stdlib.h>
#include <string.h>
#define _PID_EC2C_SRC_FILE
#include "PID.h"
/*--------
Internal structure for the call
--------*/
typedef struct  {
   void* client_data;
   //INPUTS
   _real _VALUE;
   _real _TARGET;
   _real _KP;
   _real _KI;
   _real _KD;
   //OUTPUTS
   _real _CORRECTION;
   //REGISTERS
   _real M19;
   _boolean M19_nil;
   _real M15;
   _boolean M15_nil;
   _boolean M11;
} PID_ctx;
/*--------
Output procedures must be defined,
Input procedures must be used:
--------*/
void PID_I_VALUE(PID_ctx* ctx, _real V){
   ctx->_VALUE = V;
}
void PID_I_TARGET(PID_ctx* ctx, _real V){
   ctx->_TARGET = V;
}
void PID_I_KP(PID_ctx* ctx, _real V){
   ctx->_KP = V;
}
void PID_I_KI(PID_ctx* ctx, _real V){
   ctx->_KI = V;
}
void PID_I_KD(PID_ctx* ctx, _real V){
   ctx->_KD = V;
}
extern void PID_O_CORRECTION(void* cdata, _real);
#ifdef CKCHECK
extern void PID_BOT_CORRECTION(void* cdata);
#endif
/*--------
Internal reset input procedure
--------*/
static void PID_reset_input(PID_ctx* ctx){
   //NOTHING FOR THIS VERSION...
}
/*--------
Reset procedure
--------*/
void PID_reset(PID_ctx* ctx){
   ctx->M19_nil = _true;
   ctx->M15_nil = _true;
   ctx->M11 = _true;
   PID_reset_input(ctx);
}
/*--------
Copy the value of an internal structure
--------*/
void PID_copy_ctx(PID_ctx* dest, PID_ctx* src){
   memcpy((void*)dest, (void*)src, sizeof(PID_ctx));
}
/*--------
Dynamic allocation of an internal structure
--------*/
PID_ctx* PID_new_ctx(void* cdata){
   PID_ctx* ctx = (PID_ctx*)calloc(1, sizeof(PID_ctx));
   ctx->client_data = cdata;
   PID_reset(ctx);
   return ctx;
}
/*--------
Step procedure
--------*/
void PID_step(PID_ctx* ctx){
//LOCAL VARIABLES
   _real L8;
   _real L7;
   _real L14;
   _real L10;
   _real L9;
   _real L6;
   _real L18;
   _real L17;
   _real L16;
   _real L5;
   _real T19;
   _real T15;
//CODE
   L8 = (ctx->_TARGET - ctx->_VALUE);
   L7 = (ctx->_KP * L8);
   L14 = (ctx->M15 + L8);
   if (ctx->M11) {
      L10 = 0.000000;
   } else {
      L10 = L14;
   }
   L9 = (ctx->_KI * L10);
   L6 = (L7 + L9);
   L18 = (L8 - ctx->M19);
   if (ctx->M11) {
      L17 = 0.000000;
   } else {
      L17 = L18;
   }
   L16 = (ctx->_KD * L17);
   L5 = (L6 + L16);
   PID_O_CORRECTION(ctx->client_data, L5);
   T19 = L17;
   T15 = L10;
   ctx->M19 = T19;
   ctx->M19_nil = _false;
   ctx->M15 = T15;
   ctx->M15_nil = _false;
   ctx->M11 = ctx->M11 && !(_true);
}

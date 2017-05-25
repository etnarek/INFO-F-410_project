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
   _real M21;
   _boolean M21_nil;
   _real M18;
   _boolean M18_nil;
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
   ctx->M21_nil = _true;
   ctx->M18_nil = _true;
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
   _real L14;
   _real L10;
   _real L9;
   _real L17;
   _real L16;
   _real L15;
   _real L8;
   _real L20;
   _real L19;
   _real L7;
   _boolean L6;
   _boolean L23;
   _real L22;
   _real L5;
   _real T21;
   _real T18;
//CODE
   L14 = (ctx->_TARGET - ctx->_VALUE);
   if (ctx->M11) {
      L10 = 0.000000;
   } else {
      L10 = L14;
   }
   L9 = (ctx->_KP * L10);
   L17 = (ctx->M18 + L10);
   if (ctx->M11) {
      L16 = 0.000000;
   } else {
      L16 = L17;
   }
   L15 = (ctx->_KI * L16);
   L8 = (L9 + L15);
   L20 = (L10 - ctx->M21);
   L19 = (ctx->_KD * L20);
   L7 = (L8 + L19);
   L6 = (L7 < 0.000000);
   L23 = (L7 > 255.000000);
   if (L23) {
      L22 = 255.000000;
   } else {
      L22 = L7;
   }
   if (L6) {
      L5 = 0.000000;
   } else {
      L5 = L22;
   }
   PID_O_CORRECTION(ctx->client_data, L5);
   T21 = L10;
   T18 = L16;
   ctx->M21 = T21;
   ctx->M21_nil = _false;
   ctx->M18 = T18;
   ctx->M18_nil = _false;
   ctx->M11 = ctx->M11 && !(_true);
}

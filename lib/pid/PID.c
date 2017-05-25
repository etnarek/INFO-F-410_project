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
   _integer _CTRL;
   //OUTPUTS
   _real _NEW_VALUE;
   //REGISTERS
   _real M36;
   _boolean M36_nil;
   _real M26;
   _boolean M26_nil;
   _real M22;
   _boolean M22_nil;
   _boolean M7;
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
void PID_I_CTRL(PID_ctx* ctx, _integer V){
   ctx->_CTRL = V;
}
extern void PID_O_NEW_VALUE(void* cdata, _real);
#ifdef CKCHECK
extern void PID_BOT_NEW_VALUE(void* cdata);
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
   ctx->M36_nil = _true;
   ctx->M26_nil = _true;
   ctx->M22_nil = _true;
   ctx->M7 = _true;
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
   _boolean L11;
   _real L18;
   _real L17;
   _real L21;
   _real L20;
   _real L19;
   _real L16;
   _real L25;
   _real L24;
   _real L23;
   _real L15;
   _boolean L14;
   _boolean L29;
   _real L28;
   _real L13;
   _boolean L31;
   _boolean L34;
   _real L33;
   _real L30;
   _real L10;
   _real L6;
   _real T36;
   _real T26;
   _real T22;
//CODE
   L11 = (ctx->_CTRL == 1);
   L18 = (ctx->_TARGET - ctx->_VALUE);
   L17 = (L18 * ctx->_KP);
   L21 = (ctx->M22 + L18);
   if (ctx->M7) {
      L20 = 0.000000;
   } else {
      L20 = L21;
   }
   L19 = (L20 * ctx->_KI);
   L16 = (L17 + L19);
   L25 = (L18 - ctx->M26);
   if (ctx->M7) {
      L24 = 0.000000;
   } else {
      L24 = L25;
   }
   L23 = (L24 * ctx->_KD);
   L15 = (L16 + L23);
   L14 = (L15 > 255.000000);
   L29 = (L15 < 0.000000);
   if (L29) {
      L28 = 0.000000;
   } else {
      L28 = L15;
   }
   if (L14) {
      L13 = 255.000000;
   } else {
      L13 = L28;
   }
   L31 = (ctx->_CTRL == 0);
   L34 = (ctx->_CTRL == 2);
   if (L34) {
      L33 = 255.000000;
   } else {
      L33 = ctx->M36;
   }
   if (L31) {
      L30 = 0.000000;
   } else {
      L30 = L33;
   }
   if (L11) {
      L10 = L13;
   } else {
      L10 = L30;
   }
   if (ctx->M7) {
      L6 = 0.000000;
   } else {
      L6 = L10;
   }
   PID_O_NEW_VALUE(ctx->client_data, L6);
   T36 = L6;
   T26 = L18;
   T22 = L20;
   ctx->M36 = T36;
   ctx->M36_nil = _false;
   ctx->M26 = T26;
   ctx->M26_nil = _false;
   ctx->M22 = T22;
   ctx->M22_nil = _false;
   ctx->M7 = ctx->M7 && !(_true);
}

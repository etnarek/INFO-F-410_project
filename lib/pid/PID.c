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
   _integer _VALUE;
   _integer _TARGET;
   //OUTPUTS
   _integer _CORRECTION;
   //REGISTERS
   _integer M17;
   _boolean M17_nil;
   _integer M14;
   _boolean M14_nil;
   _boolean M7;
} PID_ctx;
/*--------
Output procedures must be defined,
Input procedures must be used:
--------*/
void PID_I_VALUE(PID_ctx* ctx, _integer V){
   ctx->_VALUE = V;
}
void PID_I_TARGET(PID_ctx* ctx, _integer V){
   ctx->_TARGET = V;
}
extern void PID_O_CORRECTION(void* cdata, _integer);
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
   ctx->M17_nil = _true;
   ctx->M14_nil = _true;
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
   _integer L10;
   _integer L6;
   _integer L4;
   _integer L13;
   _integer L12;
   _integer L11;
   _integer L3;
   _integer L16;
   _integer L15;
   _integer L2;
   _integer T17;
   _integer T14;
//CODE
   L10 = (ctx->_TARGET - ctx->_VALUE);
   if (ctx->M7) {
      L6 = 0;
   } else {
      L6 = L10;
   }
   L4 = (1 * L6);
   L13 = (ctx->M14 + L6);
   if (ctx->M7) {
      L12 = 0;
   } else {
      L12 = L13;
   }
   L11 = (1 * L12);
   L3 = (L4 + L11);
   L16 = (L6 - ctx->M17);
   L15 = (1 * L16);
   L2 = (L3 + L15);
   PID_O_CORRECTION(ctx->client_data, L2);
   T17 = L6;
   T14 = L12;
   ctx->M17 = T17;
   ctx->M17_nil = _false;
   ctx->M14 = T14;
   ctx->M14_nil = _false;
   ctx->M7 = ctx->M7 && !(_true);
}

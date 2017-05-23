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
   _integer M16;
   _boolean M16_nil;
   _integer M13;
   _boolean M13_nil;
   _boolean M9;
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
   ctx->M16_nil = _true;
   ctx->M13_nil = _true;
   ctx->M9 = _true;
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
   _integer L6;
   _integer L4;
   _integer L12;
   _integer L8;
   _integer L7;
   _integer L3;
   _integer L15;
   _integer L14;
   _integer L2;
   _integer T16;
   _integer T13;
//CODE
   L6 = (ctx->_TARGET - ctx->_VALUE);
   L4 = (1 * L6);
   L12 = (ctx->M13 + L6);
   if (ctx->M9) {
      L8 = 0;
   } else {
      L8 = L12;
   }
   L7 = (1 * L8);
   L3 = (L4 + L7);
   L15 = (L6 - ctx->M16);
   L14 = (1 * L15);
   L2 = (L3 + L14);
   PID_O_CORRECTION(ctx->client_data, L2);
   T16 = L6;
   T13 = L8;
   ctx->M16 = T16;
   ctx->M16_nil = _false;
   ctx->M13 = T13;
   ctx->M13_nil = _false;
   ctx->M9 = ctx->M9 && !(_true);
}

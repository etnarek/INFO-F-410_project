/********
* ec2c version 0.67
* c file generated for node : BANG 
* context   method = HEAP
* ext call  method = PROCEDURES
********/
#include <stdlib.h>
#include <string.h>
#define _BANG_EC2C_SRC_FILE
#include "BANG.h"
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
} BANG_ctx;
/*--------
Output procedures must be defined,
Input procedures must be used:
--------*/
void BANG_I_VALUE(BANG_ctx* ctx, _integer V){
   ctx->_VALUE = V;
}
void BANG_I_TARGET(BANG_ctx* ctx, _integer V){
   ctx->_TARGET = V;
}
extern void BANG_O_CORRECTION(void* cdata, _integer);
#ifdef CKCHECK
extern void BANG_BOT_CORRECTION(void* cdata);
#endif
/*--------
Internal reset input procedure
--------*/
static void BANG_reset_input(BANG_ctx* ctx){
   //NOTHING FOR THIS VERSION...
}
/*--------
Reset procedure
--------*/
void BANG_reset(BANG_ctx* ctx){
   BANG_reset_input(ctx);
}
/*--------
Copy the value of an internal structure
--------*/
void BANG_copy_ctx(BANG_ctx* dest, BANG_ctx* src){
   memcpy((void*)dest, (void*)src, sizeof(BANG_ctx));
}
/*--------
Dynamic allocation of an internal structure
--------*/
BANG_ctx* BANG_new_ctx(void* cdata){
   BANG_ctx* ctx = (BANG_ctx*)calloc(1, sizeof(BANG_ctx));
   ctx->client_data = cdata;
   BANG_reset(ctx);
   return ctx;
}
/*--------
Step procedure
--------*/
void BANG_step(BANG_ctx* ctx){
//LOCAL VARIABLES
   _boolean L3;
   _integer L2;
//CODE
   L3 = (ctx->_TARGET >= ctx->_VALUE);
   if (L3) {
      L2 = 1;
   } else {
      L2 = 0;
   }
   BANG_O_CORRECTION(ctx->client_data, L2);
}

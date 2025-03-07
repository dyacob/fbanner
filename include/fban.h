
#ifndef FBAN_H
#define FBAN_H  1

#include <libeth.h>

#define FONTDIR "./fonts"
#define ETHFONTNAME "ethiomx12-uni.bdf"
#define LATFONTNAME "latin.bdf" 
#define MYSYMBOL "*"

/* #define DEFLANG  amh */
/* #define DEFLANG  gez */
#define DEFLANG  tir 


typedef struct {
         boolean   use_alfa, rotate, mirror;   
         boolean   flipv, fliph;
         char      sym[2];
       } MyFlags; 

typedef struct {
   char **bits;
   unsigned int myAddr;
   int dwx0; 
   int bbh,bbw; 
   int bbxoff, my_yoff;    /* Store only what is needed later */
   int my_width;
}  bdffont;

#endif

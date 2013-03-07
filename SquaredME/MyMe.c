#include <stdio.h>
#include <math.h>
#include "clooptools.h"
#include "types-c.h"
/*#include "util-c.h"*/
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"

int main(){
  #include "model_sm.h"
  #include "const.h"
  #include "vars.h"
  #include "util-c.h"
  #include "inline.h"
  #include "renconst.h"
  #include "abbr0s.c"
  /*#include "abbr1a.c"*/
  #include "abbr1s.c"
  #include "abbr0h.c"
  /*#include "abbr1h.c"*/

  abbr1s();
  printf("%f",MW);

  /*RealType a =2.0;*/
  /*ComplexType b =ToComplex2(1.0,3.0);*/
  /*b=b+a;*/
  /*printf("%f", pow(2,2));*/
  /*printf("%f",Re(b));*/
  //ComplexType fc = a;
  /*CKMlambda*CKM(1,2);*/
  /*#include "abbr1s.c"*/
  /*#include "abbr1s.c"*/
  /*printf("CKMlambda: %f \n",CKMlambda);*/

}


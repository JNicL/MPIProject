#if 0
* born.c
* form factors for {-F[2, {1}], F[2, {1}]} -> {-F[3, {3, Col3}], F[3, {3, Col4}], V[1]}
* generated by FormCalc 8.1 on 6-Apr-2013 23:49
#endif

#include "vars.h"
#include "inline.h"


void born() {

#include "vars.h"

#include "inline.h"

  Ctree(1) = Ctree(1) + 
     (Alfa*Pi)/CW2*(EL*(4/9.*Sub14829/(-MT2 + Sub14830) - 
          4/9.*Sub14831/(-MT2 + Sub14832) + 
          2/3.*(Sub14827/(-ME2 + Sub14828) + 
             Sub14833/(-ME2 + Sub14834))));

#ifdef DEBUG
  DEB("born: Ctree(1) =", Ctree(1));
#endif

}
#if 0
* self_Gen5.c
* form factors for {-F[2, {1}], F[2, {1}]} -> {-F[3, {3, Col3}], F[3, {3, Col4}]}
* generated by FormCalc 8.0 on 6-Mar-2013 10:48
#endif

#include "vars.h"


void self_Gen5() {

#include "vars.h"


#include "inline.h"

  Cloop(1) = Cloop(1) + 
     Alfa2*(16/9.*(Sub3*Sub350(Gen5))/(S*S) + 
        1/9.*(1/CW2*(Sub6*Sub351(Gen5))/(-MZ2 + S) + 
           Sub357(Gen5)/S) + 
        1/(36.*(CW2*CW2))*(Sub5*Sub365(Gen5))/Power(-MZ2 + S,2));

#ifdef DEBUG
  DEB("self_Gen5: Cloop(1) =", Cloop(1))
#endif

}

#if 0
* self_Gen6.c
* form factors for {-F[2, {1}], F[2, {1}]} -> {-F[3, {3, Col3}], F[3, {3, Col4}], V[1]}
* generated by FormCalc 8.2 on 11-Apr-2013 22:37
#endif

#include "vars.h"
#include "inline.h"


void self_Gen6() {

#include "vars.h"

#include "inline.h"

  Cloop(1) = Cloop(1) + 
     Alfa2*(EL*(1/(CW2*CW2)*
           (1/108.*Sub14845(Gen6)/(-MT2 + Sub14731) - 
             1/108.*Sub14856(Gen6)/(-MT2 + Sub14733)) - 
          MT/(8.*MW2*SW2)*((F11 + F9)*Mf2(3,Gen6)*Sub14827(Gen6))/
            (-MH2 + S34) + 
          1/72.*(-(Sub14877(Gen6)/(-ME2 + Sub14729)) - 
             Sub14888(Gen6)/(-ME2 + Sub14735))));

#ifdef DEBUG
  DEB("self_Gen6: Cloop(1) =", Cloop(1));
#endif

}
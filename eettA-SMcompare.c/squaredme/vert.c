#if 0
* vert.c
* form factors for {-F[2, {1}], F[2, {1}]} -> {-F[3, {3, Col3}], F[3, {3, Col4}], V[1]}
* generated by FormCalc 8.2 on 11-Apr-2013 22:37
#endif

#include "vars.h"
#include "inline.h"


void vert() {

#include "vars.h"

#include "inline.h"

  Cloop(1) = Cloop(1) + 
     Alfa2*(EL*(1/324.*Sub14988/(-MT2 + Sub14731) - 
          1/324.*Sub15084/(-MT2 + Sub14733) + 
          1/27.*Sub15092/(-ME2 + Sub14735) - 
          1/(432.*(CW2*CW2)*MW2*SW2)*Sub15196/(-MZ2 + S34) - 
          1/54.*Sub15268/S34 + 
          1/CW2*(-(1/27.*Sub14894/(-ME2 + Sub14729)) + 
             MT/(8.*SW2)*Sub15282/(-MH2 + S34))));

#ifdef DEBUG
  DEB("vert: Cloop(1) =", Cloop(1));
#endif

}

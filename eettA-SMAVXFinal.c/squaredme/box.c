#if 0
* box.c
* form factors for {-F[2, {1}], F[2, {1}]} -> {-F[3, {3, Col3}], F[3, {3, Col4}], V[1]}
* generated by FormCalc 8.1 on 6-Apr-2013 23:49
#endif

#include "vars.h"
#include "inline.h"


void box() {

#include "vars.h"

#include "inline.h"

  Cloop(1) = Cloop(1) + 
     Alfa2*(EL*(-(8/3.*Sub15424) - 64/81.*Sub15434 + 
          2/81.*(Sub136*Sub15421 + (Pair1 + Pair2)*Sub15426 + 
             Sub15435) + 1/324.*Sub15602/(-MZ2 + S) - 
          MT/8.*((F12 + F7)*Sub15665)/(-MH2 + S34) + 
          1/36.*Sub15733/(-ME2 + Sub14828) + 
          1/54.*(-(Sub15761/(-MT2 + Sub14830)) - 
             Sub15790/(-MT2 + Sub14832)) - 
          1/36.*Sub15817/(-ME2 + Sub14834) + 
          1/CW2*(-(2/81.*Sub15432) - 1/(3.*SW2)*Sub15651/S34) + 
          1/(24.*(CW2*CW2))*
           (-Sub15701 + 4*(CW2*CW2)*Sub15668)/(-MZ2 + S34) + 
          1/SW2*(-(1/9.*Sub15448) + 
             1/162.*(3*Sub15497 - 4*SW2*Sub15506)/S) + 
          8/3.*(Sub4189*pave1(dd1)) + 
          64/81.*(Sub14576*pave2(dd2)) - 
          2/81.*(Sub14608*pave3(dd2))));

#ifdef DEBUG
  DEB("box: Cloop(1) =", Cloop(1));
#endif

}

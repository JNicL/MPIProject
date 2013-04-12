#if 0
* abbr0h.c
* abbreviations for {-F[2, {1}], F[2, {1}]} -> {-F[3, {3, Col3}], F[3, {3, Col4}], V[1]}
* generated by FormCalc 8.2 on 11-Apr-2013 22:37
#endif

#include "vars.h"
#include "inline.h"


void abbr0h() {

#include "vars.h"

#include "inline.h"

  F32 = ChainV2(Spinor(1,2),0,ec(5),k(3),1,Spinor(4,2));

  F36 = -ChainB2(Spinor(1,2),0,ec(5),k(4),0,Spinor(3,1));

  F15 = ChainV0(Spinor(1,2),0,1,Spinor(4,2));

  F3 = -ChainB0(Spinor(1,2),0,0,Spinor(3,1));

  F25 = -ChainB0(Spinor(1,2),0,1,Spinor(4,2));

  F5 = -ChainV0(Spinor(2,1),1,0,Spinor(3,1));

  F7 = ChainB0(Spinor(2,1),1,0,Spinor(3,1));

  F23 = ChainV0(Spinor(4,2),0,0,Spinor(2,1));

  F9 = -ChainV0(Spinor(4,2),0,0,Spinor(3,1));

  F11 = ChainB0(Spinor(4,2),0,0,Spinor(3,1));

  F35 = ChainV1(Spinor(1,2),0,ec(5),0,Spinor(3,1));

  F8 = ChainV1(Spinor(1,2),0,ec(5),1,Spinor(4,2));

  F33 = ChainB1(Spinor(1,2),0,ec(5),0,Spinor(3,1));

  F6 = -ChainB1(Spinor(1,2),0,ec(5),1,Spinor(4,2));

  F30 = -ChainB1(Spinor(1,2),0,k(3),0,Spinor(2,1));

  F2 = ChainV1(Spinor(4,2),0,ec(5),0,Spinor(2,1));

  F19 = ChainV1(Spinor(4,2),0,k(2),0,Spinor(3,1));

  F4 = ChainB1(Spinor(4,2),0,ec(5),0,Spinor(2,1));

  F17 = -ChainB1(Spinor(4,2),0,k(1),0,Spinor(3,1));

  F18 = -ChainB1(Spinor(4,2),0,k(2),0,Spinor(3,1));

  F28 = ChainV2(Spinor(1,2),0,ec(5),k(2),1,Spinor(4,2));

  F34 = -ChainV2(Spinor(1,2),0,ec(5),k(4),0,Spinor(3,1));

  F27 = -ChainB2(Spinor(1,2),0,ec(5),k(2),1,Spinor(4,2));

  F31 = -ChainB2(Spinor(1,2),0,ec(5),k(3),1,Spinor(4,2));

  F24 = ChainV2(Spinor(4,2),0,ec(5),k(1),0,Spinor(2,1));

  F1 = -ChainV0(Spinor(1,2),0,0,Spinor(3,1));

  F13 = ChainB0(Spinor(4,2),0,0,Spinor(2,1));

  F12 = ChainV1(Spinor(1,2),0,ec(5),0,Spinor(2,1));

  F29 = ChainV1(Spinor(1,2),0,k(3),0,Spinor(2,1));

  F20 = ChainV1(Spinor(1,2),0,k(4),0,Spinor(2,1));

  F10 = -ChainB1(Spinor(1,2),0,ec(5),0,Spinor(2,1));

  F26 = -ChainB1(Spinor(1,2),0,k(4),0,Spinor(2,1));

  F21 = ChainV1(Spinor(4,2),0,ec(5),0,Spinor(3,1));

  F16 = ChainV1(Spinor(4,2),0,k(1),0,Spinor(3,1));

  F22 = -ChainB1(Spinor(4,2),0,ec(5),0,Spinor(3,1));

  F14 = ChainB2(Spinor(4,2),0,ec(5),k(1),0,Spinor(2,1));

  Pair1 = Pair(ec(5),k(1));

  Pair2 = Pair(ec(5),k(2));

  Sub12 = F7*F8 + F12*(-F11 + F9);

  Sub8 = F23*F33 + F10*(F11 - F9);

  Sub8316 = -(F7*F8) + F12*(F11 - F9);

  Sub4924 = F3*F4 + F10*(-F11 + F9);

  Sub408 = F12*(F16 + F19) + F7*(-F28 - 2*F15*Pair1);

  Sub472 = F10*(F16 + F19) + F3*(F24 - 2*F23*(Pair1 + Pair2))
   ;

  Sub16 = 1/SW2*((1 - 2*SW2)*Sub12 + 2*SW2*Sub8);

  Sub13 = F12*F16 + F21*(F20 + F29) + 
     F7*(F32 - 2*F15*(Pair1 + Pair2));

  Opt32 = F12*(F16 + F17 + F18 + F19);

  Sub31 = F10*F19 + F23*(-F36 + MT*F33);

  Sub32 = F12*F19 - F32*F7 - MT*(F7*F8);

  Sub409 = F10*(F17 + F18) + F5*(-F27 - 2*F25*Pair1);

  Sub2074 = -(F12*(F17 + F18)) + 
     F1*(-F14 + 2*F13*(Pair1 + Pair2));

  Sub3389 = 1/SW2*((1 - 2*SW2)*Sub13 + MT*SW2*Sub16);

  Sub1063 = F10*(F16 + F17 + F18 + F19) + F24*F3 - F27*F5;

  Sub1463 = -(F24*F3) + F21*(F29 + F30) + F28*F7;

  Sub22 = F1*F2 + Sub8316;

  Sub19 = -(F5*F6) + Sub4924;

  Sub23 = F20*F21 + Sub408;

  Sub3 = -(F21*F29) - F28*F7 + 2*F15*F7*Pair2;

  Sub20 = F21*F26 + Sub472;

  Sub9 = F10*F16 + F21*(F26 + F30) - 
     F23*(-F36 + 2*F3*(Pair1 + Pair2));

  Sub13935 = F13*F34 + F23*F36 + F31*F5 + F32*F7;

  Sub14 = F5*F6 + F10*(F11 - F9);

  Sub10 = F13*F35 + F12*(-F11 + F9);

  Sub34 = F12*F18 + F13*(-F34 + MT*F35);

  Sub8436 = F21*F26 - 2*F23*F3*(Pair1 + Pair2);

  Sub14316 = F10*F17 - 2*F25*F5*(Pair1 + Pair2);

  Sub14321 = F12*F17 - 2*F15*F7*(Pair1 + Pair2);

  Sub5 = 1/SW2*((1 - 2*SW2)*(F1*F2) + 
       SW2*(2*F3*F4 - 2*F5*F6) + (-1 + 2*SW2)*(F7*F8));

  Sub25 = 1/SW2*(2*SW2*Sub19 + (1 - 2*SW2)*Sub22);

  Sub26 = 1/SW2*(2*SW2*Sub20 + (-1 + 2*SW2)*Sub23);

  Sub6 = 1/SW2*(SW2*(-2*F24*F3 + 2*F21*F30) + (1 - 2*SW2)*Sub3)
   ;

  Sub33 = 1/SW2*(2*SW2*Sub31 + (-1 + 2*SW2)*Sub32);

  Sub35 = -(F10*F18) + F5*(F31 + MT*F6);

  Sub24 = F22*F26 + Sub409;

  Sub4 = F22*F30 + F5*(F27 - 2*F25*Pair2);

  Sub21 = -(F20*F22) + Sub2074;

  Sub15 = F10*F17 + F22*(F26 + F30) - 
     F5*(-F31 + 2*F25*(Pair1 + Pair2));

  Sub17 = Sub3389 - 2*Sub9;

  Sub2791 = (F21 + F22)*(F20 + F26);

  Sub13793 = (F21 + F22)*(F29 + F30);

  Sub28 = F23*F33 + F13*F35 - F5*F6 - F7*F8;

  Sub2534 = 2*F15*F7*Pair2 - Sub1463;

  Sub583 = (F10 + F12)*(F18 + F19) - Sub13935;

  Sub11 = -(F12*F17) - F20*F22 - F22*F29 + 
     F13*(-F34 + F1*(2*Pair1 + 2*Pair2));

  Sub14281 = Sub13935 - MT*Sub28;

  Sub3460 = -Opt32 + 2*F23*F3*Pair1 + 2*F25*F5*Pair1 + 
     F7*(F28 + 2*F15*Pair1) + 2*F23*F3*Pair2 + 
     F1*(-F14 + F13*(2*Pair1 + 2*Pair2)) - Sub1063;

  Sub18 = (4 - 8*SW2)*Sub11 + 8*SW2*Sub15 + 
     (3 - 4*SW2)*Sub17 + MT*((4 - 8*SW2)*Sub10 + 8*SW2*Sub14);

  Sub36 = (3 - 4*SW2)*Sub33 + (4 - 8*SW2)*Sub34 + 8*SW2*Sub35
   ;

  Sub27 = (-4 + 8*SW2)*Sub21 - 8*SW2*Sub24 + 3*MT*Sub25 + 
     (3 - 4*SW2)*Sub26;

  Sub7 = (4 - 8*SW2)*(F1*F14) + (-4 + 8*SW2)*(F22*F29) + 
     8*SW2*Sub4 + 3*MT*Sub5 + (-3 + 4*SW2)*Sub6;

  Sub30 = Sub583 + MT*Sub28;

  Sub1 = -Sub2791 + Sub3460;

  Sub29 = (F10 + F12)*F16 + F20*(F21 + F22) + F22*F26 - 
     2*F1*F13*(Pair1 + Pair2) + Sub13793 + Sub14281 + Sub14316 + 
     Sub14321 + Sub8436;

  Sub14732 = Sub27/(-MZ2 + S) + 8*CW2*Sub1/S;

  Sub14734 = Sub18/(-MZ2 + S34) + 8*CW2*Sub29/S34;

  Sub14728 = (8*Sub30)/S34 - 1/CW2*Sub36/(-MZ2 + S34);

  Sub655 = F1*F14 - Sub4;

  Sub424 = -(F22*F29) + Sub655;

  Sub2 = Sub2534 + Sub424;

  Sub14730 = (8*Sub2)/S - 1/CW2*Sub7/(-MZ2 + S);

}
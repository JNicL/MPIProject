#if 0
* abbr1h.c
* abbreviations for {-F[2, {1}], F[2, {1}]} -> {-F[3, {3, Col3}], F[3, {3, Col4}]}
* generated by FormCalc 8.0 on 6-Mar-2013 10:48
#endif

/*#include "vars.h"*/


void abbr1h() {
#include <math.h>

  /*#include "vars.h"*/


  /*#include "inline.h"*/

  F9 = -(ChainV0(Spinor(4,1,2),0,0,Spinor(3,-1,1))*Hel(3));

  F12 = ChainB0(Spinor(4,1,2),0,0,Spinor(3,-1,1))*Hel(3);

  F17 = ChainV1(Spinor(1,-1,2),0,k(2),1,Spinor(4,1,2))*Hel(1)
   ;

  F10 = ChainV1(Spinor(1,-1,2),0,k(3),0,Spinor(2,1,1))*Hel(1)
   ;

  F15 = -(ChainB1(Spinor(1,-1,2),0,k(2),1,Spinor(4,1,2))*
       Hel(1));

  F11 = -(ChainB1(Spinor(1,-1,2),0,k(3),0,Spinor(2,1,1))*
       Hel(1));

  F16 = ChainV1(Spinor(4,1,2),0,k(1),0,Spinor(2,1,1));

  F18 = ChainV1(Spinor(4,1,2),0,k(1),0,Spinor(3,-1,1))*Hel(3)
   ;

  F13 = ChainB1(Spinor(4,1,2),0,k(1),0,Spinor(2,1,1));

  F14 = -(ChainB1(Spinor(4,1,2),0,k(1),0,Spinor(3,-1,1))*
       Hel(3));

  Sub169 = 3*(F1*F2 + F5*F6) - 5*(F3*F4 + F7*F8);

  Sub198 = 5*(F1*F2 + F5*F6) - 3*(F3*F4 + F7*F8);

  Sub302 = 2*F17*F4 + F10*(-F12 + F9);

  Sub301 = -2*F15*F6 + F11*(-F12 + F9);

  Sub322 = 2*MT2*(F1*F2) + F10*(F18 + MT*F9);

  Sub332 = -(2*MT2*(-(F1*F2) - F3*F4)) + 
     F10*(F18 + MT*(F12 + F9));

  Sub282 = F1*(MT*F16 - 3*MT2*F2) - MT2*(F3*F4) - MT*(F10*F9)
   ;

  Sub319 = F11*(F14 + MT*F12) - 2*MT2*(F5*F6);

  Sub330 = -(2*MT2*(F5*F6)) + F11*(F14 + MT*(F12 + F9));

  Sub267 = MT*(F11*F12) + MT2*(2*F5*F6 + F7*F8);

  Sub284 = MT*(-(F11*F12) + F13*F7) + MT2*(-(F5*F6) - 3*F7*F8)
   ;

  Sub185 = 1/MW2*(MT2*F12 + (MB2 + 2*MW2)*F9);

  Sub168 = 1/MW2*(MT2*(F1*F2 + F5*F6) + 
       (MB2 + 2*MW2)*(F3*F4 + F7*F8));

  Sub184 = 1/MW2*((MB2 + 2*MW2)*F12 + MT2*F9);

  Sub170 = F12 + 1/MW2*((-MB2 - MT2)*F12 - 2*MB2*F9);

  Sub199 = (-2*MB2 + MW2)*F12 + (-MB2 - MT2 + MW2)*F9;

  Sub201 = 1/MW2*((-MB2 - MT2 + MW2)*(F1*F2 + F5*F6) - 
       4*MW2*(F3*F4 + F7*F8));

  Sub167 = MT2*(F1*F2 + F5*F6) + (MB2 + 2*MW2)*(F3*F4 + F7*F8)
   ;

  Sub197 = MT2*F12 + (MB2 + 2*MW2)*F9;

  Sub173 = (-MB2 - MT2 + 2*MW2)*F12 - 2*MB2*F9;

  Sub202 = MT*((F10 + F11)*(F12 + F9)) + 2*MT2*Sub3;

  Sub196 = (-MH2 + 4*MT2)*Sub3 + MT*((F10 + F11)*(F12 + F9));

  Sub320 = Sub319 + 2*MT2*(F5*F6 + F7*F8);

  Sub331 = Sub330 + MT2*(4*F5*F6 + 2*F7*F8);

  Sub147 = 1/(CW2*MW2)*(2*F12*Sub33 + F9*(-2*CW2*MW2 + Sub34))
   ;

  Sub165 = (F1*F2 + F5*F6)*Sub77 + (F3*F4 + F7*F8)*Sub78;

  Sub176 = (F3*F4 + F7*F8)*Sub79 - F1*F2*Sub80 - F5*F6*Sub80;

  Sub203 = -(F3*F4*Sub83) - F7*F8*Sub83 + MB2*Sub202;

  Sub166 = (F3*F4 + F7*F8)*Sub76 + (F1*F2 + F5*F6)*Sub84;

  Sub27 = 1/CW*(F6*(Alfa2*CW*Finite + 
         3*Alfa*Pi*((dZAZ1 + dZZA1)*SW)));

  Sub8 = (5 - 8*SW2)*(F3*F4) + (3 - 8*SW2)*(F7*F8);

  Sub28 = (Alfa*Pi)/CW*
     ((dZAZ1 + dZZA1)*((5 - 8*SW2)*(F3*F4) + (3 - 8*SW2)*(F7*F8)))/
      SW;

  Sub131 = 1/MW2*(F9*(Sub35 + MW2*(9 + SW2*(-36 + 32*SW2))) + 
       MW2*(9 + SW2*(-36 + 32*SW2))*F12);

  Sub132 = Pow(3 - 4*SW2,3)*(F3*F4*(-4*MT2 + S)) + 
     (MT*(3 - 4*SW2))/MW2*(F10*F12*Sub46);

  Sub17 = 2*F7*F8*Sub15 + (1 - 2*SW2)*(F3*F4*Sub16);

  Sub127 = (2 - 4*SW2)*(F10*F9*Sub35) + 
     (3 - 4*SW2)*(F11*F12*Sub46);

  Sub133 = 2*MT*(3 - 8*SW2)*(3 - 4*SW2)*(1 - 2*SW2)*
      (F10*(F12 + F9)) + Power(3 - 4*SW2,3)*(F7*F8*(-4*MT2 + S));

  Sub140 = 2*F9*Sub49 + MT2*(3 - 2*SW2)*F12;

  Sub116 = MT*(MW2*(6 - 4*SW2) + (MB2 + MT2)*(-3 + 2*SW2))*
      (F10*F12) + MT2*((F1*F2 - F3*F4)*Sub31);

  Sub117 = MT*((MB2 + MT2)*(3 - 2*SW2) + MW2*(-6 + 4*SW2))*
      (F11*F12) + MT2*((-(F5*F6) + F7*F8)*Sub31);

  Sub326 = -4*(-(F11*F12) + F13*F7) + 
     Power(1 - 2*SW2,2)/(SW2*SW2)*(F10*F12);

  Sub316 = 4*F13*F7 - Power(1 - 2*SW2,2)/(SW2*SW2)*(F1*F16);

  Sub214 = F7*F8 + Power(1 - 2*SW2,2)/(SW2*SW2)*(F3*F4);

  Sub216 = 4*F7*F8 + Power(1 - 2*SW2,2)/(SW2*SW2)*(F3*F4);

  Sub224 = 4*(F5*F6 + F7*F8) + 
     Power(1 - 2*SW2,2)/(SW2*SW2)*(F1*F2 + F3*F4);

  Sub307 = 4*F7*F8 + Power(1 - 2*SW2,2)/(SW2*SW2)*
      (F1*F2 + 2*F3*F4);

  Sub293 = 4*(F5*F6 + F7*F8) + 
     Power(1 - 2*SW2,2)/(SW2*SW2)*(F1*F2 + 2*F3*F4);

  Sub225 = 4*F11*F9 - Power(1 - 2*SW2,2)/(SW2*SW2)*
      (F1*F16 - F10*F9);

  Sub120 = 1/(SW2*SW2)*((1 - 2*SW2)*F10 - 2*SW2*F11);

  Sub113 = 1/(SW2*SW2)*(4*SW2*(F1*F2) + (-3 + 4*SW2)*(F3*F4))
   ;

  Sub93 = 1/(SW2*SW2)*((1 - 2*SW2)*(F1*F2) - 2*SW2*(F5*F6));

  Sub4 = 1/(SW2*SW2)*((1 - 2*SW2)*(F3*F4) - 2*SW2*(F7*F8));

  Sub22 = 1/(SW2*SW2)*(16*SW2*(F7*F8) + 
       (-1 + 2*SW2)*(F3*F4*Sub20));

  Sub115 = 1/(SW2*SW2)*
     ((1 - 2*SW2)*(F1*F2) + (-1 + 2*SW2)*(F3*F4) + 
       SW2*(-2*F5*F6 + 2*F7*F8));

  Sub122 = 1/(SW2*SW2)*
     ((1 - 2*SW2)*(F1*F2 + F3*F4) - 2*SW2*(F5*F6 + F7*F8));

  Sub99 = 1/(SW2*SW2)*((3 - 4*SW2)*F12 - 4*SW2*F9);

  Sub154 = 1/(SW2*SW2)*
     (Sub43*((1 - 2*SW2)*(F1*F2) - 2*SW2*(F5*F6)) + 
       Sub40*((-1 + 2*SW2)*(F3*F4) + 2*SW2*(F7*F8)));

  Sub180 = 1/(MW2*SW2)*
     (F9*(-Sub35 + MW2*(24 - 32*SW2)*SW2) + 
       F12*(-Sub46 + MW2*(24 - 32*SW2)*SW2));

  Sub29 = 1/(CW*SW2)*(F2*
        (Alfa*Pi*(3 - 12*SW2)*SW2*(dZAZ1 + dZZA1) + 
          Alfa2*CW*(1 - 4*SW2)*(Finite*SW)))/SW;

  Sub98 = 1/SW2*((-3 + 4*SW2)*F12 + 4*SW2*F9);

  Sub92 = 1/SW2*(4*SW2*(F1*F2) + (-3 + 4*SW2)*(F3*F4));

  Sub101 = 1/SW2*((-1 + 2*SW2)*F10 + 2*SW2*F11);

  Sub103 = 1/SW2*((2 - 4*SW2)*F10 + SW2*(F11*Sub96));

  Sub95 = 1/SW2*((-1 + 2*SW2)*(F1*F2) + 2*SW2*(F5*F6));

  Sub151 = 1/SW2*((1 - 2*SW2)*(F1*F2) + (-1 + 2*SW2)*(F3*F4) + 
       SW2*(-2*F5*F6 + 2*F7*F8));

  Sub102 = 1/SW2*(MB2*(-1 + 2*SW2)*(F10*F12) + 
       MT2*SW2*(F9*Sub101));

  Sub105 = 1/SW2*(MB2*(-1 + 2*SW2)*(F10*F9) + 
       MT2*SW2*(F12*Sub101));

  Sub141 = 1/SW2*(Sub140*((-1 + 2*SW2)*F10 + 2*SW2*F11));

  Sub145 = 1/SW2*(Sub144*((-1 + 2*SW2)*F10 + 2*SW2*F11));

  Sub192 = 1/SW2*((-1 + 2*SW2)*(F3*F4*Sub186) + 
       2*SW2*(F7*F8*Sub187));

  Sub268 = (MT2*(3 - 4*SW2)*Power(1 - 2*SW2,2))/SW2*
      (3*F1*F2 + 5*F3*F4) + Power(3 - 4*SW2,2)*Sub267;

  Sub12 = 1/CW2*(F5*F6);

  Sub178 = 16*SW2*(F1*F2 + F5*F6) + 
     Power(3 - 4*SW2,2)/SW2*(F3*F4 + F7*F8);

  Sub183 = Power(1 - 2*SW2,2)/SW2*(F1*F2 + F3*F4) + 
     4*SW2*(F5*F6 + F7*F8);

  Sub134 = SW2*(-1 + 2*SW2)*(F1*F2) + 2*(SW2*SW2)*(F5*F6);

  Sub218 = (Power(3 - 4*SW2,2)*Power(1 - 2*SW2,2))/(SW2*SW2)*
      (F3*F4) + 64*(SW2*SW2)*(F5*F6);

  Sub159 = 1/(CW2*MW2)*(MB2*SW2*F9 + CW2*(MW2*F12 - MB2*F9));

  Sub104 = 1/(CW2*MW2)*
     (SW2*Sub102 + CW2*(-Sub102 + 2*MW2*(F12*Sub103)));

  Sub106 = 1/(CW2*MW2)*
     (SW2*Sub105 + CW2*(-Sub105 + 2*MW2*(F9*Sub103)));

  Sub21 = ((3 - 4*SW2)*Power(-CW2 + SW2,2))/(CW2*CW2)*
      (F7*F8) + 2*(1 - 2*SW2)*(F1*F2*Sub20);

  Sub143 = Sub36*Sub95 + Sub1*(36*CW2*MT2*SW2 + MW2*Sub32);

  Sub137 = Sub37*Sub95 + Sub1*(36*CW2*MT2*SW2 + 2*MW2*Sub32);

  Sub138 = Sub101*(F12*Sub37 + 
       F9*(36*CW2*MT2*SW2 + 2*MW2*Sub32));

  Sub376 = 1/(CW2*SW2)*
     (-(2*CW2*((F1*F2 + F3*F4)*Sub375)) + SW2*(Sub183*pave8(cc2)));

    

  Sub405 = Sub106*pave14(cc11) + Sub104*pave14(cc22);

  Sub409 = MT2*((-3*F12 + 3*F9)*Sub101*pave13(cc12)) + 
     2*Sub141*pave12(cc22);

  Sub383 = 1/CW2*(-(9*CW2*MT*MT2*
          ((F10 + F11)*(F12 + F9)*pave13(cc22))) + 
       2*Sub165*pave16(cc00));

  Sub414 = (-9*F12 + 9*F9)*Sub101*Sub52*pave16(cc12) + 
     Sub138*pave16(cc22);

  Sub220 = -(F10*F12) + F1*F16 + F17*F4;

  Sub243 = -(F10*F12) + 2*F1*F16 + F17*F4;

  Sub91 = 2*F1*F2 + 5*F3*F4 + 3*F7*F8;

  Sub262 = 2*F15*F6 + F13*F7 + F11*(-F12 - 2*F9);

  Sub261 = F1*F16 + 2*F17*F4 + F10*(-2*F12 - F9);

  Sub251 = F15*F6 + F13*F7 + F11*(F12 - F9);

  Sub222 = F1*F16 + F10*(-F12 - F9);

  Sub232 = F15*F6 + F13*F7 - F11*F9;

  Sub244 = F15*F6 + 2*F13*F7 - F11*F9;

  Sub223 = -(F13*F7) + F11*(F12 + F9);

  Sub252 = F1*F16 + F17*F4 + F10*(-F12 + F9);

  Sub230 = F1*F16 + 2*F17*F4 - 2*F10*(F12 + F9);

  Sub231 = -2*F15*F6 - F13*F7 + 2*F11*(F12 + F9);

  Sub171 = (F3*F4 + F7*F8)*(8*MT2 - 2*S) + MT2*Sub169 + 
     MT*((F10 + F11)*Sub170);

  Sub200 = 2*(F3*F4 + F7*F8)*(4*MT2 - S) + MT2*Sub198 + 
     MT/MW2*((F10 + F11)*(Sub199 + MW2*F9));

  Sub177 = 1/CW2*(Sub176 + 
       CW2*(-(9*MT*MT2*((F10 + F11)*(F12 + F9))) - 
          18*(MT2*MT2)*Sub3));

  Sub205 = 2*F1*F2*Sub82 + F7*F8*Sub86 + F3*F4*Sub88;

  Sub208 = 2*F3*F4*Sub74 + F7*F8*Sub75 + F1*F2*Sub90;

  Sub9 = Sub8 + (2 - 8*SW2)*(F1*F2);

  Sub19 = 8*F5*F6*Sub18 + (4 - 8*SW2)*(F1*F2*Sub15) + 
     (3 - 4*SW2)*Sub17;

  Sub158 = 1/(CW2*(SW2*SW2))*
     (2*(SW2*SW2)*Sub1 + CW2*
        ((-3 + 6*SW2)*(F1*F2) + (3 - 6*SW2)*(F3*F4) + 
          SW2*(6*F5*F6 - 6*F7*F8)));

  Sub146 = 1/(CW2*(SW2*SW2))*
     (2*(SW2*SW2)*Sub95 + CW2*
        ((3 - 6*SW2)*(F1*F2) + (-3 + 6*SW2)*(F3*F4) + 
          SW2*(-6*F5*F6 + 6*F7*F8)));

  Sub118 = 1/(SW2*SW2)*
     ((1 - 2*SW2)*Sub116 + 2*SW2*Sub117 + 
       MB2*(SW2*SW2)*(-(4*MT*(F9*Sub101)) - 3*MT2*Sub115));

  Sub23 = 1/SW2*(-2*Sub21 + 
       SW2*(8*F5*F6*Sub20 + (-3 + 4*SW2)*Sub22));

  Sub190 = 1/SW2*(F3*F4*Sub71 + 
       SW2*(4*F1*F2*Sub59 + 2*F7*F8*Sub62));

  Sub142 = 1/SW2*((-3 + 5*SW2)*(F3*F4) + 
       SW2*(2*F1*F2 + 3*F7*F8));

  Sub109 = 1/SW2*((-4 + 8*SW2)*(F1*F2) + 
       SW2*(8*F5*F6 + (3 - 4*SW2)*Sub4));

  Sub5 = 1/SW2*((-4 + 8*SW2)*(F1*F2) + 
       SW2*(8*F5*F6 + (3 - 4*SW2)*Sub4));

  Sub94 = 1/SW2*((-4 + 8*SW2)*(F3*F4) + 
       SW2*(8*F7*F8 + (3 - 4*SW2)*Sub93));

  Sub114 = -(32*(SW2*SW2)*(F5*F6)) + 
     8*(3 - 4*SW2)*SW2*(F7*F8) + Power(1 - 2*SW2,3)*Sub113;

  Sub215 = 4*Power(1 - 2*SW2,2)*(F1*F2) + 
     64*(SW2*SW2)*(F5*F6) + Power(3 - 4*SW2,2)*Sub214;

  Sub217 = 16*Power(1 - 2*SW2,2)*(F1*F2) + 
     64*(SW2*SW2)*(F5*F6) + Power(3 - 4*SW2,2)*Sub216;

  Sub156 = -(64*(1 - 2*SW2)*SW2*(F1*F2)) + 
     128*(SW2*SW2)*(F5*F6) + Power(3 - 4*SW2,3)*Sub4;

  Sub194 = 1/(SW2*SW2)*
     (F3*F4*Sub55 + 208*Power(SW2,4)*(F5*F6) + 
       SW2*(-2*F1*F2*Sub53 - F7*F8*Sub56));

  Sub112 = 1/(CW2*MW2*SW2)*
     (-(8*MW2*SW2*(F7*F8)) + MT*(SW2*SW2)*((F12 + F9)*Sub120) + 
       CW2*(-(MT*SW2*(F12*Sub120)) - MT*SW2*(F9*Sub120) + 
          MW2*(-8*F7*F8 + (4 - 8*SW2)*SW2*(F3*F4*Sub111))));

  Sub10 = 1/CW2*(-(SW2*Sub9) + 
       CW2*(4*Sub8 + Sub9 + (8 - 32*SW2)*(F1*F2)));

  Sub97 = 1/(CW2*MW2*SW2)*
     (MT2*(SW2*SW2)*Sub95 + 
       CW2*(MW2*(-1 + 2*SW2)*(F3*F4*Sub96) + 
          SW2*(-(MT2*Sub95) + 2*MW2*(F7*F8*Sub96))));

  Sub172 = F1*F2 - F3*F4 + F5*F6 - F7*F8;

  Sub135 = 1/(SW2*SW2)*
     ((1 - 2*SW2)*Sub132 - 2*SW2*Sub133 + 
       SW2*SW2*((-256*MT2 + 64*S)*Sub134 + 8*MT*(F11*Sub131)));

  Sub6 = 1/SW2*((-2 + 8*SW2)*(F1*F2) + (-5 + 8*SW2)*(F3*F4) + 
       8*SW2*(F5*F6) + (-3 + 8*SW2)*(F7*F8));

  Sub211 = 1/(SW2*SW2)*
     ((3 + SW2*(-10 + 8*SW2))*(F1*F2) + 8*(SW2*SW2)*(F7*F8) + 
       SW2*((-4 + 8*SW2)*(F3*F4) + (-6 + 8*SW2)*(F5*F6)));

  Sub163 = 1/(SW2*SW2)*
     (F11*(SW2*(-6 + 8*SW2)*F12 + 8*(SW2*SW2)*F9) + 
       F10*((3 + SW2*(-10 + 8*SW2))*F12 + SW2*(-4 + 8*SW2)*F9));

  Sub204 = F3*F4*(Conjugate(dZfL1(2,1,1)) + 
        Conjugate(dZfL1(3,3,3))) + 
     F7*F8*(Conjugate(dZfL1(3,3,3)) + Conjugate(dZfR1(2,1,1))) + 
     F1*F2*(Conjugate(dZfL1(2,1,1)) + Conjugate(dZfR1(3,3,3))) + 
     F5*F6*(Conjugate(dZfR1(2,1,1)) + Conjugate(dZfR1(3,3,3)));

  Sub212 = 1/(MW2*(SW2*SW2))*
     (MT*(-1 + 2*SW2)*(F10*(F9*Sub45 + F12*Sub47)) + 
       2*(MT2*MW2*(SW2*SW2)*Sub211 + 
          MT*SW2*(F11*(F9*Sub45 + F12*Sub47))));

  Sub30 = 1/SW2*(SW2*(8*F5*Sub27 - 3*Sub28 - 2*F1*Sub29) + 
       Alfa2*(Finite*((-5 + 8*SW2)*(F3*F4) + (-3 + 8*SW2)*(F7*F8)))
       );

  Sub381 = MT*((F10 + F11)*
        (((-MB2 + MT2 - 2*MW2)*F12 + (MB2 - MT2 + 2*MW2)*F9)*
           pave12(cc12) + Sub197*pave12(cc22))) + 
     MT2*(Sub196*pave13(cc0) + 2*Sub3*pave13(cc00)) + 
     Sub167*pave11(bb0);

  Sub164 = 1/(SW2*SW2)*
     (MT*(SW2*SW2)*Sub163 + 
       F1*F2*(MT2*(3 + SW2*(-14 + 16*SW2)) + (1 - 2*SW2)*Sub50) + 
       F3*F4*(MT2*(3 + SW2*(-14 + 16*SW2)) + (1 - 2*SW2)*Sub51) + 
       SW2*(F5*F6*(-2*Sub50 + MT2*(-6 + 16*SW2)) + 
          F7*F8*(-2*Sub51 + MT2*(-6 + 16*SW2))));

  Sub13 = 1/(CW2*SW2)*(SW2*
        ((-2 + 8*SW2)*(F1*F2) + (-5 + 8*SW2)*(F3*F4) + 
          (-3 + 8*SW2)*(F7*F8)) + 
       CW2*((-2 + 8*SW2)*(F1*F2) + (-5 + 8*SW2)*(F3*F4) + 
          (-3 + 8*SW2)*(F7*F8) + 8*SW2*Sub12));

  Sub107 = -Sub120;

  Sub108 = -Sub4;

  Sub152 = -Sub99;

  Sub24 = -Sub2;

  Sub276 = F10*F18 + F3*F4*(-MT2 + 2*T);

  Sub277 = F11*F14 + F5*F6*(-MT2 + 2*T);

  Sub311 = F10*F18 + F3*F4*(-MT2 + T);

  Sub335 = 3*F10*F18 + F3*F4*(-2*MT2 + 2*T);

  Sub341 = 2*F10*F18 + F3*F4*(-3*MT2 + 3*T);

  Sub312 = F11*F14 + F5*F6*(-MT2 + T);

  Sub336 = 3*F11*F14 + F5*F6*(-2*MT2 + 2*T);

  Sub342 = 2*F11*F14 + F5*F6*(-3*MT2 + 3*T);

  Sub343 = 2*F10*F14 + F1*F2*(MT2 + T - 2*U);

  Sub344 = 2*F11*F18 + F7*F8*(MT2 + T - 2*U);

  Sub289 = F11*F14 + F5*F6*(T - U);

  Sub253 = 2*F11*F14 + F5*F6*(T - U);

  Sub303 = F10*F18 + F3*F4*(MT2 + T - U);

  Sub304 = F11*F14 + F5*F6*(MT2 + T - U);

  Sub305 = -(F10*F14) + F1*F2*(-4*MT2 + 2*U);

  Sub306 = F11*F18 + F7*F8*(4*MT2 - 2*U);

  Sub254 = -(F10*F14) + F1*F2*(-MT2 + U);

  Sub290 = -(F10*F14) + F1*F2*(-2*MT2 + 2*U);

  Sub233 = -2*F10*F14 + F1*F2*(-3*MT2 + 3*U);

  Sub245 = -3*F10*F14 + F1*F2*(-4*MT2 + 4*U);

  Sub246 = 3*F11*F18 + F7*F8*(4*MT2 - 4*U);

  Sub234 = 2*F11*F18 + F7*F8*(3*MT2 - 3*U);

  Sub291 = F11*F18 + F7*F8*(2*MT2 - 2*U);

  Sub255 = F11*F18 + F7*F8*(MT2 - U);

  Sub278 = -2*F10*F14 + F1*F2*(MT2 - S - 3*T + U);

  Sub279 = 2*F11*F18 + F7*F8*(-MT2 + S + 3*T - U);

  Sub235 = 2*F10*F18 + F3*F4*(-MT2 + 2*T - U);

  Sub236 = 2*F11*F14 + F5*F6*(-MT2 + 2*T - U);

  Sub292 = F10*F18 + F3*F4*(T - U);

  Sub256 = 2*F10*F18 + F3*F4*(T - U);

  Sub263 = -(F10*F14) + F1*F2*(MT2 - S - T + U);

  Sub264 = F11*F18 + F7*F8*(-MT2 + S + T - U);

  Sub265 = 2*F10*F18 + F3*F4*(-MT2 + 2*T - 2*U);

  Sub266 = 2*F11*F14 + F5*F6*(-MT2 + 2*T - 2*U);

  Sub219 = F3*F4*(-2*MT2 + S + T) + F1*(MT*F16 - MT2*F2) - 
     MT*(F10*F9);

  Sub321 = F10*F14 + F1*(F2*(MT2 - U) - MT*F16);

  Sub229 = F3*F4*(-3*MT2 + 2*T - U) - 2*MT2*(F1*F2) + 
     2*(F10*F18 + MT*Sub220);

  Sub221 = F3*F4*(4*MT2 - 2*T + 2*U) + 2*MT2*(F1*F2) - 
     2*(F10*F18 + MT*Sub220);

  Sub323 = 8*(F11*F18 - F7*F8*U) - 8*F7*(MT*F13 - MT2*F8) + 
     Power(1 - 2*SW2,2)/(SW2*SW2)*Sub322;

  Sub333 = 8*(F11*F18 - F7*F8*U) - 8*F7*(MT*F13 - MT2*F8) + 
     Power(1 - 2*SW2,2)/(SW2*SW2)*Sub332;

  Sub110 = 1/(CW2*MW2)*
     (4*MW2*Sub109 + CW2*MT*((3*F12 - 3*F9)*Sub120));

  Sub148 = F3*F4*(-16*MT2 + 4*S) + MT*(F10*Sub147);

  Sub149 = F7*F8*(-16*MT2 + 4*S) + MT*(F11*Sub147);

  Sub160 = F3*F4*(8*MT2 - 2*S) + MT*(F10*Sub159);

  Sub161 = F7*F8*(8*MT2 - 2*S) + MT*(F11*Sub159);

  Sub174 = MT2*(-MB2 + MT2 + 2*MW2)*Sub172 + 
     MT*((F10 + F11)*Sub173);

  Sub175 = 1/MW2*(Sub174 + MW2*((F3*F4 + F7*F8)*(8*MT2 - 2*S)))
   ;

  Sub239 = Sub233 + MT*(F1*F16 + 2*F10*F9);

  Sub339 = Sub336 + 2*MT*(F11*F12 + F13*F7);

  Sub391 = 2*Sub151*Sub389 + MT*((F12 - F9)*Sub101*Sub390);

  Sub25 = 1/CW2*(6*Alfa*Pi*(dZZZ1*Sub2) + 
       Alfa2*CW2*(Finite*Sub5));

  Sub128 = 2*MT*Sub127 + MT2*((-9*F5*F6 + 9*F7*F8)*Sub54);

  Sub191 = (-Sub190 + 8*F5*F6*Sub73*SW)/SW;

  Sub14 = (Sub9 - 8*SW2*(F5*F6))/SW;

  Sub206 = 1/CW*(2*dZZA1*F5*F6*SW + CW*(Sub204 + F5*F6*Sub89))
   ;

  Sub181 = -(Power(3 - 4*SW2,2)*
        ((F3*F4 + F7*F8)*(-4*MT2 + S))) + 3*MT2*(3 - 8*SW2)*Sub172;

    

  Sub153 = 2*F11*Sub98 + (1 - 2*SW2)*(F10*Sub99);

  Sub100 = 2*F11*Sub98 + (1 - 2*SW2)*(F10*Sub99);

  Sub119 = 1/MW2*(Sub118 + 
       MW2*(Sub4*(MT2*(24 - 16*SW2) + (-6 + 4*SW2)*S)));

  Sub121 = 2*F9*Sub101 + (3 - 2*SW2)*(F12*Sub120);

  Sub139 = 2*Sub1*Sub49 + MT2*(3 - 2*SW2)*Sub95;

  Sub337 = 4*Sub244 - Power(1 - 2*SW2,2)/(SW2*SW2)*
      (F1*F16 + F10*F9);

  Sub345 = 8*Sub232 - Power(1 - 2*SW2,2)/(SW2*SW2)*
      (F1*F16 + 2*F10*F9);

  Sub294 = 2*F11*F12 - Power(1 - 2*SW2,2)/(SW2*SW2)*Sub220;

  Sub237 = -2*(2*F11*F12 + F13*F7) + 
     Power(1 - 2*SW2,2)/(SW2*SW2)*Sub220;

  Sub247 = -4*(F11*F12 + F13*F7) + 
     Power(1 - 2*SW2,2)/(SW2*SW2)*Sub243;

  Sub257 = 4*Sub251 - Power(1 - 2*SW2,2)/(SW2*SW2)*Sub252;

  Sub258 = 8*Sub255 + Power(1 - 2*SW2,2)/(SW2*SW2)*Sub256;

  Sub313 = 4*Sub255 + Power(1 - 2*SW2,2)/(SW2*SW2)*Sub311;

  Sub11 = 1/SW2*(Sub10 + 8*SW2*(F5*F6*Sub7));

  Sub179 = 1/(CW2*MW2*SW2)*(CW2*Sub177 + 4*MT2*MW2*SW2*Sub178)
   ;

  Sub226 = 1/SW2*(4*SW2*(F10*F12) + (-3 + 4*SW2)*Sub222);

  Sub327 = 1/SW2*(SW2*(4*F1*F16 - 4*F10*F9) + 
       (3 - 4*SW2)*Sub222);

  Sub347 = 1/SW2*(8*SW2*Sub220 + (3 - 4*SW2)*Sub230);

  Sub209 = 1/SW2*(Sub208 + 52*(SW2*SW2)*(F5*F6));

  Sub272 = Power(1 - 2*SW2,2)/SW2*Sub261 + 4*SW2*Sub262;

  Sub240 = MT*(3 - 4*SW2)*SW2*Sub231 + 
     Power(1 - 2*SW2,2)*Sub239;

  Sub348 = SW2*SW2*(8*F11*F12 + 4*F13*F7) + 
     (3 - 4*SW2)*SW2*Sub231;

  Sub241 = ((3 - 4*SW2)*Power(1 - 2*SW2,2))/SW2*Sub230 + 
     32*(SW2*SW2)*Sub232;

  Sub314 = 1/(SW2*SW2)*
     (MT*(-9 + 24*SW2)*(F1*F16) + 16*(SW2*SW2)*Sub254);

  Sub299 = 1/(SW2*SW2)*
     (MT*(-9 + 24*SW2)*Sub252 + 32*(SW2*SW2)*Sub254);

  Sub415 = MT*Sub414 + 2*Sub143*pave3(bb0);

  Sub372 = 1/CW*(Alfa*MZ2*Pi*(dZZA1*Sub14) + 
       Alfa2*CW*MW2*(Sub13*pave2(bb0)));

  Sub367 = 1/(CW2*CW2)*
     (CW2*CW2*(Sub19*pave2(bb0)) + Sub5*pave4(bb00));

  Sub403 = Sub142*pave2(bb0) + Sub92*pave9(cc00);

  Sub378 = 1/MW2*(MW2*(Sub91*pave2(bb0)) + Sub167*pave12(cc00))
   ;

  Sub408 = Sub164*pave13(cc0) + 2*Sub94*pave13(cc00);

  Sub412 = MT2*(Sub5*pave5(cc1)) + Sub114*pave8(cc00);

  Sub401 = 1/(CW2*MW2*SW2)*
     (MT*((F12 - F9)*Sub101*pave12(cc1)) + 
       CW2*MW2*SW2*(Sub112*pave14(cc0)));

  Sub410 = MT*Sub409 - 6*(MT2*MT2)*(Sub151*pave13(cc2));

  Sub397 = (3*F12 - 3*F9)*Sub101*Sub396 + 
     SW2*(Sub100*pave13(cc22));

  Sub273 = Sub263 + MT2*(F1*F2 + 2*F3*F4) + MT*(F10*F9);

  Sub269 = -Sub265 + MT2*(2*F1*F2 + 3*F3*F4) - 2*MT*Sub220;

  Sub271 = Sub266 + MT2*(-3*F5*F6 - 2*F7*F8) + 2*MT*Sub232;

  Sub280 = Sub276 + MT2*(2*F1*F2 + F3*F4) + MT*(F10*F9);

  Sub285 = Sub277 + MT*(F11*F12) + MT2*(F5*F6 + 2*F7*F8);

  Sub297 = -Sub289 + MT2*(2*F5*F6 + F7*F8) - MT*Sub232;

  Sub296 = Sub290 + 2*MT2*(F1*F2 + F3*F4) + MT*(F10*F9);

  Sub309 = -Sub304 + MT2*(2*F5*F6 + F7*F8) - MT*Sub232;

  Sub393 = -2*Sub139*Sub388 + 3*MT2*Sub391 - 
     4*MW2*(Sub392*Sub92);

  Sub406 = 8*Sub403 - 2*Sub404*Sub92 + 3*MT*Sub405;

  Sub155 = 1/CW2*(Sub154 + 
       CW2*(MT2*MT2*(27 - 72*SW2)*Sub122 + 9*MT*MT2*Sub153));

  Sub238 = 4*Sub234 + Power(1 - 2*SW2,2)/(SW2*SW2)*Sub235 + 
     2*MT*Sub237;

  Sub248 = 2*Sub246 + Power(1 - 2*SW2,2)/(SW2*SW2)*Sub235 + 
     MT*Sub247;

  Sub281 = 4*Sub279 - 4*F7*(2*MT*F13 - MT2*F8) + 
     Power(1 - 2*SW2,2)/(SW2*SW2)*Sub280;

  Sub338 = 16*Sub255 + Power(1 - 2*SW2,2)/(SW2*SW2)*Sub335 - 
     2*MT*Sub337;

  Sub346 = 4*Sub344 + Power(1 - 2*SW2,2)/(SW2*SW2)*Sub341 - 
     MT*Sub345;

  Sub150 = 1/(SW2*SW2)*
     ((-1 + 2*SW2)*Sub148 + 2*(MT2*(SW2*SW2)*Sub146 + SW2*Sub149));

    

  Sub283 = 1/SW2*((3 - 4*SW2)*Sub282 + 
       SW2*(4*Sub278 + F1*(8*MT*F16 - 4*MT2*F2)));

  Sub182 = 1/SW2*(Sub181 + 
       SW2*SW2*((F1*F2 + F5*F6)*(64*MT2 - 16*S)) + 
       MT*SW2*((F10 + F11)*Sub180));

  Sub324 = 64*(SW2*SW2)*Sub320 + 
     32*Power(1 - 2*SW2,2)*Sub321 + Power(3 - 4*SW2,2)*Sub323;

  Sub334 = 32*Power(1 - 2*SW2,2)*Sub321 + 
     64*(SW2*SW2)*Sub331 + Power(3 - 4*SW2,2)*Sub333;

  Sub249 = 8*Sub245 + (MT2*(9 + SW2*(-24 + 32*SW2)))/(SW2*SW2)*
      (F1*F2 + F3*F4) + 16*MT*(F1*F16 + F10*F9);

  Sub318 = Sub311 + MT*(F1*F16);

  Sub260 = Sub256 + MT*Sub252;

  Sub373 = 2*Sub372 + Alfa2*(Sub11*(pave1 - 2*pave2(bb00)));

  Sub382 = 1/CW2*(CW2*(9*Sub381 + 
          27*MB2*MT*((F10 + F11)*(F12 + F9)*pave14(cc0))) - 
       2*Sub166*pave3(bb0));

  Sub407 = 1/(CW2*CW2*MW2)*
     (CW2*CW2*MW2*(9*Sub406 - 54*Sub97*pave14(cc00)) + 
       Sub137*pave16(cc00));

  Sub384 = -(1/MW2*((Sub203 + MT2*MW2*Sub201)*pave12(cc0))) + 
     Sub175*pave12(cc2) + 8*(F1*F2 + F3*F4)*pave9(cc00);

  Sub380 = 1/SW2*(MT*((F10 + F11)*
          ((9 - 24*SW2)*F12 + (-9 + 24*SW2)*F9)*pave16(cc12)) + 
       SW2*(Sub182*pave16(cc2) + 18*Sub183*pave8(cc00)));

  Sub295 = 2*Sub291 + Power(1 - 2*SW2,2)/(SW2*SW2)*Sub292 - 
     MT2*Sub293 - MT*Sub294;

  Sub308 = -((MT*Power(1 - 2*SW2,2))/(SW2*SW2)*Sub220) - 
     2*(Sub306 + MT*Sub301) - 
     Power(1 - 2*SW2,2)/(SW2*SW2)*Sub303 + MT2*Sub307;

  Sub193 = 1/(CW*CW2)*(Sub191 + 
       CW*CW2*((-4 + 8*SW2)*(F1*F2*Sub188) + 
          8*SW2*(F5*F6*Sub189) + (-3 + 4*SW2)*Sub192));

  Sub227 = -(64*(SW2*SW2)*(-(F11*F12) + F13*F7)) + 
     16*(3 - 4*SW2)*SW2*Sub223 + Power(3 - 4*SW2,2)*Sub225 + 
     4*Power(1 - 2*SW2,2)*Sub226;

  Sub328 = 64*(SW2*SW2)*(F11*F9) + 16*(3 - 4*SW2)*SW2*Sub223 + 
     Power(3 - 4*SW2,2)*Sub326 - 4*Power(1 - 2*SW2,2)*Sub327;

  Sub259 = 64*(SW2*SW2)*Sub253 - 
     32*Power(1 - 2*SW2,2)*Sub254 - 3*MT*(3 - 8*SW2)*Sub257 + 
     Power(3 - 4*SW2,2)*Sub258;

  Sub286 = Power(3 - 4*SW2,2)*Sub281 - 
     4*Power(1 - 2*SW2,2)*Sub283 - 16*(3 - 4*SW2)*SW2*Sub284 + 
     64*(SW2*SW2)*Sub285;

  Sub317 = -(16*Power(1 - 2*SW2,2)*Sub254) + 
     64*(SW2*SW2)*Sub312 + Power(3 - 4*SW2,2)*Sub313 - 
     3*MT*(3 - 8*SW2)*Sub316;

  Sub340 = 2*MT2*(Sub213*Sub224) + Power(3 - 4*SW2,2)*Sub338 + 
     64*(SW2*SW2)*Sub339 - 
     32*Power(1 - 2*SW2,2)*(2*Sub254 + MT*Sub243);

  Sub162 = 1/(CW2*MW2*(SW2*SW2))*
     (F12*(-(MB2*MT*Power(SW2,3)*Sub120) - 
          MT*MT2*Power(SW2,3)*Sub120) + 
       CW2*(MT*(MB2 + MT2)*(SW2*SW2)*(F12*Sub120) + 
          MW2*(2*MT2*(SW2*SW2)*Sub158 + (-2 + 4*SW2)*Sub160 + 
             4*SW2*Sub161)));

  Sub315 = 12*MT*(-3 + 8*SW2)*(F13*F7) + 64*(SW2*SW2)*Sub312 + 
     Power(3 - 4*SW2,2)*Sub313 - Power(1 - 2*SW2,2)*Sub314;

  Sub300 = 12*MT*(-3 + 8*SW2)*Sub251 + 64*(SW2*SW2)*Sub253 + 
     Power(3 - 4*SW2,2)*Sub258 - Power(1 - 2*SW2,2)*Sub299;

  Sub250 = 4*MT2*(9 + SW2*(-24 + 32*SW2))*(F5*F6 + F7*F8) - 
     Power(3 - 4*SW2,2)*Sub248 + Power(1 - 2*SW2,2)*Sub249 - 
     64*(SW2*SW2)*(Sub236 + MT*Sub244);

  Sub325 = Sub303 + MT2*(-(F1*F2) - 2*F3*F4) + MT*Sub220;

  Sub288 = Sub235 - MT2*(F1*F2) - MT2*(F3*F4) + MT*Sub243;

  Sub287 = Sub292 + MT2*(-(F1*F2) - 2*F3*F4) + MT*Sub220;

  Sub370 = 1/Power(CW2,3)*
     (Sub369*Sub5 + Power(CW2,3)*
        (4*Sub367 + Sub23*(-2*pave1 + 4*pave2(bb00))));

  Sub413 = Sub212*pave5(cc2) + 
     Sub114*(MZ2*pave8(cc0) + pave7(bb0) + S*pave8(cc2));

  Sub419 = Sub287*pave25(dd11) + Sub325*pave25(dd12) + 
     Sub288*pave25(dd13) + Sub260*pave25(dd23);

  Sub242 = 16*Sub240 + 18*MT2*Sub224 - 64*(SW2*SW2)*Sub236 - 
     Power(3 - 4*SW2,2)*Sub238 - 4*MT*Sub241;

  Sub349 = 18*MT2*Sub224 + 64*(SW2*SW2)*Sub342 + 
     Power(3 - 4*SW2,2)*Sub346 + 16*MT*Sub348 + 
     4*Power(1 - 2*SW2,2)*(4*Sub343 - MT*Sub347);

  Sub420 = 8*F3*F4*pave25(dd00) + Sub221*pave25(dd1) - 
     Sub219*pave25(dd2) - Sub229*pave25(dd3) - 
     2*(Sub419 + Sub318*pave25(dd33));

  Sub385 = 9*Sub384 + 1/MW2*
      (-Sub382 - Sub383 - 27*MT*(MB2 + MT2 + 2*MW2)*
         ((F10 + F11)*(F12 + F9)*pave14(cc12))) - 
     27*MT*((F10 + F11)*(Sub185*pave14(cc11) + 
          Sub184*pave14(cc22))) + 54*Sub168*pave14(cc00) + 
     27*(Sub171*pave14(cc1) + Sub200*pave14(cc2));

  Sub329 = Sub217*T + MT2*(-Sub217 + 9*Sub224) + MT*Sub328;

  Sub228 = -(S*Sub217) - Sub217*T + MT2*(Sub217 + 9*Sub224) + 
     MT*Sub227;

  Sub129 = 1/CW2*(Sub128 + CW2*(MT2*MT2)*(27*F5*F6 - 27*F7*F8))
   ;

  Sub157 = 1/(CW2*MW2)*(CW2*Sub155 - 4*MT2*MW2*Sub156);

  Sub195 = 1/CW2*(36*Alfa*CW2*Pi*Sub193 - 
       Alfa2*(Finite*Sub194));

  Sub26 = 1/CW2*(CW2*(S*Sub25) - 
       6*Alfa*Pi*(Sub2*(dMZsq1 + MZ2*dZZZ1)));

  Sub207 = 1/CW*(-Sub205 + 4*CW*(Sub206*SW))/SW;

  Sub123 = MT*Sub121 + MT2*(3 - 4*SW2)*Sub122;

  Sub270 = 4*Sub264 - Power(1 - 2*SW2,2)/(SW2*SW2)*Sub269;

  Sub130 = 1/(SW2*SW2)*
     (Sub126*((-9 + 18*SW2)*(F1*F2) + (9 - 18*SW2)*(F3*F4)) + 
       2*SW2*Sub129);

  Sub379 = 1/(CW2*SW2)*(SW2*(Sub183*Sub377) + CW2*Sub378);

  Sub274 = MT2*(3 - 4*SW2)*SW2*(5*F5*F6 + 3*F7*F8) + 
     Power(1 - 2*SW2,2)*Sub273;

  Sub398 = 1/(MW2*SW2)*
     (MT*Sub397 - MW2*SW2*(Sub110*pave5(cc0)));

  Sub411 = Sub410 - 8*MW2*(Sub92*pave6(cc00));

  Sub374 = 4*Sub3*Sub371 + (3*Sub373)/(-MZ2 + S);

  Sub416 = 1/(MW2*SW2)*
     (Sub415 + MW2*SW2*(36*Sub412 - 18*Sub413));

  Sub124 = 1/(SW2*SW2)*
     (MB2*(SW2*SW2)*Sub123 + 
       (1 - 2*SW2)*(F3*F4*Sub44 + MT2*(F1*F2*Sub48)) - 
       2*SW2*(F7*F8*Sub44 + MT2*(F5*F6*Sub48)));

  Sub298 = -(Power(3 - 4*SW2,2)*Sub295) + 
     8*Power(1 - 2*SW2,2)*Sub296 + 64*(SW2*SW2)*Sub297;

  Sub310 = Power(3 - 4*SW2,2)*Sub308 + 64*(SW2*SW2)*Sub309 + 
     8*Power(1 - 2*SW2,2)*(Sub305 + 2*MT2*(F1*F2) + MT*Sub302);

  Sub402 = 1/SW2*(MT*((F12 + F9)*Sub145*pave14(cc12)) + 
       SW2*(Sub162*pave14(cc1) - Sub150*pave14(cc2)));

  Sub386 = 1/(CW2*SW2)*
     (-(2*SW2*Sub380) + CW2*
        (Sub385 + SW2*(18*Sub379 - Sub179*pave16(cc0))));

  Sub275 = 4*Sub268 + 16*Sub274 - Power(3 - 4*SW2,2)*Sub270 - 
     64*(SW2*SW2)*Sub271 - 4*MT*(3 - 4*SW2)*Sub272;

  Sub422 = Sub300*pave26(dd23) + Sub315*pave26(dd33) - 
     Sub298*pave27(dd11) - Sub310*pave27(dd12) - 
     Sub250*pave27(dd13) + Sub259*pave27(dd23) + Sub217*pave28(cc0)
    ;

  Sub421 = -(Sub286*pave26(dd1)) - Sub324*pave26(dd11) - 
     Sub334*pave26(dd12) - Sub340*pave26(dd13) - 
     Sub329*pave26(dd2) - Sub349*pave26(dd3) + 
     Sub275*pave27(dd1) + Sub228*pave27(dd2) + Sub242*pave27(dd3);

    

  Sub136 = 1/(CW2*MW2)*(CW2*Sub130 - 2*MW2*Sub135);

  Sub210 = 1/CW2*(18*Alfa*CW2*Pi*Sub207 - 
       Alfa2*(Finite*Sub209));

  Sub125 = 1/MW2*(Sub124 + MT2*MW2*(-12 + 8*SW2)*Sub4);

  Sub417 = Sub407 + SW2*(27*Sub402 - 27*MB2*Sub401);

  Sub387 = 1/(CW2*MW2*SW2)*
     (CW2*MW2*SW2*Sub210 + 
       Alfa2*MT*((F10 + F11)*(F12*Sub77 + F9*Sub78)*pave16(cc22)));

    

  Sub418 = MW2*SW2*Sub416 + 
     CW2*(9*Sub411 - 9*MT2*SW2*Sub408 - 2*CW2*MW2*Sub417);

  Sub394 = 1/(MW2*SW2)*
     (MT*((-F12 + F9)*Sub101*Sub57*pave12(cc12)) + 
       MW2*SW2*(Sub125*pave12(cc0) - Sub119*pave12(cc2)));

  Sub399 = 9*Sub393 + MW2*SW2*
      (18*Sub394 - 9*MT2*Sub398 - Sub157*pave16(cc0) + 
        Sub136*pave16(cc2));

  Sub423 = Sub421 + 6*Sub218*pave26(dd00) + 
     8*Sub215*pave27(dd00) - 2*(Sub422 + Sub317*pave27(dd33));

  Sub400 = 1/(MW2*SW2)*(2*MW2*SW2*Sub195 - Alfa2*Sub399);

  LOOP(Gen5, 1,3,1)

  Sub357(Gen5) = 1/CW2*(Sub6*Sub356(Gen5))/(-MZ2 + S) + 
     16*Sub3*Sub352(Gen5);

  ENDLOOP(Gen5)

}
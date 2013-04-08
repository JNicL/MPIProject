#if 0
* CalcRenConst.c
* renormalization constants
* generated by FormCalc 8.1 on 6-Apr-2013 23:50
#endif

#include "decl.h"
#include "inline.h"


void CalcRenConst() {

#include "decl.h"

  integer Gen3;

  ComplexType dup1, dup2, dup3, dup4, dup5;

#include "inline.h"

  dMWsq1 = Alfa/Pi*(1/SW2*
        (MW2*(-(1/6.*Finite) + 1/4.*Re(B0i(bb0,MW2,MH2,MW2)) + 
             CW2/2.*Re(B0i(bb1,MW2,MW2,MZ2))) + 3/8.*Re(A0(MW2)) + 
          1/16.*(12*CW2*Re(A0(MZ2)) + 
             (CW2*CW2*(-12*MW2 - 8*MZ2) + 4*MW2*(SW2*SW2))/CW2*
              Re(B0i(bb0,MW2,MW2,MZ2)) + Re(A0(MH2)) + Re(A0(MZ2)))
            + 1/4.*((-1 - 8*CW2)*Re(B0i(bb00,MW2,MW2,MZ2)) - 
             Re(B0i(bb00,MW2,MW2,MH2)))) + 
       MW2*(-(1/2.*Re(B0i(bb0,MW2,0.,MW2))) + 
          1/2.*Re(B0i(bb1,MW2,MW2,0.))) - 
       2*Re(B0i(bb00,MW2,MW2,0.)));

  LOOP(Gen3, 1,3,1)

  dMWsq1 = dMWsq1 + Alfa/(Pi*SW2)*
      (MW2*(-(1/4.*Re(B0i(bb1,MW2,0.,Mf2(2,Gen3)))) - 
           3/4.*Re(B0i(bb1,MW2,Mf2(3,Gen3),Mf2(4,Gen3)))) - 
        1/4.*Re(A0(Mf2(2,Gen3))) - 
        3/4.*(Re(A0(Mf2(4,Gen3))) + 
           Mf2(3,Gen3)*Re(B0i(bb0,MW2,Mf2(3,Gen3),Mf2(4,Gen3)))) + 
        1/2.*Re(B0i(bb00,MW2,0.,Mf2(2,Gen3))) + 
        3/2.*Re(B0i(bb00,MW2,Mf2(3,Gen3),Mf2(4,Gen3))));

  ENDLOOP(Gen3)

#ifdef DEBUG
  DEB("dMWsq1 =", dMWsq1);
#endif

  dMZsq1 = Alfa/(Pi*SW2)*
     (1/16.*((4*MW2)/(CW2*CW2)*Re(B0i(bb0,MZ2,MH2,MZ2)) + 
          (CW2*CW2*(-8*MW2 - 20*MZ2) + 8*MW2*(SW2*SW2))/CW2*
           Re(B0i(bb0,MZ2,MW2,MW2))) - 
       1/CW2*(1/16.*(-Re(A0(MH2)) - Re(A0(MZ2))) - 
          3/4.*Re(B0i(bb00,MZ2,0.,0.)) + 
          1/4.*Re(B0i(bb00,MZ2,MH2,MZ2))) - 
       (CW2*(9*CW2 - 2*SW2) + SW2*SW2)/CW2*
        (-(1/8.*Re(A0(MW2))) + 1/4.*Re(B0i(bb00,MZ2,MW2,MW2))) + 
       MZ2*(-(CW2/6.*Finite) - 
          3/(8.*CW2)*Re(B0i(bb1,MZ2,0.,0.))) - 
       (CW2*MZ2)/2.*Re(B0i(bb1,MZ2,MW2,MW2)));

  LOOP(Gen3, 1,3,1)

  dMZsq1 = dMZsq1 + Alfa/(CW2*Pi*SW2)*
      (1/24.*((-9 - SW2*(-24 + 32*SW2))*Re(A0(Mf2(3,Gen3))) + 
           (-9 - SW2*(-12 + 8*SW2))*Re(A0(Mf2(4,Gen3)))) + 
        (-1 - SW2*(-4 + 8*SW2))*
         (1/8.*Re(A0(Mf2(2,Gen3))) - 
           1/4.*Re(B0i(bb00,MZ2,Mf2(2,Gen3),Mf2(2,Gen3)))) + 
        1/12.*((9 + SW2*(-24 + 32*SW2))*
            Re(B0i(bb00,MZ2,Mf2(3,Gen3),Mf2(3,Gen3))) + 
           (9 + SW2*(-12 + 8*SW2))*
            Re(B0i(bb00,MZ2,Mf2(4,Gen3),Mf2(4,Gen3)))) + 
        MZ2*(1/24.*((-9 - SW2*(-24 + 32*SW2))*
               Re(B0i(bb1,MZ2,Mf2(3,Gen3),Mf2(3,Gen3))) + 
              (-9 - SW2*(-12 + 8*SW2))*
               Re(B0i(bb1,MZ2,Mf2(4,Gen3),Mf2(4,Gen3)))) + 
           (-1 - SW2*(-4 + 8*SW2))/8.*
            Re(B0i(bb1,MZ2,Mf2(2,Gen3),Mf2(2,Gen3)))) - 
        1/8.*(Mf2(2,Gen3)*Re(B0i(bb0,MZ2,Mf2(2,Gen3),
             Mf2(2,Gen3)))) - 
        3/8.*(Mf2(3,Gen3)*Re(B0i(bb0,MZ2,Mf2(3,Gen3),
              Mf2(3,Gen3))) + 
           Mf2(4,Gen3)*Re(B0i(bb0,MZ2,Mf2(4,Gen3),Mf2(4,Gen3)))));

    

  ENDLOOP(Gen3)

#ifdef DEBUG
  DEB("dMZsq1 =", dMZsq1);
#endif

  dSW1 = CW2/(2.*MW2*MZ2)*(-(MZ2*dMWsq1) + MW2*dMZsq1)/SW;

#ifdef DEBUG
  DEB("dSW1 =", dSW1);
#endif

  dZAA1 = -(Alfa/Pi*(-(1/6.*Finite) - 
         5/4.*Re(B0i(bb0,0.,MW2,MW2)) - 
         1/2.*Re(B0i(bb1,0.,MW2,MW2)) - 3*Re(B0i(dbb00,0.,MW2,MW2))
         ));

  LOOP(Gen3, 1,3,1)

  dZAA1 = dZAA1 - Alfa/Pi*
      (-(4/3.*Re(B0i(bb1,0.,Mf2(3,Gen3),Mf2(3,Gen3)))) - 
        1/3.*Re(B0i(bb1,0.,Mf2(4,Gen3),Mf2(4,Gen3))) + 
        8/3.*Re(B0i(dbb00,0.,Mf2(3,Gen3),Mf2(3,Gen3))) + 
        2/3.*Re(B0i(dbb00,0.,Mf2(4,Gen3),Mf2(4,Gen3))) - 
        Re(B0i(bb1,0.,Mf2(2,Gen3),Mf2(2,Gen3))) + 
        2*Re(B0i(dbb00,0.,Mf2(2,Gen3),Mf2(2,Gen3))));

  ENDLOOP(Gen3)

#ifdef DEBUG
  DEB("dZAA1 =", dZAA1);
#endif

  dZAZ1 = -((2*Alfa)/(MZ2*Pi)*
       ((CW*MZ2)/6.*Finite + 
          1/CW*((5*CW2 - SW2)*
              (-(1/4.*Re(A0(MW2))) + 
                1/2.*Re(B0i(bb00,MZ2,MW2,MW2))) + 
             (4*MW2 + 10*CW2*MZ2)/8.*Re(B0i(bb0,MZ2,MW2,MW2)) + 
             (CW2*MZ2)/2.*Re(B0i(bb1,MZ2,MW2,MW2))))/SW);

  LOOP(Gen3, 1,3,1)

  dZAZ1 = dZAZ1 - (2*Alfa)/(CW*MZ2*Pi)*
      ((-1 + 4*SW2)*(-(1/4.*Re(A0(Mf2(2,Gen3)))) + 
            1/2.*Re(B0i(bb00,MZ2,Mf2(2,Gen3),Mf2(2,Gen3)))) + 
         (-3 + 8*SW2)*(-(1/6.*Re(A0(Mf2(3,Gen3)))) + 
            1/3.*Re(B0i(bb00,MZ2,Mf2(3,Gen3),Mf2(3,Gen3)))) + 
         (-3 + 4*SW2)*(-(1/12.*Re(A0(Mf2(4,Gen3)))) + 
            1/6.*Re(B0i(bb00,MZ2,Mf2(4,Gen3),Mf2(4,Gen3)))) + 
         MZ2*((1 - 4*SW2)/4.*
             Re(B0i(bb1,MZ2,Mf2(2,Gen3),Mf2(2,Gen3))) + 
            (3 - 8*SW2)/6.*
             Re(B0i(bb1,MZ2,Mf2(3,Gen3),Mf2(3,Gen3))) + 
            (3 - 4*SW2)/12.*
             Re(B0i(bb1,MZ2,Mf2(4,Gen3),Mf2(4,Gen3)))))/SW;

  ENDLOOP(Gen3)

#ifdef DEBUG
  DEB("dZAZ1 =", dZAZ1);
#endif

  dZZA1 = (2*Alfa)/(CW*MZ2*Pi)*
     ((5*CW2 - SW2)*(-(1/4.*Re(A0(MW2))) + 
           1/2.*Re(B0i(bb00,0.,MW2,MW2))) + 
        MW2/2.*Re(B0i(bb0,0.,MW2,MW2)))/SW;

  LOOP(Gen3, 1,3,1)

  dZZA1 = dZZA1 + (2*Alfa)/(CW*MZ2*Pi)*
      ((-1 + 4*SW2)*(-(1/4.*Re(A0(Mf2(2,Gen3)))) + 
            1/2.*Re(B0i(bb00,0.,Mf2(2,Gen3),Mf2(2,Gen3)))) + 
         (-3 + 8*SW2)*(-(1/6.*Re(A0(Mf2(3,Gen3)))) + 
            1/3.*Re(B0i(bb00,0.,Mf2(3,Gen3),Mf2(3,Gen3)))) + 
         (-3 + 4*SW2)*(-(1/12.*Re(A0(Mf2(4,Gen3)))) + 
            1/6.*Re(B0i(bb00,0.,Mf2(4,Gen3),Mf2(4,Gen3)))))/SW;

  ENDLOOP(Gen3)

#ifdef DEBUG
  DEB("dZZA1 =", dZZA1);
#endif

  dZZZ1 = -(Alfa/(Pi*SW2)*
       (CW2*(-(1/6.*Finite) + 
            1/2.*(-(MZ2*Re(B0i(dbb1,MZ2,MW2,MW2))) - 
               Re(B0i(bb1,MZ2,MW2,MW2)))) + 
         1/16.*(-(20*CW2*Re(B0i(bb0,MZ2,MW2,MW2))) + 
            (4*MW2)/(CW2*CW2)*Re(B0i(dbb0,MZ2,MH2,MZ2)) + 
            (CW2*CW2*(-8*MW2 - 20*MZ2) + 8*MW2*(SW2*SW2))/CW2*
             Re(B0i(dbb0,MZ2,MW2,MW2))) + 
         1/CW2*(-(3/8.*(MZ2*Re(B0i(dbb1,MZ2,0.,0.)) + 
                 Re(B0i(bb1,MZ2,0.,0.)))) + 
            3/4.*Re(B0i(dbb00,MZ2,0.,0.)) + 
            1/4.*((-(CW2*(9*CW2 - 2*SW2)) - SW2*SW2)*
                Re(B0i(dbb00,MZ2,MW2,MW2)) - 
               Re(B0i(dbb00,MZ2,MH2,MZ2))))));

  LOOP(Gen3, 1,3,1)

  dZZZ1 = dZZZ1 - Alfa/(CW2*Pi*SW2)*
      (1/24.*((-9 - SW2*(-24 + 32*SW2))*
            Re(B0i(bb1,MZ2,Mf2(3,Gen3),Mf2(3,Gen3))) + 
           (-9 - SW2*(-12 + 8*SW2))*
            Re(B0i(bb1,MZ2,Mf2(4,Gen3),Mf2(4,Gen3)))) + 
        1/12.*((9 + SW2*(-24 + 32*SW2))*
            Re(B0i(dbb00,MZ2,Mf2(3,Gen3),Mf2(3,Gen3))) + 
           (9 + SW2*(-12 + 8*SW2))*
            Re(B0i(dbb00,MZ2,Mf2(4,Gen3),Mf2(4,Gen3)))) + 
        MZ2*(1/24.*((-9 - SW2*(-24 + 32*SW2))*
               Re(B0i(dbb1,MZ2,Mf2(3,Gen3),Mf2(3,Gen3))) + 
              (-9 - SW2*(-12 + 8*SW2))*
               Re(B0i(dbb1,MZ2,Mf2(4,Gen3),Mf2(4,Gen3)))) + 
           (-1 - SW2*(-4 + 8*SW2))/8.*
            Re(B0i(dbb1,MZ2,Mf2(2,Gen3),Mf2(2,Gen3)))) + 
        1/8.*((-1 - SW2*(-4 + 8*SW2))*
            Re(B0i(bb1,MZ2,Mf2(2,Gen3),Mf2(2,Gen3))) - 
           Mf2(2,Gen3)*Re(B0i(dbb0,MZ2,Mf2(2,Gen3),Mf2(2,Gen3))))-
          3/8.*(Mf2(3,Gen3)*
            Re(B0i(dbb0,MZ2,Mf2(3,Gen3),Mf2(3,Gen3))) + 
           Mf2(4,Gen3)*Re(B0i(dbb0,MZ2,Mf2(4,Gen3),Mf2(4,Gen3))))+
          (1 + SW2*(-4 + 8*SW2))/4.*
         Re(B0i(dbb00,MZ2,Mf2(2,Gen3),Mf2(2,Gen3))));

  ENDLOOP(Gen3)

#ifdef DEBUG
  DEB("dZZZ1 =", dZZZ1);
#endif

  dup1 = 1/(2.*CW2)*(-2*
        (CW2*Re(B0i(dbb0,ME2,0.,ME2)) + 
          SW2*Re(B0i(dbb0,ME2,ME2,MZ2))) + 
       Re(B0i(dbb0,ME2,ME2,MZ2)));

  dup2 = (Alfa*ME)/Pi*(1/SW2*
        (-(1/4.*Re(B0i(dbb1,ME2,0.,MW2))) - 
          (1 + SW2*(-4 + 8*SW2))/(8.*CW2)*Re(B0i(dbb1,ME2,ME2,MZ2))
          ) - Re(B0i(dbb1,ME2,ME2,0.)));

  dZfL1(2,1,1) = -((2*Alfa*ME2)/Pi*dup1) - ME*dup2 - 
     Alfa/Pi*(1/SW2*(1/CW2*
            ((-1 - SW2*(-4 + 4*SW2) - CW2*(2 + 4*SW2))/16.*
               Finite - Power(1 - 2*SW2,2)/8.*
               Re(B0i(bb1,ME2,ME2,MZ2))) - 
           1/4.*Re(B0i(bb1,ME2,0.,MW2))) - 
        1/2.*Re(B0i(bb1,ME2,ME2,0.)));

#ifdef DEBUG
  DEB("dZfL1(2,1,1) =", dZfL1(2,1,1));
#endif

  dup3 = -(MB2/8.*Re(B0i(dbb0,MT2,MB2,MW2))) + 
     MT2/16.*Re(B0i(dbb0,MT2,MH2,MT2));

  dup4 = 1/(MW2*SW2)*(dup3 + 
        (-9*CW2*MT2 + MW2*(48 - 64*SW2)*SW2)/(144.*CW2)*
         Re(B0i(dbb0,MT2,MT2,MZ2))) - 4/9.*Re(B0i(dbb0,MT2,0.,MT2))
    ;

  dup5 = (Alfa*MT)/Pi*(1/8.*
        (-((MB2 + MT2 + 2*MW2)/(MW2*SW2)*
             Re(B0i(dbb1,MT2,MB2,MW2))) - 
          MT2/(MW2*SW2)*Re(B0i(dbb1,MT2,MT2,MH2))) - 
       4/9.*Re(B0i(dbb1,MT2,MT2,0.)) - 
       (9*CW2*MT2 + MW2*(9 + SW2*(-24 + 32*SW2)))/
         (72.*CW2*MW2*SW2)*Re(B0i(dbb1,MT2,MT2,MZ2)));

  dZfL1(3,3,3) = -((2*Alfa*MT2)/Pi*dup4) - MT*dup5 - 
     Alfa/Pi*(1/SW2*(1/MW2*
            (-(MB2/8.*Re(B0i(bb1,MT2,MB2,MW2))) - 
              MW2/4.*Re(B0i(bb1,MT2,MB2,MW2)) - 
              MT2/16.*Re(B0i(bb1,MT2,MT2,MH2))) + 
           1/144.*(-((9 + SW2*(-24 + 16*SW2) + CW2*(18 + 16*SW2))/
                  CW2*Finite) - 
              (9*CW2*MT2 + 2*MW2*Power(3 - 4*SW2,2))/(CW2*MW2)*
               Re(B0i(bb1,MT2,MT2,MZ2)))) - 
        2/9.*Re(B0i(bb1,MT2,MT2,0.)));

#ifdef DEBUG
  DEB("dZfL1(3,3,3) =", dZfL1(3,3,3));
#endif

  dZfR1(2,1,1) = -((2*Alfa*ME2)/Pi*dup1) - ME*dup2 - 
     Alfa/Pi*(1/CW2*(-(1/4.*Finite) - 
           SW2/2.*Re(B0i(bb1,ME2,ME2,MZ2))) - 
        1/2.*Re(B0i(bb1,ME2,ME2,0.)));

#ifdef DEBUG
  DEB("dZfR1(2,1,1) =", dZfR1(2,1,1));
#endif

  dZfR1(3,3,3) = -((2*Alfa*MT2)/Pi*dup4) - MT*dup5 - 
     Alfa/Pi*(MT2/(MW2*SW2)*
         (-(1/8.*Re(B0i(bb1,MT2,MB2,MW2))) - 
           1/16.*Re(B0i(bb1,MT2,MT2,MH2))) + 
        1/CW2*(-(1/9.*Finite) - 
           (9*CW2*MT2 + 32*MW2*(SW2*SW2))/(144.*MW2*SW2)*
            Re(B0i(bb1,MT2,MT2,MZ2))) - 
        2/9.*Re(B0i(bb1,MT2,MT2,0.)));

#ifdef DEBUG
  DEB("dZfR1(3,3,3) =", dZfR1(3,3,3));
#endif

  dZe1 = 1/(2.*CW)*(-(dZZA1*SW) - CW*dZAA1);

#ifdef DEBUG
  DEB("dZe1 =", dZe1);
#endif

}

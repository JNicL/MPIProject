#include "vars.h"
#include "inline.h"


void abbr0h() {

#include "vars.h"

#include "inline.h"


  F32 = ChainV2(Spinor(1,2),0,ec(5),k(3),1,Spinor(4,2));

  F34 = -1*(ChainB2(Spinor(1,2),0,ec(5),k(4),0,Spinor(3,1)));

  F9 = -1*(ChainV0(Spinor(4,2),0,0,Spinor(3,1)));

  F13 = ChainB0(Spinor(4,2),0,0,Spinor(2,1));

  F12 = ChainB0(Spinor(4,2),0,0,Spinor(3,1));

  F35 = ChainV1(Spinor(1,2),0,ec(5),0,Spinor(3,1));

  F3 = ChainV1(Spinor(1,2),0,ec(5),1,Spinor(4,2));

  F33 = ChainB1(Spinor(1,2),0,ec(5),0,Spinor(3,1));

  F6 = -1*(ChainB1(Spinor(1,2),0,ec(5),1,Spinor(4,2)));

  F30 = -1*(ChainB1(Spinor(1,2),0,k(3),0,Spinor(2,1)));

  F8 = ChainV1(Spinor(4,2),0,ec(5),0,Spinor(2,1));

  F17 = ChainV1(Spinor(4,2),0,k(2),0,Spinor(3,1));

  F4 = ChainB1(Spinor(4,2),0,ec(5),0,Spinor(2,1));

  F22 = -1*(ChainB1(Spinor(4,2),0,k(1),0,Spinor(3,1)));

  F18 = -1*(ChainB1(Spinor(4,2),0,k(2),0,Spinor(3,1)));

  F27 = ChainV2(Spinor(1,2),0,ec(5),k(2),1,Spinor(4,2));

  F36 = -1*(ChainV2(Spinor(1,2),0,ec(5),k(4),0,Spinor(3,1)));

  F28 = -1*(ChainB2(Spinor(1,2),0,ec(5),k(2),1,Spinor(4,2)));

  F31 = -1*(ChainB2(Spinor(1,2),0,ec(5),k(3),1,Spinor(4,2)));

  F23 = ChainV2(Spinor(4,2),0,ec(5),k(1),0,Spinor(2,1));

  F7 = -1*(ChainV0(Spinor(1,2),0,0,Spinor(3,1)));

  F15 = ChainV0(Spinor(1,2),0,1,Spinor(4,2));

  F1 = -1*(ChainB0(Spinor(1,2),0,0,Spinor(3,1)));

  F25 = -1*(ChainB0(Spinor(1,2),0,1,Spinor(4,2)));

  F5 = -1*(ChainV0(Spinor(2,1),1,0,Spinor(3,1)));

  F2 = ChainB0(Spinor(2,1),1,0,Spinor(3,1));

  F24 = ChainV0(Spinor(4,2),0,0,Spinor(2,1));

  F10 = ChainV1(Spinor(1,2),0,ec(5),0,Spinor(2,1));

  F29 = ChainV1(Spinor(1,2),0,k(3),0,Spinor(2,1));

  F19 = ChainV1(Spinor(1,2),0,k(4),0,Spinor(2,1));

  F11 = -1*(ChainB1(Spinor(1,2),0,ec(5),0,Spinor(2,1)));

  F26 = -1*(ChainB1(Spinor(1,2),0,k(4),0,Spinor(2,1)));

  F20 = ChainV1(Spinor(4,2),0,ec(5),0,Spinor(3,1));

  F16 = ChainV1(Spinor(4,2),0,k(1),0,Spinor(3,1));

  F21 = -1*(ChainB1(Spinor(4,2),0,ec(5),0,Spinor(3,1)));

  F14 = ChainB2(Spinor(4,2),0,ec(5),k(1),0,Spinor(2,1));

  Pair1 = Pair(ec(5),k(1));

  Pair2 = Pair(ec(5),k(2));

  Sub436 = cmult(F10,F16+F17)+cmult(F2,-F27-cmult(2*(F15),Pair1));

  Sub3721 = -1*(cmult(F11,F16+F17))+cmult(F1,-F23+cmult(2*(F24),Pair1+Pair2));

  Sub18 = cmult(F2,F3)+cmult(F10,-F12+F9);

  Sub437 = cmult(F11,F18+F22)+cmult(F5,-F28-cmult(2*(F25),Pair1));

  Sub1408 = cmult(F10,F18+F22)-cmult(F7,-F14+cmult(2*(F13),Pair1+Pair2));

  Sub14 = cmult(F24,F33)+cmult(F11,F12-F9);

  Sub32 = cmult(F19,F20)+Sub436;

  Sub29 = -1*(cmult(F20,F26))+Sub3721;

  Sub4 = cmult(F10,F17)+cmult(F2,-F32-MT*F3);

  Sub3 = cmult(F11,F17)+cmult(F24,-F34+MT*(F33));

  Sub22 = (1/(SW2))*((2*(SW2))*(Sub14)+(1-2*(SW2))*(Sub18));

  Sub35 = (1/(SW2))*((2*(SW2))*(Sub29)+(1-2*(SW2))*(Sub32));

  Sub31 = -1*(cmult(F7,F8))+Sub18;

  Sub28 = cmult(F1,F4)-cmult(F5,F6)+cmult(F11,-F12+F9);

  Sub33 = cmult(F21,F26)+Sub437;

  Sub2949 = cmult(F1,F23)+cmult(F2,-F27+cmult(2*(F15),Pair2));

  Sub9 = -1*(cmult(F20,F29))+cmult(F2,-F27+cmult(2*(F15),Pair2));

  Sub15 = cmult(F11,F16)+cmult(F20,F26+F30)-cmult(F24,-F34+cmult(2*F1,Pair1+Pair2));

  Sub30 = cmult(F19,F21)+Sub1408;

  Sub9998 = cmult(F2,F32)+cmult(F24,F34)+cmult(F13,F36)+cmult(F31,F5);

  Sub19 = cmult(F10,F16)+cmult(F20,F19+F29)+cmult(F2,F32-cmult(2*(F15),Pair1+Pair2));

  Opt25 = -1*(cmult(F21,F29))+cmult(F20,-F29-F30)-cmult(F21,F30);

  Sub20 = cmult(F5,F6)+cmult(F11,F12-F9);

  Sub16 = cmult(F13,F35)+cmult(F10,-F12+F9);

  Sub6 = cmult(F10,F18)+cmult(F13,-F36+MT*(F35));

  Sub8561 = cmult(F20,F26)-cmult(cmult(2*F1,F24),Pair1+Pair2);

  Sub14151 = cmult(F11,F22)-cmult(cmult(2*(F25),F5),Pair1+Pair2);

  Sub14146 = cmult(F10,F22)-cmult(cmult(2*(F13),F7),Pair1+Pair2);

  Sub11 = (1/(SW2))*((1-2*(SW2))*(cmult(F2,F3))+(SW2)*(cmult(-2*F1,F4)+cmult(2*F5,F6))+(-1+2*(SW2))*(cmult(F7,F8)));

  Sub34 = (1/(SW2))*((2*(SW2))*(Sub28)+(-1+2*(SW2))*(Sub31));

  Sub5 = (1/(SW2))*((2*(SW2))*(Sub3)+(-1+2*(SW2))*(Sub4));

  Sub12 = (1/(SW2))*((SW2)*(cmult(-2*F1,F23)+cmult(2*(F20),F30))+(1-2*(SW2))*(Sub9));

  Sub1070 = cmult(F11,F16+F17+F18+F22)+cmult(F1,F23)-cmult(F28,F5);

  Sub917 = cmult(F10,F16+F17+F18+F22)-cmult(F2,F27)+cmult(F14,F7);

  Sub7 = -1*(cmult(F11,F18))+cmult(F5,F31+MT*F6);

  Sub10 = cmult(F21,F30)+cmult(F5,F28-cmult(2*(F25),Pair2));

  Sub8567 = -1*(cmult(F19,F21))+cmult(cmult(2*(F13),F7),Pair1+Pair2);

  Sub21 = cmult(F11,F22)+cmult(F21,F26+F30)-cmult(F5,-F31+cmult(2*(F25),Pair1+Pair2));

  Sub23 = (1/(SW2))*((-1+2*(SW2))*(Sub19)+(SW2)*(2*(Sub15)-MT*(Sub22)));

  Sub753 = (-1*4+8*(SW2))*(Sub30)+(8*(SW2))*(Sub33)+(3-4*(SW2))*(Sub35);

  Sub14061 = -1*(cmult(F2,F3))+cmult(F24,F33)+cmult(F13,F35)-cmult(F5,F6);

  Sub612 = cmult(F10+F11,F17+F18)-Sub9998;

  Sub566 = cmult(F20,-F29-F30)+Sub2949;

  Sub569 = -1*(cmult(F21,F29))+cmult(F14,F7)-Sub10;

  Sub17 = cmult(F21,F19+F29)+cmult(F13,F36)+Sub14146;

  Sub14237 = Sub9998-MT*(Sub14061);

  Sub24 = (4-8*(SW2))*(Sub17)-(8*(SW2))*(Sub21)+(3-4*(SW2))*(Sub23)+MT*((-4+8*(SW2))*(Sub16)-(8*(SW2))*(Sub20));

  Sub8 = (3-4*(SW2))*(Sub5)+(4-8*(SW2))*(Sub6)+(8*(SW2))*(Sub7);

  Sub13 = (4-8*(SW2))*(cmult(F21,F29))+(-4+8*(SW2))*(cmult(F14,F7))-(8*(SW2))*(Sub10)+(3*MT)*(Sub11)+(3-4*(SW2))*(Sub12);

  Sub36 = -1*(Sub753)+(3*MT)*(Sub34);

  Sub26 = Sub612+MT*(Sub14061);

  Sub2 = Sub566+Sub569;

  Sub1 = cmult(F21,F26)+cmult(F20,F19+F26)-2*(cmult(cmult(F15,F2)+cmult(F1,F24)+cmult(F25,F5),Pair1)+cmult(cmult(F1,F24),Pair2))+Sub1070-Sub8567+Sub917;

  Sub27 = cmult(F10+F11,F16)+cmult(F19,F20+F21)+cmult(F21,F26)-Opt25-cmult(cmult(2*(F15),F2),Pair1+Pair2)+Sub14146+Sub14151+Sub14237+Sub8561;

  Sub14662 = (Sub13)/(-MZ2+S)+(8*(CW2))*((Sub2)/S);

  Sub14664 = (8*(Sub1))/S-(1/(CW2))*((Sub36)/(-MZ2+S));

  Sub14666 = (8*(Sub27))/(S34)-(1/(CW2))*((Sub24)/(-MZ2+S34));

  Sub14660 = (8*(Sub26))/(S34)-(1/(CW2))*((Sub8)/(-MZ2+S34));
}

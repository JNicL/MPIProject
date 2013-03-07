/** inline.h*/
/** inline versions of the util functions*/
/** this file is part of FormCalc*/
/** last modified 16 Nov 12 th*/


/*RealType SInvariant, TInvariant;*/
/*ComplexType Pair, Eps_, Eps;*/
	/*ComplexType SxS;*/
/*ComplexType SxV1, SxV2, SxB1, SxB2;*/
/*ComplexType VxS1, VxS2, BxS1, BxS2;*/
/*ComplexType SxVxB1, SxVxB2, SxBxV1, SxBxV2;*/
/*ComplexType BxVxS1, BxVxS2, VxBxS1, VxBxS2;*/
/*ComplexType SxVxBxV1, SxVxBxV2, SxBxVxB1, SxBxVxB2;*/
/*ComplexType VxBxVxS1, VxBxVxS2, BxVxBxS1, BxVxBxS2;*/
/*ComplexType ChainB0;*/
/*ComplexType ChainV1, ChainB1;*/
/*ComplexType ChainV2, ChainB2;*/
/*ComplexType ChainV3, ChainB3;*/
/*ComplexType ChainV4, ChainB4;*/
/*ComplexType ChainV5, ChainB5;*/
/*ComplexType ChainV6, ChainB6;*/
/*integer IndexEps_, IndexEps;*/
/*RealType ThreeMom_, ThreeMom;*/

/*ComplexType l1_, l2_, r1_, r2_;*/
/*integer a_, b_, c_, d_, e_, f_;*/
/*integer iL_, iR_, eL_, eR_;*/
/*RealType sqrtS_, ma_, mb_;*/

	ComplexType SInvariant(integer  a_,integer b_) {
	  return
	(Re(vec(1,1,a_)) + Re(vec(1,1,b_)))*
	(Re(vec(2,2,a_)) + Re(vec(2,2,b_))) -
	Sq(vec(1,2,a_) + vec(1,2,b_));
	}

 ComplexType TInvariant(integer a_,integer b_){
  return
    (Re(vec(1,1,a_)) - Re(vec(1,1,b_)))*
    (Re(vec(2,2,a_)) - Re(vec(2,2,b_))) -
    Sq(vec(1,2,a_) - vec(1,2,b_));
}

 ComplexType Pair(integer a_,integer b_){
  return .5E0*(
      vec(1,1,a_)*vec(2,2,b_) + vec(2,2,a_)*vec(1,1,b_) -
      vec(1,2,a_)*vec(2,1,b_) - vec(2,1,a_)*vec(1,2,b_) );
}


/*Eps_(integer a_,integer b_,integer c_,integer d_){*/
/*return*/
/*(vec(1,1,a_)*vec(2,2,b_) - vec(2,2,a_)*vec(1,1,b_))**/
/*(vec(2,1,c_)*vec(1,2,d_) - vec(1,2,c_)*vec(2,1,d_));*/
/*}*/
	/*Eps(a_, b_, c_, d_) = .25D0*(*/
	/*&    Eps_(a_, b_, c_, d_) + Eps_(c_, d_, a_, b_) -*/
	/*&    Eps_(a_, c_, b_, d_) - Eps_(b_, d_, a_, c_) +*/
	/*&    Eps_(a_, d_, b_, c_) + Eps_(b_, c_, a_, d_) )*/

	ComplexType SxS(ComplexType l1_,ComplexType l2_, ComplexType r1_,ComplexType r2_) {return l1_*r1_ + l2_*r2_;}

	ComplexType SxV1(ComplexType l1_,ComplexType l2_, integer a_){ return l1_*vec(1,1,a_) + l2_*vec(2,1,a_);}

	ComplexType SxV2(ComplexType l1_,ComplexType l2_, integer a_){ l2_*vec(2,2,a_) + l1_*vec(1,2,a_);}

	ComplexType SxB1(ComplexType l1_,ComplexType l2_,integer a_){ return l1_*vec(2,2,a_) - l2_*vec(2,1,a_);}

	ComplexType SxB2(ComplexType l1_,ComplexType l2_, integer a_){ return l2_*vec(1,1,a_) - l1_*vec(1,2,a_);}

	ComplexType VxS1(integer a_, ComplexType r1_,ComplexType r2_){ return vec(1,1,a_)*r1_ + vec(1,2,a_)*r2_;}

	ComplexType VxS2(integer a_, ComplexType r1_,ComplexType r2_){ return vec(2,1,a_)*r1_ + vec(2,2,a_)*r2_;}

	ComplexType BxS1(integer a_, ComplexType r1_,ComplexType r2_){ return vec(2,2,a_)*r1_ - vec(1,2,a_)*r2_;}

	ComplexType BxS2(integer a_, ComplexType r1_,ComplexType r2_){ return vec(1,1,a_)*r2_ - vec(2,1,a_)*r1_;}


  ComplexType SxVxB1(ComplexType l1_,ComplexType l2_, integer a_, integer b_){
    return SxB1(SxV1(l1_,l2_, a_),SxV2(l1_,l2_, a_), b_);
  }

 ComplexType SxVxB2(ComplexType l1_,ComplexType l2_, integer a_, integer b_){
    return SxB2(SxV1(l1_,l2_, a_),SxV2(l1_,l2_, a_), b_);
  }

ComplexType  SxBxV1(ComplexType l1_,ComplexType l2_, integer a_, integer b_){
    return SxV1(SxB1(l1_,l2_, a_),SxB2(l1_,l2_, a_), b_);
  }

  ComplexType SxBxV2(ComplexType l1_,ComplexType l2_, integer a_, integer b_){
    return SxV2(SxB1(l1_,l2_, a_),SxB2(l1_,l2_, a_), b_);
  }

  ComplexType BxVxS1(integer b_, integer a_, ComplexType r1_,ComplexType r2_){
    return
    BxS1(b_, VxS1(a_, r1_,r2_),VxS2(a_, r1_,r2_));
  }

 ComplexType BxVxS2(integer b_, integer a_, ComplexType r1_,ComplexType r2_){
    return
    BxS2(b_, VxS1(a_, r1_,r2_),VxS2(a_, r1_,r2_));
  }

 ComplexType VxBxS1(integer b_, integer a_, integer r1_,integer r2_){
    return
    VxS1(b_, BxS1(a_, r1_,r2_),BxS2(a_, r1_,r2_));
  }

ComplexType  VxBxS2(integer b_, integer a_, integer r1_,integer r2_){
    return
    VxS2(b_, BxS1(a_, r1_,r2_),BxS2(a_, r1_,r2_));
  }

 ComplexType SxVxBxV1(ComplexType l1_,ComplexType l2_, integer a_, integer b_,integer c_){
    return
    SxBxV1(SxV1(l1_,l2_, a_),SxV2(l1_,l2_, a_), b_, c_);
  }

 ComplexType SxVxBxV2(ComplexType l1_,ComplexType l2_, integer a_, integer b_,integer c_){
    return
    SxBxV2(SxV1(l1_,l2_, a_),SxV2(l1_,l2_, a_), b_, c_);
  }

 ComplexType SxBxVxB1(ComplexType l1_,ComplexType l2_, integer a_, integer b_, integer c_){
    return
    SxVxB1(SxB1(l1_,l2_, a_),SxB2(l1_,l2_, a_), b_, c_);
  }

 ComplexType SxBxVxB2(ComplexType l1_,ComplexType l2_, integer a_, integer b_, integer c_){
    return
    SxVxB2(SxB1(l1_,l2_, a_),SxB2(l1_,l2_, a_), b_, c_);
  }

  ComplexType VxBxVxS1(integer c_, integer b_, integer a_, ComplexType r1_,ComplexType r2_){
    return
    VxBxS1(c_, b_, VxS1(a_, r1_,r2_),VxS2(a_, r1_,r2_));
  }

 ComplexType VxBxVxS2(integer c_, integer b_, integer a_, ComplexType r1_,ComplexType r2_){
    return
    VxBxS2(c_, b_, VxS1(a_, r1_,r2_),VxS2(a_, r1_,r2_));
  }

 ComplexType BxVxBxS1(integer c_,integer b_,integer a_,ComplexType r1_,ComplexType r2_){
    return
    BxVxS1(c_, b_, BxS1(a_, r1_,r2_),BxS2(a_, r1_,r2_));
  }

 ComplexType BxVxBxS2(integer c_, integer b_, integer a_, integer r1_,integer r2_){
    return
    BxVxS2(c_, b_, BxS1(a_, r1_,r2_),BxS2(a_, r1_,r2_));
  }
#ifndef SpiLV
#define SpiLV(iL,eL) (1-2*eL)*vec(1+eL,1+eL,iL), vec(2-eL,1+eL,iL)
#define SpiLB(iL,eL) (1-2*eL)*vec(1+eL,2-eL,iL), vec(2-eL,2-eL,iL)

#define SpiRV(eR,iR) vec(1+eR,1+eR,iR), (1-2*eR)*vec(2-eR,1+eR,iR)

#define SpiRB(eR,iR) vec(1+eR,2-eR,iR), (1-2*eR)*vec(2-eR,2-eR,iR)
#endif

	ComplexType ChainV0(integer iL_,integer eL_, integer eR_,integer iR_) {
	 return  SxS(SpiLB(iL_,eL_),SpiRV(eR_,iR_) );
	}

 ComplexType ChainB0(integer iL_,integer eL_, integer eR_,integer iR_){
   return SxS(
          SpiLV(iL_,eL_),
          SpiRB(eR_,iR_) );
 }

 ComplexType ChainV1(integer iL_,integer eL_, integer a_, integer eR_,integer iR_){
   return SxS(
          SxV1(SpiLB(iL_,eL_), a_),
          SxV2(SpiLB(iL_,eL_), a_),
          SpiRB(eR_,iR_) );
  }

ComplexType ChainB1(integer iL_,integer eL_, integer a_, integer eR_,integer iR_){
 return SxS(
        SxB1(SpiLV(iL_,eL_), a_),
        SxB2(SpiLV(iL_,eL_), a_),
        SpiRV(eR_,iR_) );
}

 ComplexType ChainV2(integer iL_,integer eL_, integer a_, integer b_, integer eR_,integer iR_){
   return SxS(
          SxV1(SpiLB(iL_,eL_), a_),
          SxV2(SpiLB(iL_,eL_), a_),
          BxS1(b_, SpiRV(eR_,iR_)),
          BxS2(b_, SpiRV(eR_,iR_)) );
  }

 ComplexType ChainB2(integer iL_,integer eL_, integer a_, integer b_, integer eR_,integer iR_){
   return SxS(
          SxB1(SpiLV(iL_,eL_), a_),
          SxB2(SpiLV(iL_,eL_), a_),
          VxS1(b_, SpiRB(eR_,iR_)),
          VxS2(b_, SpiRB(eR_,iR_)) );
  }

 ComplexType ChainV3(integer iL_,integer eL_, integer a_, integer b_, integer c_, integer eR_,integer iR_){
   return SxS(
          SxVxB1(SpiLB(iL_,eL_), a_, b_),
          SxVxB2(SpiLB(iL_,eL_), a_, b_),
          VxS1(c_, SpiRB(eR_,iR_)),
          VxS2(c_, SpiRB(eR_,iR_)) );
  }

 ComplexType ChainB3(integer iL_,integer eL_, integer a_, integer b_, integer c_, integer eR_,integer iR_){
   return SxS(
          SxBxV1(SpiLV(iL_,eL_), a_, b_),
          SxBxV2(SpiLV(iL_,eL_), a_, b_),
          BxS1(c_, SpiRV(eR_,iR_)),
          BxS2(c_, SpiRV(eR_,iR_)) );
  }

 ComplexType ChainV4(integer iL_,integer eL_, integer a_, integer b_, integer c_, integer d_, integer eR_,integer iR_){
   return SxS(
          SxVxB1(SpiLB(iL_,eL_), a_, b_),
          SxVxB2(SpiLB(iL_,eL_), a_, b_),
          VxBxS1(c_, d_, SpiRV(eR_,iR_)),
          VxBxS2(c_, d_, SpiRV(eR_,iR_)) );
  }

 ComplexType ChainB4(integer iL_,integer eL_, integer a_, integer b_, integer c_, integer d_, integer eR_,integer iR_){
   return SxS(
          SxBxV1(SpiLV(iL_,eL_), a_, b_),
          SxBxV2(SpiLV(iL_,eL_), a_, b_),
          BxVxS1(c_, d_, SpiRB(eR_,iR_)),
          BxVxS2(c_, d_, SpiRB(eR_,iR_)) );
  }

 ComplexType ChainV5(integer iL_,integer eL_, integer a_, integer b_, integer c_, integer d_, integer e_, integer eR_,integer iR_){
   return SxS(
          SxVxBxV1(SpiLB(iL_,eL_), a_, b_, c_),
          SxVxBxV2(SpiLB(iL_,eL_), a_, b_, c_),
          BxVxS1(d_, e_, SpiRB(eR_,iR_)),
          BxVxS2(d_, e_, SpiRB(eR_,iR_)) );
  }

 ComplexType ChainB5(integer iL_,integer eL_, integer a_, integer b_, integer c_, integer d_, integer e_, integer eR_,integer iR_){
   return SxS(
          SxBxVxB1(SpiLV(iL_,eL_), a_, b_, c_),
          SxBxVxB2(SpiLV(iL_,eL_), a_, b_, c_),
          VxBxS1(d_, e_, SpiRV(eR_,iR_)),
          VxBxS2(d_, e_, SpiRV(eR_,iR_)) );
  }

 ComplexType ChainV6(integer iL_,integer eL_, integer a_, integer b_, integer c_, integer d_, integer e_, integer f_, integer eR_,integer iR_){
   return SxS(
          SxVxBxV1(SpiLB(iL_,eL_), a_, b_, c_),
          SxVxBxV2(SpiLB(iL_,eL_), a_, b_, c_),
          BxVxBxS1(d_, e_, f_, SpiRV(eR_,iR_)),
          BxVxBxS2(d_, e_, f_, SpiRV(eR_,iR_)) );
  }

 ComplexType ChainB6(integer iL_,integer eL_, integer a_, integer b_, integer c_, integer d_, integer e_, integer f_, integer eR_,integer iR_){
   return SxS(
          SxBxVxB1(SpiLV(iL_,eL_), a_, b_, c_),
          SxBxVxB2(SpiLV(iL_,eL_), a_, b_, c_),
          VxBxVxS1(d_, e_, f_, SpiRB(eR_,iR_)),
          VxBxVxS2(d_, e_, f_, SpiRB(eR_,iR_)) );
  }

	ComplexType IndexEps_(integer a_){ return 2*signbit(a_) - signbit(ior(a_, -a_));}

 ComplexType IndexEps(integer a_, integer b_, integer c_){
    return
    IndexEps_(b_ - a_)*IndexEps_(b_ - c_)*IndexEps_(c_ - a_);
  }
	RealType ThreeMom_(RealType ma_,RealType mb_){ return (ma_ - mb_)*(ma_ + mb_);}
		RealType ThreeMom(RealType sqrtS_,RealType ma_,RealType mb_){ return sqrt(ThreeMom_(.5E0*(sqrtS_ - ThreeMom_(ma_, mb_)/sqrtS_), mb_ ));}


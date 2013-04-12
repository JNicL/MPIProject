#if 0
	inline.h
	inline versions of the util functions
	this file is part of FormCalc
	last modified 11 Apr 13 th
#endif

#ifndef INLINE_H
#define INLINE_H

#define HelFun static inline HelType
#define SpiType(s1,s2) cHelType s1, cHelType s2
#define SpiSpec(i,e) cint i, cint e
#define SpiLV(i,e) (1-2*e)*Vec(1+e,1+e,i), Vec(2-e,1+e,i)
#define SpiLB(i,e) (1-2*e)*Vec(1+e,2-e,i), Vec(2-e,2-e,i)
#define SpiRV(e,i) Vec(1+e,1+e,i), (1-2*e)*Vec(2-e,1+e,i)
#define SpiRB(e,i) Vec(1+e,2-e,i), (1-2*e)*Vec(2-e,2-e,i)

#define NSSE 2

#if NSSE>1
#ifdef __AVX__
#define cmult(a,b) cmultAVX(a,b)
#define cdiv(a,b) cdivAVX(a,b)
#else
#ifdef __SSE__
#define cmult(a,b) cmultnaive(a,b)
#else
#define cmult(a,b) cmultnaive(a,b)
#endif
#endif
#else
#ifdef __SSE__
#define cmult(a,b) cmultnaive(a,b)
#else
#define cmult(a,b) cmultnaive(a,b)
#endif
#endif


#ifdef __AVX__
inline void cmultIntrinsicAVX(__m256d *a, __m256d *b,__m256d *c){
	__m256d tmp1 = _mm256_movedup_pd(*b);
	__m256d tmp2 = _mm256_shuffle_pd(*b,*b,0xF);
	tmp1 =_mm256_mul_pd(*a,tmp1);
	tmp2 =_mm256_mul_pd(*a,tmp2);
	tmp2 = _mm256_shuffle_pd(tmp2,tmp2,0x5);
	*c = _mm256_addsub_pd(tmp1,tmp2);
}
inline void  cdivIntrinsicAVX(__m256d *a,__m256d *b,__m256d *c){
	__m256d normb = _mm256_mul_pd(*b,*b);
	__m256d tmp =  normb;
	tmp = _mm256_shuffle_pd(tmp,tmp, 0x5);
	normb = _mm256_add_pd(normb,tmp);
	tmp =_mm256_movedup_pd(*b);
	__m256d tmp2 = _mm256_shuffle_pd(*b,*b, 0xF);
	tmp = _mm256_mul_pd(tmp,*a);
	tmp2 = _mm256_mul_pd(tmp2,*a); 
	tmp = _mm256_shuffle_pd(tmp,tmp, 0x5);
	tmp = _mm256_addsub_pd(tmp,tmp2);
	tmp = _mm256_shuffle_pd(tmp,tmp, 0x5);
	*c = _mm256_div_pd(tmp,normb);
}

inline vectortype cmultAVX(vectortype a,vectortype b){
	vectortype ret;
	int i;
	for(i=0; i<nsse/2; i++){
		cmultIntrinsicAVX(((__m256d *)&a+i),((__m256d *)&b+i),((__m256d *)&ret+i));
	}
	return ret;
}
inline vectortype cdivAVX(vectortype a,vectortype b){
	vectortype ret;
	int i;
	for(i=0; i<nsse/2; i++){
		cdivIntrinsicAVX(((__m256d *)&a+i),((__m256d *)&b+i),((__m256d *)&ret+i));
	}
	return ret;
}

#else

//Missing SSE variant of cmult
inline vectortype cmultnaive(vectortype a,vectortype b){
	v2complex ret;
	v2complex *A;
	v2complex *B;
	A = (v2complex *)&a;
	B = (v2complex *)&b;
	
	int i;
	for(i=0; i<nsse; i++){
		ret.c[i] = A->c[i] * B->c[i];
	}

	return ret.v;
}
#endif

enum { MBbits = 8, MBmask = (1LL << MBbits) - 1 };
#define MomEncoding(f,i) (((f) & (JK-1)) << MBbits*(i-1))

#define Sqrt sqrt

#define Power(x, n) ({ \
  typeof(x) _x = x, _r = 1; \
  typeof(n) _n = n; \
  while( _n ) { \
    if( _n & 1 ) _r *= _x; \
    _n >>= 1; \
    _x *= _x; \
  } \
  _r; \
})

static inline RealType Sq(cComplexType c) {
  return Re(c*Conjugate(c));
}

static inline ComplexType SInvariant(cint a, cint b) {
  return (Re(vec(1,1,k0(a))) + Re(vec(1,1,k0(b))))*
         (Re(vec(2,2,k0(a))) + Re(vec(2,2,k0(b)))) -
         Sq(vec(1,2,k0(a)) + vec(1,2,k0(b)));
}

static inline ComplexType TInvariant(cint a, cint b) {
  return (Re(vec(1,1,k0(a))) - Re(vec(1,1,k0(b))))*
         (Re(vec(2,2,k0(a))) - Re(vec(2,2,k0(b)))) -
         Sq(vec(1,2,k0(a)) - vec(1,2,k0(b)));
}

#undef HelFun
#undef HelType
#undef cHelType
#define HelType vectortype
#define cHelType const vectortype
#define HelFun static inline vectortype

HelFun Pair(cint a, cint b) {
  return .5*(cmult(Vec(1,1,a),Vec(2,2,b)) + cmult(Vec(2,2,a),Vec(1,1,b)) -
             cmult(Vec(1,2,a),Vec(2,1,b)) - cmult(Vec(2,1,a),Vec(1,2,b)));
}

HelFun Eps_(cint a, cint b, cint c, cint d) {
  return (cmult(Vec(1,1,a),Vec(2,2,b)) -cmult(Vec(2,2,a),Vec(1,1,b)))*
         (cmult(Vec(2,1,c),Vec(1,2,d)) - cmult(Vec(1,2,c),Vec(2,1,d)));
}

HelFun Eps(cint a, cint b, cint c, cint d) {
  return .25*(
    Eps_(a, b, c, d) + Eps_(c, d, a, b) -
    Eps_(a, c, b, d) - Eps_(b, d, a, c) +
    Eps_(a, d, b, c) + Eps_(b, c, a, d) );
}

HelFun SxS(SpiType(l1,l2), SpiType(r1,r2)) {
  return cmult(l1,r1) + cmult(l2,r2);
}

HelFun SxV1(SpiType(l1,l2), cint a) {
  return cmult(l1,Vec(1,1,a)) + cmult(l2,Vec(2,1,a));
}

HelFun SxV2(SpiType(l1,l2), cint a) {
  return cmult(l2,Vec(2,2,a)) + cmult(l1,Vec(1,2,a));
}

HelFun SxB1(SpiType(l1,l2), cint a) {
  return cmult(l1,Vec(2,2,a)) - cmult(l2,Vec(2,1,a));
}

HelFun SxB2(SpiType(l1,l2), cint a) {
  return cmult(l2,Vec(1,1,a)) - cmult(l1,Vec(1,2,a));
}

HelFun VxS1(cint a, SpiType(r1,r2)) {
  return cmult(Vec(1,1,a),r1) + cmult(Vec(1,2,a),r2);
}

HelFun VxS2(cint a, SpiType(r1,r2)) {
  return cmult(Vec(2,1,a),r1) + cmult(Vec(2,2,a),r2);
}

HelFun BxS1(cint a, SpiType(r1,r2)) {
  return cmult(Vec(2,2,a),r1) - cmult(Vec(1,2,a),r2);
}

HelFun BxS2(cint a, SpiType(r1,r2)) {
  return cmult(Vec(1,1,a),r2) - cmult(Vec(2,1,a),r1);
}

HelFun SxVxB1(SpiType(l1,l2), cint a, cint b) {
  return SxB1(SxV1(l1,l2, a),SxV2(l1,l2, a), b);
}

HelFun SxVxB2(SpiType(l1,l2), cint a, cint b) {
  return SxB2(SxV1(l1,l2, a),SxV2(l1,l2, a), b);
}

HelFun SxBxV1(SpiType(l1,l2), cint a, cint b) {
  return SxV1(SxB1(l1,l2, a),SxB2(l1,l2, a), b);
}

HelFun SxBxV2(SpiType(l1,l2), cint a, cint b) {
  return SxV2(SxB1(l1,l2, a),SxB2(l1,l2, a), b);
}

HelFun BxVxS1(cint b, cint a, SpiType(r1,r2)) {
  return BxS1(b, VxS1(a, r1,r2),VxS2(a, r1,r2));
}

HelFun BxVxS2(cint b, cint a, SpiType(r1,r2)) {
  return BxS2(b, VxS1(a, r1,r2),VxS2(a, r1,r2));
}

HelFun VxBxS1(cint b, cint a, SpiType(r1,r2)) {
  return VxS1(b, BxS1(a, r1,r2),BxS2(a, r1,r2));
}

HelFun VxBxS2(cint b, cint a, SpiType(r1,r2)) {
  return VxS2(b, BxS1(a, r1,r2),BxS2(a, r1,r2));
}

HelFun SxVxBxV1(SpiType(l1,l2), cint a, cint b, cint c) {
  return SxBxV1(SxV1(l1,l2, a),SxV2(l1,l2, a), b, c);
}

HelFun SxVxBxV2(SpiType(l1,l2), cint a, cint b, cint c) {
  return SxBxV2(SxV1(l1,l2, a),SxV2(l1,l2, a), b, c);
}

HelFun SxBxVxB1(SpiType(l1,l2), cint a, cint b, cint c) {
  return SxVxB1(SxB1(l1,l2, a),SxB2(l1,l2, a), b, c);
}

HelFun SxBxVxB2(SpiType(l1,l2), cint a, cint b, cint c) {
  return SxVxB2(SxB1(l1,l2, a),SxB2(l1,l2, a), b, c);
}

HelFun VxBxVxS1(cint c, cint b, cint a, SpiType(r1,r2)) {
  return VxBxS1(c, b, VxS1(a, r1,r2),VxS2(a, r1,r2));
}

HelFun VxBxVxS2(cint c, cint b, cint a, SpiType(r1,r2)) {
  return VxBxS2(c, b, VxS1(a, r1,r2),VxS2(a, r1,r2));
}

HelFun BxVxBxS1(cint c, cint b, cint a, SpiType(r1,r2)) {
  return BxVxS1(c, b, BxS1(a, r1,r2),BxS2(a, r1,r2));
}

HelFun BxVxBxS2(cint c, cint b, cint a, SpiType(r1,r2)) {
  return BxVxS2(c, b, BxS1(a, r1,r2),BxS2(a, r1,r2));
}

HelFun ChainV0(SpiSpec(iL,eL), SpiSpec(eR,iR)) {
  return SxS(SpiLB(iL,eL), SpiRV(eR,iR));
}

HelFun ChainB0(SpiSpec(iL,eL), SpiSpec(eR,iR)) {
  return SxS(SpiLV(iL,eL),
             SpiRB(eR,iR));
}

HelFun ChainV1(SpiSpec(iL,eL), cint a, SpiSpec(eR,iR)) {
  return SxS(SxV1(SpiLB(iL,eL), a),
             SxV2(SpiLB(iL,eL), a),
             SpiRB(eR,iR));
}

HelFun ChainB1(SpiSpec(iL,eL), cint a, SpiSpec(eR,iR)) {
  return SxS(SxB1(SpiLV(iL,eL), a),
             SxB2(SpiLV(iL,eL), a),
             SpiRV(eR,iR));
}

HelFun ChainV2(SpiSpec(iL,eL), cint a, cint b, SpiSpec(eR,iR)) {
  return SxS(SxV1(SpiLB(iL,eL), a),
             SxV2(SpiLB(iL,eL), a),
             BxS1(b, SpiRV(eR,iR)),
             BxS2(b, SpiRV(eR,iR)));
}

HelFun ChainB2(SpiSpec(iL,eL), cint a, cint b, SpiSpec(eR,iR)) {
  return SxS(SxB1(SpiLV(iL,eL), a),
             SxB2(SpiLV(iL,eL), a),
             VxS1(b, SpiRB(eR,iR)),
             VxS2(b, SpiRB(eR,iR)));
}

HelFun ChainV3(SpiSpec(iL,eL), cint a, cint b,
    cint c, SpiSpec(eR,iR)) {
  return SxS(SxVxB1(SpiLB(iL,eL), a, b),
             SxVxB2(SpiLB(iL,eL), a, b),
             VxS1(c, SpiRB(eR,iR)),
             VxS2(c, SpiRB(eR,iR)));
}

HelFun ChainB3(SpiSpec(iL,eL), cint a, cint b,
    cint c, SpiSpec(eR,iR)) {
  return SxS(SxBxV1(SpiLV(iL,eL), a, b),
             SxBxV2(SpiLV(iL,eL), a, b),
             BxS1(c, SpiRV(eR,iR)),
             BxS2(c, SpiRV(eR,iR)));
}

HelFun ChainV4(SpiSpec(iL,eL), cint a, cint b,
    cint c, cint d, SpiSpec(eR,iR)) {
  return SxS(SxVxB1(SpiLB(iL,eL), a, b),
             SxVxB2(SpiLB(iL,eL), a, b),
             VxBxS1(c, d, SpiRV(eR,iR)),
             VxBxS2(c, d, SpiRV(eR,iR)));
}

HelFun ChainB4(SpiSpec(iL,eL), cint a, cint b,
    cint c, cint d, SpiSpec(eR,iR)) {
  return SxS(SxBxV1(SpiLV(iL,eL), a, b),
             SxBxV2(SpiLV(iL,eL), a, b),
             BxVxS1(c, d, SpiRB(eR,iR)),
             BxVxS2(c, d, SpiRB(eR,iR)));
}

HelFun ChainV5(SpiSpec(iL,eL), cint a, cint b, cint c,
    cint d, cint e, SpiSpec(eR,iR)) {
  return SxS(SxVxBxV1(SpiLB(iL,eL), a, b, c),
             SxVxBxV2(SpiLB(iL,eL), a, b, c),
             BxVxS1(d, e, SpiRB(eR,iR)),
             BxVxS2(d, e, SpiRB(eR,iR)));
}

HelFun ChainB5(SpiSpec(iL,eL), cint a, cint b, cint c,
    cint d, cint e, SpiSpec(eR,iR)) {
  return SxS(SxBxVxB1(SpiLV(iL,eL), a, b, c),
             SxBxVxB2(SpiLV(iL,eL), a, b, c),
             VxBxS1(d, e, SpiRV(eR,iR)),
             VxBxS2(d, e, SpiRV(eR,iR)));
}

HelFun ChainV6(SpiSpec(iL,eL), cint a, cint b, cint c,
    cint d, cint e, cint f, SpiSpec(eR,iR)) {
  return SxS(SxVxBxV1(SpiLB(iL,eL), a, b, c),
             SxVxBxV2(SpiLB(iL,eL), a, b, c),
             BxVxBxS1(d, e, f, SpiRV(eR,iR)),
             BxVxBxS2(d, e, f, SpiRV(eR,iR)));
}

HelFun ChainB6(SpiSpec(iL,eL), cint a, cint b, cint c,
    cint d, cint e, cint f, SpiSpec(eR,iR)) {
  return SxS(SxBxVxB1(SpiLV(iL,eL), a, b, c),
             SxBxVxB2(SpiLV(iL,eL), a, b, c),
             VxBxVxS1(d, e, f, SpiRB(eR,iR)),
             VxBxVxS2(d, e, f, SpiRB(eR,iR)));
}

static inline int IndexDelta(cint a, cint b) {
  enum { n = 8*sizeof a - 1 };
  return (unsigned)((a ^ b) - 1) >> n;
}

static inline int IndexSign(cint a) {
  enum { n = 8*sizeof a - 1 };
  return (a >> n) | (((unsigned)-a) >> n);
}

static inline int IndexEps(cint a, cint b, cint c) {
  return IndexSign(a - b)*IndexSign(c - b)*IndexSign(a - c);
}

static inline RealType SqDiff(cRealType ma, cRealType mb) {
  return (ma - mb)*(ma + mb);
}

static inline RealType ThreeMom(cRealType sqrtS,
    cRealType ma, cRealType mb) {
  return sqrt(SqDiff(.5*(sqrtS - SqDiff(ma, mb)/sqrtS), mb));
}

#endif


#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

/*#define __AVX__*/
#include <immintrin.h>

/*------------------AVX-TYPES----------------*/
typedef union int2{
	__m64 v;
	int i[2];
}int2;

typedef union vcomplex{
	__m128d v;
	ComplexType c;
	double d[2];
}vcomplex;

typedef union v2complex{
	__m256d v2;
	double d[4];
	/*vcomplex v[2];*/
	ComplexType c[2];
}v2complex;

/*#include "varsAVX.h"*/
/**/




//Creating helicity map
  typedef struct hel_comb{
	  /*struct{*/
  		int2 hels[LEGS];
		/*};*/

  }hel_comb;


// Flag is Hel_Mask created. SHould be done only once
int HEL_COMB_DONE = 0;
int num_hels;
hel_comb *helcomb;


inline int2 Spinor_AVX(int i, int s, int d, int N){
	int2 ret;
	//mmset was buggy for Chain functions, seems to work here, dunno why.
	/*ret.v =*/
	/*_mm_set_pi32(nvec*(i-1)+d+5,nvec*(i-1)+d+5) +(s*helcomb[N].hels[i-1].v);*/
	/*ret.v +=(s*helcomb[N].hels[i-1].v);*/
	ret.i[0] = nvec*(i-1)+d+5+(s*helcomb[N].hels[i-1].i[0]);
	ret.i[1] = nvec*(i-1)+d+5+(s*helcomb[N].hels[i-1].i[1]);

	return ret;
}

inline int2 e_AVX(int i, int N){
	int2 ret;
	/*ret.v =_mm_set_pi32(nvec*(i-1)+3,nvec*(i-1)+3)+(helcomb[N].hels[i-1].v);*/
	ret.i[0] = nvec*(i-1)+3+(helcomb[N].hels[i-1].i[0]);
	ret.i[1] = nvec*(i-1)+3+(helcomb[N].hels[i-1].i[1]);

	return ret;
}
inline int2 ec_AVX(int i, int N){
	int2 ret;
	/*ret.v =_mm_set_pi32(nvec*(i-1)+3,nvec*(i-1)+3)-(helcomb[n].hels[i-1].v);*/
	ret.i[0] = nvec*(i-1)+3-(helcomb[N].hels[i-1].i[0]);
	ret.i[1] = nvec*(i-1)+3-(helcomb[N].hels[i-1].i[1]);

	return ret;
}


/*-------------------AVX operations-----------------*/


void cmult2(__m256d *a, __m256d *b, __m256d *c){

	asm 
		(
		 "vmovupd %2,%%ymm1;"
		 "vmovupd %2, %%ymm2;"
		 "vmovddup %%ymm2, %%ymm2;"
		 /*"vmovddup %%ymm1, %%ymm2;"*/
		 "vshufpd $15,%%ymm1,%%ymm1,%%ymm1;"
		 "vmulpd %1, %%ymm2, %%ymm2;"
		 "vmulpd %1, %%ymm1, %%ymm1;"
		 "vshufpd $5,%%ymm1,%%ymm1, %%ymm1;"
		 "vaddsubpd %%ymm1, %%ymm2,%%ymm1;"

		 "vmovupd %%ymm1, %0;"
		 :
		 "=m"(*c)
		 :
		 "m" (*a),
		 "m" (*b)
		 :
		 "%xmm1","%xmm2"
		);

}
__m256d cmult22(__m256d *a, __m256d *b){
	__m256d ret;
	asm 
		(
		 "vmovupd %2,%%ymm1;"
		 /*"vmovupd %2, %%ymm2;"*/
		 "vmovddup %%ymm1, %%ymm2;"
		 /*"vmovddup %%ymm1, %%ymm2;"*/
		 "vshufpd $15,%%ymm1,%%ymm1,%%ymm1;"
		 "vmulpd %1, %%ymm2, %%ymm2;"
		 "vmulpd %1, %%ymm1, %%ymm1;"
		 "vshufpd $5,%%ymm1,%%ymm1, %%ymm1;"
		 "vaddsubpd %%ymm1, %%ymm2,%%ymm1;"

		 "vmovupd %%ymm1, %0;"
		 :
		 "=m"(ret)
		 :
		 "m" (*a),
		 "m" (*b)
		 :
		 "%xmm1","%xmm2"
		);

	_mm256_zeroupper();
	return ret;
}
inline void cmultabc(v2complex *a, v2complex *b, v2complex *c){
	__m256d tmp1 = _mm256_movedup_pd(b->v2);
	__m256d tmp2 = _mm256_shuffle_pd(b->v2,b->v2,15);
	tmp1 =_mm256_mul_pd(a->v2,tmp1);
	tmp2 =_mm256_mul_pd(a->v2,tmp2);
	tmp2 = _mm256_shuffle_pd(tmp2,tmp2,5);
	tmp2 = _mm256_addsub_pd(tmp1,tmp2);
	c->v2 = tmp2;
}
inline __m256d cmultabc2(__m256d *a, __m256d *b){
	__m256d tmp1 = _mm256_movedup_pd(*b);
	__m256d tmp2 = _mm256_shuffle_pd(*b,*b,15);
	tmp1 =_mm256_mul_pd(*a,tmp1);
	tmp2 =_mm256_mul_pd(*a,tmp2);
	tmp2 = _mm256_shuffle_pd(tmp2,tmp2,5);
	tmp2 = _mm256_addsub_pd(tmp1,tmp2);
	return tmp2;
}

void cmultnaive(v2complex *a, v2complex *b, v2complex *c){

	c->c[0] = a->c[0] * b->c[0];
	c->c[1] = a->c[1] * b->c[1];
}
void cdivnaive(v2complex *a, v2complex *b, v2complex *c){

	c->c[0] = a->c[0] / b->c[0];
	c->c[1] = a->c[1] / b->c[1];
}

__m256d cdiv(__m256d a,__m256d b){
	__m256d ret;
	v2complex *p1,*p2,*p3;
	p1 = (v2complex *)&a;
	p2 = (v2complex *)&b;
	p3 = (v2complex *)&ret;
	cdivnaive(p1,p2,p3);
	return ret;
}

inline v2complex cmult_AVX(v2complex a,v2complex b){
	v2complex ret;
	cmultnaive(&a,&b,&ret);
	/*cmultabc(&a,&b,&ret);*/
	return ret;
}
inline __m256d cmult(__m256d a,__m256d b){
	/*return cmult22(&a,&b);*/
	return cmultabc2(&a,&b);

	/*__m256d ret;*/
	/*cmultnaive( &a,&b,&ret);*/
	/*return ret;*/
}

v2complex cadd_AVX(v2complex a, v2complex b){
	v2complex ret;
	ret.v2 = a.v2+b.v2;
	return ret;
}
v2complex csub_AVX(v2complex a, v2complex b){
	v2complex ret;
	ret.v2 = a.v2-b.v2;
	return ret;
}


#define SpiLB_AVX(i,e) SpiLB_AVX2(i,e),vec(2-e,2-e,i)
#define SpiRV_AVX(e,i) vec(1+e,1+e,i), SpiRV_AVX2(e,i)

#define SpiTypeL(s1,s2) v2complex s1, v2complex s2
/*#define SpiType(s1,s2) v2complex s1, v2complex s2*/
#define SpiType_AVX(s1,s2) v2complex s1, v2complex s2
#define SpiTypeR(s1,s2) v2complex s1, v2complex s2
#define SpiSpecL_AVX(i,e) int2 i, int e
#define SpiSpecR_AVX(e,i) int e, int2 i
#define SpiSpec_AVX(e,i) int2 e, int2 i


v2complex Pair_AVX(int2 a, int b){
	v2complex ret;
	ret.c[0] =.5*(vec(1,1,a.i[0])*vec(2,2,b) + vec(2,2,a.i[0])*vec(1,1,b) -
			vec(1,2,a.i[0])*vec(2,1,b) - vec(2,1,a.i[0])*vec(1,2,b));
	ret.c[1] =.5*(vec(1,1,a.i[1])*vec(2,2,b) + vec(2,2,a.i[1])*vec(1,1,b) -
			vec(1,2,a.i[1])*vec(2,1,b) - vec(2,1,a.i[1])*vec(1,2,b));
	return ret;

}



inline v2complex SpiLB_AVX1(int2 i,int e){
	v2complex ret;
	ret.c[0] = (1-2*e)*vec(1+e,2-e,i.i[0]);
	ret.c[1] = (1-2*e)*vec(1+e,2-e,i.i[1]);
	return ret;
}
inline v2complex SpiLV_AVX1(int2 i,int e){
	v2complex ret;
	ret.c[0] = (1-2*e)*vec(1+e,1+e,i.i[0]);
	ret.c[1] = (1-2*e)*vec(1+e,1+e,i.i[1]);
	return ret;
}
inline v2complex SpiLB_AVX2(int2 i,int e){
	v2complex ret;
	ret.c[0] = vec(2-e,2-e,i.i[0]);
	ret.c[1] = vec(2-e,2-e,i.i[1]);
	return ret;
}
inline v2complex SpiLV_AVX2(int2 i,int e){
	v2complex ret;
	ret.c[0] = vec(2-e,1+e,i.i[0]);
	ret.c[1] = vec(2-e,1+e,i.i[1]);
	return ret;
}

inline v2complex SpiRV_AVX2(int e,int2 i){
	v2complex ret;
	ret.c[0] = (1-2*e)*vec(2-e,1+e,i.i[0]);
	ret.c[1] = (1-2*e)*vec(2-e,1+e,i.i[1]);
	/*fprintf(stderr, "test in spinrv: %f %f\n",Re(ret.c[0]),Im(ret.c[0]));*/
	/*fprintf(stderr, "test2 in spinrv: %i \n",i.i[0]);*/
	return ret;
}

inline v2complex SpiRB_AVX2(int e,int2 i){
	v2complex ret;
	ret.c[0] = (1-2*e)*vec(2-e,2-e,i.i[0]);
	ret.c[1] = (1-2*e)*vec(2-e,2-e,i.i[1]);
	return ret;
}

inline v2complex SpiRV_AVX1(int e,int2 i){
	v2complex ret;
	ret.c[0] = vec(1+e,1+e,i.i[0]);
	ret.c[1] = vec(1+e,1+e,i.i[1]);
	return ret;
}
inline v2complex SpiRB_AVX1(int e,int2 i){
	v2complex ret;
	ret.c[0] = vec(1+e,2-e,i.i[0]);
	ret.c[1] = vec(1+e,2-e,i.i[1]);
	return ret;
}


/*The General input for ChainV0 is*/
/*Chainv0(Spinor, integer, integer, Spinor)*/

/*SpiLB takes one int2 and one int*/
/*Therefore SxS takes*/
/*v2complex complex, complex  v2complex*/




inline v2complex SxS_AVX(v2complex a1,v2complex a2,v2complex b1,v2complex b2) {
	/*fprintf(stderr,"SSE%.20f\n",Re(a2.c[0]));*/
	/*fprintf(stderr,"SSE%.20f\n",Re(b2.c[0]));*/
	/*fprintf(stderr,"SSE%.20f\n",Re(b1.c[0]));*/
	/*fprintf(stderr,"SSE%.20f\n",Re(a1.c[0]));*/

	return cadd_AVX(cmult_AVX(a1,b1),cmult_AVX(a2,b2));
}
inline v2complex SxV1_AVX(SpiType_AVX(l1,l2), int2 a) {
	v2complex vec1;
	v2complex vec2;
	vec1.c[0] = vec(1,1,a.i[0]);
	vec1.c[1] = vec(1,1,a.i[1]);
	vec2.c[0] = vec(2,1,a.i[0]);
	vec2.c[1] = vec(2,1,a.i[1]);
	return cadd_AVX(cmult_AVX(l1,vec1),cmult_AVX(l2,vec2));
}
inline v2complex SxV2_AVX(SpiType_AVX(l1,l2), int2 a) {
	v2complex vec1;
	v2complex vec2;
	vec1.c[0] = vec(2,2,a.i[0]);
	vec1.c[1] = vec(2,2,a.i[1]);
	vec2.c[0] = vec(1,2,a.i[0]);
	vec2.c[1] = vec(1,2,a.i[1]);
	return cadd_AVX(cmult_AVX(l2,vec1),cmult_AVX(l1,vec2));
}
inline v2complex SxB1_AVX(SpiType_AVX(l1,l2), int2 a) {
	v2complex vec1;
	v2complex vec2;
	vec1.c[0] = vec(2,2,a.i[0]);
	vec1.c[1] = vec(2,2,a.i[1]);
	vec2.c[0] = vec(2,1,a.i[0]);
	vec2.c[1] = vec(2,1,a.i[1]);
	return csub_AVX(cmult_AVX(l1,vec1),cmult_AVX(l2,vec2));
}
inline v2complex SxB2_AVX(SpiType_AVX(l1,l2), int2 a) {
	v2complex vec1;
	v2complex vec2;
	vec1.c[0] = vec(1,1,a.i[0]);
	vec1.c[1] = vec(1,1,a.i[1]);
	vec2.c[0] = vec(1,2,a.i[0]);
	vec2.c[1] = vec(1,2,a.i[1]);
	return csub_AVX(cmult_AVX(l2,vec1),cmult_AVX(l1,vec2));
}
inline v2complex VxS1_AVX(int2 a,SpiType_AVX(r1,r2)) {
	v2complex vec1;
	v2complex vec2;
	vec1.c[0] = vec(1,1,a.i[0]);
	vec1.c[1] = vec(1,1,a.i[1]);
	vec2.c[0] = vec(1,2,a.i[0]);
	vec2.c[1] = vec(1,2,a.i[1]);
	return cadd_AVX(cmult_AVX(r1,vec1),cmult_AVX(r2,vec2));
}
inline v2complex VxS2_AVX(int2 a,SpiType_AVX(r1,r2)) {
	v2complex vec1;
	v2complex vec2;
	vec1.c[0] = vec(2,1,a.i[0]);
	vec1.c[1] = vec(2,1,a.i[1]);
	vec2.c[0] = vec(2,2,a.i[0]);
	vec2.c[1] = vec(2,2,a.i[1]);
	return cadd_AVX(cmult_AVX(r1,vec1),cmult_AVX(r2,vec2));
}
inline v2complex BxS1_AVX(int2 a,v2complex r1, v2complex r2){
	/*SpiType_AVX(r1,r2)) {*/

	/*fprintf(stderr,"test BxS1%.20f\n",Re(r1.c[0]));*/
	v2complex vec1;
	v2complex vec2;
	vec1.c[0] = vec(2,2,a.i[0]);
	vec1.c[1] = vec(2,2,a.i[1]);
	vec2.c[0] = vec(1,2,a.i[0]);
	vec2.c[1] = vec(1,2,a.i[1]);
	return csub_AVX(cmult_AVX(r1,vec1),cmult_AVX(r2,vec2));
}
inline v2complex BxS2_AVX(int2 a,SpiType_AVX(r1,r2)) {
	v2complex vec1;
	v2complex vec2;
	vec1.c[0] = vec(1,1,a.i[0]);
	vec1.c[1] = vec(1,1,a.i[1]);
	vec2.c[0] = vec(2,1,a.i[0]);
	vec2.c[1] = vec(2,1,a.i[1]);
	return csub_AVX(cmult_AVX(r2,vec1),cmult_AVX(r1,vec2));
}
v2complex SxVxB1_AVX(SpiType_AVX(l1,l2), int2 a, int2 b) {
	return SxB1_AVX(SxV1_AVX(l1,l2, a),SxV2_AVX(l1,l2, a), b);
}

v2complex SxVxB2_AVX(SpiType_AVX(l1,l2), int2 a, int2 b) {
	return SxB2_AVX(SxV1_AVX(l1,l2, a),SxV2_AVX(l1,l2, a), b);
}
v2complex SxBxV1_AVX(SpiType_AVX(l1,l2), int2 a, int2 b) {
	return SxV1_AVX(SxB1_AVX(l1,l2, a),SxB2_AVX(l1,l2, a), b);
}
v2complex SxBxV2_AVX(SpiType_AVX(l1,l2), int2 a, int2 b) {
	return SxV2_AVX(SxB1_AVX(l1,l2, a),SxB2_AVX(l1,l2, a), b);
}

v2complex ChainV0_AVX(SpiSpecL_AVX(iL,eL), SpiSpecR_AVX(eR,iR)) {
	v2complex a1 =SpiLB_AVX1(iL,eL);
	/*fprintf(stderr, "test in chainv0: %i %i",a1.i[0],a1.i[1]);*/
	v2complex a2 =SpiLB_AVX2(iL,eL);
	v2complex b1 =SpiRV_AVX1(eR,iR);
	v2complex b2 =SpiRV_AVX2(eR,iR);
	return SxS_AVX(a1,a2,b1,b2);
	/*return SxS_AVX(SpiLB_AVX(iL,eL), SpiRV_AVX(eR,iR));*/
}
v2complex ChainB0_AVX(SpiSpecL_AVX(iL,eL), SpiSpecR_AVX(eR,iR)) {
	v2complex a1 =SpiLV_AVX1(iL,eL);
	/*fprintf(stderr, "test in chainv0: %i %i",a1.i[0],a1.i[1]);*/
	v2complex a2 =SpiLV_AVX2(iL,eL);
	v2complex b1 =SpiRB_AVX1(eR,iR);
	v2complex b2 =SpiRB_AVX2(eR,iR);
	return SxS_AVX(a1,a2,b1,b2);
	/*return SxS_AVX(SpiLB_AVX(iL,eL), SpiRV_AVX(eR,iR));*/
}
v2complex ChainV1_AVX(SpiSpecL_AVX(iL,eL), int2 a, SpiSpecR_AVX(eR,iR)) {
	v2complex a1 =SpiLB_AVX1(iL,eL);
	v2complex a2 =SpiLB_AVX2(iL,eL);
	v2complex b1 =SpiRB_AVX1(eR,iR);
	v2complex b2 =SpiRB_AVX2(eR,iR);

	return SxS_AVX(SxV1_AVX(a1,a2, a),SxV2_AVX(a1,a2, a),b1,b2);
}
v2complex ChainV1O_AVX(SpiSpecL_AVX(iL,eL), int a, SpiSpecR_AVX(eR,iR)) {
	v2complex a1 =SpiLB_AVX1(iL,eL);
	v2complex a2 =SpiLB_AVX2(iL,eL);
	v2complex b1 =SpiRB_AVX1(eR,iR);
	v2complex b2 =SpiRB_AVX2(eR,iR);
	int2 c;
	c.i[0] = a;
	c.i[1] = a;
	/*c.v= _mm_set_pi32(a,a);*/ //BUGGY!!!

	return SxS_AVX(SxV1_AVX(a1,a2, c),SxV2_AVX(a1,a2, c),b1,b2);
}

v2complex ChainB1_AVX(SpiSpecL_AVX(iL,eL), int2 a, SpiSpecR_AVX(eR,iR)) {
	v2complex a1 =SpiLV_AVX1(iL,eL);
	v2complex a2 =SpiLV_AVX2(iL,eL);
	v2complex b1 =SpiRV_AVX1(eR,iR);
	v2complex b2 =SpiRV_AVX2(eR,iR);
	return SxS_AVX(SxB1_AVX(a1,a2,a),SxB2_AVX(a1,a2,a),b1,b2);
}

v2complex ChainB1O_AVX(SpiSpecL_AVX(iL,eL), int a, SpiSpecR_AVX(eR,iR)) {
	v2complex a1 =SpiLV_AVX1(iL,eL);
	v2complex a2 =SpiLV_AVX2(iL,eL);
	v2complex b1 =SpiRV_AVX1(eR,iR);
	v2complex b2 =SpiRV_AVX2(eR,iR);
	int2 c;
	c.i[0] = a;
	c.i[1] = a;
	/*c.v= _mm_set_pi32(a,a);*/
	return SxS_AVX(SxB1_AVX(a1,a2,c),SxB2_AVX(a1,a2,c),b1,b2);
}

v2complex ChainV2_AVX(SpiSpecL_AVX(iL,eL), int2 a, int b, SpiSpecR_AVX(eR,iR)) {
	v2complex a1 =SpiLB_AVX1(iL,eL);
	v2complex a2 =SpiLB_AVX2(iL,eL);
	v2complex b1 =SpiRV_AVX1(eR,iR);
	v2complex b2 =SpiRV_AVX2(eR,iR);
	int2 c;
	/*c.v= _mm_set_pi32(b,b);*/
	c.i[0] = b;
	c.i[1] = b;
	return SxS_AVX(SxV1_AVX(a1,a2,a),SxV2_AVX(a1,a2, a),
			BxS1_AVX(c,b1,b2),BxS2_AVX(c,b1,b2));
}
v2complex ChainV2O_AVX(SpiSpecL_AVX(iL,eL), int a, int b, SpiSpecR_AVX(eR,iR)) {
	v2complex a1 =SpiLB_AVX1(iL,eL);
	v2complex a2 =SpiLB_AVX2(iL,eL);
	v2complex b1 =SpiRV_AVX1(eR,iR);
	v2complex b2 =SpiRV_AVX2(eR,iR);
	int2 c;
	int2 d;
	/*c.v= _mm_set_pi32(a,a);*/
	c.i[0] = a;
	c.i[1] = a;
	/*d.v= _mm_set_pi32(b,b);*/
	d.i[0] = b;
	d.i[1] = b;
	return SxS_AVX(SxV1_AVX(a1,a2,c),SxV2_AVX(a1,a2, c),
			BxS1_AVX(d,b1,b2),BxS2_AVX(d,b1,b2));
}
v2complex ChainB2_AVX(SpiSpecL_AVX(iL,eL), int2 a, int b, SpiSpecR_AVX(eR,iR)) {
	v2complex a1 =SpiLV_AVX1(iL,eL);
	v2complex a2 =SpiLV_AVX2(iL,eL);
	v2complex b1 =SpiRB_AVX1(eR,iR);
	v2complex b2 =SpiRB_AVX2(eR,iR);
	int2 c;
	/*c.v= _mm_set_pi32(b,b);*/
	c.i[0] = b;
	c.i[1] = b;
	return SxS_AVX(SxB1_AVX(a1,a2,a),SxB2_AVX(a1,a2, a),
			VxS1_AVX(c,b1,b2),VxS2_AVX(c,b1,b2));
}
v2complex ChainB2O_AVX(SpiSpecL_AVX(iL,eL), int a, int b, SpiSpecR_AVX(eR,iR)) {
	v2complex a1 =SpiLV_AVX1(iL,eL);
	v2complex a2 =SpiLV_AVX2(iL,eL);
	v2complex b1 =SpiRB_AVX1(eR,iR);
	v2complex b2 =SpiRB_AVX2(eR,iR);
	int2 c;
	int2 d;
	/*c.v= _mm_set_pi32(a,a);*/
	c.i[0] = a;
	c.i[1] = a;
	/*d.v= _mm_set_pi32(b,b);*/
	d.i[0] = b;
	d.i[1] = b;
	return SxS_AVX(SxB1_AVX(a1,a2,c),SxB2_AVX(a1,a2, c),
			VxS1_AVX(d,b1,b2),VxS2_AVX(d,b1,b2));
}
v2complex ChainV3_AVX(SpiSpecL_AVX(iL,eL), int2 a, int b,int c, SpiSpecR_AVX(eR,iR)) {
	v2complex a1 =SpiLB_AVX1(iL,eL);
	v2complex a2 =SpiLB_AVX2(iL,eL);
	v2complex b1 =SpiRB_AVX1(eR,iR);
	v2complex b2 =SpiRB_AVX2(eR,iR);

	int2 bb;
	/*bb.v= _mm_set_pi32(b,b);*/
	bb.i[0] = b;
	bb.i[1] = b;
	int2 cc;
	/*cc.v= _mm_set_pi32(c,c);*/
	cc.i[0] = c;
	cc.i[1] = c;
	return SxS_AVX(SxVxB1_AVX(a1,a2, a, bb),
			SxVxB2_AVX(a1,a2, a, bb),
			VxS1_AVX(cc, b1,b2),
			VxS2_AVX(cc,b1,b2 ));
}

v2complex ChainB3_AVX(SpiSpecL_AVX(iL,eL), int2 a, int b,int c, SpiSpecR_AVX(eR,iR)) {
	v2complex a1 =SpiLV_AVX1(iL,eL);
	v2complex a2 =SpiLV_AVX2(iL,eL);
	v2complex b1 =SpiRV_AVX1(eR,iR);
	v2complex b2 =SpiRV_AVX2(eR,iR);

	int2 bb;
	/*bb.v= _mm_set_pi32(b,b);*/
	bb.i[0] = b;
	bb.i[1] = b;
	int2 cc;
	/*cc.v= _mm_set_pi32(c,c);*/
	cc.i[0] = c;
	cc.i[1] = c;
	return SxS_AVX(SxBxV1_AVX(a1,a2,a,bb),
			SxBxV2_AVX(a1,a2,a,bb),
			BxS1_AVX(cc,b1,b2),
			BxS2_AVX(cc,b1,b2));
}

void cpyhelmask(long long int *helicities);

void create_hel_mask(long long int *helicities){
	int r = 0;
	LOOP_HEL(Hel(1))
		TEST(helicities, BIT_HEL(1))

		LOOP_HEL(Hel(2))
		TEST(helicities, BIT_HEL(2))
		LOOP_HEL(Hel(3))
		TEST(helicities, BIT_HEL(3))
		LOOP_HEL(Hel(4))
		TEST(helicities, BIT_HEL(4))

		LOOP_HEL(Hel(5))
		TEST(helicities, BIT_HEL(5))

		r+=1;

	ENDTEST(helicities, BIT_HEL(5))
		ENDLOOP_HEL(Hel5)

		ENDTEST(helicities, BIT_HEL(4))
		ENDLOOP_HEL(Hel4)

		ENDTEST(helicities, BIT_HEL(3))
		ENDLOOP_HEL(Hel3)

		ENDTEST(helicities, BIT_HEL(2))
		ENDLOOP_HEL(Hel2)

		ENDTEST(helicities, BIT_HEL(1))
		ENDLOOP_HEL(Hel1)

		/*fprintf(stderr,"COMBS %i \n",r);*/

	if (r%2==0){
		helcomb = (hel_comb*) malloc((r/2) * sizeof(hel_comb));
	}else{
		fprintf(stderr,"HelComb not a multiple of 2");
		exit(0);
	}

	cpyhelmask(helicities);
	/*sethelcomb(helcomb);*/
	num_hels = r/2;
	HEL_COMB_DONE = 1;
}
void cpyhelmask(long long int *helicities){
	int r = 0;
	int index;
	int remainder;
	LOOP_HEL(Hel(1))
		TEST(helicities, BIT_HEL(1))

		LOOP_HEL(Hel(2))
		TEST(helicities, BIT_HEL(2))

		LOOP_HEL(Hel(3))
		TEST(helicities, BIT_HEL(3))

		LOOP_HEL(Hel(4))
		TEST(helicities, BIT_HEL(4))

		LOOP_HEL(Hel(5))
		TEST(helicities, BIT_HEL(5))

		index = r/2;
	remainder = r%2;
	/*fprintf(stderr,"%i %i \n",index,remainder);*/
	/*fprintf(stderr,"HEL 4%i\n",Hel(4));*/

	helcomb[index].hels[0].i[remainder] = Hel(1);
	helcomb[index].hels[1].i[remainder] = Hel(2);
	helcomb[index].hels[2].i[remainder] = Hel(3);
	helcomb[index].hels[3].i[remainder] = Hel(4);
	helcomb[index].hels[4].i[remainder] = Hel(5);
	r+=1;

	ENDTEST(helicities, BIT_HEL(5))
		ENDLOOP_HEL(Hel5)

		ENDTEST(helicities, BIT_HEL(4))
		ENDLOOP_HEL(Hel4)

		ENDTEST(helicities, BIT_HEL(3))
		ENDLOOP_HEL(Hel3)

		ENDTEST(helicities, BIT_HEL(2))
		ENDLOOP_HEL(Hel2)

		ENDTEST(helicities, BIT_HEL(1))
		ENDLOOP_HEL(Hel1)
}

__m256d cmultci(__m256d a,__m64 b){
	__m256d aa;
	int2 bb;
	bb.v = b;
	// it seems that the function setr set were swapped
	aa =_mm256_setr_pd((double)bb.i[0],0,(double)bb.i[1],0);
	/*fprintf(stderr,"Heltest %i\n",bb.i[0]);*/

	__m256d ret;
	cmult2(&a,&aa,&ret);
	return ret;
}	

inline __m256d CtoV2(complex c){
	__m128d *ptr_t =(__m128d *) &(c);
	__m256d t2 = _mm256_insertf128_pd(t2,*ptr_t,0);
	t2 = _mm256_insertf128_pd(t2,*ptr_t,1);
	return t2;
}
inline __m256d DtoV2(double c){
	__m256d ret =_mm256_setr_pd(c,0,c,0);
	return ret;
}

static double sumup(complex CCloop,
		ComplexType CCtree) {

#include "vars.h"

	ComplexType s = 0;

	ComplexType m = 0;
	m += CCloop*MatSUN(1,1);
	s += Re(Conjugate(CCtree)*m);
	return s;
}

#undef Hel
#define Hel(i,j) helcomb[j].hels[i-1].v
#undef Spinor
#define Spinor(i,j,k,l) Spinor_AVX(i,j,k,l)
#undef ec
#define ec(i,l) ec_AVX(i,l)
#define ChainV0(a,b,c,d) ChainV0_AVX(a,b,c,d).v2
#define ChainB0(a,b,c,d) ChainB0_AVX(a,b,c,d).v2
#define ChainV1(a,b,c,d,e) ChainV1_AVX(a,b,c,d,e).v2
#define ChainV1O(a,b,c,d,e) ChainV1O_AVX(a,b,c,d,e).v2
#define ChainB1(a,b,c,d,e) ChainB1_AVX(a,b,c,d,e).v2
#define ChainB1O(a,b,c,d,e) ChainB1O_AVX(a,b,c,d,e).v2
#define ChainV2(a,b,c,d,e,f) ChainV2_AVX(a,b,c,d,e,f).v2
#define ChainV2O(a,b,c,d,e,f) ChainV2O_AVX(a,b,c,d,e,f).v2
#define ChainB2(a,b,c,d,e,f) ChainB2_AVX(a,b,c,d,e,f).v2
#define ChainB2O(a,b,c,d,e,f) ChainB2O_AVX(a,b,c,d,e,f).v2
#define ChainV3(a,b,c,d,e,f,g) ChainV3_AVX(a,b,c,d,e,f,g).v2
#define ChainB3(a,b,c,d,e,f,g) ChainB3_AVX(a,b,c,d,e,f,g).v2
#define Pair(a,b) Pair_AVX(a,b).v2

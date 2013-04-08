#if defined(cl_khr_fp64)  // Khronos extension available?
    #pragma OPENCL EXTENSION cl_khr_fp64 : enable
    #define double_active 1
#elif defined(cl_amd_fp64)
    #define double_active 1
    #pragma OPENCL EXTENSION cl_amd_fp64 : enable
#else
    #define double_active 0
    #error "Double precision floating point not supported by OpenCL implementation."
#endif
#define RealType  double
#define integer int

#include "ccomplex.h"

typedef struct ComplexType{
	RealType re, im;
} ComplexType;

enum { nvec = 10 };
#define LEGS  4


//From C/util.h
typedef struct vectors{
  	ctype vec[LEGS*nvec+1][2][2];
}vectors_;

#define vec(i,j,n) (*vectors).vec[n][j-1][i-1]

#define ComplexFun static inline ctype
#define SpiType(s1,s2) ctype s1, ctype s2
#define SpiSpec(i,e) integer i, integer e
#define SpiLV(i,e) cmult(((ctype)((1-2*e),0.)) ,vec(1+e,1+e,i)), vec(2-e,1+e,i)
#define SpiLB(i,e) cmult(((ctype)((1-2*e),0)),vec(1+e,2-e,i)), vec(2-e,2-e,i)
#define SpiRV(e,i) vec(1+e,1+e,i), cmult((ctype)(1-2*e,0.),vec(2-e,1+e,i))
#define SpiRB(e,i) vec(1+e,2-e,i), cmult((ctype)(1-2*e,0.),vec(2-e,2-e,i))



ComplexFun SxS(SpiType(l1,l2), SpiType(r1,r2)) {
	return cmult(l1,r1) + cmult(l2,r2);
}
ComplexFun ChainV0(SpiSpec(iL,eL), SpiSpec(eR,iR),vectors_ *vectors) {
	return SxS(SpiLB(iL,eL), SpiRV(eR,iR));
}
ComplexFun ChainB0(SpiSpec(iL,eL), SpiSpec(eR,iR),vectors_ *vectors) {
	return SxS(SpiLV(iL,eL),SpiRB(eR,iR));
}

#define ToCC(a) ((ctype)((*a).re,(*a).im))

ComplexType ToCT(ctype b){
	ComplexType ret;
	ret.re =b.x;
	ret.im =(b).y;
	return ret;
} 


/*typedef struct var0h {*/
typedef struct{
	ctype F3, F5, F1, F7, F8, F6, F2, F4, Sub1, Sub2, Sub3;
} var0h_;


#define F3 (*var0h).F3
#define F5 (*var0h).F5
#define F1 (*var0h).F1
#define F7 (*var0h).F7
#define F8 (*var0h).F8
#define F6 (*var0h).F6
#define F2 (*var0h).F2
#define F4 (*var0h).F4
#define Sub1 (*var0h).Sub1
#define Sub2 (*var0h).Sub2
#define Sub3 (*var0h).Sub3

typedef struct helvars {
		integer Hel[4];
	} helvars_;

typedef struct hel_comb{
	struct{
  		integer Hel[4];
  	};
}hel_comb;


#define seq(i) helvars.seq[i-1]
#define Hel(i) (double)((*helvars).Hel[i-1])


//From model_sm.c
#define MZ 91.1876
#define MZ2 MZ*MZ
#define MW 80.3990
#define MW2 (MW*MW)
#define CW (MW/MZ)
#define CW2 (CW*CW)
#define SW2 (1.0 - CW2)


//From C/util.h
#define Spinor(i,s,d) (s*Hel(i)+nvec*(i-1)+d+5)

void test(vectors_ *vectors){
	vec(1,1,1)=2.0;
}

void test2(helvars_ *h){

}


/*void abbr0h(vectors_ *vectors,var0h_ *var0h,helvars_ *helvars) {*/
void abbr0h(vectors_ *vectors,var0h_ *var0h,__global hel_comb *helvars) {

	//BE AWARE OF MULTIPLICATION RULE!!!!.
	//as long no mult of two c numbers all goes fine.
	F3 = -(ChainV0(Spinor(1,-1,2),0,0,Spinor(3,-1,1),vectors)*(Hel(1))*Hel(3));

	F5 = ChainV0(Spinor(1,-1,2),0,1,Spinor(4,1,2),vectors)*Hel(1);

	F1 = -(ChainB0(Spinor(1,-1,2),0,0,Spinor(3,-1,1),vectors)*Hel(1)*
			Hel(3));

	F7 = -(ChainB0(Spinor(1,-1,2),0,1,Spinor(4,1,2),vectors)*Hel(1));

	F8 = -(ChainV0(Spinor(2,1,1),1,0,Spinor(3,-1,1),vectors)*Hel(3));

	F6 = ChainB0(Spinor(2,1,1),1,0,Spinor(3,-1,1),vectors)*Hel(3);

	F2 = ChainV0(Spinor(4,1,2),0,0,Spinor(2,1,1),vectors);

	F4 = ChainB0(Spinor(4,1,2),0,0,Spinor(2,1,1),vectors);

	Sub1 = cmult((ctype)(1/SW2,0),2*cmult((ctype)(SW2,0),(cmult(F1,F2))) + cmult((ctype)(-1 + 2*SW2,0),cmult(F5,F6)));

	Sub2 = cmult((ctype)((4 - 8*SW2),0),cmult(F3,F4)) - 8*cmult((ctype)(SW2,0),cmult(F7,F8)) + cmult((ctype)((3 - 4*SW2),0),Sub1);

	Sub3 = cmult(F1,F2) + cmult(F3,F4) + cmult(F5,F6) + cmult(F7,F8);

}


//From const.h
#define Alfa (1/137.035999679)
#define Pi 3.1415926535897932384626433832795029


/*//From vars.h*/
typedef struct kinvars {
	RealType S, T, U;
} kinvars_;
#define S (*kinvars).S
#define T (*kinvars).T
#define U (*kinvars).U

/*//From SquaredME.c*/
void born(ctype *Ctree,var0h_ *var0h,__global kinvars_ *kinvars){
	*Ctree = *Ctree + cmult((ctype)(Alfa*Pi,0),-cmult((ctype)(2/(3.*CW2),0),cdiv(Sub2,(ctype)(-MZ2 + S,0))) + cmult(Sub3, (ctype) (16/(3.*S),0)));
}

#undef S
/*#define S (kinvars).S*/

#undef Hel(i)
#define Hel(i) (helvars).Hel[i-1]

#undef vec(i,j,n)
#define vec(i,j,n) (vectors).vec[n][j-1][i-1]

typedef struct{
	RealType r,i;
}comp;

typedef struct{
	comp c[LEGS*nvec+1][2][2];
}port_vec;

/*__kernel void simple_return(__global ComplexType *A,__global ComplexType *B){*/
/*__kernel void simple_return(__global port_vec *portvec,__global hel_comb *h,__global kinvars_ *k,__global comp *res){*/
__kernel void simple_return(__global ComplexType *IN,__global ComplexType *OUT){


	/*__local double a;*/
	/*a = 0;*/
	/*__local double b;*/
	/*b = 0;*/
	/*IN[0].re = 1.0;*/
	/*IN[0].im *= 2.0;*/
	int num_CC_in =500;
	int i,j;
	/*__local ComplexType b[500];*/
	/*for(i=0;i<num_CC_in;i++){*/
	/*b[i] = IN[i];*/
	/*}*/
	/*async_work_group_copy((__local unsigned int*)&b, */
	/*(__global unsigned int*)IN, */
	/*num_CC_in*sizeof(ComplexType) / sizeof(unsigned int),*/
	/*0); */
	/**b = *IN;*/
	int gid = get_global_id(0);
	int lid = get_local_id(0);
	int ggid = get_group_id(0);

	int runs = 4000;

	__local double a[1024];
	a[gid] = 1;
	for(i = 0; i< runs; i++){
	/*for(j = 0; j< runs; j++){*/
	/*a = a *b[(i*gid)%(num_CC_in)].re;*/
		a[gid] = a[gid] *IN[(i*gid)%(num_CC_in)].re;
	}
	/*}*/
	/*for(i = 0; i< runs; i++){*/
	/*for(j = 0; j< runs; j++){*/
			/*a = a *b[(i*j)%(400)].re;*/
	/*a = a *IN[(i*j)%(num_CC_in)].re;*/
	/*}*/
	/*}*/
	/*a = IN[0].re;*/
	/*OUT[0].re = b[0].re;*/
	//OUT[0].re = a;

	/**//*int t = gid%lid;*/
	/**//*a *=2;*/
	/*switch(lid)*/
	/*{*/
	/*case 0:*/
	/*a = 2;*/
	/*break;*/
	/*case 1:*/
	/*b =3;*/
	/*break;*/
	/*}*/
	/*barrier(CLK_GLOBAL_MEM_FENCE);*/
	/*switch(lid)*/
	/*{*/
	/*case 0:*/
	/*a = 2*b;*/
	/*break;*/
	/*case 1:*/
	/**//*a = 2*b;*/
	/*break;*/
	/**//*b = 3*a;*/
	/*}*/

	/*OUT[0].re =IN[0].re + IN[0].im;*/
	/**//*OUT[0].im =IN[0].im;*/
	/**//*OUT[0].im = get_local_size(0);*/

	/**//*OUT[gid].im = ggid;*/
	/*OUT[gid].im = a;*/


	/*barrier(CLK_GLOBAL_MEM_FENCE);*/
	/*if(ggid ==0) OUT[0].im = a;*/
	/*if(ggid ==1) OUT[0].im = 0;*/
	/*barrier(CLK_GLOBAL_MEM_FENCE);*/
	/*else OUT[0].im = 0;*/

	//NO GLOBAL VARS!
	//vector_ vec initialisation here
	//
	//No malloc!

	/*vectors_ vectors;*/
	/*int i;*/
	/*for (i = 0; i < LEGS*nvec+1;i++){*/
	/*vec(1,1,i) =(ctype) ((*portvec).c[i][0][0].r,(*portvec).c[i][0][0].i);*/
	/*vec(2,1,i) = (ctype)((*portvec).c[i][0][1].r,(*portvec).c[i][0][1].i);*/
	/*vec(1,2,i) = (ctype)((*portvec).c[i][1][0].r,(*portvec).c[i][1][0].i);*/
	/*vec(2,2,i) = (ctype)((*portvec).c[i][1][1].r,(*portvec).c[i][1][1].i);*/
	/*}*/
	/*ctype ctree;*/
	/*var0h_ var0h[15];*/


	/*int gid = get_global_id(0);*/


	/*abbr0h(&vectors,&(var0h[gid]),&(h[gid]));*/
	/*born(&(ctree[0]),&(var0h[gid]),k);*/
	/*abbr0h(&vectors,&(var0h),&(h[gid]));*/
	/*born(&(ctree),&(var0h),k);*/

	/*(res[gid]).r=(ctree).x;*/
	/*(res[gid]).i=(ctree).y;*/
	/*res[0].r += (ctree.x) * (ctree.x) -(ctree.y) * (ctree.y);*/
	/*(res[gid]).i=2;*/
	/*(res[0]).r=(float)(h->a).Hel[0];*/
	/*(res[gid]).r=(ctree[gid]).x;*/
	/*(res[gid]).i=(ctree[gid]).y;*/

}


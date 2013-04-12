#if 0
	util.h
	prototypes for the util functions
	this file is part of FormCalc
	last modified 11 Apr 13 th
#endif


#ifndef LEGS
#define LEGS 1
#endif

enum { nvec = 8 };

struct {
  ComplexType vec[LEGS*nvec+1][2][2];
} vec_;

#define vec(i,j,n) vec_.vec[n][j-1][i-1]

#define k0(i) (1+nvec*(i-1))
#define s0(i) (3+nvec*(i-1))
#define e0(i) (3+Hel(i)+nvec*(i-1))
#define ec0(i) (3-Hel(i)+nvec*(i-1))
#define Spinor0(i,d) (Hel(i)+d+5+nvec*(i-1))

#ifdef VECTORIZED

enum { nsse = 1, nves = 6 };
typedef ComplexType HelType;
	// 1) HelType must syntactically allow scalar multiplication
	// 2) nsse must fulfill sizeof(HelType) = nsse*sizeof(ComplexType)

struct {
  HelType ves[LEGS*nves+1][2][2];
} ves_;

#define ves(i,j,n) ves_.ves[n][j-1][i-1]

#define k(i) (1+nves*(i-1))
#define s(i) (2+nves*(i-1))
#define e(i) (3+nves*(i-1))
#define ec(i) (4+nves*(i-1))
#define Spinor(i,d) (4+d+nves*(i-1))

#define Vec(x,y,i) ves(x,y,i)
#define bVec ves(1,1,1)
#define eVec ves_end

#if NOUNDERSCORE
#define veccopyhel_ veccopyhel
#endif

extern void veccopyhel_(cint *v, cint *n, cint *hel);

#define VEC_DECL int v
#define VEC_INI v = 1
#define VEC_INC v = v % nsse + 1
#define VEC_EXEC(cmd) if( v == 1 ) cmd
#define VEC_FINAL(cmd) if( v != 1 ) cmd
#define VEC_COPY(hel) veccopyhel_(&v, (int[]){LEGS}, hel)

#else

typedef ComplexType HelType;

#define k k0
#define s s0
#define e e0
#define ec ec0
#define Spinor Spinor0
#define Vec(x,y,i) vec(x,y,i)
#define bVec vec(1,1,1)
#define eVec vec_end
#define VEC_DECL
#define VEC_INI
#define VEC_INC
#define VEC_COPY(hel)
#define VEC_EXEC(cmd) cmd
#define VEC_FINAL(cmd)

#endif

typedef const HelType cHelType;

#define DEB(a,x) printf(a " (%.13lg,%.13lg)\n", Re(x), Im(x))
#define LOOP(var,from,to,step) for( var = from; var <= to; var += step ) {
#define ENDLOOP(var) }
#define TEST(i,b) if( *(i) & (1 << (b)) ) {
#define ENDTEST(i,b) }

#define BIT_RESET 0
#define BIT_LOOP 1
#define BIT_HEL(i) (5*(LEGS-i)+Hel(i)+2)
#define LOOP_HEL(h) for( h = -2; h <= 2; ++h ) {
#define ENDLOOP_HEL(h) }

#define INI_S(seq) clearcache()
#define INI_ANGLE(seq) markcache()
#define DEINI(seq) restorecache()

#define PAR_PREP(h,he, a,ae, s,se)
#define PAR_EXEC(f, res, flags) f(res, flags)
#define PAR_SYNC(res)


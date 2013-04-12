* util.h
* prototypes for the util functions
* this file is part of FormCalc
* last modified 10 Apr 13 th


#ifndef LEGS
#define LEGS 1
#endif

	integer nvec
	parameter (nvec = 8)

* vec(...,0) is q1 in num.h
	ComplexType vec(2,2,0:nvec*LEGS), vec_end(0)
	common /vec/ vec, vec_end

#ifdef VECTORIZED
	integer nsse, nves
	parameter (nsse = 2, nves = 6)

	ComplexType ves(nsse,2,2,0:nves*LEGS), ves_end(0)
	common /ves/ ves, ves_end
#endif

	RealType momspec(12,LEGS)
	common /momspec/ momspec

* encoding base for momenta
	integer*8 JK
	parameter (JK = 256)


#ifndef SPEC_M

#define SPEC_M 1
#define SPEC_K 2
#define SPEC_E 3
#define SPEC_KT 4
#define SPEC_ET 5
#define SPEC_PRAP 6
#define SPEC_RAP 7
#define SPEC_DELTAK 8
#define SPEC_PHI 9
#define SPEC_EX 10
#define SPEC_EY 11
#define SPEC_EZ 12

#define k0(i) (1+nvec*(i-1))
#define s0(i) (3+nvec*(i-1))
#define e0(i) (3+Hel(i)+nvec*(i-1))
#define ec0(i) (3-Hel(i)+nvec*(i-1))
#define Spinor0(i,d) (Hel(i)+d+5+nvec*(i-1))

#ifdef VECTORIZED
#define k(i) (1+nves*(i-1))
#define s(i) (2+nves*(i-1))
#define e(i) (3+nves*(i-1))
#define ec(i) (4+nves*(i-1))
#define Spinor(i,d) (4+d+nves*(i-1))
#define Vec(x,y,i) ves(1,x,y,i)
#define bVec ves(1,1,1,1)
#define eVec ves_end
#define VEC_DECL integer v
#define VEC_INI v = 1
#define VEC_INC v = mod(v, nsse) + 1
#define VEC_EXEC(cmd) if( v .eq. 1 ) cmd
#define VEC_FINAL(cmd) if( v .ne. 1 ) cmd
#define VEC_COPY(hel) call VecCopyHel(v, LEGS, hel)
#else
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
#define VEC_EXEC(cmd) cmd
#define VEC_FINAL(cmd)
#define VEC_COPY(hel)
#endif

#define MomEncoding(f,i) iand(f,JK-1)*JK**(i-1)

#define Digit(i) char(i+48)
#define Polar(r,theta) r*exp(cI*degree*theta)

#define Error(err,msg) call m_(err, __LINE__, __FILE__, msg)
#define Warning(msg) call m_(0, 0, __FILE__, msg)
#define INFO print *,
#define DEB(a,x) print *, a, x
#define LOOP(var,from,to,step) do var = from, to, step
#define ENDLOOP(var) enddo
#define TEST(i,b) if( btest(i,b) ) then
#define ENDTEST(i,b) endif

#define BIT_RESET 0
#define BIT_LOOP 1
#define BIT_HEL(i) (5*(LEGS-i)+Hel(i)+2)
#define LOOP_HEL(h) do h = -2, 2
#define ENDLOOP_HEL(h) enddo

#define INI_S(seq) call clearcache
#define INI_ANGLE(seq) call markcache
#define DEINI(seq) call restorecache

#ifdef PARALLEL
#define PAR_PREP(h,he, a,ae, s,se) call sqmeprep(bVec,eVec, h,he, a,ae, s,se)
#define PAR_EXEC(f, res, flags) call sqmeexec(f, res, flags)
#define PAR_SYNC(res) call sqmesync(res)
#else
#define PAR_PREP(h,he, a,ae, s,se)
#define PAR_EXEC(f, res, flags) call f(res, flags)
#define PAR_SYNC(res)
#endif

#define Cut(c,m) (m)*(c)

#define CUT_MIN 1
#define CUT_MAX 2

#define CUT_COSTH 4
#define CUT_COSTHCMS 16
#define CUT_COSTH_E 64
#define CUT_COSTH_K 65
#define CUT_MREM 256
#define CUT_MREM_E 1024
#define CUT_MREM_K 1025
#define CUT_MREM_ET 4096
#define CUT_MREM_KT 4097
#define CUT_MREM_RAP 16384
#define CUT_MREM_PRAP 16385

#endif


//#define CHECK

#if 0
* SquaredME.c
* assembly of squared matrix element
* generated by FormCalc 8.1 on 6-Apr-2013 23:49
#endif

#include <math.h>
#include "vars.h"
#include "varsAVX.h"
#include "inline.h"

#include <sys/time.h>


#if NOUNDERSCORE
#define SquaredME squaredme
#else
#define SquaredME squaredme_
#endif

int HEL_COMB_DONE = 0;

void abbrhAVX(double *a, double *b);

void abbr0s(void);
void abbr1s(void);
void abbr0a(void);
void abbr1a(void);
void abbr0h(void);
void abbr1h1(void);
void abbr1h2(void);
void abbr1h3(void);
void abbr1h4(void);
void abbr1h5(void);
void abbr1h6(void);
void abbr1h7(void);
void abbr1h8(void);
void abbr1h9(void);
void abbr1h10(void);
void abbr1h11(void);
void abbr1h12(void);
void abbr1h13(void);
void abbr1h14(void);
void abbr1h15(void);
void abbr1h16(void);
void abbr1h17(void);
void abbr1h18(void);
void born(void);
void self(void);
void self_Gen6(void);
void vert(void);
void vert_Gen6(void);
void box(void);

struct formfactors formfactors = {
  .MatSUN[0 ... 0][0 ... 0] = NAN };

/**********************************************************************/

static RealType sumup(ComplexType CCloop[1],
  ComplexType CCtree[1]) {

#include "vars.h"

  ComplexType s = 0;

  ComplexType m = 0;
  m += CCloop[1-1]*MatSUN(1,1);
  s += Re(Conjugate(CCtree[1-1])*m);
  return s;
}

/**********************************************************************/

void SquaredMEHel(RealType *result, int *flags) {

#include "vars.h"

// BEGIN ABBR_HEL
  abbr0h();
  TEST(flags, BIT_LOOP)
  abbr1h1();
  abbr1h2();
  abbr1h3();
  abbr1h4();
  abbr1h5();
  abbr1h6();
  abbr1h7();
  abbr1h8();
  abbr1h9();
  abbr1h10();
  abbr1h11();
  abbr1h12();
  abbr1h13();
  abbr1h14();
  abbr1h15();
  abbr1h16();
  abbr1h17();
  abbr1h18();
  ENDTEST(flags, BIT_LOOP)
// END ABBR_HEL

// BEGIN FF_INI
  Ctree(1) = 0;

  Cloop(1) = 0;
// END FF_INI

// BEGIN FF_TREE
  born();

  result[0] += sumup(formfactors.Ctree, formfactors.Ctree);
// END FF_TREE

  TEST(flags, BIT_LOOP)
// BEGIN FF_LOOP
  self();
  vert();
  box();

  LOOP(Gen6, 1,3,1)
  self_Gen6();
  vert_Gen6();
  ENDLOOP(Gen6)

  result[1] += 2*sumup(formfactors.Cloop, formfactors.Ctree);
// END FF_LOOP
  ENDTEST(flags, BIT_LOOP)
}

/**********************************************************************/

void SquaredME(RealType *result, long long int *helicities, int *flags) {

#include "vars.h"

// BEGIN VARDECL
  int Hel1, Hel2, Hel3, Hel4, Hel5;
// END VARDECL

#include "inline.h"
  if(!HEL_COMB_DONE){
 	create_hel_mask(helicities);
	HEL_COMB_DONE =1;
  }

  PREP(seq,seq_end, vec,vec_end, varangle,varangle_end, vars,vars_end);

// BEGIN INVARIANTS
  S = SInvariant(k(1),k(2));
  T = TInvariant(k(1),k(3));
  T14 = TInvariant(k(1),k(4));
  U = TInvariant(k(2),k(3));
  T24 = TInvariant(k(2),k(4));
  S34 = SInvariant(k(3),k(4));
// END INVARIANTS

  TEST(flags, BIT_RESET)
// BEGIN ABBR_S
  ++seq(1);
  INI_S(seq);
  abbr0s();
  TEST(flags, BIT_LOOP)
  abbr1s();
  ENDTEST(flags, BIT_LOOP)
// END ABBR_S
  ENDTEST(flags, BIT_RESET)

// BEGIN ABBR_ANGLE
  ++seq(2);
  INI_ANGLE(seq);
  abbr0a();
  TEST(flags, BIT_LOOP)
  abbr1a();
  ENDTEST(flags, BIT_LOOP)
// END ABBR_ANGLE

// BEGIN RES_INI
  result[0] = 0;
  result[1] = 0;
// END RES_INI
  struct timeval t0,t1,t2;

int runs = 1;
int counter;
gettimeofday(&t0, 0);

#if 1
for(counter = 0;counter<runs;counter++){
  result[0] = 0;
  result[1] = 0;
// BEGIN HEL_LOOPS
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

  EXEC(SquaredMEHel, result, flags);

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
// END HEL_LOOPS
 

#endif

gettimeofday(&t1, 0);


  double tree[1];
  double loop[1];



  for(counter = 0;counter<runs;counter++){
	  abbrhAVX(tree,loop);
  }

  /*result[0] = tree[0];*/
  /*result[1] = loop[0];*/

  SYNC(result);
  DEINI(seq);

  gettimeofday(&t2, 0);

  long elapsed1 = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;
  long elapsed2 = (t2.tv_sec-t1.tv_sec)*1000000 + t2.tv_usec-t1.tv_usec;

  fprintf(stderr,"%f\n",(double)elapsed1/(double)(runs*1000)); // in ms
  fprintf(stderr,"%f\n",(double)elapsed2/(double)(runs*1000));

  fprintf(stderr,"NSSE %.20f\n",result[0]);
  fprintf(stderr,"NSSE %.20f\n",result[1]);
  fprintf(stderr,"SSE  %.20f\n",tree[0]);
  fprintf(stderr,"SSE  %.20f\n",loop[0]);

  printf("Please press <ENTER> to continue.");
  while(getchar() != '\n');

  /*abbrhAVX(tree,loop);*/
  /*fprintf(stderr,"SSE  %.20f\n",tree[0]);*/

  /*exit(0);*/


#ifdef CHECK
  printf("S = %g\n", S);
  printf("T = %g\n", T);
  printf("T14 = %g\n", T14);
  printf("U = %g\n", U);
  printf("T24 = %g\n", T24);
  printf("S34 = %g\n", S34);
  printf("tree = (%g,%g)\n",  Re(result[0]), Im(result[0]));
  printf("loop = (%g,%g)\n",  Re(result[1]), Im(result[1]));
  exit(1);
#endif

// END SQUAREDME
}

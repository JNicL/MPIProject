#if 0
* renconst.h
* RC declarations
* generated by FormCalc 8.2 on 11-Apr-2013 22:38
#endif

struct renconst {
  ComplexType dMWsq1, dMZsq1, dSW1, dZAA1, dZAZ1, dZe1, dZZA1;
  ComplexType dZZZ1, dZfL1[3][3][3], dZfR1[3][3][3];
} renconst;

#define dMWsq1 renconst.dMWsq1
#define dMZsq1 renconst.dMZsq1
#define dSW1 renconst.dSW1
#define dZAA1 renconst.dZAA1
#define dZAZ1 renconst.dZAZ1
#define dZe1 renconst.dZe1
#define dZZA1 renconst.dZZA1
#define dZZZ1 renconst.dZZZ1
#define dZfL1(i,j,k) renconst.dZfL1[k-1][j-1][i-1]
#define dZfR1(i,j,k) renconst.dZfR1[k-1][j-1][i-1]



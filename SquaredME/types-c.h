/*
  types-c.h
  real-based type declarations
  this file is part of FormCalc
  last modified 22 May 11 th
*/


#ifndef TYPES_H
#define TYPES_H

#ifdef QUAD
/*#define RealType long double*/
/*#define Re creall*/
/*#define Im cimagl*/
/*#define Conjugate conjl*/
#define parameter 
#else
/*#define RealType long double*/
/*#define Re creal*/
/*#define Im cimag*/
/*#define Conjugate conj*/
#define parameter
#endif

typedef int integer;
/*typedef RealType complex ComplexType;*/

/*ComplexType operator+(RealType a,ComplexType b){*/
/*ComplexType ret;*/
/*ret = b+ ToComplex2(a,0.0);*/
/*return b;*/
/*}*/
/*ComplexType operator*(RealType a,ComplexType b){*/
/*ComplexType ret;*/
/*ret = ToComplex2(a,0.0)*b;*/
/*return b;*/
/*}*/

/*#define ToComplex(r,i) ((r) + I*(i))*/
#define Sq(c) Re((c)*Conjugate(c))

#endif


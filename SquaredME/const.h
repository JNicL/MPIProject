/*const.h*/

	RealType pi, degree, sqrt2, hbar_c2;

	parameter pi = (3.1415926535897932384626433832795029E0);
	parameter degree = pi/180E0;
	parameter sqrt2 = 1.41421356237309504880168872421E0;

	parameter (hbar_c2 = 3.8937966E8);
  /**         = hbar c^2 in picobarn*/

	ComplexType bogus, cI;

	parameter bogus = ToComplex2(-1E123, -2E123);
  /**	  some weird number likely to noticeably distort the final result;*/
  /**	  used for initializing arrays to check that all components*/
  /**	  have been calculated*/

	parameter cI = ToComplex2(0E0, 1E0);
	struct{
	  RealType Divergence, mudim, lambda, muscale;
	  integer epscoeff, Finite;
	}renorm;
#define Finite renorm.Finite
#define epscoeff renorm.epscoeff
#define Divergence renorm.Divergence
#define mudim renorm.mudim
#define lambda renorm.lambda
#define muscale renorm.muscale

	struct{
	  RealType rootsvalue, imode;
	}cuttools_para;

#define rootsvalue cuttools_para.rootsvalue
#define imode cuttools_para.imode


//2 component vector to hold the real and imaginary parts of a complex number:

typedef double2 ctype;

#define I ((ctype)(0.0, 1.0))


/*
 * Return Real (Imaginary) component of complex number:
 */
inline float  real(ctype a){
     return a.x;
}
inline float  imag(ctype a){
     return a.y;
}

/*
 * Get the modulus of a complex number (its length):
 */
inline float cmod(ctype a){
    return (sqrt(a.x*a.x + a.y*a.y));
}

/*
 * Get the argument of a complex number (its angle):
 * http://en.wikipedia.org/wiki/Complex_number#Absolute_value_and_argument
 */
inline float carg(ctype a){
    if(a.x > 0){
        return atan(a.y / a.x);

    }else if(a.x < 0 && a.y >= 0){
        return atan(a.y / a.x) + M_PI;

    }else if(a.x < 0 && a.y < 0){
        return atan(a.y / a.x) - M_PI;

    }else if(a.x == 0 && a.y > 0){
        return M_PI/2;

    }else if(a.x == 0 && a.y < 0){
        return -M_PI/2;

    }else{
        return 0;
    }
}

/*
 * Multiply two complex numbers:
 *
 *  a = (aReal + I*aImag)
 *  b = (bReal + I*bImag)
 *  a * b = (aReal + I*aImag) * (bReal + I*bImag)
 *        = aReal*bReal +I*aReal*bImag +I*aImag*bReal +I^2*aImag*bImag
 *        = (aReal*bReal - aImag*bImag) + I*(aReal*bImag + aImag*bReal)
 */
inline ctype  cmult(ctype a, ctype b){
    return (ctype)( a.x*b.x - a.y*b.y, a.x*b.y + a.y*b.x);
}


/*
 * Divide two complex numbers:
 *
 *  aReal + I*aImag     (aReal + I*aImag) * (bReal - I*bImag)
 * ----------------- = ---------------------------------------
 *  bReal + I*bImag     (bReal + I*bImag) * (bReal - I*bImag)
 * 
 *        aReal*bReal - I*aReal*bImag + I*aImag*bReal - I^2*aImag*bImag
 *     = ---------------------------------------------------------------
 *            bReal^2 - I*bReal*bImag + I*bImag*bReal  -I^2*bImag^2
 * 
 *        aReal*bReal + aImag*bImag         aImag*bReal - Real*bImag 
 *     = ---------------------------- + I* --------------------------
 *            bReal^2 + bImag^2                bReal^2 + bImag^2
 * 
 */
/*inline ctype cdiv(ctype a, cfloat b){*/
/*return (ctype)((a.x*b.x + a.y*b.y)/(b.x*b.x + b.y*b.y), (a.y*b.x - a.x*b.y)/(b.x*b.x + b.y*b.y));*/
/*}*/


/*
 *  Square root of complex number.
 *  Although a complex number has two square roots, numerically we will
 *  only determine one of them -the principal square root, see wikipedia
 *  for more info: 
 *  http://en.wikipedia.org/wiki/Square_root#Principal_square_root_of_a_complex_number
 */
 inline ctype csqrt(ctype a){
     return (ctype)( sqrt(cmod(a)) * cos(carg(a)/2),  sqrt(cmod(a)) * sin(carg(a)/2));
 }

inline ctype cdiv(ctype a,ctype b){
	/*double tmp =(a.x*b.x + a.y*b.y)/(b.x*b.x + b.y*b.y);*/
	/*double tmp2 = (a.y*b.x - a.x*b.y)/(b.x*b.x + b.y*b.y);*/
	return(ctype)((a.x*b.x + a.y*b.y)/(b.x*b.x + b.y*b.y),(a.y*b.x - a.x*b.y)/(b.x*b.x + b.y*b.y));

	/*return ret;*/
}

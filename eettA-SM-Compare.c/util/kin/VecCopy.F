* VecCopy.F
* set up the correct polarization vectors and spinors
* for a particular helicity combination
* this file is part of FormCalc
* last modified 9 Apr 13 th

#include "types.h"

#define VECTORIZED

* v: the SSE index
* n: the number of external particles
* Hel: the helicities

	subroutine VecCopy(n)
	implicit none
	integer n

#include "util.h"

	integer i, v, ka, kb, sa, sb

	do i = 1, n
	  ka = k0(i)
	  kb = k(i)
	  sa = s0(i)
	  sb = s(i)

	  do v = 1, nsse
	    ves(v,1,1,kb) = vec(1,1,ka)
	  enddo
	  do v = 1, nsse
	    ves(v,2,1,kb) = vec(2,1,ka)
	  enddo
	  do v = 1, nsse
	    ves(v,1,2,kb) = vec(1,2,ka)
	  enddo
	  do v = 1, nsse
	    ves(v,2,2,kb) = vec(2,2,ka)
	  enddo

	  do v = 1, nsse
	    ves(v,1,1,sb) = vec(1,1,sa)
	  enddo
	  do v = 1, nsse
	    ves(v,2,1,sb) = vec(2,1,sa)
	  enddo
	  do v = 1, nsse
	    ves(v,1,2,sb) = vec(1,2,sa)
	  enddo
	  do v = 1, nsse
	    ves(v,2,2,sb) = vec(2,2,sa)
	  enddo
	enddo
	end


************************************************************************

	subroutine VecCopyHel(v, n, Hel)
	implicit none
	integer v, n, Hel(*)

#include "util.h"

	integer i, a, b

	do i = 1, n
	  a = e0(i)
	  b = e(i)
	  ves(v,1,1,b) = vec(1,1,a)
	  ves(v,2,1,b) = vec(2,1,a)
	  ves(v,1,2,b) = vec(1,2,a)
	  ves(v,2,2,b) = vec(2,2,a)

	  a = ec0(i)
	  b = ec(i)
	  ves(v,1,1,b) = vec(1,1,a)
	  ves(v,2,1,b) = vec(2,1,a)
	  ves(v,1,2,b) = vec(1,2,a)
	  ves(v,2,2,b) = vec(2,2,a)

	  a = Spinor0(i,1)
	  b = Spinor(i,1)
	  ves(v,1,1,b) = vec(1,1,a)
	  ves(v,2,1,b) = vec(2,1,a)
	  ves(v,1,2,b) = vec(1,2,a)
	  ves(v,2,2,b) = vec(2,2,a)

	  a = Spinor0(i,2)
	  b = Spinor(i,2)
	  ves(v,1,1,b) = vec(1,1,a)
	  ves(v,2,1,b) = vec(2,1,a)
	  ves(v,1,2,b) = vec(1,2,a)
	  ves(v,2,2,b) = vec(2,2,a)
	enddo
	end


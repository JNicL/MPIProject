program test
  POINTER e
	REAL a,b,c,d
  common a,b,c
 
  call sub
	write(*,*) a,b,c
end program

subroutine sub
  real x,y,z
  common x,y,z
  x=3.3
  z=4.4
end

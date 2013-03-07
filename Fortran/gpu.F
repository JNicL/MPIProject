#define a b
#define GPU_C 1
#ifdef GPU_C
#define functor(f,k) call ex(f,k)
#else
#define functor(f,k) call f(k) 
#endif
        program gpu
                implicit none
                integer :: i
                external func
                i=3
C                call test
                functor(func,i)
!          call func(i)

                write (*,*) i
        end

        subroutine func(i)
                implicit none
                integer :: i 

                write (*,*) 'Called func'
                i=i*2
        end

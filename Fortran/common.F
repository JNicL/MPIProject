#define marker double precision
        program com
                implicit none

                marker b0s(0)
                common /vars/ b0s
C                b0s=1.
                loc(b0s(0))
                call test
        end
        
        subroutine test
                implicit none
                marker b0s(0)
                common /vars/ b0s
                
                write (*,*) b0s

        end




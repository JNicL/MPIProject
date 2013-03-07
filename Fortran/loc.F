        PROGRAM Vector
        implicit none
C        integer(8) addr1, addr2
        real b(0)
        real, pointer :: p1
C        real, target :: t1
        integer  array(6)
        data  array /0,1,2,3,4,5/
        p1=>b(0)
C        t1 = 42
        write (*,*) p1
C        addr1 = loc(p1)
C        addr2 = loc(t1)
C        write (*,*) addr1, addr2
C        write (*,*) loc(b)
        END

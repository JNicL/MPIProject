# --- variables defined by configure ---

SRC = .
PREFIX = x86_64-Linux
LIBDIRSUFFIX = 64

EXE = 
DEF = -D

LT = ../../../LoopTools/x86_64-Linux/lib64
CT = 
SAMURAI = 
STDLIBS =  -L$(LT) -looptools -L/usr/local/lib64 -lFH -L/usr/local/lib64 -Wl,-rpath,/usr/local/lib64 -lLHAPDF
LDFLAGS = -lpthread -Wl,/opt/PGI/pgi-13.3/linux86-64/13.3/lib/pgi.ld -L/opt/PGI/share/13.3/lib64 -L/opt/PGI/pgi-13.3/linux86-64/13.3/lib -L/usr/lib64 -L/usr/lib64/gcc/x86_64-suse-linux/4.7 -L/usr/lib64/gcc-lib/x86_64-suse-linux/3.3.3-hammer/ -Wl,-rpath,/opt/PGI/share/13.3/lib64 -Wl,-rpath,/opt/PGI/pgi-13.3/linux86-64/13.3/lib -lpgmp -lnuma -lpthread -lpgftnrtl -lpgmp -lnspgc -lpgc -lrt -lpthread -lgfortran -lm

FC = pgf77
FFLAGS = -O3 -g  -Mextend -Minform=inform -g77libs   $(DEF)U77EXT=1 

CC = gcc
CFLAGS = -O3 -g -std=gnu99 -fomit-frame-pointer -ffast-math -march=corei7-avx -m64  

CXX = g++
CXXFLAGS =  -m64  

MCFLAGS =   -b64

# --- end defs by configure ---


# makefile.in
# makefile template used by configure
# this file is part of FormCalc
# last modified 18 Mar 13 th

# Note: make permanent changes only in makefile.in,
# changes in makefile will be overwritten by configure.


.PHONY: all force clean distclean

MAKECMDGOALS ?= run

MAKECMDGOALS := $(MAKECMDGOALS:%=%$(EXE))

all: $(MAKECMDGOALS)


PREFIX :=


DIR = $(SRC)/$(FOLDER)
LIB = $(FOLDER).a

LIBS :=

VPATH := $(LT)/../include:$(LT):$(CT)/../include:$(CT):$(SAMURAI)

FOLDER := squaredme
-include $(DIR)/makefile

FOLDER := renconst
-include $(DIR)/makefile

CLEANLIBS := $(LIBS)

FOLDER := util
-include $(DIR)/makefile


INCLUDE := $(patsubst %,-I%,$(subst :, ,$(VPATH)))
FINCLUDE = -I$(<D) -I$(SRC)/F $(INCLUDE)
CINCLUDE = -I$(<D) -I$(SRC)/C $(INCLUDE)

FFLAGS += $(FINCLUDE)
CFLAGS += $(CINCLUDE)

ifdef DEBUG
FFLAGS += -g $(DEF)DEBUG
CFLAGS += -g -DDEBUG
endif

export FC
export FFLAGS
export CC
export CFLAGS


DEPS := $(wildcard *.d)

clean:
	$(RM) $(DEPS) $(DEPS:%.d=%.o) $(DEPS:%.d=%$(EXE)) $(CLEANLIBS)

distclean:
	$(RM) $(DEPS) $(DEPS:%.d=%.o) $(DEPS:%.d=%$(EXE)) $(LIBS) makefile


define makedeps
( echo '#include "$<"' ; echo '#include "$<"' ) > deps.c
$(CPP) -M -I$(<D) $(INCLUDE) deps.c | sed 's|^.*: deps.c|$@:|' > $@
$(RM) deps.c
endef

-include Fdecl.d
-include Finline.d
-include Fnum.d

F%.d: $(SRC)/F/%.h renconst.h
	$(makedeps)

-include Cdecl.d
-include Cinline.d
-include Cnum.d

C%.d: $(SRC)/C/%.h renconst.h
	$(makedeps)


-include $(MAKECMDGOALS:%$(EXE)=%.d)
%.d: $(SRC)/%.F
	{ grep "^[^c*].*Mma" $< >/dev/null 2>&1 ; \
	  echo "MMA = $$?" ; \
	  echo "$*$(EXE): $@ $(LIBS)" ; \
	  $(CPP) -M $(FINCLUDE) -x c $< | sed 's|^.*:|$@:|' ; \
	} > $@

ifeq ($(MMA), 0)
%$(EXE):: $(SRC)/%.F %.d $(SRC)/tools/mktm
	$(SRC)/tools/mktm $<
	$(FC) $(FFLAGS) $(DEF)MMA $(DEF)PREFIX=$(PREFIX) -c $<
	CC="$(SRC)/tools/fcc" REALCC="$(CC) $(CFLAGS)" \
	CXX="$(SRC)/tools/f++" REALCXX="$(CXX) $(CXXFLAGS)" \
	  PATH="$(PATH):$(SRC)/tools" \
	  mcc $(MCFLAGS) -o $@ $*.tm $*.o $(LIBS) $(STDLIBS) $(LDFLAGS)
	-$(RM) $*.o $*.tm.c
else
%$(EXE):: $(SRC)/%.F %.d
	$(FC) $(FFLAGS) $(DEF)PREFIX=$(PREFIX) -o $@ $< $(LIBS) $(STDLIBS)
	-$(RM) $*.o
endif


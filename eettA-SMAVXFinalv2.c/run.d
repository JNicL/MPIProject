MMA = 1
run: run.d  squaredme.a renconst.a util.a
run.d: run.F F/main.F F/xsection.F F/decl.h F/types.h F/user.h F/inline.h \
 process.h F/2to3.F F/lumi_parton.F F/xsection.h F/const.h F/model_mssm.h \
 F/model_sm.h F/util.h \
 ../../../LoopTools/x86_64-Linux/lib64/../include/looptools.h \
 F/model_sm.F F/AlphaS.F

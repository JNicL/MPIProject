#if 0
* model_sm.h
#endif

	RealType CKMlambda,CKMA, CKMrhobar,CKMetabar;
	parameter (CKMlambda = .2253E0);
	parameter (CKMA = .808E0);
	parameter (CKMrhobar = .132E0);
	parameter (CKMetabar = .341E0);

	RealType MZ, MZ2, MW, MW2, CW, CW2, SW2;
	parameter (MZ = 91.1876E0, MZ2 = MZ*MZ);
	parameter (MW = 80.399E0, MW2 = MW*MW);
	parameter (CW = MW/MZ, CW2 = CW*CW);
	parameter (SW2 = 1 - CW2);

	RealType GF, Alfa, Alfa2, AlfaMZ, AlfasMZ;
	parameter (GF = 1.16637E-5);
	parameter (Alfa = 1/137.035999679E0, Alfa2 = Alfa*Alfa);
	/*c	parameter (Alfa = sqrt2/pi*GF*MW2*SW2, Alfa2 = Alfa**2);*/
	parameter (AlfaMZ = 1/127.934E0);
	parameter (AlfasMZ = .1184E0);

	RealType ME, ME2, MM, MM2, ML, ML2;
	parameter (ME = .510998910E-3, ME2 = ME*ME);
	parameter (MM = 105.658367E-3, MM2 = MM*MM);
	parameter (ML = 1776.82E-3, ML2 = ML*ML);

	RealType MU, MU2, MC, MC2, MT, MT2;
	parameter (MU = 53.8E-3, MU2 = MU*MU);
	parameter (MC = 1.27, MC2 = MC*MC);
	parameter (MT = 172.0, MT2 = MT*MT);

	RealType MD, MD2, MS, MS2, MB, MB2, MBatMB;
	parameter (MD = 53.8E-3, MD2 = MD*MD);
	parameter (MS = 101E-3, MS2 = MS*MS);
	parameter (MB = 4.67, MB2 = MB*MB);
	parameter (MBatMB = 4.25);


	struct{
	  ComplexType CKM[3][3];
	  RealType Mf[4][3], Mf2[4][3];
	  RealType MH, MH2;
	  RealType EL, GS, Alfas, Alfas2, SW;
	}modelpara;


#define CKM(i,j) modelpara.CKM[i-1][j-1]
#define MF(i,j) modelpara.MF[i-1][j-1]
#define MF2(i,j) modelpara.MF2[i-1][j-1]
#define MH modelpara.MH
#define MH2 modelpara.MH2
#define EL modelpara.EL
#define GS modelpara.GS
#define Alfas modelpara.Alfas
#define Alfas2 modelpara.Alfas2
#define SW modelpara.SW


#ifndef CKMC
#define CKMC(i,j) Conjugate(CKM(i,j))
#endif


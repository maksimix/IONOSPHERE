/* msise90.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    real tlb, s, db04, db16, db28, db32, db40, db48, db01, za, t0, z0, g0, rl,
	     dd, db14, tr12;
} gts3c_;

#define gts3c_1 gts3c_

struct {
    real tn1[5], tn2[4], tn3[5], tgn1[2], tgn2[2], tgn3[2];
} meso6_;

#define meso6_1 meso6_

struct lower6_1_ {
    real ptm[10], pdm[80]	/* was [10][8] */;
};

#define lower6_1 (*(struct lower6_1_ *) &lower6_)

struct parm6_1_ {
    real pt[150], pd[1350]	/* was [150][9] */, ps[150], pdl[50]	/* 
	    was [25][2] */, ptl[400]	/* was [100][4] */, pma[1000]	/* 
	    was [100][10] */;
};
struct parm6_2_ {
    real pt1[50], pt2[50], pt3[50], pa1[50], pa2[50], pa3[50], pb1[50], pb2[
	    50], pb3[50], pc1[50], pc2[50], pc3[50], pd1[50], pd2[50], pd3[50]
	    , pe1[50], pe2[50], pe3[50], pf1[50], pf2[50], pf3[50], pg1[50], 
	    pg2[50], pg3[50], ph1[50], ph2[50], ph3[50], pi1[50], pi2[50], 
	    pi3[50], pj1[50], pj2[50], pj3[50], pk1[50], pl1[50], pl2[50], 
	    pm1[50], pm2[50], pn1[50], pn2[50], po1[50], po2[50], pp1[50], 
	    pp2[50], pq1[50], pq2[50], pr1[50], pr2[50], ps1[50], ps2[50], 
	    pu1[50], pu2[50], pv1[50], pv2[50], pw1[50], pw2[50], px1[50], 
	    px2[50], py1[50], py2[50], pz1[50], pz2[50];
};

#define parm6_1 (*(struct parm6_1_ *) &parm6_)
#define parm6_2 (*(struct parm6_2_ *) &parm6_)

struct datim6_1_ {
    integer isd[3], ist[2], nam[2];
};
struct datim6_2_ {
    char isdate[12], istime[8], name__[8];
};

#define datim6_1 (*(struct datim6_1_ *) &datim6_)
#define datim6_2 (*(struct datim6_2_ *) &datim6_)

struct {
    integer isdate[3], istime[2], name__[2];
} datime_;

#define datime_1 datime_

struct {
    real sw[25];
    integer isw;
    real swc[25];
} csw_;

#define csw_1 csw_

struct mavg6_1_ {
    real pavgm[10];
};

#define mavg6_1 (*(struct mavg6_1_ *) &mavg6_)

struct {
    real dm04, dm16, dm28, dm32, dm40, dm01, dm14;
} dmix_;

#define dmix_1 dmix_

struct {
    real gsurf, re;
} parmb_;

#define parmb_1 parmb_

struct metsel_1_ {
    integer imr;
};

#define metsel_1 (*(struct metsel_1_ *) &metsel_)

union {
    struct {
	real tinfg, gb, rout, tt[15];
    } _1;
    struct {
	real tinf, gb, rout, t[15];
    } _2;
} ttest_;

#define ttest_1 (ttest_._1)
#define ttest_2 (ttest_._2)

union {
    struct {
	real plg[36]	/* was [9][4] */, ctloc, stloc, c2tloc, s2tloc, 
		c3tloc, s3tloc;
	integer iyr;
	real day, df, dfa, apd, apdf, apt[4], xlong, clong, slong;
    } _1;
    struct {
	real plg[36]	/* was [9][4] */, ctloc, stloc, c2tloc, s2tloc, 
		c3tloc, s3tloc;
	integer iyr;
	real day, df, dfa, apd, apdf, apt[4], long__, clong, slong;
    } _2;
} lpoly_;

#define lpoly_1 (lpoly_._1)
#define lpoly_2 (lpoly_._2)

struct {
    integer mp, ii, jg, lt;
    real qpb[50];
    integer ierr, ifun, n, j;
    real dv[60];
} lsqv_;

#define lsqv_1 lsqv_

struct {
    real taf;
} fit_;

#define fit_1 fit_

/* Initialized data */

struct {
    integer e_1;
    } metsel_ = { 0 };

struct {
    real e_1[90];
    } lower6_ = { (float)1041.3, (float)386., (float)195., (float)16.6728, (
	    float)213., (float)120., (float)240., (float)187., (float)-2., (
	    float)0., (float)2.456e7, (float)6.71072e-6, (float)100., (float)
	    0., (float)110., (float)10., (float)0., (float)0., (float)0., (
	    float)0., (float)8.594e10, (float).54, (float)105., (float)-8., (
	    float)110., (float)10., (float)90., (float)2., (float)0., (float)
	    0., (float)2.81e11, (float)0., (float)105., (float)28., (float)
	    28.95, (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)3.3e10, (float).26827, (float)105., (float)0., (float)110., 
	    (float)10., (float)0., (float)0., (float)0., (float)0., (float)
	    1.33e9, (float).0119615, (float)105., (float)0., (float)110., (
	    float)10., (float)0., (float)0., (float)0., (float)0., (float)
	    176100., (float)1., (float)95., (float)-8., (float)110., (float)
	    10., (float)90., (float)2., (float)0., (float)0., (float)1e7, (
	    float)1., (float)105., (float)-8., (float)110., (float)10., (
	    float)90., (float)2., (float)0., (float)0., (float)1e7, (float)1.,
	     (float)105., (float)-8., (float)110., (float)10., (float)90., (
	    float)2., (float)0., (float)0. };

struct {
    real e_1[3100];
    } parm6_ = { (float).99604, (float).0385528, (float).00303445, (float)
	    -.105531, (float)-.00607134, (float)-5.16278e-4, (float)-.115622, 
	    (float).0020224, (float).00990156, (float)-.127371, (float)
	    -.0302449, (float).0123512, (float)-.00526277, (float)-8.45398, (
	    float)0., (float).014237, (float)0., (float)125.818, (float)
	    .00805486, (float).00164419, (float)-6.21452e-6, (float).00311701,
	     (float)0., (float).00386578, (float).132397, (float).213315, (
	    float)0., (float)0., (float)0., (float)-6.4111e-6, (float)0., (
	    float)30.015, (float).00533297, (float).00389146, (float)
	    .00204725, (float)0., (float)0., (float)-.0192645, (float)2.75905,
	     (float).00147284, (float)3.41345e-4, (float)-.00117388, (float)
	    -3.54589e-4, (float).113139, (float).169134, (float).00508295, (
	    float)3.65016e-5, (float).00426385, (float)1.15102e-4, (float)
	    .00511819, (float).00609108, (float)4.04995e-5, (float).00153049, 
	    (float)2.4147e-5, (float).00230764, (float).00155267, (float)
	    .00133722, (float)-.00182318, (float)-263.007, (float)0., (float)
	    .00137337, (float)9.95774e-4, (float)0., (float)-108.983, (float)
	    .00562606, (float).00594053, (float).00109358, (float)0., (float)
	    -.013341, (float)-.0243409, (float)-.0135688, (float)31137., (
	    float)0., (float)0., (float)0., (float)-2830.23, (float)
	    8.45583e-4, (float)5.38706e-4, (float)0., (float)247.956, (float)
	    .00292246, (float)0., (float)0., (float)7.47703e-5, (float)
	    8.87993e-4, (float)0., (float)0., (float)0., (float)0., (float)0.,
	     (float)-.011654, (float)-.00449173, (float)-3.53189e-4, (float)
	    -1.73933e-4, (float)-1.53218e-4, (float)-.565411, (float)
	    .00777272, (float)-91.1784, (float)6.45187e-4, (float)0., (float)
	    -8.37685e-4, (float).00242318, (float).00473796, (float)
	    -.00301801, (float)-.00423564, (float)-.00248289, (float)
	    9.19286e-4, (float).00216372, (float)8.63968e-4, (float).00189689,
	     (float).00415654, (float)0., (float).0118068, (float).0033119, (
	    float)0., (float).00120222, (float)0., (float)0., (float)-3.07246,
	     (float)0., (float)0., (float)6.72403e-4, (float).0010893, (float)
	    9.72278e-4, (float)4.68242, (float)-3.15034e-4, (float).00400059, 
	    (float).00515036, (float).00162989, (float).00108824, (float)
	    9.95261e-4, (float)4.18955, (float)-.364059, (float).00170182, (
	    float)0., (float)0., (float)-3.2012, (float)0., (float).00580206, 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    1.04934, (float)-.0288362, (float)-.207095, (float)-.103314, (
	    float)-.00702373, (float).0129664, (float).408853, (float)
	    -.00919895, (float)-.018866, (float)1.40927, (float).175033, (
	    float).0187351, (float).110979, (float)-7.42871, (float)0., (
	    float).267143, (float)-.0595979, (float)105.038, (float)-.0840963,
	     (float)-6.97632e-4, (float)2.06521e-6, (float)7.65306e-4, (float)
	    0., (float)0., (float).126762, (float).128876, (float)-.0504479, (
	    float)-.0130735, (float)-.0224348, (float)0., (float)0., (float)
	    -150.832, (float)-.00629928, (float)0., (float)-.0040776, (float)
	    0., (float)0., (float).0525725, (float)-31.1486, (float)
	    -.00313351, (float).00275838, (float)0., (float)0., (float)
	    .111247, (float).108815, (float)-.0466713, (float)0., (float)
	    -.00329329, (float)0., (float).00167838, (float)-.00916691, (
	    float)3.45044e-5, (float)-.00971806, (float)0., (float)-.00204672,
	     (float)-.00786899, (float)-.00798285, (float).00536515, (float)
	    -5311.72, (float)0., (float)-.00642781, (float)-.0017169, (float)
	    0., (float)-67.9131, (float)-.0179912, (float)-.0158305, (float)
	    -.00712313, (float)0., (float).0253477, (float).085296, (float)
	    .102163, (float)29500.9, (float)0., (float)0., (float)0., (float)
	    -6846.25, (float)-.00619098, (float)-.00269289, (float)0., (float)
	    -520.231, (float)-.00633463, (float)0., (float)0., (float)
	    -.00602428, (float)-.00407077, (float).00542264, (float)0., (
	    float)0., (float)0., (float)0., (float).040756, (float).0282288, (
	    float).00908088, (float)0., (float)0., (float)-.405204, (float)
	    -.0597931, (float)-73.1823, (float)-.0020662, (float)0., (float)
	    -.00372723, (float)-.0188146, (float)-.0101794, (float).00804633, 
	    (float).010109, (float).00873253, (float).0238268, (float)
	    .00480444, (float).00171088, (float).0396369, (float)-.0213809, (
	    float)0., (float)-.102588, (float)-.00591702, (float)0., (float)
	    .00270923, (float)0., (float)0., (float)-175.043, (float).603489, 
	    (float)-.617589, (float).00838098, (float).00183871, (float)
	    -7.05329e-4, (float)-4.06644, (float)-.00509347, (float)-.0284344,
	     (float)-.012416, (float).0133665, (float).0039341, (float)
	    -5.03723e-4, (float)-4.57683, (float)-.529542, (float)-.00425812, 
	    (float)0., (float)0., (float)19.1541, (float)0., (float).00323247,
	     (float)0., (float)0., (float)0., (float)0., (float)0., (float)0.,
	     (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    .931113, (float)-.138721, (float)-.133457, (float)-.0529542, (
	    float)-.00444983, (float).0135264, (float).0598075, (float)
	    -.036288, (float)-.0312798, (float).372068, (float).0295974, (
	    float).0120509, (float).0521995, (float)-7.78888, (float)0., (
	    float).118634, (float)-.0204495, (float)103.28, (float).0982432, (
	    float)4.77694e-4, (float)0., (float).00274372, (float)0., (float)
	    0., (float).0757809, (float).171403, (float)-.0105205, (float)0., 
	    (float)0., (float)0., (float)0., (float)-8.73348, (float)
	    -.00581094, (float)0., (float)-.00814944, (float)0., (float)0., (
	    float).0517255, (float)-15.3028, (float)-.00348932, (float)
	    9.61771e-4, (float).00557732, (float)-4.5418e-4, (float).0988213, 
	    (float).0940456, (float)-.0318797, (float)0., (float)0., (float)
	    0., (float).00232122, (float)-.0060022, (float)2.77654e-5, (float)
	    -.00322019, (float)0., (float)-.00378551, (float)-.00334809, (
	    float)-.00170668, (float)0., (float)6361.84, (float)0., (float)
	    .00159986, (float)-.00388204, (float)-.00164825, (float)-74.7955, 
	    (float)-.010536, (float)-.00945723, (float)-.00159824, (float)
	    -7.0673e-4, (float)-.0168513, (float)-.113023, (float)-.0636637, (
	    float)-13770.9, (float)0., (float)0., (float)0., (float)-15236.8, 
	    (float)-.00586061, (float)-.00253108, (float)0., (float)-2548.37, 
	    (float)-.00328988, (float)0., (float)0., (float)-.00276364, (
	    float).00967923, (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float).0434255, (float).011402, (float)-.00618447, (
	    float)0., (float)0., (float)-.302568, (float)-.0327694, (float)
	    -67.1589, (float)-.0022834, (float)0., (float).0030623, (float)
	    -.00465113, (float)-.00973421, (float).0128326, (float).00788553, 
	    (float).00797197, (float)-.012076, (float)-.00767547, (float)
	    -.00120755, (float)-.0298523, (float)-.012656, (float)0., (float)
	    -.056835, (float)-.0153039, (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float).00242911, (
	    float)-.00401347, (float)-.00219074, (float)3.11281, (float)
	    .00323251, (float)-.00639523, (float)-.00663069, (float)
	    -3.04403e-4, (float)-.0040192, (float)-.00118708, (float)4.15211, 
	    (float)-.201896, (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)1.06903, (float)0., (float)0., (float).0036621, (
	    float)0., (float).0190412, (float)-.00178929, (float)0., (float)
	    -.0392257, (float)-.119444, (float)0., (float)0., (float)0., (
	    float)-8.45398, (float)0., (float).020818, (float)0., (float)
	    139.638, (float).0898481, (float)0., (float)0., (float)3.77113e-4,
	     (float)0., (float)0., (float).132397, (float).213315, (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)-23.6325, (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)-.00243022, (float)-3.99776e-6, (float).00632343,
	     (float).00548144, (float).113139, (float).169134, (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    2.4147e-5, (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float).976619, (float)0., (
	    float)0., (float)-.02002, (float)0., (float)-.00938391, (float)
	    -.00195833, (float)0., (float).013148, (float)-.0192414, (float)
	    0., (float)0., (float)0., (float)-8.45398, (float)0., (float)
	    .0107674, (float)0., (float)89.382, (float)0., (float)0., (float)
	    0., (float)5.68478e-4, (float)0., (float)0., (float).132397, (
	    float).213315, (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float).00466814, (float)0., (float)0., (float)
	    5.11651e-5, (float).00255717, (float)0., (float)0., (float)0., (
	    float)0., (float)-.00260147, (float)-8.08556e-4, (float).113139, (
	    float).169134, (float).00664196, (float)0., (float)0., (float)0., 
	    (float)0., (float).00582026, (float)2.4147e-5, (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float).00621998, (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float).931402, (float).137976, (float)0., (float)
	    3.23736e-4, (float)0., (float)-.00910906, (float).0707506, (float)
	    0., (float)-.051665, (float).0689755, (float)0., (float)0., (
	    float)0., (float)-8.45398, (float)0., (float).028114, (float)0., (
	    float)73.6009, (float).0596604, (float)0., (float)0., (float)
	    -.00151792, (float)0., (float)0., (float).132397, (float).213315, 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    9.48758, (float).00884541, (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float).113139, (float).169134, (float).0145192, (float)
	    0., (float)0., (float)0., (float)0., (float).0107906, (float)
	    2.99942e-5, (float)0., (float)0., (float)0., (float)0., (float)0.,
	     (float)0., (float)0., (float)0., (float)0., (float)0., (float)0.,
	     (float)0., (float)-.014893, (float)-.00787184, (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)-.068342, (
	    float)-.0441778, (float)0., (float)0., (float)0., (float)0., (
	    float).022973, (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float).868053, (float).236364, (float).134306, (float)
	    .0103086, (float)0., (float)-.00379164, (float)-.157806, (float)
	    0., (float)-.0587644, (float)-.312508, (float)0., (float).0437387,
	     (float)-.0354091, (float)-22.3636, (float)0., (float)-.0533976, (
	    float)0., (float)114.091, (float).0517497, (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float).132397, (float).213315, (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    342.702, (float).0157033, (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)-.00366278, (float)-.00116193, (
	    float)0., (float)0., (float).113139, (float).169134, (float)
	    .0178431, (float)0., (float)0., (float)0., (float)0., (float)
	    .0162864, (float)3.16963e-5, (float).0127968, (float)0., (float)
	    0., (float)-.00704599, (float).00207921, (float).0063666, (float)
	    22994., (float)0., (float).0127833, (float)-.00208036, (float)
	    -.0046182, (float)-62.9391, (float)-.0120745, (float).0136675, (
	    float).0136011, (float)-.00537162, (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)19250.9, (
	    float).00835522, (float).00419439, (float)0., (float)12036.6, (
	    float)0., (float)0., (float)0., (float)-.0100034, (float)
	    -.00233267, (float).00972374, (float)0., (float)0., (float)0., (
	    float)0., (float)-.0265079, (float)-.0209125, (float)-.0109465, (
	    float)0., (float)0., (float)0., (float).0217252, (float)-71.2385, 
	    (float)-.00189428, (float)0., (float)-.00602006, (float).0169058, 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float).0290646, (float).00348971, (float)0., (float)
	    .0501174, (float).0550595, (float)0., (float)-.00955897, (float)
	    0., (float)0., (float)-1516.93, (float)0., (float)0., (float)
	    .0129306, (float).00269567, (float)0., (float)3.92243, (float)
	    -.0084769, (float).0116896, (float)0., (float).0148967, (float)
	    .00544521, (float)0., (float)5.64918, (float)0., (float)
	    -.00772178, (float)0., (float)0., (float)-73.4042, (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)1.27515, (float)-.210472, (float)-.177924, (float).2189, (
	    float).0288436, (float).0190077, (float).291001, (float).0217437, 
	    (float)-.0105186, (float).436141, (float).107605, (float).0330755,
	     (float).0400581, (float)-9.58051, (float)0., (float).0154028, (
	    float)0., (float)73.4194, (float).049654, (float)-.00595906, (
	    float)3.84512e-5, (float)-.0136, (float)0., (float)0., (float)
	    .132397, (float).213315, (float)-.041661, (float)0., (float)0., (
	    float)0., (float)0., (float)146.276, (float)-.0198408, (float)0., 
	    (float).013253, (float)0., (float)0., (float)0., (float)0., (
	    float)-1.04687e-4, (float)-.00147562, (float)0., (float)0., (
	    float).113139, (float).169134, (float)-.0126913, (float)0., (
	    float)0., (float)0., (float)-.0060837, (float)-.0257587, (float)
	    3.19022e-5, (float)0., (float)0., (float).0156644, (float).010364,
	     (float).00105771, (float)0., (float)3579.49, (float)0., (float)
	    -.00125672, (float).00152783, (float).00130518, (float)7.55558, (
	    float)-.00920341, (float)-.0209142, (float)-.0134106, (float)0., (
	    float)-.0483312, (float).08309, (float).0988009, (float)-14114.8, 
	    (float)0., (float)0., (float)0., (float)-1055.13, (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float).00673442, (float).00201691, (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float).0598019, (float).00633298, (
	    float)-.00112871, (float)0., (float)0., (float)0., (float)
	    -.0128604, (float)0., (float)0., (float)0., (float)-.0049496, (
	    float)-.0136415, (float)-.0115039, (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)-.0058686, (float)
	    -.00141732, (float).00213697, (float)2.63845, (float)-.00834186, (
	    float)-.0187336, (float)-.019087, (float)-.0080381, (float)
	    -.00284279, (float).00256722, (float)1.71429, (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)57.3587, (
	    float)-.398747, (float)0., (float)-.529554, (float)-.00582186, (
	    float).0714177, (float)-.679279, (float)-.167715, (float)
	    -.0642434, (float)-.211569, (float)-.159922, (float)-1.71024e-4, (
	    float)-.115885, (float)6.51603, (float)0., (float)-.176683, (
	    float).0650395, (float)1.43504, (float).0928208, (float).00511662,
	     (float)0., (float).00995121, (float)0., (float)0., (float)
	    .132397, (float).213315, (float).101451, (float)0., (float)0., (
	    float)0., (float)0., (float)56.7667, (float).00238192, (float)0., 
	    (float)-.018824, (float)0., (float)0., (float).0476218, (float)
	    23.5206, (float).00475901, (float).00576162, (float).0151815, (
	    float)-.019273, (float).113139, (float).169134, (float)-.0288771, 
	    (float)0., (float)0., (float)0., (float).00118418, (float)
	    -.00368927, (float)3.14704e-5, (float).00882198, (float)0., (
	    float)-.0192562, (float)-.00258674, (float)-.0219913, (float)0., (
	    float)4386.55, (float)0., (float).00760126, (float).00259438, (
	    float).0017231, (float)77.9204, (float)7.97786e-4, (float)
	    -.0077051, (float).00190982, (float).00272707, (float).0101016, (
	    float).116537, (float)-.00312236, (float)13978.3, (float)0., (
	    float)0., (float)0., (float)-1307.12, (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    -.00320544, (float)-.020697, (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float).015901, (float)-.00191427, (float)
	    -.0342829, (float)0., (float)0., (float)0., (float)-.0345379, (
	    float)89.4518, (float).00171556, (float)0., (float)-.00765278, (
	    float)-2.08987e-4, (float)-.0157393, (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)-.00860673, (float)
	    -.0119922, (float)-.00646356, (float)-3.00107, (float)-.00932511, 
	    (float)-.0150205, (float)-.00867835, (float)-.00764801, (float)
	    -.0131495, (float)-.0067672, (float)-1.82396, (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    -8.45398, (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    .132397, (float).213315, (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float).113139, (float).169134, (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float).951363, (float)-.0467542, (float).12026, (
	    float)0., (float)0., (float).0191357, (float)0., (float)0., (
	    float).00125429, (float)-.13324, (float)0., (float)0., (float)0., 
	    (float)-8.45398, (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float).00252317, (float)0., (
	    float)-.00973404, (float).132397, (float).213315, (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)-7.18482e-4, (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float).00787683, (float)
	    -.00233698, (float).113139, (float).169134, (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float).933804, (float)5.47446, (float).153263, (float)
	    .919303, (float)16.4109, (float)4.27083, (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float).140925, (float)
	    1.15897, (float).471094, (float)1.09459, (float)5.25012, (float)
	    1., (float)1., (float)1.03999, (float).767132, (float)1.10514, (
	    float)1.75636, (float)1.10845, (float)2.33439, (float).796532, (
	    float)4.3152, (float)4.073, (float)122.807, (float).239547, (
	    float)2.53791e-6, (float).842931, (float)1.04192, (float)2.00202, 
	    (float)1., (float)1., (float)1., (float).962736, (float)1.02083, (
	    float).0408449, (float)-.0234582, (float)4.38274e-4, (float)
	    -.015238, (float)-.0209089, (float).00446355, (float)-.0034125, (
	    float)-.0112961, (float)-.0703277, (float)-.0482724, (float)0., (
	    float)0., (float)-6.20496, (float)0., (float)-.00980197, (float)
	    -.0145065, (float)-113.226, (float).0228455, (float)0., (float)0.,
	     (float)4.93658e-4, (float)0., (float).00379078, (float).132397, (
	    float).213315, (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)-8890.51, (float).002259, (float).00176142, (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)-2.55015e-4, (
	    float).00221388, (float)-5.99073e-4, (float)-.00352331, (float)
	    .113139, (float).169134, (float).00779156, (float)-.00193458, (
	    float)-.0108596, (float)-4.39285e-4, (float)0., (float).00383994, 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float).00676608, (float)0., (
	    float)0., (float)0., (float).92488, (float).0741986, (float)
	    -.00637629, (float).00600575, (float).00129382, (float).0069755, (
	    float)-.00170782, (float).00280584, (float)-.00887214, (float)
	    -.0435703, (float)0., (float)0., (float)0., (float)4.31515, (
	    float)0., (float)-.0181474, (float)-.0606627, (float)-84.3503, (
	    float).00846944, (float)0., (float)0., (float)0., (float)
	    -.0217081, (float)-.002195, (float).132397, (float).213315, (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    247.58, (float).00441585, (float).00780466, (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)6.44155e-4, (float)
	    -.00249166, (float).00290482, (float)-3.40501e-4, (float).113139, 
	    (float).169134, (float)-.0060146, (float)-.00163368, (float)0., (
	    float)-.0043134, (float)0., (float).00453979, (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)-.0054366, (float)0., (float)0., (float)0., 
	    (float).972669, (float)-.0426748, (float).0112876, (float)
	    -.00844951, (float).00704114, (float).0126036, (float)-.00388164, 
	    (float)-5.20509e-4, (float)-6.0971e-4, (float).131603, (float)
	    .113804, (float)0., (float)0., (float)-6.1597, (float)0., (float)
	    -.0214214, (float)-.0662913, (float)-.202884, (float).023535, (
	    float)0., (float)0., (float)0., (float).0113573, (float)
	    -.00184905, (float).132397, (float).213315, (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)1.42645, (float)
	    -.00264405, (float)-5.57771e-4, (float)0., (float)0., (float)0., (
	    float)0., (float)-22.0621, (float)-.00110313, (float)3.97063e-5, (
	    float)5.47632e-5, (float).00357577, (float).113139, (float)
	    .169134, (float)0., (float).00118897, (float)0., (float)
	    7.62305e-4, (float)0., (float)-.00352015, (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    -9.5255e-4, (float)8.56253e-4, (float)4.33114e-4, (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float).00121223, (float)2.38694e-4, (float)9.15245e-4, (float)
	    .00128385, (float)8.67668e-4, (float)-5.61425e-6, (float)1.04445, 
	    (float)34.1112, (float)0., (float)-.840704, (float)-239.639, (
	    float).706668, (float)-20.5873, (float)-.363696, (float)23.9245, (
	    float)10., (float)-.00106657, (float)-7.67292e-4, (float)
	    1.54534e-4, (float)0., (float)0., (float)0., (float)0., (float)0.,
	     (float)0., (float)0., (float).999368, (float).0433893, (float)
	    -.00207009, (float).00109617, (float).0010544, (float)4.83408e-4, 
	    (float)9.7704e-4, (float)9.24791e-4, (float)4.80247e-4, (float)
	    .0494737, (float).00105985, (float)0., (float)0., (float)2.74409, 
	    (float)0., (float)-.00496656, (float)-.0151684, (float)46.5158, (
	    float)-.00751133, (float)0., (float)0., (float)0., (float)0., (
	    float)6.63808e-4, (float).132397, (float).213315, (float)
	    -.00206652, (float)-.00632046, (float)0., (float)0., (float)
	    .00594545, (float)-190.958, (float)0., (float)-.00416892, (float)
	    0., (float)-.0167499, (float)0., (float).00258987, (float)597.781,
	     (float)0., (float)0., (float)4.4489e-4, (float)4.66444e-4, (
	    float).113139, (float).169134, (float)0., (float)7.1136e-4, (
	    float).0132186, (float).00223948, (float)0., (float)0., (float)0.,
	     (float)0., (float)0., (float)0., (float)0., (float)0., (float)0.,
	     (float)0., (float)0., (float)0., (float)0., (float)0., (float)0.,
	     (float).00160571, (float)6.28078e-4, (float)5.05469e-5, (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)-.00157829, (float)-4.00855e-4, (float)5.04077e-5, (
	    float)-.00139001, (float)-.00233406, (float)-4.81197e-4, (float)
	    1.46758, (float)6.20332, (float)0., (float).366476, (float)
	    -61.976, (float).309198, (float)-19.8999, (float)0., (float)
	    -329.933, (float)0., (float)-.0011008, (float)-9.3931e-5, (float)
	    1.39638e-4, (float)0., (float)0., (float)0., (float)0., (float)0.,
	     (float)0., (float)0., (float).981637, (float)-.00141317, (float)
	    .0387323, (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)-.0358707, (float)-.00863658, (float)0., (float)
	    0., (float)-2.02226, (float)0., (float)-.00869424, (float)
	    -.0191397, (float)87.6779, (float).00452188, (float)0., (float)0.,
	     (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    -.00707572, (float)0., (float)0., (float)0., (float)-.0041121, (
	    float)35.006, (float)0., (float)0., (float)0., (float).022376, (
	    float)0., (float)-.00836657, (float)16.1347, (float)0., (float)0.,
	     (float)0., (float)0., (float)0., (float)0., (float)0., (float)0.,
	     (float)-.014513, (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float).00124152, (float)6.43365e-4, (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    .00133255, (float).00242657, (float).00160666, (float)-.00185728, 
	    (float)-.00146874, (float)-4.79163e-6, (float)1.22464, (float)
	    35.351, (float)0., (float).449223, (float)-47.7466, (float)
	    .470681, (float)8.41861, (float)-.288198, (float)167.854, (float)
	    0., (float)7.11493e-4, (float)6.05601e-4, (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)1.00422, (float)-.00711212, (float).0052448, (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    -.0528914, (float)-.0241301, (float)0., (float)0., (float)
	    -21.2219, (float)0., (float)-.00328077, (float).0165727, (float)
	    1.68564, (float)-.00668154, (float)0., (float)0., (float)0., (
	    float).00842365, (float)0., (float)0., (float)0., (float)
	    -.00434645, (float)-.010383, (float)-.00808279, (float).021678, (
	    float)0., (float)-138.459, (float)0., (float)0., (float)0., (
	    float).0145155, (float)0., (float).00704573, (float)-47.3204, (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float).0108767, (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)5.21769e-4, (float)-2.27387e-4, (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float).00326769, (float).00316901, (float)
	    4.60316e-4, (float)-1.01431e-4, (float).00102131, (float)
	    9.96601e-4, (float)1.25707, (float)25.0114, (float)0., (float)
	    .424472, (float)-27.7655, (float).344625, (float)27.5412, (float)
	    0., (float)794.251, (float)0., (float).00245835, (float).00138871,
	     (float)0., (float)0., (float)0., (float)0., (float)0., (float)0.,
	     (float)0., (float)0., (float)1.0189, (float)-.0246603, (float)
	    .0100078, (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)-.0670977, (float)-.0402286, (float)0., (float)
	    0., (float)-22.9466, (float)0., (float).0022658, (float).0263931, 
	    (float)37.2625, (float)-.00639041, (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)-.00185291,
	     (float)-.00747019, (float)-.00707265, (float)0., (float)0., (
	    float)139.717, (float)0., (float)0., (float)0., (float).00958383, 
	    (float)0., (float).00919771, (float)-369.121, (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)-.0157067, (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)-.00292953, (float)-.00277739, (float)-4.40092e-4, (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float).0024728, (float)2.95035e-4, (float)-.00181246, (float)
	    .00281945, (float).00427296, (float)9.78863e-4, (float)1.40545, (
	    float)-6.19173, (float)0., (float)0., (float)-79.3632, (float)
	    .444643, (float)-403.085, (float)0., (float)11.5603, (float)0., (
	    float).00225068, (float)8.48557e-4, (float)-2.98493e-4, (float)0.,
	     (float)0., (float)0., (float)0., (float)0., (float)0., (float)0.,
	     (float).975801, (float).038068, (float)-.0305198, (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    .0385575, (float).0504057, (float)0., (float)0., (float)-176.046, 
	    (float)0., (float)-.00148297, (float)-.0036856, (float)30.2185, (
	    float)-.00323338, (float)0., (float)0., (float)0., (float)
	    -.0115558, (float)0., (float)0., (float)0., (float).0048962, (
	    float).0144594, (float).00991215, (float)-.0100616, (float)
	    -.00821324, (float)-157.757, (float)0., (float)0., (float)0., (
	    float).0153569, (float)0., (float).00663564, (float)45.841, (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)-.025128, (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)-8.73148e-4, (float)-.00129648, (
	    float)-7.32026e-5, (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)-.0046811, (float)
	    -.00466003, (float)-.00131567, (float)-7.3939e-4, (float)
	    6.32499e-4, (float)-4.65588e-4, (float)-1.29785, (float)-157.139, 
	    (float)0., (float).25835, (float)-36.9453, (float).410672, (float)
	    9.78196, (float)-.152064, (float)-3850.84, (float)0., (float)
	    -8.52706e-4, (float)-.00140945, (float)-7.26786e-4, (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float).960722, (float).0703757, (float)-.0300266, (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    .0222671, (float).0410423, (float)0., (float)0., (float)-163.07, (
	    float)0., (float)5.40747e-4, (float).00779481, (float)144.908, (
	    float)1.51484e-4, (float)0., (float)0., (float)0., (float)
	    -.0141844, (float)0., (float)0., (float)0., (float).00577884, (
	    float).0106073, (float).00536685, (float).00974319, (float)0., (
	    float)-2880.15, (float)0., (float)0., (float)0., (float).0197547, 
	    (float)0., (float)-.00444902, (float)-29.276, (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float).0234419, (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)-4.65325e-4, (float)-5.50628e-4, (float)3.31465e-4, (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)-.00206179, (float)-.00308575, (float)-7.93589e-4, (
	    float)-1.08629e-4, (float)5.95511e-4, (float)-9.0505e-4, (float)
	    1.18997, (float)41.5924, (float)0., (float)-.472064, (float)
	    -947.15, (float).398723, (float)19.8304, (float)0., (float)
	    3732.19, (float)0., (float)-.0015004, (float)-.00114933, (float)
	    -1.56769e-4, (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)1.03123, (float)-.0705124, (
	    float).00871615, (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)-.0382621, (float)-.00980975, (float)
	    0., (float)0., (float)28.9286, (float)0., (float)0., (float)0., (
	    float)86.6153, (float)7.91938e-4, (float)0., (float)0., (float)0.,
	     (float).00468917, (float)0., (float)0., (float)0., (float)
	    .00786638, (float).00957341, (float).00572268, (float).00990827, (
	    float)0., (float)65.5573, (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)-40.02, (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float).00707457, (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)-2.0497e-4, (float).0012156, (float)-8.05579e-6, (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)-.00249941, (float)-4.57256e-4, (float)-1.59311e-4, (float)
	    2.96481e-4, (float)-.00177318, (float)-6.37918e-4, (float)1.02395,
	     (float)12.8172, (float)0., (float).149903, (float)-26.3818, (
	    float)0., (float)47.0628, (float)-.222139, (float).0482292, (
	    float)0., (float)-8.67075e-4, (float)-5.86479e-4, (float)
	    5.32462e-4, (float)0., (float)0., (float)0., (float)0., (float)0.,
	     (float)0., (float)0., (float)1.00828, (float)-.0910404, (float)
	    -.0226549, (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)-.023242, (float)-.00908925, (float)0., (float)
	    0., (float)33.6105, (float)0., (float)0., (float)0., (float)
	    -12.4957, (float)-.00587939, (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)27.9765, (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)2012.37, (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)-.0175553, (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float).00329699, (float).00126659, (float)
	    2.68402e-4, (float)0., (float)0., (float)0., (float)0., (float)0.,
	     (float)0., (float)0., (float).00117894, (float).00148746, (float)
	    1.06478e-4, (float)1.34743e-4, (float)-.00220939, (float)
	    -6.23523e-4, (float).636539, (float)11.3621, (float)0., (float)
	    -.393777, (float)2386.87, (float)0., (float)661.865, (float)
	    -.121434, (float)9.27608, (float)0., (float)1.68478e-4, (float)
	    .00124892, (float).00171345, (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)1.57293, (float)
	    -.6784, (float).6475, (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)-.0762974, (float)-.360423, (float)
	    0., (float)0., (float)128.358, (float)0., (float)0., (float)0., (
	    float)46.8038, (float)0., (float)0., (float)0., (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)-.167898, (float)0., (
	    float)0., (float)0., (float)0., (float)29099.4, (float)0., (float)
	    0., (float)0., (float)0., (float)0., (float)0., (float)31.5706, (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float).866492, (float).355807, (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    -1.12111, (float)0., (float)0., (float)0., (float)1.82458, (float)
	    0., (float)0., (float)0., (float)101.024, (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    654.251, (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)-.0156959, (float).0191001, (float).0315971, (
	    float).0100982, (float)-.00671565, (float).00257693, (float)
	    1.38692, (float).282132, (float)0., (float)0., (float)381.511, (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)1.06029, (float)-.0525231, 
	    (float).373034, (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float).0331072, (float)-.388409, (float)0., 
	    (float)0., (float)-165.295, (float)0., (float)-.0438916, (float)
	    -.322716, (float)-88.2393, (float).118458, (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    -.119782, (float)-.213801, (float)0., (float)0., (float)0., (
	    float)26.2229, (float)0., (float)0., (float)0., (float)-.435863, (
	    float)0., (float)0., (float)-53.7443, (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)-.455788, (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float)0., (float)0., (float)0., (
	    float).0384009, (float).0396733, (float)0., (float)0., (float)0., 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)
	    .0505494, (float).0739617, (float).01922, (float)-.00846151, (
	    float)-.0134244, (float).0196338, (float)1.50421, (float)18.8368, 
	    (float)0., (float)0., (float)-51.3114, (float)0., (float)0., (
	    float)0., (float)0., (float)0., (float).0511923, (float).0361225, 
	    (float)0., (float)0., (float)0., (float)0., (float)0., (float)0., 
	    (float)0., (float)0. };

struct {
    char e_1[28];
    } datim6_ = { {'1', '2', '-', 'M', 'A', 'R', '-', '9', '0', ' ', ' ', ' ',
	     '1', '5', ':', '0', '9', ':', '0', '4', 'M', 'S', 'I', 'S', 'E', 
	    ' ', '9', '0'} };

struct {
    real e_1[10];
    } mavg6_ = { (float)261., (float)264., (float)229., (float)217., (float)
	    217., (float)223., (float)286.76, (float)-2.9394, (float)2.5, (
	    float)0. };


/* Table of constant values */

static integer c__1 = 1;
static real c_b14 = (float)1.;
static integer c__0 = 0;
static integer c__48 = 48;
static integer c__2 = 2;
static real c_b36 = (float)1e3;
static real c_b44 = (float)28.;
static real c_b45 = (float)0.;
static real c_b46 = (float)-1.;
static real c_b55 = (float)4.;
static real c_b56 = (float)-.4;
static real c_b58 = (float)-1.4;
static real c_b61 = (float)16.;
static real c_b67 = (float)32.;
static real c_b73 = (float)40.;
static real c_b85 = (float)14.;
static doublereal c_b104 = .5;
static real c_b114 = (float)2.;
static integer c__9 = 9;
static integer c__4 = 4;

/* I am forwarding to you the latest version of the MSIS model for your */
/* analysis work. I would appreciate your bringing any problems you mightc */
/* discover to my attention.  I would also appreciate hearing about your */
/* results using this model. */

/* Alan E. Hedin, 10/9/90 */
/* PACF::HEDIN */
/* (301)-286-8393 */

/* Contents:  MSIS FORTRAN SUBROUTINE GTD6 */
/*            FORTRAN TEST DRIVER */
/*            OUTPUT OF TEST */

/* ================================================================== */
/* Version: 22-JUL-1991 15:59:42.72 */

/* This version includes SAVE statements and new driver and test data. */

/* NOTE: This model is NOT an upgrade for the upper thermosphere and is */
/*       probably less efficient than MSIS86. */
/* ================================================================== */
/* Version: 10-MAR-1993 15:31:11.76 */

/* Changing to density per cubic meter instead of per cubic centimeter */
/* did under certain particular conditions result in erroneous density */
/* by less than a percent (wrong entry name) when first (and only */
/* first) calling subroutine GTD6. This was corrected. */

/* ================================================================== */

/* Contents:  MSIS FORTRAN SUBROUTINE GTD6 */
/*            FORTRAN TEST DRIVER */
/*            OUTPUT OF TEST */

/* ---------------------------------------------------------------- */
/* Subroutine */ int gtd6_(iyd, sec, alt, glat, glong, stl, f107a, f107, ap, 
	mass, d__, t)
integer *iyd;
real *sec, *alt, *glat, *glong, *stl, *f107a, *f107, *ap;
integer *mass;
real *d__, *t;
{
    /* Initialized data */

    static integer mn3 = 5;
    static real zn3[5] = { (float)32.5,(float)20.,(float)15.,(float)10.,(
	    float)0. };
    static integer mn2 = 4;
    static real zn2[4] = { (float)72.5,(float)55.,(float)45.,(float)32.5 };
    static real zmix = (float)62.5;
    static real alast = (float)99999.;
    static integer mssl = -999;
    static real sv[25] = { (float)1.,(float)1.,(float)1.,(float)1.,(float)1.,(
	    float)1.,(float)1.,(float)1.,(float)1.,(float)1.,(float)1.,(float)
	    1.,(float)1.,(float)1.,(float)1.,(float)1.,(float)1.,(float)1.,(
	    float)1.,(float)1.,(float)1.,(float)1.,(float)1.,(float)1.,(float)
	    1. };

    /* System generated locals */
    real r__1;

    /* Local variables */
    static real dm28m, altt, xlat;
    extern doublereal vtst_();
    static integer i__, j;
    extern /* Subroutine */ int glatf_();
    extern doublereal densm_();
    static real d6[8], v1, t6[2];
    extern doublereal glob6s_();
    static real tz;
    extern /* Subroutine */ int tselec_();
    static real dmc, dmr, dz28, xmm;
    static integer mss;
    extern /* Subroutine */ int gts6_();

/*        Neutral Atmosphere Empirical Model from the surface to lower */
/*          exosphere  MSISE90 (JGR, 96, 1159-1172, 1991) */
/*         A.E.Hedin 4/24/90;6/3/91(add SAVE) */
/*         2/11/93 correct switch initialization and mks calculation */
/*           See subroutine GHP6 to specify a pressure rather than */
/*           altitude. */
/*     INPUT: */
/*        IYD - YEAR AND DAY AS YYYYDDD or just DDD (day of year from 1 to 365) */
/*        SEC - UT(SEC) */
/*        ALT - ALTITUDE(KM) */
/*        GLAT - GEODETIC LATITUDE(DEG) */
/*        GLONG - GEODETIC LONGITUDE(DEG) */
/*        STL - LOCAL APPARENT SOLAR TIME(HRS) */
/*        F107A - 3 MONTH AVERAGE OF F10.7 FLUX */
/*        F107 - DAILY F10.7 FLUX FOR PREVIOUS DAY */
/*        AP - MAGNETIC INDEX(DAILY) OR WHEN SW(9)=-1. : */
/*           - ARRAY CONTAINING: */
/*             (1) DAILY AP */
/*             (2) 3 HR AP INDEX FOR CURRENT TIME */
/*             (3) 3 HR AP INDEX FOR 3 HRS BEFORE CURRENT TIME */
/*             (4) 3 HR AP INDEX FOR 6 HRS BEFORE CURRENT TIME */
/*             (5) 3 HR AP INDEX FOR 9 HRS BEFORE CURRENT TIME */
/*             (6) AVERAGE OF EIGHT 3 HR AP INDICIES FROM 12 TO 33 HRS PRIOR */
/*                    TO CURRENT TIME */
/*             (7) AVERAGE OF EIGHT 3 HR AP INDICIES FROM 36 TO 59 HRS PRIOR */
/*                    TO CURRENT TIME */
/*        MASS - MASS NUMBER (ONLY DENSITY FOR SELECTED GAS IS */
/*                 CALCULATED.  MASS 0 IS TEMPERATURE.  MASS 48 FOR ALL. */
/*     Note:  Ut, Local Time, and Longitude are used independently in the */
/*            model and are not of equal importance for every situation. */
/*            For the most physically realistic calculation these three */
/*            variables should be consistent (STL=SEC/3600+GLONG/15). */
/*            F107, F107A, and AP effects are not large below 80 km */
/*            and these can be set to 150., 150., and 4. respectively. */
/*     OUTPUT: */
/*        D(1) - HE NUMBER DENSITY(CM-3) */
/*        D(2) - O NUMBER DENSITY(CM-3) */
/*        D(3) - N2 NUMBER DENSITY(CM-3) */
/*        D(4) - O2 NUMBER DENSITY(CM-3) */
/*        D(5) - AR NUMBER DENSITY(CM-3) */
/*        D(6) - TOTAL MASS DENSITY(GM/CM3) */
/*        D(7) - H NUMBER DENSITY(CM-3) */
/*        D(8) - N NUMBER DENSITY(CM-3) */
/*        T(1) - EXOSPHERIC TEMPERATURE */
/*        T(2) - TEMPERATURE AT ALT */

/*      TO GET OUTPUT IN M-3 and KG/M3:   CALL METER6(.TRUE.) */

/*      O, H, and N set to zero below 72.5 km */
/*      Exospheric temperature set to average for altitudes below 120 km. */

/*           The following is for test and special purposes: */
/*            TO TURN ON AND OFF PARTICULAR VARIATIONS CALL TSELEC(SW) */
/*               WHERE SW IS A 25 ELEMENT ARRAY CONTAINING 0. FOR OFF, 1. */
/*               FOR ON, OR 2. FOR MAIN EFFECTS OFF BUT CROSS TERMS ON */
/*               FOR THE FOLLOWING VARIATIONS */
/*               1 - F10.7 EFFECT ON MEAN  2 - TIME INDEPENDENT */
/*               3 - SYMMETRICAL ANNUAL    4 - SYMMETRICAL SEMIANNUAL */
/*               5 - ASYMMETRICAL ANNUAL   6 - ASYMMETRICAL SEMIANNUAL */
/*               7 - DIURNAL               8 - SEMIDIURNAL */
/*               9 - DAILY AP             10 - ALL UT/LONG EFFECTS */
/*              11 - LONGITUDINAL         12 - UT AND MIXED UT/LONG */
/*              13 - MIXED AP/UT/LONG     14 - TERDIURNAL */
/*              15 - DEPARTURES FROM DIFFUSIVE EQUILIBRIUM */
/*              16 - ALL TINF VAR         17 - ALL TLB VAR */
/*              18 - ALL TN1 VAR           19 - ALL S VAR */
/*              20 - ALL TN2 VAR           21 - ALL NLB VAR */
/*              22 - ALL TN3 VAR           23 - TURBO SCALE HEIGHT VAR */

/*              To get current values of SW: CALL TRETRV(SW) */

    /* Parameter adjustments */
    --t;
    --d__;
    --ap;

    /* Function Body */
    if (csw_1.isw != 64999) {
	tselec_(sv);
    }
/*      Put identification data into common/datime/ */
    for (i__ = 1; i__ <= 3; ++i__) {
	datime_1.isdate[i__ - 1] = datim6_1.isd[i__ - 1];
/* L1: */
    }
    for (i__ = 1; i__ <= 2; ++i__) {
	datime_1.istime[i__ - 1] = datim6_1.ist[i__ - 1];
	datime_1.name__[i__ - 1] = datim6_1.nam[i__ - 1];
/* L2: */
    }

/* e        Test for changed input */
    v1 = vtst_(iyd, sec, glat, glong, stl, f107a, f107, &ap[1], &c__1);
/*       Latitude variation of gravity (none for SW(2)=0) */
    xlat = *glat;
    if (csw_1.sw[1] == (float)0.) {
	xlat = (float)45.;
    }
    glatf_(&xlat, &parmb_1.gsurf, &parmb_1.re);

    xmm = lower6_1.pdm[24];

/*       THERMOSPHERE/UPPER MESOSPHERE [above ZN2(1)] */
    altt = dmax(*alt,zn2[0]);
    mss = *mass;
/* e       Only calculate N2 in thermosphere if alt in mixed region */
    if (*alt < zmix && *mass > 0) {
	mss = 28;
    }
/* e       Only calculate thermosphere if input parameters changed */
/* e         or altitude above ZN2(1) in mesosphere */
    if (v1 == (float)1. || *alt > zn2[0] || alast > zn2[0] || mss != mssl) {
	gts6_(iyd, sec, &altt, glat, glong, stl, f107a, f107, &ap[1], &mss, 
		d6, t6);
	dm28m = dmix_1.dm28;
/*         metric adjustment */
	if (metsel_1.imr == 1) {
	    dm28m = dmix_1.dm28 * (float)1e6;
	}
	mssl = mss;
    }
    t[1] = t6[0];
    t[2] = t6[1];
    if (*alt >= zn2[0]) {
	for (j = 1; j <= 8; ++j) {
	    d__[j] = d6[j - 1];
/* L5: */
	}
	goto L10;
    }

/*       LOWER MESOSPHERE/UPPER STRATOSPHERE [between ZN3(1) and ZN2(1)] */
/*         Temperature at nodes and gradients at end nodes */
/*         Inverse temperature a linear function of spherical harmonics */
/* e        Only calculate nodes if input changed */
    if (v1 == (float)1. || alast >= zn2[0]) {
	meso6_1.tgn2[0] = meso6_1.tgn1[1];
	meso6_1.tn2[0] = meso6_1.tn1[4];
	meso6_1.tn2[1] = parm6_1.pma[0] * mavg6_1.pavgm[0] / ((float)1. - 
		csw_1.sw[19] * glob6s_(parm6_1.pma));
	meso6_1.tn2[2] = parm6_1.pma[100] * mavg6_1.pavgm[1] / ((float)1. - 
		csw_1.sw[19] * glob6s_(&parm6_1.pma[100]));
	meso6_1.tn2[3] = parm6_1.pma[200] * mavg6_1.pavgm[2] / ((float)1. - 
		csw_1.sw[19] * csw_1.sw[21] * glob6s_(&parm6_1.pma[200]));
/* Computing 2nd power */
	r__1 = parm6_1.pma[200] * mavg6_1.pavgm[2];
	meso6_1.tgn2[1] = mavg6_1.pavgm[8] * parm6_1.pma[900] * (csw_1.sw[19] 
		* csw_1.sw[21] * glob6s_(&parm6_1.pma[900]) + (float)1.) * 
		meso6_1.tn2[3] * meso6_1.tn2[3] / (r__1 * r__1);
	meso6_1.tn3[0] = meso6_1.tn2[3];
    }
    if (*alt >= zn3[0]) {
	goto L6;
    }

/*       LOWER STRATOSPHERE AND TROPOSPHERE [below ZN3(1)] */
/*         Temperature at nodes and gradients at end nodes */
/*         Inverse temperature a linear function of spherical harmonics */
/* e        Only calculate nodes if input changed */
    if (v1 == (float)1. || alast >= zn3[0]) {
	meso6_1.tgn3[0] = meso6_1.tgn2[1];
	meso6_1.tn3[1] = parm6_1.pma[300] * mavg6_1.pavgm[3] / ((float)1. - 
		csw_1.sw[21] * glob6s_(&parm6_1.pma[300]));
	meso6_1.tn3[2] = parm6_1.pma[400] * mavg6_1.pavgm[4] / ((float)1. - 
		csw_1.sw[21] * glob6s_(&parm6_1.pma[400]));
	meso6_1.tn3[3] = parm6_1.pma[500] * mavg6_1.pavgm[5] / ((float)1. - 
		csw_1.sw[21] * glob6s_(&parm6_1.pma[500]));
	meso6_1.tn3[4] = parm6_1.pma[600] * mavg6_1.pavgm[6] / ((float)1. - 
		csw_1.sw[21] * glob6s_(&parm6_1.pma[600]));
/* Computing 2nd power */
	r__1 = parm6_1.pma[600] * mavg6_1.pavgm[6];
	meso6_1.tgn3[1] = parm6_1.pma[700] * mavg6_1.pavgm[7] * (csw_1.sw[21] 
		* glob6s_(&parm6_1.pma[700]) + (float)1.) * meso6_1.tn3[4] * 
		meso6_1.tn3[4] / (r__1 * r__1);
    }
L6:
    if (*mass == 0) {
	goto L50;
    }
/* e          Linear transition to full mixing at ZMIX from almost */
/* e            full mixing at ZN2(1) to improve efficiency */
    dmc = (float)0.;
    if (*alt > zmix) {
	dmc = (float)1. - (zn2[0] - *alt) / (zn2[0] - zmix);
    }
    dz28 = d6[2];
/*      ***** N2 DENSITY **** */
    dmr = d6[2] / dm28m - (float)1.;
    d__[3] = densm_(alt, &dm28m, &xmm, &tz, &mn3, zn3, meso6_1.tn3, 
	    meso6_1.tgn3, &mn2, zn2, meso6_1.tn2, meso6_1.tgn2);
    d__[3] *= dmr * dmc + (float)1.;
/*      ***** HE DENSITY **** */
    d__[1] = (float)0.;
    if (*mass != 4 && *mass != 48) {
	goto L204;
    }
    dmr = d6[0] / (dz28 * lower6_1.pdm[1]) - (float)1.;
    d__[1] = d__[3] * lower6_1.pdm[1] * (dmr * dmc + (float)1.);
L204:
/*      **** O DENSITY **** */
    d__[2] = (float)0.;
/* L216: */
/*      ***** O2 DENSITY **** */
    d__[4] = (float)0.;
    if (*mass != 32 && *mass != 48) {
	goto L232;
    }
    dmr = d6[3] / (dz28 * lower6_1.pdm[31]) - (float)1.;
    d__[4] = d__[3] * lower6_1.pdm[31] * (dmr * dmc + (float)1.);
L232:
/*      ***** AR DENSITY **** */
    d__[5] = (float)0.;
    if (*mass != 40 && *mass != 48) {
	goto L240;
    }
    dmr = d6[4] / (dz28 * lower6_1.pdm[41]) - (float)1.;
    d__[5] = d__[3] * lower6_1.pdm[41] * (dmr * dmc + (float)1.);
L240:
/*      ***** HYDROGEN DENSITY **** */
    d__[7] = (float)0.;
/*      ***** ATOMIC NITROGEN DENSITY **** */
    d__[8] = (float)0.;

/*       TOTAL MASS DENSITY */

    if (*mass == 48) {
	d__[6] = (d__[1] * (float)4. + d__[2] * (float)16. + d__[3] * (float)
		28. + d__[4] * (float)32. + d__[5] * (float)40. + d__[7] + 
		d__[8] * (float)14.) * (float)1.66e-24;
	if (metsel_1.imr == 1) {
	    d__[6] /= (float)1e3;
	}
    }
    t[2] = tz;
L10:
    goto L90;
L50:
    gts3c_1.dd = densm_(alt, &c_b14, &c__0, &tz, &mn3, zn3, meso6_1.tn3, 
	    meso6_1.tgn3, &mn2, zn2, meso6_1.tn2, meso6_1.tgn2);
    t[2] = tz;
L90:
    alast = *alt;
    return 0;
} /* gtd6_ */

/* ---------------------------------------------------------------- */
/* Subroutine */ int ghp6_(iyd, sec, alt, glat, glong, stl, f107a, f107, ap, 
	d__, t, press)
integer *iyd;
real *sec, *alt, *glat, *glong, *stl, *f107a, *f107, *ap, *d__, *t, *press;
{
    /* Initialized data */

    static real bm = (float)1.3806e-19;
    static real rgas = (float)831.4;
    static real test = (float)4.3e-4;

    /* Format strings */
    static char fmt_100[] = "(1x,\002GHP6 NOT CONVERGING FOR PRESS\002,1pe12\
.2,e12.2)";

    /* System generated locals */
    real r__1;

    /* Builtin functions */
    double r_lg10();
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static real diff;
    static integer iday;
    static real g;
    static integer l;
    static real p, z__, ca, cd, cl, sh, pl, zi, xm, xn, cl2;
    extern /* Subroutine */ int gtd6_();

    /* Fortran I/O blocks */
    static cilist io___41 = { 0, 6, 0, fmt_100, 0 };


/*       FIND ALTITUDE OF PRESSURE SURFACE (PRESS) FROM GTD6 */
/*     INPUT: */
/*        IYD - YEAR AND DAY AS YYYYDDD */
/*        SEC - UT(SEC) */
/*        GLAT - GEODETIC LATITUDE(DEG) */
/*        GLONG - GEODETIC LONGITUDE(DEG) */
/*        STL - LOCAL APPARENT SOLAR TIME(HRS) */
/*        F107A - 3 MONTH AVERAGE OF F10.7 FLUX */
/*        F107 - DAILY F10.7 FLUX FOR PREVIOUS DAY */
/*        AP - MAGNETIC INDEX(DAILY) OR WHEN SW(9)=-1. : */
/*           - ARRAY CONTAINING: */
/*             (1) DAILY AP */
/*             (2) 3 HR AP INDEX FOR CURRENT TIME */
/*             (3) 3 HR AP INDEX FOR 3 HRS BEFORE CURRENT TIME */
/*             (4) 3 HR AP INDEX FOR 6 HRS BEFORE CURRENT TIME */
/*             (5) 3 HR AP INDEX FOR 9 HRS BEFORE CURRENT TIME */
/*             (6) AVERAGE OF EIGHT 3 HR AP INDICIES FROM 12 TO 33 HRS PRIOR */
/*                    TO CURRENT TIME */
/*             (7) AVERAGE OF EIGHT 3 HR AP INDICIES FROM 36 TO 59 HRS PRIOR */
/*                    TO CURRENT TIME */
/*        PRESS - PRESSURE LEVEL(MB) */
/*     OUTPUT: */
/*        ALT - ALTITUDE(KM) */
/*        D(1) - HE NUMBER DENSITY(CM-3) */
/*        D(2) - O NUMBER DENSITY(CM-3) */
/*        D(3) - N2 NUMBER DENSITY(CM-3) */
/*        D(4) - O2 NUMBER DENSITY(CM-3) */
/*        D(5) - AR NUMBER DENSITY(CM-3) */
/*        D(6) - TOTAL MASS DENSITY(GM/CM3) */
/*        D(7) - H NUMBER DENSITY(CM-3) */
/*        D(8) - N NUMBER DENSITY(CM-3) */
/*        T(1) - EXOSPHERIC TEMPERATURE */
/*        T(2) - TEMPERATURE AT ALT */

    /* Parameter adjustments */
    --t;
    --d__;
    --ap;

    /* Function Body */
    pl = r_lg10(press);
/*      Initial altitude estimate */
    if (pl >= (float)-5.) {
	if (pl > (float)2.5) {
	    zi = ((float)3. - pl) * (float)18.06;
	}
	if (pl > (float).75 && pl <= (float)2.5) {
	    zi = ((float)3.08 - pl) * (float)14.98;
	}
	if (pl > (float)-1. && pl <= (float).75) {
	    zi = ((float)2.72 - pl) * (float)17.8;
	}
	if (pl > (float)-2. && pl <= (float)-1.) {
	    zi = ((float)3.64 - pl) * (float)14.28;
	}
	if (pl > (float)-4. && pl <= (float)-2.) {
	    zi = ((float)4.32 - pl) * (float)12.72;
	}
	if (pl <= (float)-4.) {
	    zi = ((float).11 - pl) * (float)25.3;
	}
	iday = *iyd % 1000;
	cl = *glat / (float)90.;
	cl2 = cl * cl;
	if (iday < 182) {
	    cd = (float)1. - iday / (float)91.25;
	}
	if (iday >= 182) {
	    cd = iday / (float)91.25 - (float)3.;
	}
	ca = (float)0.;
	if (pl > (float)-1.11 && pl <= (float)-.23) {
	    ca = (float)1.;
	}
	if (pl > (float)-.23) {
	    ca = ((float)2.79 - pl) / (float)3.02;
	}
	if (pl <= (float)-1.11 && pl > (float)-3.) {
	    ca = ((float)-2.93 - pl) / (float)-1.8200000000000001;
	}
	z__ = zi - cl * (float)4.87 * cd * ca - cl2 * (float)1.64 * ca + ca * 
		(float).31 * cl;
    }
    if (pl < (float)-5.) {
/* Computing 2nd power */
	r__1 = pl + (float)4.;
	z__ = r__1 * r__1 * (float)22. + 110;
    }
    l = 0;
/*      ITERATION LOOP */
L10:
    ++l;
    gtd6_(iyd, sec, &z__, glat, glong, stl, f107a, f107, &ap[1], &c__48, &d__[
	    1], &t[1]);
    xn = d__[1] + d__[2] + d__[3] + d__[4] + d__[5] + d__[7] + d__[8];
    p = bm * xn * t[2];
    if (metsel_1.imr == 1) {
	p *= (float)1e-6;
    }
    diff = pl - r_lg10(&p);
    if (dabs(diff) < test || l == 6) {
	goto L20;
    }
    xm = d__[6] / xn / (float)1.66e-24;
/* Computing 2nd power */
    r__1 = z__ / parmb_1.re + (float)1.;
    g = parmb_1.gsurf / (r__1 * r__1);
    sh = rgas * t[2] / (xm * g);
/*         New altitude estimate using scale height */
    z__ -= sh * diff * (float)2.302;
    goto L10;
L20:
    if (l == 6) {
	s_wsfe(&io___41);
	do_fio(&c__1, (char *)&(*press), (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&diff, (ftnlen)sizeof(real));
	e_wsfe();
    }
    *alt = z__;
    return 0;
} /* ghp6_ */

/* ---------------------------------------------------------------- */
/* Subroutine */ int glatf_(lat, gv, reff)
real *lat, *gv, *reff;
{
    /* Initialized data */

    static real dgtr = (float).0174533;
    static real latl = (float)-999.;

    /* Builtin functions */
    double cos();

    /* Local variables */
    static real c2;

/*      CALCULATE LATITUDE VARIABLE GRAVITY (GV) AND EFFECTIVE */
/*      RADIUS (REFF) */
    if (*lat != latl) {
	c2 = cos((float)2. * dgtr * *lat);
    }
    latl = *lat;
    *gv = ((float)1. - c2 * (float).0026373) * (float)980.616;
    *reff = *gv * (float)2. / (c2 * (float)2.27e-9 + (float)3.085462e-6) * (
	    float)1e-5;
    return 0;
} /* glatf_ */

/* ---------------------------------------------------------------- */
doublereal vtst_(iyd, sec, glat, glong, stl, f107a, f107, ap, ic)
integer *iyd;
real *sec, *glat, *glong, *stl, *f107a, *f107, *ap;
integer *ic;
{
    /* Initialized data */

    static integer iydl[2] = { -999,-999 };
    static real secl[2] = { (float)-999.,(float)-999. };
    static real glatl[2] = { (float)-999.,(float)-999. };
    static real gll[2] = { (float)-999.,(float)-999. };
    static real stll[2] = { (float)-999.,(float)-999. };
    static real fal[2] = { (float)-999.,(float)-999. };
    static real fl[2] = { (float)-999.,(float)-999. };
    static real apl[14]	/* was [7][2] */ = { (float)-999.,(float)-999.,(float)
	    -999.,(float)-999.,(float)-999.,(float)-999.,(float)-999.,(float)
	    -999.,(float)-999.,(float)-999.,(float)-999.,(float)-999.,(float)
	    -999.,(float)-999. };
    static real swl[50]	/* was [25][2] */ = { (float)-999.,(float)-999.,(
	    float)-999.,(float)-999.,(float)-999.,(float)-999.,(float)-999.,(
	    float)-999.,(float)-999.,(float)-999.,(float)-999.,(float)-999.,(
	    float)-999.,(float)-999.,(float)-999.,(float)-999.,(float)-999.,(
	    float)-999.,(float)-999.,(float)-999.,(float)-999.,(float)-999.,(
	    float)-999.,(float)-999.,(float)-999.,(float)-999.,(float)-999.,(
	    float)-999.,(float)-999.,(float)-999.,(float)-999.,(float)-999.,(
	    float)-999.,(float)-999.,(float)-999.,(float)-999.,(float)-999.,(
	    float)-999.,(float)-999.,(float)-999.,(float)-999.,(float)-999.,(
	    float)-999.,(float)-999.,(float)-999.,(float)-999.,(float)-999.,(
	    float)-999.,(float)-999.,(float)-999. };
    static real swcl[50]	/* was [25][2] */ = { (float)-999.,(float)
	    -999.,(float)-999.,(float)-999.,(float)-999.,(float)-999.,(float)
	    -999.,(float)-999.,(float)-999.,(float)-999.,(float)-999.,(float)
	    -999.,(float)-999.,(float)-999.,(float)-999.,(float)-999.,(float)
	    -999.,(float)-999.,(float)-999.,(float)-999.,(float)-999.,(float)
	    -999.,(float)-999.,(float)-999.,(float)-999.,(float)-999.,(float)
	    -999.,(float)-999.,(float)-999.,(float)-999.,(float)-999.,(float)
	    -999.,(float)-999.,(float)-999.,(float)-999.,(float)-999.,(float)
	    -999.,(float)-999.,(float)-999.,(float)-999.,(float)-999.,(float)
	    -999.,(float)-999.,(float)-999.,(float)-999.,(float)-999.,(float)
	    -999.,(float)-999.,(float)-999.,(float)-999. };

    /* System generated locals */
    real ret_val;

    /* Local variables */
    static integer i__;

/*       Test if geophysical variables or switches changed and save */
/*       Return 0 if unchanged and 1 if changed */
    /* Parameter adjustments */
    --ap;

    /* Function Body */
    ret_val = (float)0.;
    if (*iyd != iydl[*ic - 1]) {
	goto L10;
    }
    if (*sec != secl[*ic - 1]) {
	goto L10;
    }
    if (*glat != glatl[*ic - 1]) {
	goto L10;
    }
    if (*glong != gll[*ic - 1]) {
	goto L10;
    }
    if (*stl != stll[*ic - 1]) {
	goto L10;
    }
    if (*f107a != fal[*ic - 1]) {
	goto L10;
    }
    if (*f107 != fl[*ic - 1]) {
	goto L10;
    }
    for (i__ = 1; i__ <= 7; ++i__) {
	if (ap[i__] != apl[i__ + *ic * 7 - 8]) {
	    goto L10;
	}
/* L5: */
    }
    for (i__ = 1; i__ <= 25; ++i__) {
	if (csw_1.sw[i__ - 1] != swl[i__ + *ic * 25 - 26]) {
	    goto L10;
	}
	if (csw_1.swc[i__ - 1] != swcl[i__ + *ic * 25 - 26]) {
	    goto L10;
	}
/* L7: */
    }
    goto L20;
L10:
    ret_val = (float)1.;
    iydl[*ic - 1] = *iyd;
    secl[*ic - 1] = *sec;
    glatl[*ic - 1] = *glat;
    gll[*ic - 1] = *glong;
    stll[*ic - 1] = *stl;
    fal[*ic - 1] = *f107a;
    fl[*ic - 1] = *f107;
    for (i__ = 1; i__ <= 7; ++i__) {
	apl[i__ + *ic * 7 - 8] = ap[i__];
/* L15: */
    }
    for (i__ = 1; i__ <= 25; ++i__) {
	swl[i__ + *ic * 25 - 26] = csw_1.sw[i__ - 1];
	swcl[i__ + *ic * 25 - 26] = csw_1.swc[i__ - 1];
/* L16: */
    }
L20:
    return ret_val;
} /* vtst_ */

/* ---------------------------------------------------------------- */
/* Subroutine */ int gts6_0_(n__, iyd, sec, alt, glat, glong, stl, f107a, 
	f107, ap, mass, d__, t, meter)
int n__;
integer *iyd;
real *sec, *alt, *glat, *glong, *stl, *f107a, *f107, *ap;
integer *mass;
real *d__, *t;
logical *meter;
{
    /* Initialized data */

    static integer mt[10] = { 48,0,4,16,28,32,40,1,49,14 };
    static real altl[8] = { (float)200.,(float)400.,(float)160.,(float)200.,(
	    float)240.,(float)450.,(float)320.,(float)450. };
    static integer mn1 = 5;
    static real zn1[5] = { (float)120.,(float)110.,(float)100.,(float)90.,(
	    float)72.5 };
    static real dgtr = (float).0174533;
    static real dr = (float).0172142;
    static real alast = (float)-999.;

    /* Format strings */
    static char fmt_100[] = "(1x,\002MASS\002,i5,\002  NOT VALID\002)";

    /* System generated locals */
    real r__1;

    /* Builtin functions */
    double r_mod(), sin(), cos();
    integer s_wsfe(), do_fio(), e_wsfe();
    double exp(), log();

    /* Local variables */
    static real hcc14, hcc16, zcc01, zcc14;
    extern doublereal ccor_();
    static real zcc16, ddum;
    extern doublereal dnet_();
    static real zhm01, tinf, zhm04, zhm32, zhm16, zhm40, zhm14, zhm28;
    extern doublereal vtst_();
    static integer i__, j;
    extern doublereal densu_();
    static real g1, g4, v2;
    extern doublereal globe6_(), glob6s_();
    static real b01, b04, b32, b16, g40, b28, g32, g16, b40, g14, g28, b14, 
	    tz, hc04, hc32, hc16, rc16, day, zc04, zh04, zlb, zhf, yrd, xmm, 
	    zh28, xmd, zh16, zc16, zh32, zc32, zh40, hc40, zc40, zh01, hc01, 
	    zc01, rc01, zh14, hc14, zc14, rc14, hcc01;

    /* Fortran I/O blocks */
    static cilist io___72 = { 0, 6, 0, fmt_100, 0 };


/*        Neutral Thermosphere Model above 72.5 km for MSISE-90 */
/*         A.E.Hedin 3/9/90 */
/*         Coefficients not changed for 120km and above, but results may differ */
/*        by a few percent from MSIS-86 (GTS5) with introduction of a */
/*        latitude dependent accel. of gravity. */
/*         Lower thermosphere reformulated for better continuation into */
/*        lower atmosphere. */
/*        For efficiency: */
/*         Exospheric temperature left at average value for alt below 120km; */
/*         120 km gradient left at average value for alt below 72 km; */
/*     INPUT: */
/*        IYD - YEAR AND DAY AS YYYYDDD */
/*        SEC - UT(SEC) */
/*        ALT - ALTITUDE(KM) (GREATER THAN 72.5 KM) */
/*        GLAT - GEODETIC LATITUDE(DEG) */
/*        GLONG - GEODETIC LONGITUDE(DEG) */
/*        STL - LOCAL APPARENT SOLAR TIME(HRS) */
/*        F107A - 3 MONTH AVERAGE OF F10.7 FLUX */
/*        F107 - DAILY F10.7 FLUX FOR PREVIOUS DAY */
/*        AP - MAGNETIC INDEX(DAILY) OR WHEN SW(9)=-1. : */
/*           - ARRAY CONTAINING: */
/*             (1) DAILY AP */
/*             (2) 3 HR AP INDEX FOR CURRENT TIME */
/*             (3) 3 HR AP INDEX FOR 3 HRS BEFORE CURRENT TIME */
/*             (4) 3 HR AP INDEX FOR 6 HRS BEFORE CURRENT TIME */
/*             (5) 3 HR AP INDEX FOR 9 HRS BEFORE CURRENT TIME */
/*             (6) AVERAGE OF EIGHT 3 HR AP INDICIES FROM 12 TO 33 HRS PRIOR */
/*                    TO CURRENT TIME */
/*             (7) AVERAGE OF EIGHT 3 HR AP INDICIES FROM 36 TO 59 HRS PRIOR */
/*                    TO CURRENT TIME */
/*        MASS - MASS NUMBER (ONLY DENSITY FOR SELECTED GAS IS */
/*                 CALCULATED.  MASS 0 IS TEMPERATURE.  MASS 48 FOR ALL. */
/*     Note:  Ut, Local Time, and Longitude are used independently in the */
/*            model and are not of equal importance for every situation. */
/*            For the most physically realistic calculation these three */
/*            variables should be consistent (STL=SEC/3600+GLONG/15). */
/*     OUTPUT: */
/*        D(1) - HE NUMBER DENSITY(CM-3) */
/*        D(2) - O NUMBER DENSITY(CM-3) */
/*        D(3) - N2 NUMBER DENSITY(CM-3) */
/*        D(4) - O2 NUMBER DENSITY(CM-3) */
/*        D(5) - AR NUMBER DENSITY(CM-3) */
/*        D(6) - TOTAL MASS DENSITY(GM/CM3) */
/*        D(7) - H NUMBER DENSITY(CM-3) */
/*        D(8) - N NUMBER DENSITY(CM-3) */
/*        T(1) - EXOSPHERIC TEMPERATURE */
/*        T(2) - TEMPERATURE AT ALT */

/*           The following is for test and special purposes: */
/*           (1) LOWER BOUND QUANTITIES IN COMMON/GTS3C/ */
/*           (2) TO TURN ON AND OFF PARTICULAR VARIATIONS CALL TSELEC(SW) */
/*               WHERE SW IS A 25 ELEMENT ARRAY CONTAINING 0. FOR OFF, 1. */
/*               FOR ON, OR 2. FOR MAIN EFFECTS OFF BUT CROSS TERMS ON */
/*               FOR THE FOLLOWING VARIATIONS */
/*               1 - F10.7 EFFECT ON MEAN  2 - TIME INDEPENDENT */
/*               3 - SYMMETRICAL ANNUAL    4 - SYMMETRICAL SEMIANNUAL */
/*               5 - ASYMMETRICAL ANNUAL   6 - ASYMMETRICAL SEMIANNUAL */
/*               7 - DIURNAL               8 - SEMIDIURNAL */
/*               9 - DAILY AP             10 - ALL UT/LONG EFFECTS */
/*              11 - LONGITUDINAL         12 - UT AND MIXED UT/LONG */
/*              13 - MIXED AP/UT/LONG     14 - TERDIURNAL */
/*              15 - DEPARTURES FROM DIFFUSIVE EQUILIBRIUM */
/*              16 - ALL TINF VAR         17 - ALL TLB VAR */
/*              18 - ALL TN1 VAR           19 - ALL S VAR */
/*              20 - ALL TN2 VAR           21 - ALL NLB VAR */
/*              22 - ALL TN3 VAR           23 - TURBO SCALE HEIGHT VAR */

/*              To get current values of SW: CALL TRETRV(SW) */

    /* Parameter adjustments */
    if (ap) {
	--ap;
	}
    if (d__) {
	--d__;
	}
    if (t) {
	--t;
	}

    /* Function Body */
    switch(n__) {
	case 1: goto L_meter6;
	}

/* e        Test for changed input */
    v2 = vtst_(iyd, sec, glat, glong, stl, f107a, f107, &ap[1], &c__2);

    yrd = (real) (*iyd);
    gts3c_1.za = parm6_1.pdl[40];
    zn1[0] = gts3c_1.za;
    for (j = 1; j <= 8; ++j) {
	d__[j] = (float)0.;
/* L2: */
    }
/* e       TINF VARIATIONS NOT IMPORTANT BELOW ZA OR ZN1(1) */
    if (*alt > zn1[0]) {
	if (v2 == (float)1. || alast <= zn1[0]) {
	    tinf = lower6_1.ptm[0] * parm6_1.pt[0] * (csw_1.sw[15] * globe6_(&
		    yrd, sec, glat, glong, stl, f107a, f107, &ap[1], 
		    parm6_1.pt) + (float)1.);
	}
    } else {
	tinf = lower6_1.ptm[0] * parm6_1.pt[0];
    }
    t[1] = tinf;
/* e         GRADIENT VARIATIONS NOT IMPORTANT BELOW ZN1(5) */
    if (*alt > zn1[4]) {
	if (v2 == (float)1. || alast <= zn1[4]) {
	    gts3c_1.g0 = lower6_1.ptm[3] * parm6_1.ps[0] * (csw_1.sw[18] * 
		    globe6_(&yrd, sec, glat, glong, stl, f107a, f107, &ap[1], 
		    parm6_1.ps) + (float)1.);
	}
    } else {
	gts3c_1.g0 = lower6_1.ptm[3] * parm6_1.ps[0];
    }
/* e      Calculate these temperatures only if input changed */
    if (v2 == (float)1.) {
	gts3c_1.tlb = lower6_1.ptm[1] * (csw_1.sw[16] * globe6_(&yrd, sec, 
		glat, glong, stl, f107a, f107, &ap[1], &parm6_1.pd[450]) + (
		float)1.) * parm6_1.pd[450];
    }
    gts3c_1.s = gts3c_1.g0 / (tinf - gts3c_1.tlb);
/* e       Lower thermosphere temp variations not significant for */
/* e        density above 300 km */
    if (*alt < (float)300.) {
	if (v2 == (float)1. || alast >= (float)300.) {
	    meso6_1.tn1[1] = lower6_1.ptm[6] * parm6_1.ptl[0] / ((float)1. - 
		    csw_1.sw[17] * glob6s_(parm6_1.ptl));
	    meso6_1.tn1[2] = lower6_1.ptm[2] * parm6_1.ptl[100] / ((float)1. 
		    - csw_1.sw[17] * glob6s_(&parm6_1.ptl[100]));
	    meso6_1.tn1[3] = lower6_1.ptm[7] * parm6_1.ptl[200] / ((float)1. 
		    - csw_1.sw[17] * glob6s_(&parm6_1.ptl[200]));
	    meso6_1.tn1[4] = lower6_1.ptm[4] * parm6_1.ptl[300] / ((float)1. 
		    - csw_1.sw[17] * csw_1.sw[19] * glob6s_(&parm6_1.ptl[300])
		    );
/* Computing 2nd power */
	    r__1 = lower6_1.ptm[4] * parm6_1.ptl[300];
	    meso6_1.tgn1[1] = lower6_1.ptm[8] * parm6_1.pma[800] * (csw_1.sw[
		    17] * csw_1.sw[19] * glob6s_(&parm6_1.pma[800]) + (float)
		    1.) * meso6_1.tn1[4] * meso6_1.tn1[4] / (r__1 * r__1);
	}
    } else {
	meso6_1.tn1[1] = lower6_1.ptm[6] * parm6_1.ptl[0];
	meso6_1.tn1[2] = lower6_1.ptm[2] * parm6_1.ptl[100];
	meso6_1.tn1[3] = lower6_1.ptm[7] * parm6_1.ptl[200];
	meso6_1.tn1[4] = lower6_1.ptm[4] * parm6_1.ptl[300];
/* Computing 2nd power */
	r__1 = lower6_1.ptm[4] * parm6_1.ptl[300];
	meso6_1.tgn1[1] = lower6_1.ptm[8] * parm6_1.pma[800] * meso6_1.tn1[4] 
		* meso6_1.tn1[4] / (r__1 * r__1);
    }

    gts3c_1.z0 = zn1[3];
    gts3c_1.t0 = meso6_1.tn1[3];
    zlb = lower6_1.ptm[5];
    gts3c_1.tr12 = (float)1.;

    if (*mass == 0) {
	goto L50;
    }
/*       N2 variation factor at Zlb */
    g28 = csw_1.sw[20] * globe6_(&yrd, sec, glat, glong, stl, f107a, f107, &
	    ap[1], &parm6_1.pd[300]);
/*        Variation of turbopause height */
    day = r_mod(&yrd, &c_b36);
    zhf = parm6_1.pdl[49] * (csw_1.sw[4] * parm6_1.pdl[24] * sin(dgtr * *glat)
	     * cos(dr * (day - parm6_1.pt[13])) + (float)1.);

    yrd = (real) (*iyd);
    t[1] = tinf;
    xmm = lower6_1.pdm[24];

    for (j = 1; j <= 10; ++j) {
	if (*mass == mt[j - 1]) {
	    goto L15;
	}
/* L10: */
    }
    s_wsfe(&io___72);
    do_fio(&c__1, (char *)&(*mass), (ftnlen)sizeof(integer));
    e_wsfe();
    goto L90;
L15:
    if (*alt > altl[5] && *mass != 28 && *mass != 48) {
	goto L17;
    }

/*       **** N2 DENSITY **** */

/*      Diffusive density at Zlb */
    gts3c_1.db28 = lower6_1.pdm[20] * exp(g28) * parm6_1.pd[300];
/*      Diffusive density at Alt */
    d__[3] = densu_(alt, &gts3c_1.db28, &tinf, &gts3c_1.tlb, &c_b44, &c_b45, &
	    t[2], &zlb, &gts3c_1.s, &mn1, zn1, meso6_1.tn1, meso6_1.tgn1);
    gts3c_1.dd = d__[3];
/*      Turbopause */
    zh28 = lower6_1.pdm[22] * zhf;
    zhm28 = lower6_1.pdm[23] * parm6_1.pdl[30];
    xmd = (float)28. - xmm;
/*      Mixed density at Zlb */
    b28 = densu_(&zh28, &gts3c_1.db28, &tinf, &gts3c_1.tlb, &xmd, &c_b46, &tz,
	     &zlb, &gts3c_1.s, &mn1, zn1, meso6_1.tn1, meso6_1.tgn1);
    if (*alt > altl[2] || csw_1.sw[14] == (float)0.) {
	goto L17;
    }
/*      Mixed density at Alt */
    dmix_1.dm28 = densu_(alt, &b28, &tinf, &gts3c_1.tlb, &xmm, &c_b45, &tz, &
	    zlb, &gts3c_1.s, &mn1, zn1, meso6_1.tn1, meso6_1.tgn1);
/*      Net density at Alt */
    d__[3] = dnet_(&d__[3], &dmix_1.dm28, &zhm28, &xmm, &c_b44);
L17:
    switch ((int)j) {
	case 1:  goto L20;
	case 2:  goto L50;
	case 3:  goto L20;
	case 4:  goto L25;
	case 5:  goto L90;
	case 6:  goto L35;
	case 7:  goto L40;
	case 8:  goto L45;
	case 9:  goto L25;
	case 10:  goto L48;
    }
L20:

/*       **** HE DENSITY **** */

/*       Density variation factor at Zlb */
    g4 = csw_1.sw[20] * globe6_(&yrd, sec, glat, glong, stl, f107a, f107, &ap[
	    1], parm6_1.pd);
/*      Diffusive density at Zlb */
    gts3c_1.db04 = lower6_1.pdm[0] * exp(g4) * parm6_1.pd[0];
/*      Diffusive density at Alt */
    d__[1] = densu_(alt, &gts3c_1.db04, &tinf, &gts3c_1.tlb, &c_b55, &c_b56, &
	    t[2], &zlb, &gts3c_1.s, &mn1, zn1, meso6_1.tn1, meso6_1.tgn1);
    gts3c_1.dd = d__[1];
    if (*alt > altl[0] || csw_1.sw[14] == (float)0.) {
	goto L24;
    }
/*      Turbopause */
    zh04 = lower6_1.pdm[2];
    zhm04 = zhm28;
/*      Mixed density at Zlb */
    r__1 = (float)4. - xmm;
    b04 = densu_(&zh04, &gts3c_1.db04, &tinf, &gts3c_1.tlb, &r__1, &c_b58, &t[
	    2], &zlb, &gts3c_1.s, &mn1, zn1, meso6_1.tn1, meso6_1.tgn1);
/*      Mixed density at Alt */
    dmix_1.dm04 = densu_(alt, &b04, &tinf, &gts3c_1.tlb, &xmm, &c_b45, &t[2], 
	    &zlb, &gts3c_1.s, &mn1, zn1, meso6_1.tn1, meso6_1.tgn1);
/*      Net density at Alt */
    d__[1] = dnet_(&d__[1], &dmix_1.dm04, &zhm04, &xmm, &c_b55);
/*      Correction to specified mixing ratio at ground */
    gts3c_1.rl = log(b28 * lower6_1.pdm[1] / b04);
    zc04 = lower6_1.pdm[4] * parm6_1.pdl[25];
    hc04 = lower6_1.pdm[5] * parm6_1.pdl[26];
/*      Net density corrected at Alt */
    d__[1] *= ccor_(alt, &gts3c_1.rl, &hc04, &zc04);
L24:
    if (*mass != 48) {
	goto L90;
    }
L25:

/*      **** O DENSITY **** */

/*       Density variation factor at Zlb */
    g16 = csw_1.sw[20] * globe6_(&yrd, sec, glat, glong, stl, f107a, f107, &
	    ap[1], &parm6_1.pd[150]);
/*      Diffusive density at Zlb */
    gts3c_1.db16 = lower6_1.pdm[10] * exp(g16) * parm6_1.pd[150];
/*       Diffusive density at Alt */
    d__[2] = densu_(alt, &gts3c_1.db16, &tinf, &gts3c_1.tlb, &c_b61, &c_b45, &
	    t[2], &zlb, &gts3c_1.s, &mn1, zn1, meso6_1.tn1, meso6_1.tgn1);
    gts3c_1.dd = d__[2];
    if (*alt > altl[1] || csw_1.sw[14] == (float)0.) {
	goto L34;
    }
/*  Corrected from PDM(3,1) to PDM(3,2)  12/2/85 */
/*       Turbopause */
    zh16 = lower6_1.pdm[12];
    zhm16 = zhm28;
/*      Mixed density at Zlb */
    r__1 = 16 - xmm;
    b16 = densu_(&zh16, &gts3c_1.db16, &tinf, &gts3c_1.tlb, &r__1, &c_b46, &t[
	    2], &zlb, &gts3c_1.s, &mn1, zn1, meso6_1.tn1, meso6_1.tgn1);
/*      Mixed density at Alt */
    dmix_1.dm16 = densu_(alt, &b16, &tinf, &gts3c_1.tlb, &xmm, &c_b45, &t[2], 
	    &zlb, &gts3c_1.s, &mn1, zn1, meso6_1.tn1, meso6_1.tgn1);
/*      Net density at Alt */
    d__[2] = dnet_(&d__[2], &dmix_1.dm16, &zhm16, &xmm, &c_b61);
/*       Correction to specified mixing ratio at ground */
    gts3c_1.rl = log(b28 * lower6_1.pdm[11] * dabs(parm6_1.pdl[41]) / b16);
    hc16 = lower6_1.pdm[15] * parm6_1.pdl[28];
    zc16 = lower6_1.pdm[14] * parm6_1.pdl[27];
    d__[2] *= ccor_(alt, &gts3c_1.rl, &hc16, &zc16);
/*       Chemistry correction */
    hcc16 = lower6_1.pdm[17] * parm6_1.pdl[38];
    zcc16 = lower6_1.pdm[16] * parm6_1.pdl[37];
    rc16 = lower6_1.pdm[13] * parm6_1.pdl[39];
/*      Net density corrected at Alt */
    d__[2] *= ccor_(alt, &rc16, &hcc16, &zcc16);
L34:
    if (*mass != 48 && *mass != 49) {
	goto L90;
    }
L35:

/*       **** O2 DENSITY **** */

/*       Density variation factor at Zlb */
    g32 = csw_1.sw[20] * globe6_(&yrd, sec, glat, glong, stl, f107a, f107, &
	    ap[1], &parm6_1.pd[600]);
/*      Diffusive density at Zlb */
    gts3c_1.db32 = lower6_1.pdm[30] * exp(g32) * parm6_1.pd[600];
/*       Diffusive density at Alt */
    d__[4] = densu_(alt, &gts3c_1.db32, &tinf, &gts3c_1.tlb, &c_b67, &c_b45, &
	    t[2], &zlb, &gts3c_1.s, &mn1, zn1, meso6_1.tn1, meso6_1.tgn1);
    if (*mass == 49) {
	gts3c_1.dd += d__[4] * (float)2.;
    } else {
	gts3c_1.dd = d__[4];
    }
    if (*alt > altl[3] || csw_1.sw[14] == (float)0.) {
	goto L39;
    }
/*       Turbopause */
    zh32 = lower6_1.pdm[32];
    zhm32 = zhm28;
/*      Mixed density at Zlb */
    r__1 = (float)32. - xmm;
    b32 = densu_(&zh32, &gts3c_1.db32, &tinf, &gts3c_1.tlb, &r__1, &c_b46, &t[
	    2], &zlb, &gts3c_1.s, &mn1, zn1, meso6_1.tn1, meso6_1.tgn1);
/*      Mixed density at Alt */
    dmix_1.dm32 = densu_(alt, &b32, &tinf, &gts3c_1.tlb, &xmm, &c_b45, &t[2], 
	    &zlb, &gts3c_1.s, &mn1, zn1, meso6_1.tn1, meso6_1.tgn1);
/*      Net density at Alt */
    d__[4] = dnet_(&d__[4], &dmix_1.dm32, &zhm32, &xmm, &c_b67);
/*       Correction to specified mixing ratio at ground */
    gts3c_1.rl = log(b28 * lower6_1.pdm[31] / b32);
    hc32 = lower6_1.pdm[35] * parm6_1.pdl[32];
    zc32 = lower6_1.pdm[34] * parm6_1.pdl[31];
/*      Net density corrected at Alt */
    d__[4] *= ccor_(alt, &gts3c_1.rl, &hc32, &zc32);
L39:
    if (*mass != 48) {
	goto L90;
    }
L40:

/*       **** AR DENSITY **** */

/*       Density variation factor at Zlb */
    g40 = csw_1.sw[20] * globe6_(&yrd, sec, glat, glong, stl, f107a, f107, &
	    ap[1], &parm6_1.pd[750]);
/*      Diffusive density at Zlb */
    gts3c_1.db40 = lower6_1.pdm[40] * exp(g40) * parm6_1.pd[750];
/*       Diffusive density at Alt */
    d__[5] = densu_(alt, &gts3c_1.db40, &tinf, &gts3c_1.tlb, &c_b73, &c_b45, &
	    t[2], &zlb, &gts3c_1.s, &mn1, zn1, meso6_1.tn1, meso6_1.tgn1);
    gts3c_1.dd = d__[5];
    if (*alt > altl[4] || csw_1.sw[14] == (float)0.) {
	goto L44;
    }
/*       Turbopause */
    zh40 = lower6_1.pdm[42];
    zhm40 = zhm28;
/*      Mixed density at Zlb */
    r__1 = (float)40. - xmm;
    b40 = densu_(&zh40, &gts3c_1.db40, &tinf, &gts3c_1.tlb, &r__1, &c_b46, &t[
	    2], &zlb, &gts3c_1.s, &mn1, zn1, meso6_1.tn1, meso6_1.tgn1);
/*      Mixed density at Alt */
    dmix_1.dm40 = densu_(alt, &b40, &tinf, &gts3c_1.tlb, &xmm, &c_b45, &t[2], 
	    &zlb, &gts3c_1.s, &mn1, zn1, meso6_1.tn1, meso6_1.tgn1);
/*      Net density at Alt */
    d__[5] = dnet_(&d__[5], &dmix_1.dm40, &zhm40, &xmm, &c_b73);
/*       Correction to specified mixing ratio at ground */
    gts3c_1.rl = log(b28 * lower6_1.pdm[41] / b40);
    hc40 = lower6_1.pdm[45] * parm6_1.pdl[34];
    zc40 = lower6_1.pdm[44] * parm6_1.pdl[33];
/*      Net density corrected at Alt */
    d__[5] *= ccor_(alt, &gts3c_1.rl, &hc40, &zc40);
L44:
    if (*mass != 48) {
	goto L90;
    }
L45:

/*        **** HYDROGEN DENSITY **** */

/*       Density variation factor at Zlb */
    g1 = csw_1.sw[20] * globe6_(&yrd, sec, glat, glong, stl, f107a, f107, &ap[
	    1], &parm6_1.pd[900]);
/*      Diffusive density at Zlb */
    gts3c_1.db01 = lower6_1.pdm[50] * exp(g1) * parm6_1.pd[900];
/*       Diffusive density at Alt */
    d__[7] = densu_(alt, &gts3c_1.db01, &tinf, &gts3c_1.tlb, &c_b14, &c_b56, &
	    t[2], &zlb, &gts3c_1.s, &mn1, zn1, meso6_1.tn1, meso6_1.tgn1);
    gts3c_1.dd = d__[7];
    if (*alt > altl[6] || csw_1.sw[14] == (float)0.) {
	goto L47;
    }
/*       Turbopause */
    zh01 = lower6_1.pdm[52];
    zhm01 = zhm28;
/*      Mixed density at Zlb */
    r__1 = (float)1. - xmm;
    b01 = densu_(&zh01, &gts3c_1.db01, &tinf, &gts3c_1.tlb, &r__1, &c_b58, &t[
	    2], &zlb, &gts3c_1.s, &mn1, zn1, meso6_1.tn1, meso6_1.tgn1);
/*      Mixed density at Alt */
    dmix_1.dm01 = densu_(alt, &b01, &tinf, &gts3c_1.tlb, &xmm, &c_b45, &t[2], 
	    &zlb, &gts3c_1.s, &mn1, zn1, meso6_1.tn1, meso6_1.tgn1);
/*      Net density at Alt */
    d__[7] = dnet_(&d__[7], &dmix_1.dm01, &zhm01, &xmm, &c_b14);
/*       Correction to specified mixing ratio at ground */
    gts3c_1.rl = log(b28 * lower6_1.pdm[51] * dabs(parm6_1.pdl[42]) / b01);
    hc01 = lower6_1.pdm[55] * parm6_1.pdl[36];
    zc01 = lower6_1.pdm[54] * parm6_1.pdl[35];
    d__[7] *= ccor_(alt, &gts3c_1.rl, &hc01, &zc01);
/*       Chemistry correction */
    hcc01 = lower6_1.pdm[57] * parm6_1.pdl[44];
    zcc01 = lower6_1.pdm[56] * parm6_1.pdl[43];
    rc01 = lower6_1.pdm[53] * parm6_1.pdl[45];
/*      Net density corrected at Alt */
    d__[7] *= ccor_(alt, &rc01, &hcc01, &zcc01);
L47:
L48:

/*        **** ATOMIC NITROGEN DENSITY **** */

/*       Density variation factor at Zlb */
    g14 = csw_1.sw[20] * globe6_(&yrd, sec, glat, glong, stl, f107a, f107, &
	    ap[1], &parm6_1.pd[1050]);
/*      Diffusive density at Zlb */
    gts3c_1.db14 = lower6_1.pdm[60] * exp(g14) * parm6_1.pd[1050];
/*       Diffusive density at Alt */
    d__[8] = densu_(alt, &gts3c_1.db14, &tinf, &gts3c_1.tlb, &c_b85, &c_b45, &
	    t[2], &zlb, &gts3c_1.s, &mn1, zn1, meso6_1.tn1, meso6_1.tgn1);
    gts3c_1.dd = d__[8];
    if (*alt > altl[7] || csw_1.sw[14] == (float)0.) {
	goto L49;
    }
/*       Turbopause */
    zh14 = lower6_1.pdm[62];
    zhm14 = zhm28;
/*      Mixed density at Zlb */
    r__1 = (float)14. - xmm;
    b14 = densu_(&zh14, &gts3c_1.db14, &tinf, &gts3c_1.tlb, &r__1, &c_b46, &t[
	    2], &zlb, &gts3c_1.s, &mn1, zn1, meso6_1.tn1, meso6_1.tgn1);
/*      Mixed density at Alt */
    dmix_1.dm14 = densu_(alt, &b14, &tinf, &gts3c_1.tlb, &xmm, &c_b45, &t[2], 
	    &zlb, &gts3c_1.s, &mn1, zn1, meso6_1.tn1, meso6_1.tgn1);
/*      Net density at Alt */
    d__[8] = dnet_(&d__[8], &dmix_1.dm14, &zhm14, &xmm, &c_b85);
/*       Correction to specified mixing ratio at ground */
    gts3c_1.rl = log(b28 * lower6_1.pdm[61] * dabs(parm6_1.pdl[2]) / b14);
    hc14 = lower6_1.pdm[65] * parm6_1.pdl[1];
    zc14 = lower6_1.pdm[64] * parm6_1.pdl[0];
    d__[8] *= ccor_(alt, &gts3c_1.rl, &hc14, &zc14);
/*       Chemistry correction */
    hcc14 = lower6_1.pdm[67] * parm6_1.pdl[4];
    zcc14 = lower6_1.pdm[66] * parm6_1.pdl[3];
    rc14 = lower6_1.pdm[63] * parm6_1.pdl[5];
/*      Net density corrected at Alt */
    d__[8] *= ccor_(alt, &rc14, &hcc14, &zcc14);
L49:
    if (*mass != 48) {
	goto L90;
    }

/*       TOTAL MASS DENSITY */

    d__[6] = (d__[1] * (float)4. + d__[2] * (float)16. + d__[3] * (float)28. 
	    + d__[4] * (float)32. + d__[5] * (float)40. + d__[7] + d__[8] * (
	    float)14.) * (float)1.66e-24;
    gts3c_1.db48 = (gts3c_1.db04 * (float)4. + gts3c_1.db16 * (float)16. + 
	    gts3c_1.db28 * (float)28. + gts3c_1.db32 * (float)32. + 
	    gts3c_1.db40 * (float)40. + gts3c_1.db01 + gts3c_1.db14 * (float)
	    14.) * (float)1.66e-24;
    goto L90;
/*       TEMPERATURE AT ALTITUDE */
L50:
    ddum = densu_(alt, &c_b14, &tinf, &gts3c_1.tlb, &c_b45, &c_b45, &t[2], &
	    zlb, &gts3c_1.s, &mn1, zn1, meso6_1.tn1, meso6_1.tgn1);
    goto L90;
L90:
/*       ADJUST DENSITIES FROM CGS TO KGM */
    if (metsel_1.imr == 1) {
	for (i__ = 1; i__ <= 8; ++i__) {
	    d__[i__] *= (float)1e6;
/* L95: */
	}
	d__[6] /= (float)1e3;
    }
    alast = *alt;
    return 0;

L_meter6:
    metsel_1.imr = 0;
    if (*meter) {
	metsel_1.imr = 1;
    }
} /* gts6_ */

/* Subroutine */ int gts6_(iyd, sec, alt, glat, glong, stl, f107a, f107, ap, 
	mass, d__, t)
integer *iyd;
real *sec, *alt, *glat, *glong, *stl, *f107a, *f107, *ap;
integer *mass;
real *d__, *t;
{
    return gts6_0_(0, iyd, sec, alt, glat, glong, stl, f107a, f107, ap, mass, 
	    d__, t, (logical *)0);
    }

/* Subroutine */ int meter6_(meter)
logical *meter;
{
    return gts6_0_(1, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, (real *)0, (integer *)0, (
	    real *)0, (real *)0, meter);
    }

/* ---------------------------------------------------------------- */
doublereal globe6_(yrd, sec, lat, long__, tloc, f107a, f107, ap, p)
real *yrd, *sec, *lat, *long__, *tloc, *f107a, *f107, *ap, *p;
{
    /* Initialized data */

    static real dgtr = (float).0174533;
    static real dr = (float).0172142;
    static real xl = (float)1e3;
    static real tll = (float)1e3;
    static real sw9 = (float)1.;
    static real dayl = (float)-1.;
    static real p14 = (float)-1e3;
    static real p18 = (float)-1e3;
    static real p32 = (float)-1e3;
    static real hr = (float).2618;
    static real sr = (float)7.2722e-5;
    static real sv[25] = { (float)1.,(float)1.,(float)1.,(float)1.,(float)1.,(
	    float)1.,(float)1.,(float)1.,(float)1.,(float)1.,(float)1.,(float)
	    1.,(float)1.,(float)1.,(float)1.,(float)1.,(float)1.,(float)1.,(
	    float)1.,(float)1.,(float)1.,(float)1.,(float)1.,(float)1.,(float)
	    1. };
    static integer nsw = 14;
    static real p39 = (float)-1e3;
    static real longl = (float)-999.;

    /* System generated locals */
    integer i__1;
    real ret_val, r__1, r__2, r__3, r__4, r__5, r__6;
    doublereal d__1;

    /* Builtin functions */
    double sin(), cos(), exp(), pow_dd();

    /* Local variables */
    static real c__;
    static integer i__, j;
    static real s, c2, c4, f1, f2, s2, p44, p45, t71, t72, t81, t82;
    extern /* Subroutine */ int tselec_();
    static real cd14, cd32, cd18, cd39, exp1, exp2;

/*       CALCULATE G(L) FUNCTION */
/*       Upper Thermosphere Parameters */
    /* Parameter adjustments */
    --p;
    --ap;

    /* Function Body */
/*       3hr Magnetica activity functions */

    if (csw_1.isw != 64999) {
	tselec_(sv);
    }
    for (j = 1; j <= 14; ++j) {
	ttest_2.t[j - 1] = (float)0.;
/* L10: */
    }
    if (csw_1.sw[8] > (float)0.) {
	sw9 = (float)1.;
    }
    if (csw_1.sw[8] < (float)0.) {
	sw9 = (float)-1.;
    }
    lpoly_1.iyr = *yrd / (float)1e3;
    lpoly_1.day = *yrd - lpoly_1.iyr * (float)1e3;
    lpoly_1.xlong = *long__;
    if (xl == *lat) {
	goto L15;
    }
/*          CALCULATE LEGENDRE POLYNOMIALS */
    c__ = sin(*lat * dgtr);
    s = cos(*lat * dgtr);
    c2 = c__ * c__;
    c4 = c2 * c2;
    s2 = s * s;
    lpoly_1.plg[1] = c__;
    lpoly_1.plg[2] = (c2 * (float)3. - (float)1.) * (float).5;
    lpoly_1.plg[3] = (c__ * (float)5. * c2 - c__ * (float)3.) * (float).5;
    lpoly_1.plg[4] = (c4 * (float)35. - c2 * (float)30. + (float)3.) / (float)
	    8.;
    lpoly_1.plg[5] = (c2 * (float)63. * c2 * c__ - c2 * (float)70. * c__ + 
	    c__ * (float)15.) / (float)8.;
    lpoly_1.plg[6] = (c__ * (float)11. * lpoly_1.plg[5] - lpoly_1.plg[4] * (
	    float)5.) / (float)6.;
/*     PLG(8,1) = (13.*C*PLG(7,1) - 6.*PLG(6,1))/7. */
    lpoly_1.plg[10] = s;
    lpoly_1.plg[11] = c__ * (float)3. * s;
    lpoly_1.plg[12] = (c2 * (float)5. - (float)1.) * (float)1.5 * s;
    lpoly_1.plg[13] = (c2 * (float)7. * c__ - c__ * (float)3.) * (float)2.5 * 
	    s;
    lpoly_1.plg[14] = (c4 * (float)21. - c2 * (float)14. + (float)1.) * (
	    float)1.875 * s;
    lpoly_1.plg[15] = (c__ * (float)11. * lpoly_1.plg[14] - lpoly_1.plg[13] * 
	    (float)6.) / (float)5.;
/*     PLG(8,2) = (13.*C*PLG(7,2)-7.*PLG(6,2))/6. */
/*     PLG(9,2) = (15.*C*PLG(8,2)-8.*PLG(7,2))/7. */
    lpoly_1.plg[20] = s2 * (float)3.;
    lpoly_1.plg[21] = s2 * (float)15. * c__;
    lpoly_1.plg[22] = (c2 * (float)7. - (float)1.) * (float)7.5 * s2;
    lpoly_1.plg[23] = c__ * (float)3. * lpoly_1.plg[22] - lpoly_1.plg[21] * (
	    float)2.;
    lpoly_1.plg[24] = (c__ * (float)11. * lpoly_1.plg[23] - lpoly_1.plg[22] * 
	    (float)7.) / (float)4.;
    lpoly_1.plg[25] = (c__ * (float)13. * lpoly_1.plg[24] - lpoly_1.plg[23] * 
	    (float)8.) / (float)5.;
    lpoly_1.plg[30] = s2 * (float)15. * s;
    lpoly_1.plg[31] = s2 * (float)105. * s * c__;
    lpoly_1.plg[32] = (c__ * (float)9. * lpoly_1.plg[31] - lpoly_1.plg[30] * (
	    float)7.) / (float)2.;
    lpoly_1.plg[33] = (c__ * (float)11. * lpoly_1.plg[32] - lpoly_1.plg[31] * 
	    (float)8.) / (float)3.;
    xl = *lat;
L15:
    if (tll == *tloc) {
	goto L16;
    }
    if (csw_1.sw[6] == (float)0. && csw_1.sw[7] == (float)0. && csw_1.sw[13] 
	    == (float)0.) {
	goto L16;
    }
    lpoly_1.stloc = sin(hr * *tloc);
    lpoly_1.ctloc = cos(hr * *tloc);
    lpoly_1.s2tloc = sin(hr * (float)2. * *tloc);
    lpoly_1.c2tloc = cos(hr * (float)2. * *tloc);
    lpoly_1.s3tloc = sin(hr * (float)3. * *tloc);
    lpoly_1.c3tloc = cos(hr * (float)3. * *tloc);
    tll = *tloc;
L16:
    if (*long__ != longl) {
	lpoly_1.clong = cos(dgtr * *long__);
	lpoly_1.slong = sin(dgtr * *long__);
    }
    longl = *long__;
    if (lpoly_1.day != dayl || p[14] != p14) {
	cd14 = cos(dr * (lpoly_1.day - p[14]));
    }
    if (lpoly_1.day != dayl || p[18] != p18) {
	cd18 = cos(dr * (float)2. * (lpoly_1.day - p[18]));
    }
    if (lpoly_1.day != dayl || p[32] != p32) {
	cd32 = cos(dr * (lpoly_1.day - p[32]));
    }
    if (lpoly_1.day != dayl || p[39] != p39) {
	cd39 = cos(dr * (float)2. * (lpoly_1.day - p[39]));
    }
    dayl = lpoly_1.day;
    p14 = p[14];
    p18 = p[18];
    p32 = p[32];
    p39 = p[39];
/*         F10.7 EFFECT */
    lpoly_1.df = *f107 - *f107a;
    lpoly_1.dfa = *f107a - (float)150.;
/* Computing 2nd power */
    r__1 = lpoly_1.dfa;
    ttest_2.t[0] = p[20] * lpoly_1.df + p[21] * lpoly_1.df * lpoly_1.df + p[
	    22] * lpoly_1.dfa + p[30] * (r__1 * r__1);
    f1 = (p[48] * lpoly_1.dfa + p[20] * lpoly_1.df + p[21] * lpoly_1.df * 
	    lpoly_1.df) * csw_1.swc[0] + (float)1.;
    f2 = (p[50] * lpoly_1.dfa + p[20] * lpoly_1.df + p[21] * lpoly_1.df * 
	    lpoly_1.df) * csw_1.swc[0] + (float)1.;
/*        TIME INDEPENDENT */
    ttest_2.t[1] = p[2] * lpoly_1.plg[2] + p[3] * lpoly_1.plg[4] + p[23] * 
	    lpoly_1.plg[6] + p[15] * lpoly_1.plg[2] * lpoly_1.dfa * csw_1.swc[
	    0] + p[27] * lpoly_1.plg[1];
/*        SYMMETRICAL ANNUAL */
    ttest_2.t[2] = p[19] * cd32;
/*        SYMMETRICAL SEMIANNUAL */
    ttest_2.t[3] = (p[16] + p[17] * lpoly_1.plg[2]) * cd18;
/*        ASYMMETRICAL ANNUAL */
    ttest_2.t[4] = f1 * (p[10] * lpoly_1.plg[1] + p[11] * lpoly_1.plg[3]) * 
	    cd14;
/*         ASYMMETRICAL SEMIANNUAL */
    ttest_2.t[5] = p[38] * lpoly_1.plg[1] * cd39;
/*        DIURNAL */
    if (csw_1.sw[6] == (float)0.) {
	goto L200;
    }
    t71 = p[12] * lpoly_1.plg[11] * cd14 * csw_1.swc[4];
    t72 = p[13] * lpoly_1.plg[11] * cd14 * csw_1.swc[4];
    ttest_2.t[6] = f2 * ((p[4] * lpoly_1.plg[10] + p[5] * lpoly_1.plg[12] + p[
	    28] * lpoly_1.plg[14] + t71) * lpoly_1.ctloc + (p[7] * 
	    lpoly_1.plg[10] + p[8] * lpoly_1.plg[12] + p[29] * lpoly_1.plg[14]
	     + t72) * lpoly_1.stloc);
L200:
/*        SEMIDIURNAL */
    if (csw_1.sw[7] == (float)0.) {
	goto L210;
    }
    t81 = (p[24] * lpoly_1.plg[21] + p[36] * lpoly_1.plg[23]) * cd14 * 
	    csw_1.swc[4];
    t82 = (p[34] * lpoly_1.plg[21] + p[37] * lpoly_1.plg[23]) * cd14 * 
	    csw_1.swc[4];
    ttest_2.t[7] = f2 * ((p[6] * lpoly_1.plg[20] + p[42] * lpoly_1.plg[22] + 
	    t81) * lpoly_1.c2tloc + (p[9] * lpoly_1.plg[20] + p[43] * 
	    lpoly_1.plg[22] + t82) * lpoly_1.s2tloc);
L210:
/*        TERDIURNAL */
    if (csw_1.sw[13] == (float)0.) {
	goto L220;
    }
    ttest_2.t[13] = f2 * ((p[40] * lpoly_1.plg[30] + (p[94] * lpoly_1.plg[31] 
	    + p[47] * lpoly_1.plg[33]) * cd14 * csw_1.swc[4]) * 
	    lpoly_1.s3tloc + (p[41] * lpoly_1.plg[30] + (p[95] * lpoly_1.plg[
	    31] + p[49] * lpoly_1.plg[33]) * cd14 * csw_1.swc[4]) * 
	    lpoly_1.c3tloc);
L220:
/*          MAGNETIC ACTIVITY BASED ON DAILY AP */
    if (sw9 == (float)-1.) {
	goto L30;
    }
    lpoly_1.apd = ap[1] - (float)4.;
    p44 = p[44];
    p45 = p[45];
    if (p44 < (float)0.) {
	p44 = (float)1e-5;
    }
    lpoly_1.apdf = lpoly_1.apd + (p45 - (float)1.) * (lpoly_1.apd + (exp(-p44 
	    * lpoly_1.apd) - (float)1.) / p44);
    if (csw_1.sw[8] == (float)0.) {
	goto L40;
    }
    ttest_2.t[8] = lpoly_1.apdf * (p[33] + p[46] * lpoly_1.plg[2] + p[35] * 
	    lpoly_1.plg[4] + (p[101] * lpoly_1.plg[1] + p[102] * lpoly_1.plg[
	    3] + p[103] * lpoly_1.plg[5]) * cd14 * csw_1.swc[4] + (p[122] * 
	    lpoly_1.plg[10] + p[123] * lpoly_1.plg[12] + p[124] * lpoly_1.plg[
	    14]) * csw_1.swc[6] * cos(hr * (*tloc - p[125])));
    goto L40;
L30:
    if (p[52] == (float)0.) {
	goto L40;
    }
    exp1 = exp(dabs(p[52]) * (float)-10800. / (p[139] * ((float)45. - dabs(*
	    lat)) + (float)1.));
    if (exp1 > (float).99999) {
	exp1 = (float).99999;
    }
    exp2 = exp(dabs(p[54]) * (float)-10800.);
    if (exp2 > (float).99999) {
	exp2 = (float).99999;
    }
    if (p[25] < (float)1e-4) {
	p[25] = (float)1e-4;
    }
/* Computing 3rd power */
    r__1 = exp1;
/* Computing 4th power */
    r__2 = exp1, r__2 *= r__2;
/* Computing 12th power */
    r__3 = exp1, r__3 *= r__3, r__3 *= r__3;
/* Computing 8th power */
    r__4 = exp1, r__4 *= r__4, r__4 *= r__4;
/* Computing 19th power */
    r__5 = exp1, r__6 = r__5, r__5 *= r__5, r__6 *= r__5, r__5 *= r__5, r__5 
	    *= r__5;
    d__1 = (doublereal) exp1;
    lpoly_1.apt[0] = (ap[2] - (float)4. + (p[26] - (float)1.) * (ap[2] - (
	    float)4. + (exp(-dabs(p[25]) * (ap[2] - (float)4.)) - (float)1.) /
	     dabs(p[25])) + ((ap[3] - (float)4. + (p[26] - (float)1.) * (ap[3]
	     - (float)4. + (exp(-dabs(p[25]) * (ap[3] - (float)4.)) - (float)
	    1.) / dabs(p[25]))) * exp1 + (ap[4] - (float)4. + (p[26] - (float)
	    1.) * (ap[4] - (float)4. + (exp(-dabs(p[25]) * (ap[4] - (float)4.)
	    ) - (float)1.) / dabs(p[25]))) * exp1 * exp1 + (ap[5] - (float)4. 
	    + (p[26] - (float)1.) * (ap[5] - (float)4. + (exp(-dabs(p[25]) * (
	    ap[5] - (float)4.)) - (float)1.) / dabs(p[25]))) * (r__1 * (r__1 *
	     r__1)) + ((ap[6] - (float)4. + (p[26] - (float)1.) * (ap[6] - (
	    float)4. + (exp(-dabs(p[25]) * (ap[6] - (float)4.)) - (float)1.) /
	     dabs(p[25]))) * (r__2 * r__2) + (ap[7] - (float)4. + (p[26] - (
	    float)1.) * (ap[7] - (float)4. + (exp(-dabs(p[25]) * (ap[7] - (
	    float)4.)) - (float)1.) / dabs(p[25]))) * (r__3 * (r__3 * r__3))) 
	    * ((float)1. - r__4 * r__4) / ((float)1. - exp1))) / ((float)1. + 
	    ((float)1. - r__6 * (r__5 * r__5)) / ((float)1. - exp1) * pow_dd(&
	    d__1, &c_b104));
/* Computing 3rd power */
    r__1 = exp2;
/* Computing 4th power */
    r__2 = exp2, r__2 *= r__2;
/* Computing 12th power */
    r__3 = exp2, r__3 *= r__3, r__3 *= r__3;
/* Computing 8th power */
    r__4 = exp2, r__4 *= r__4, r__4 *= r__4;
/* Computing 19th power */
    r__5 = exp2, r__6 = r__5, r__5 *= r__5, r__6 *= r__5, r__5 *= r__5, r__5 
	    *= r__5;
    d__1 = (doublereal) exp2;
    lpoly_1.apt[2] = (ap[2] - (float)4. + (p[26] - (float)1.) * (ap[2] - (
	    float)4. + (exp(-dabs(p[25]) * (ap[2] - (float)4.)) - (float)1.) /
	     dabs(p[25])) + ((ap[3] - (float)4. + (p[26] - (float)1.) * (ap[3]
	     - (float)4. + (exp(-dabs(p[25]) * (ap[3] - (float)4.)) - (float)
	    1.) / dabs(p[25]))) * exp2 + (ap[4] - (float)4. + (p[26] - (float)
	    1.) * (ap[4] - (float)4. + (exp(-dabs(p[25]) * (ap[4] - (float)4.)
	    ) - (float)1.) / dabs(p[25]))) * exp2 * exp2 + (ap[5] - (float)4. 
	    + (p[26] - (float)1.) * (ap[5] - (float)4. + (exp(-dabs(p[25]) * (
	    ap[5] - (float)4.)) - (float)1.) / dabs(p[25]))) * (r__1 * (r__1 *
	     r__1)) + ((ap[6] - (float)4. + (p[26] - (float)1.) * (ap[6] - (
	    float)4. + (exp(-dabs(p[25]) * (ap[6] - (float)4.)) - (float)1.) /
	     dabs(p[25]))) * (r__2 * r__2) + (ap[7] - (float)4. + (p[26] - (
	    float)1.) * (ap[7] - (float)4. + (exp(-dabs(p[25]) * (ap[7] - (
	    float)4.)) - (float)1.) / dabs(p[25]))) * (r__3 * (r__3 * r__3))) 
	    * ((float)1. - r__4 * r__4) / ((float)1. - exp2))) / ((float)1. + 
	    ((float)1. - r__6 * (r__5 * r__5)) / ((float)1. - exp2) * pow_dd(&
	    d__1, &c_b104));
    if (csw_1.sw[8] == (float)0.) {
	goto L40;
    }
    ttest_2.t[8] = lpoly_1.apt[0] * (p[51] + p[97] * lpoly_1.plg[2] + p[55] * 
	    lpoly_1.plg[4] + (p[126] * lpoly_1.plg[1] + p[127] * lpoly_1.plg[
	    3] + p[128] * lpoly_1.plg[5]) * cd14 * csw_1.swc[4] + (p[129] * 
	    lpoly_1.plg[10] + p[130] * lpoly_1.plg[12] + p[131] * lpoly_1.plg[
	    14]) * csw_1.swc[6] * cos(hr * (*tloc - p[132])));
L40:
    if (csw_1.sw[9] == (float)0. || *long__ <= (float)-1e3) {
	goto L49;
    }
/*        LONGITUDINAL */
    if (csw_1.sw[10] == (float)0.) {
	goto L230;
    }
    ttest_2.t[10] = (p[81] * lpoly_1.dfa * csw_1.swc[0] + (float)1.) * ((p[65]
	     * lpoly_1.plg[11] + p[66] * lpoly_1.plg[13] + p[67] * 
	    lpoly_1.plg[15] + p[104] * lpoly_1.plg[10] + p[105] * lpoly_1.plg[
	    12] + p[106] * lpoly_1.plg[14] + csw_1.swc[4] * (p[110] * 
	    lpoly_1.plg[10] + p[111] * lpoly_1.plg[12] + p[112] * lpoly_1.plg[
	    14]) * cd14) * lpoly_1.clong + (p[91] * lpoly_1.plg[11] + p[92] * 
	    lpoly_1.plg[13] + p[93] * lpoly_1.plg[15] + p[107] * lpoly_1.plg[
	    10] + p[108] * lpoly_1.plg[12] + p[109] * lpoly_1.plg[14] + 
	    csw_1.swc[4] * (p[113] * lpoly_1.plg[10] + p[114] * lpoly_1.plg[
	    12] + p[115] * lpoly_1.plg[14]) * cd14) * lpoly_1.slong);
L230:
/*        UT AND MIXED UT,LONGITUDE */
    if (csw_1.sw[11] == (float)0.) {
	goto L240;
    }
    ttest_2.t[11] = (p[96] * lpoly_1.plg[1] + (float)1.) * (p[82] * 
	    lpoly_1.dfa * csw_1.swc[0] + (float)1.) * (p[120] * lpoly_1.plg[1]
	     * csw_1.swc[4] * cd14 + (float)1.) * ((p[69] * lpoly_1.plg[1] + 
	    p[70] * lpoly_1.plg[3] + p[71] * lpoly_1.plg[5]) * cos(sr * (*sec 
	    - p[72])));
    ttest_2.t[11] += csw_1.swc[10] * (p[77] * lpoly_1.plg[21] + p[78] * 
	    lpoly_1.plg[23] + p[79] * lpoly_1.plg[25]) * cos(sr * (*sec - p[
	    80]) + dgtr * (float)2. * *long__) * (p[138] * lpoly_1.dfa * 
	    csw_1.swc[0] + (float)1.);
L240:
/*        UT,LONGITUDE MAGNETIC ACTIVITY */
    if (csw_1.sw[12] == (float)0.) {
	goto L48;
    }
    if (sw9 == (float)-1.) {
	goto L45;
    }
    ttest_2.t[12] = lpoly_1.apdf * csw_1.swc[10] * (p[121] * lpoly_1.plg[1] + 
	    (float)1.) * ((p[61] * lpoly_1.plg[11] + p[62] * lpoly_1.plg[13] 
	    + p[63] * lpoly_1.plg[15]) * cos(dgtr * (*long__ - p[64]))) + 
	    lpoly_1.apdf * csw_1.swc[10] * csw_1.swc[4] * (p[116] * 
	    lpoly_1.plg[10] + p[117] * lpoly_1.plg[12] + p[118] * lpoly_1.plg[
	    14]) * cd14 * cos(dgtr * (*long__ - p[119])) + lpoly_1.apdf * 
	    csw_1.swc[11] * (p[84] * lpoly_1.plg[1] + p[85] * lpoly_1.plg[3] 
	    + p[86] * lpoly_1.plg[5]) * cos(sr * (*sec - p[76]));
    goto L48;
L45:
    if (p[52] == (float)0.) {
	goto L48;
    }
    ttest_2.t[12] = lpoly_1.apt[0] * csw_1.swc[10] * (p[133] * lpoly_1.plg[1] 
	    + (float)1.) * ((p[53] * lpoly_1.plg[11] + p[99] * lpoly_1.plg[13]
	     + p[68] * lpoly_1.plg[15]) * cos(dgtr * (*long__ - p[98]))) + 
	    lpoly_1.apt[0] * csw_1.swc[10] * csw_1.swc[4] * (p[134] * 
	    lpoly_1.plg[10] + p[135] * lpoly_1.plg[12] + p[136] * lpoly_1.plg[
	    14]) * cd14 * cos(dgtr * (*long__ - p[137])) + lpoly_1.apt[0] * 
	    csw_1.swc[11] * (p[56] * lpoly_1.plg[1] + p[57] * lpoly_1.plg[3] 
	    + p[58] * lpoly_1.plg[5]) * cos(sr * (*sec - p[59]));
L48:
L49:
    ttest_2.tinf = p[31];
    i__1 = nsw;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L50: */
	ttest_2.tinf += (r__1 = csw_1.sw[i__ - 1], dabs(r__1)) * ttest_2.t[
		i__ - 1];
    }
    ret_val = ttest_2.tinf;
    return ret_val;
} /* globe6_ */

/* ---------------------------------------------------------------- */
/* Subroutine */ int tselec_0_(n__, sv, svv)
int n__;
real *sv, *svv;
{
    /* System generated locals */
    real r__1, r__2;

    /* Builtin functions */
    double r_mod();

    /* Local variables */
    static integer i__;
    static real sav[25];

/*        SET SWITCHES */
/*        SW FOR MAIN TERMS, SWC FOR CROSS TERMS */
    /* Parameter adjustments */
    if (sv) {
	--sv;
	}
    if (svv) {
	--svv;
	}

    /* Function Body */
    switch(n__) {
	case 1: goto L_tretrv;
	}

    for (i__ = 1; i__ <= 25; ++i__) {
	sav[i__ - 1] = sv[i__];
	csw_1.sw[i__ - 1] = r_mod(&sv[i__], &c_b114);
	if ((r__1 = sv[i__], dabs(r__1)) == (float)1. || (r__2 = sv[i__], 
		dabs(r__2)) == (float)2.) {
	    csw_1.swc[i__ - 1] = (float)1.;
	} else {
	    csw_1.swc[i__ - 1] = (float)0.;
	}
/* L100: */
    }
    csw_1.isw = 64999;
    return 0;

L_tretrv:
    for (i__ = 1; i__ <= 25; ++i__) {
	svv[i__] = sav[i__ - 1];
/* L200: */
    }
} /* tselec_ */

/* Subroutine */ int tselec_(sv)
real *sv;
{
    return tselec_0_(0, sv, (real *)0);
    }

/* Subroutine */ int tretrv_(svv)
real *svv;
{
    return tselec_0_(1, (real *)0, svv);
    }

/* ---------------------------------------------------------------- */
doublereal glob6s_(p)
real *p;
{
    /* Initialized data */

    static real dr = (float).0172142;
    static real dayl = (float)-1.;
    static real p32 = (float)-1e3;
    static real p18 = (float)-1e3;
    static real p14 = (float)-1e3;
    static real p39 = (float)-1e3;

    /* System generated locals */
    real ret_val, r__1;

    /* Builtin functions */
    double cos();

    /* Local variables */
    static integer i__, j;
    static real t[14], t71, t72, t81, t82, tt, cd32, cd14, cd18, cd39;

/*      VERSION OF GLOBE FOR LOWER ATMOSPHERE 1/17/90 */
    /* Parameter adjustments */
    --p;

    /* Function Body */
    for (j = 1; j <= 14; ++j) {
	t[j - 1] = (float)0.;
/* L10: */
    }
    if (lpoly_2.day != dayl || p32 != p[32]) {
	cd32 = cos(dr * (lpoly_2.day - p[32]));
    }
    if (lpoly_2.day != dayl || p18 != p[18]) {
	cd18 = cos(dr * (float)2. * (lpoly_2.day - p[18]));
    }
    if (lpoly_2.day != dayl || p14 != p[14]) {
	cd14 = cos(dr * (lpoly_2.day - p[14]));
    }
    if (lpoly_2.day != dayl || p39 != p[39]) {
	cd39 = cos(dr * (float)2. * (lpoly_2.day - p[39]));
    }
    dayl = lpoly_2.day;
    p32 = p[32];
    p18 = p[18];
    p14 = p[14];
    p39 = p[39];

/*       F10.7 */
    t[0] = p[22] * lpoly_2.dfa;
/*       TIME INDEPENDENT */
    t[1] = p[2] * lpoly_2.plg[2] + p[3] * lpoly_2.plg[4] + p[23] * 
	    lpoly_2.plg[6] + p[27] * lpoly_2.plg[1] + p[28] * lpoly_2.plg[3] 
	    + p[29] * lpoly_2.plg[5];
/*       SYMMETRICAL ANNUAL */
    t[2] = (p[19] + p[48] * lpoly_2.plg[2] + p[30] * lpoly_2.plg[4]) * cd32;
/*       SYMMETRICAL SEMIANNUAL */
    t[3] = (p[16] + p[17] * lpoly_2.plg[2] + p[31] * lpoly_2.plg[4]) * cd18;
/*       ASYMMETRICAL ANNUAL */
    t[4] = (p[10] * lpoly_2.plg[1] + p[11] * lpoly_2.plg[3] + p[36] * 
	    lpoly_2.plg[5]) * cd14;
/*       ASYMMETRICAL SEMIANNUAL */
    t[5] = p[38] * lpoly_2.plg[1] * cd39;
/*        DIURNAL */
    if (csw_1.sw[6] == (float)0.) {
	goto L200;
    }
    t71 = p[12] * lpoly_2.plg[11] * cd14 * csw_1.swc[4];
    t72 = p[13] * lpoly_2.plg[11] * cd14 * csw_1.swc[4];
    t[6] = (p[4] * lpoly_2.plg[10] + p[5] * lpoly_2.plg[12] + t71) * 
	    lpoly_2.ctloc + (p[7] * lpoly_2.plg[10] + p[8] * lpoly_2.plg[12] 
	    + t72) * lpoly_2.stloc;
L200:
/*        SEMIDIURNAL */
    if (csw_1.sw[7] == (float)0.) {
	goto L210;
    }
    t81 = (p[24] * lpoly_2.plg[21] + p[47] * lpoly_2.plg[23]) * cd14 * 
	    csw_1.swc[4];
    t82 = (p[34] * lpoly_2.plg[21] + p[49] * lpoly_2.plg[23]) * cd14 * 
	    csw_1.swc[4];
    t[7] = (p[6] * lpoly_2.plg[20] + p[42] * lpoly_2.plg[22] + t81) * 
	    lpoly_2.c2tloc + (p[9] * lpoly_2.plg[20] + p[43] * lpoly_2.plg[22]
	     + t82) * lpoly_2.s2tloc;
L210:
/*        TERDIURNAL */
    if (csw_1.sw[13] == (float)0.) {
	goto L220;
    }
    t[13] = p[40] * lpoly_2.plg[30] * lpoly_2.s3tloc + p[41] * lpoly_2.plg[30]
	     * lpoly_2.c3tloc;
L220:
/*       MAGNETIC ACTIVITY */
    if (csw_1.sw[8] == (float)0.) {
	goto L40;
    }
    if (csw_1.sw[8] == (float)1.) {
	t[8] = lpoly_2.apdf * (p[33] + p[46] * lpoly_2.plg[2] * csw_1.swc[1]);
    }
    if (csw_1.sw[8] == (float)-1.) {
	t[8] = p[51] * lpoly_2.apt[2] + p[97] * lpoly_2.plg[2] * lpoly_2.apt[
		2] * csw_1.swc[1];
    }
L40:
    if (csw_1.sw[9] == (float)0. || csw_1.sw[10] == (float)0. || 
	    lpoly_2.long__ <= (float)-1e3) {
	goto L49;
    }
/*        LONGITUDINAL */
    t[10] = (lpoly_2.plg[1] * (p[81] * csw_1.swc[4] * cos(dr * (lpoly_2.day - 
	    p[82])) + p[86] * csw_1.swc[5] * cos(dr * (float)2. * (
	    lpoly_2.day - p[87]))) + (float)1. + p[84] * csw_1.swc[2] * cos(
	    dr * (lpoly_2.day - p[85])) + p[88] * csw_1.swc[3] * cos(dr * (
	    float)2. * (lpoly_2.day - p[89]))) * ((p[65] * lpoly_2.plg[11] + 
	    p[66] * lpoly_2.plg[13] + p[67] * lpoly_2.plg[15] + p[75] * 
	    lpoly_2.plg[10] + p[76] * lpoly_2.plg[12] + p[77] * lpoly_2.plg[
	    14]) * lpoly_2.clong + (p[91] * lpoly_2.plg[11] + p[92] * 
	    lpoly_2.plg[13] + p[93] * lpoly_2.plg[15] + p[78] * lpoly_2.plg[
	    10] + p[79] * lpoly_2.plg[12] + p[80] * lpoly_2.plg[14]) * 
	    lpoly_2.slong);
L49:
    tt = (float)0.;
    for (i__ = 1; i__ <= 14; ++i__) {
/* L50: */
	tt += (r__1 = csw_1.sw[i__ - 1], dabs(r__1)) * t[i__ - 1];
    }
    ret_val = tt;
    return ret_val;
} /* glob6s_ */

/* ---------------------------------------------------------------- */
doublereal densu_(alt, dlb, tinf, tlb, xm, alpha, tz, zlb, s2, mn1, zn1, tn1, 
	tgn1)
real *alt, *dlb, *tinf, *tlb, *xm, *alpha, *tz, *zlb, *s2;
integer *mn1;
real *zn1, *tn1, *tgn1;
{
    /* Initialized data */

    static real rgas = (float)831.4;

    /* System generated locals */
    integer i__1;
    real ret_val, r__1, r__2;
    doublereal d__1, d__2;

    /* Builtin functions */
    double exp(), pow_dd();

    /* Local variables */
    static real gamm, expl;
    static integer k;
    static real y2out[5], gamma, x, y, z__, densa, zgdif, t1, t2, z1, z2, ta, 
	    za;
    static integer mn;
    static real zg, yi, tt, xs[5], ys[5];
    extern /* Subroutine */ int spline_(), splini_(), splint_();
    static real yd1, yd2, zg2, glb, dta;

/*       Calculate Temperature and Density Profiles for MSIS models */
/*       New lower thermo polynomial 10/30/89 */
    /* Parameter adjustments */
    --tn1;
    --zn1;
    --tgn1;

    /* Function Body */
/* CCCCCWRITE(6,*) 'DB',ALT,DLB,TINF,TLB,XM,ALPHA,ZLB,S2,MN1,ZN1,TN1 */
    ret_val = (float)1.;
/*        Joining altitude of Bates and spline */
    za = zn1[1];
    z__ = dmax(*alt,za);
/*      Geopotential altitude difference from ZLB */
    zg2 = (z__ - *zlb) * (parmb_1.re + *zlb) / (parmb_1.re + z__);
/*      Bates temperature */
    tt = *tinf - (*tinf - *tlb) * exp(-(*s2) * zg2);
    ta = tt;
    *tz = tt;
    ret_val = *tz;
    if (*alt >= za) {
	goto L10;
    }

/*       CALCULATE TEMPERATURE BELOW ZA */
/*      Temperature gradient at ZA from Bates profile */
/* Computing 2nd power */
    r__1 = (parmb_1.re + *zlb) / (parmb_1.re + za);
    dta = (*tinf - ta) * *s2 * (r__1 * r__1);
    tgn1[1] = dta;
    tn1[1] = ta;
/* Computing MAX */
    r__1 = *alt, r__2 = zn1[*mn1];
    z__ = dmax(r__1,r__2);
    mn = *mn1;
    z1 = zn1[1];
    z2 = zn1[mn];
    t1 = tn1[1];
    t2 = tn1[mn];
/*      Geopotental difference from Z1 */
    zg = (z__ - z1) * (parmb_1.re + z1) / (parmb_1.re + z__);
    zgdif = (z2 - z1) * (parmb_1.re + z1) / (parmb_1.re + z2);
/*       Set up spline nodes */
    i__1 = mn;
    for (k = 1; k <= i__1; ++k) {
	xs[k - 1] = (zn1[k] - z1) * (parmb_1.re + z1) / (parmb_1.re + zn1[k]) 
		/ zgdif;
	ys[k - 1] = (float)1. / tn1[k];
/* L20: */
    }
/*        End node derivatives */
    yd1 = -tgn1[1] / (t1 * t1) * zgdif;
/* Computing 2nd power */
    r__1 = (parmb_1.re + z2) / (parmb_1.re + z1);
    yd2 = -tgn1[2] / (t2 * t2) * zgdif * (r__1 * r__1);
/*       Calculate spline coefficients */
    spline_(xs, ys, &mn, &yd1, &yd2, y2out);
    x = zg / zgdif;
    splint_(xs, ys, y2out, &mn, &x, &y);
/*       temperature at altitude */
    *tz = (float)1. / y;
    ret_val = *tz;
L10:
    if (*xm == (float)0.) {
	goto L50;
    }

/*      CALCULATE DENSITY ABOVE ZA */
/* Computing 2nd power */
    r__1 = *zlb / parmb_1.re + (float)1.;
    glb = parmb_1.gsurf / (r__1 * r__1);
    gamma = *xm * glb / (*s2 * rgas * *tinf);
    expl = exp(-(*s2) * gamma * zg2);
    if (expl > (float)50. || tt <= (float)0.) {
	expl = (float)50.;
    }
/*       Density at altitude */
    d__1 = (doublereal) (*tlb / tt);
    d__2 = (doublereal) (*alpha + (float)1. + gamma);
    densa = *dlb * pow_dd(&d__1, &d__2) * expl;
    ret_val = densa;
    if (*alt >= za) {
	goto L50;
    }

/*      CALCULATE DENSITY BELOW ZA */
/* Computing 2nd power */
    r__1 = z1 / parmb_1.re + (float)1.;
    glb = parmb_1.gsurf / (r__1 * r__1);
    gamm = *xm * glb * zgdif / rgas;
/*       integrate spline temperatures */
    splini_(xs, ys, y2out, &mn, &x, &yi);
    expl = gamm * yi;
    if (expl > (float)50. || *tz <= (float)0.) {
	expl = (float)50.;
    }
/*       Density at altitude */
    d__1 = (doublereal) (t1 / *tz);
    d__2 = (doublereal) (*alpha + (float)1.);
    ret_val = ret_val * pow_dd(&d__1, &d__2) * exp(-expl);
L50:
    return ret_val;
} /* densu_ */

/* ---------------------------------------------------------------- */
doublereal densm_(alt, d0, xm, tz, mn3, zn3, tn3, tgn3, mn2, zn2, tn2, tgn2)
real *alt, *d0, *xm, *tz;
integer *mn3;
real *zn3, *tn3, *tgn3;
integer *mn2;
real *zn2, *tn2, *tgn2;
{
    /* Initialized data */

    static real rgas = (float)831.4;

    /* System generated locals */
    integer i__1;
    real ret_val, r__1, r__2;

    /* Builtin functions */
    double exp();

    /* Local variables */
    static real gamm, expl;
    static integer k;
    static real y2out[10], x, y, z__, zgdif, t1, t2, z1, z2;
    static integer mn;
    static real zg, yi, xs[10], ys[10];
    extern /* Subroutine */ int spline_(), splini_(), splint_();
    static real yd1, yd2, glb;

/*       Calculate Temperature and Density Profiles for lower atmos. */
    /* Parameter adjustments */
    --tn3;
    --zn3;
    --tgn3;
    --tn2;
    --zn2;
    --tgn2;

    /* Function Body */
    ret_val = *d0;
    if (*alt > zn2[1]) {
	goto L50;
    }
/*      STRATOSPHERE/MESOSPHERE TEMPERATURE */
/* Computing MAX */
    r__1 = *alt, r__2 = zn2[*mn2];
    z__ = dmax(r__1,r__2);
    mn = *mn2;
    z1 = zn2[1];
    z2 = zn2[mn];
    t1 = tn2[1];
    t2 = tn2[mn];
    zg = (z__ - z1) * (parmb_1.re + z1) / (parmb_1.re + z__);
    zgdif = (z2 - z1) * (parmb_1.re + z1) / (parmb_1.re + z2);
/*       Set up spline nodes */
    i__1 = mn;
    for (k = 1; k <= i__1; ++k) {
	xs[k - 1] = (zn2[k] - z1) * (parmb_1.re + z1) / (parmb_1.re + zn2[k]) 
		/ zgdif;
	ys[k - 1] = (float)1. / tn2[k];
/* L210: */
    }
    yd1 = -tgn2[1] / (t1 * t1) * zgdif;
/* Computing 2nd power */
    r__1 = (parmb_1.re + z2) / (parmb_1.re + z1);
    yd2 = -tgn2[2] / (t2 * t2) * zgdif * (r__1 * r__1);
/*       Calculate spline coefficients */
    spline_(xs, ys, &mn, &yd1, &yd2, y2out);
    x = zg / zgdif;
    splint_(xs, ys, y2out, &mn, &x, &y);
/*       Temperature at altitude */
    *tz = (float)1. / y;
    if (*xm == (float)0.) {
	goto L20;
    }

/*      CALCULATE STRATOSPHERE/MESOSPHERE DENSITY */
/* Computing 2nd power */
    r__1 = z1 / parmb_1.re + (float)1.;
    glb = parmb_1.gsurf / (r__1 * r__1);
    gamm = *xm * glb * zgdif / rgas;
/*       Integrate temperature profile */
    splini_(xs, ys, y2out, &mn, &x, &yi);
    expl = gamm * yi;
    if (expl > (float)50.) {
	expl = (float)50.;
    }
/*       Density at altitude */
    ret_val = ret_val * (t1 / *tz) * exp(-expl);
L20:
    if (*alt > zn3[1]) {
	goto L50;
    }

/*      TROPOSPHERE/STRATOSPHERE TEMPERATURE */
    z__ = *alt;
    mn = *mn3;
    z1 = zn3[1];
    z2 = zn3[mn];
    t1 = tn3[1];
    t2 = tn3[mn];
    zg = (z__ - z1) * (parmb_1.re + z1) / (parmb_1.re + z__);
    zgdif = (z2 - z1) * (parmb_1.re + z1) / (parmb_1.re + z2);
/*       Set up spline nodes */
    i__1 = mn;
    for (k = 1; k <= i__1; ++k) {
	xs[k - 1] = (zn3[k] - z1) * (parmb_1.re + z1) / (parmb_1.re + zn3[k]) 
		/ zgdif;
	ys[k - 1] = (float)1. / tn3[k];
/* L220: */
    }
    yd1 = -tgn3[1] / (t1 * t1) * zgdif;
/* Computing 2nd power */
    r__1 = (parmb_1.re + z2) / (parmb_1.re + z1);
    yd2 = -tgn3[2] / (t2 * t2) * zgdif * (r__1 * r__1);
/*       Calculate spline coefficients */
    spline_(xs, ys, &mn, &yd1, &yd2, y2out);
    x = zg / zgdif;
    splint_(xs, ys, y2out, &mn, &x, &y);
/*       temperature at altitude */
    *tz = (float)1. / y;
    if (*xm == (float)0.) {
	goto L30;
    }

/*      CALCULATE TROPOSPHERIC/STRATOSPHERE DENSITY */

/* Computing 2nd power */
    r__1 = z1 / parmb_1.re + (float)1.;
    glb = parmb_1.gsurf / (r__1 * r__1);
    gamm = *xm * glb * zgdif / rgas;
/*        Integrate temperature profile */
    splini_(xs, ys, y2out, &mn, &x, &yi);
    expl = gamm * yi;
    if (expl > (float)50.) {
	expl = (float)50.;
    }
/*        Density at altitude */
    ret_val = ret_val * (t1 / *tz) * exp(-expl);
L30:
L50:
    if (*xm == (float)0.) {
	ret_val = *tz;
    }
    return ret_val;
} /* densm_ */

/* ---------------------------------------------------------------- */
/* Subroutine */ int spline_(x, y, n, yp1, ypn, y2)
real *x, *y;
integer *n;
real *yp1, *ypn, *y2;
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, k;
    static real p, u[100], qn, un, sig;

/*        CALCULATE 2ND DERIVATIVES OF CUBIC SPLINE INTERP FUNCTION */
/*        ADAPTED FROM NUMERICAL RECIPES BY PRESS ET AL */
/*        X,Y: ARRAYS OF TABULATED FUNCTION IN ASCENDING ORDER BY X */
/*        N: SIZE OF ARRAYS X,Y */
/*        YP1,YPN: SPECIFIED DERIVATIVES AT X(1) AND X(N); VALUES */
/*                 >= 1E30 SIGNAL SIGNAL SECOND DERIVATIVE ZERO */
/*        Y2: OUTPUT ARRAY OF SECOND DERIVATIVES */
    /* Parameter adjustments */
    --y2;
    --y;
    --x;

    /* Function Body */
    if (*yp1 > (float)9.9e29) {
	y2[1] = (float)0.;
	u[0] = (float)0.;
    } else {
	y2[1] = (float)-.5;
	u[0] = (float)3. / (x[2] - x[1]) * ((y[2] - y[1]) / (x[2] - x[1]) - *
		yp1);
    }
    i__1 = *n - 1;
    for (i__ = 2; i__ <= i__1; ++i__) {
	sig = (x[i__] - x[i__ - 1]) / (x[i__ + 1] - x[i__ - 1]);
	p = sig * y2[i__ - 1] + (float)2.;
	y2[i__] = (sig - (float)1.) / p;
	u[i__ - 1] = (((y[i__ + 1] - y[i__]) / (x[i__ + 1] - x[i__]) - (y[i__]
		 - y[i__ - 1]) / (x[i__] - x[i__ - 1])) * (float)6. / (x[i__ 
		+ 1] - x[i__ - 1]) - sig * u[i__ - 2]) / p;
/* L11: */
    }
    if (*ypn > (float)9.9e29) {
	qn = (float)0.;
	un = (float)0.;
    } else {
	qn = (float).5;
	un = (float)3. / (x[*n] - x[*n - 1]) * (*ypn - (y[*n] - y[*n - 1]) / (
		x[*n] - x[*n - 1]));
    }
    y2[*n] = (un - qn * u[*n - 2]) / (qn * y2[*n - 1] + (float)1.);
    for (k = *n - 1; k >= 1; --k) {
	y2[k] = y2[k] * y2[k + 1] + u[k - 1];
/* L12: */
    }
    return 0;
} /* spline_ */

/* ---------------------------------------------------------------- */
/* Subroutine */ int splint_(xa, ya, y2a, n, x, y)
real *xa, *ya, *y2a;
integer *n;
real *x, *y;
{
    /* Builtin functions */
    integer s_wsle(), do_lio(), e_wsle();

    /* Local variables */
    static real a, b, h__;
    static integer k, khi, klo;

    /* Fortran I/O blocks */
    static cilist io___242 = { 0, 6, 0, 0, 0 };


/*        CALCULATE CUBIC SPLINE INTERP VALUE */
/*        ADAPTED FROM NUMBERICAL RECIPES BY PRESS ET AL. */
/*        XA,YA: ARRAYS OF TABULATED FUNCTION IN ASCENDING ORDER BY X */
/*        Y2A: ARRAY OF SECOND DERIVATIVES */
/*        N: SIZE OF ARRAYS XA,YA,Y2A */
/*        X: ABSCISSA FOR INTERPOLATION */
/*        Y: OUTPUT VALUE */
    /* Parameter adjustments */
    --y2a;
    --ya;
    --xa;

    /* Function Body */
    klo = 1;
    khi = *n;
L1:
    if (khi - klo > 1) {
	k = (khi + klo) / 2;
	if (xa[k] > *x) {
	    khi = k;
	} else {
	    klo = k;
	}
	goto L1;
    }
    h__ = xa[khi] - xa[klo];
    if (h__ == (float)0.) {
	s_wsle(&io___242);
	do_lio(&c__9, &c__1, "BAD XA INPUT TO SPLINT", (ftnlen)22);
	e_wsle();
    }
    a = (xa[khi] - *x) / h__;
    b = (*x - xa[klo]) / h__;
    *y = a * ya[klo] + b * ya[khi] + ((a * a * a - a) * y2a[klo] + (b * b * b 
	    - b) * y2a[khi]) * h__ * h__ / (float)6.;
    return 0;
} /* splint_ */

/* ---------------------------------------------------------------- */
/* Subroutine */ int splini_(xa, ya, y2a, n, x, yi)
real *xa, *ya, *y2a;
integer *n;
real *x, *yi;
{
    /* System generated locals */
    real r__1, r__2;

    /* Local variables */
    static real a, b, h__, a2, b2, xx;
    static integer khi, klo;

/*       INTEGRATE CUBIC SPLINE FUNCTION FROM XA(1) TO X */
/*        XA,YA: ARRAYS OF TABULATED FUNCTION IN ASCENDING ORDER BY X */
/*        Y2A: ARRAY OF SECOND DERIVATIVES */
/*        N: SIZE OF ARRAYS XA,YA,Y2A */
/*        X: ABSCISSA ENDPOINT FOR INTEGRATION */
/*        Y: OUTPUT VALUE */
    /* Parameter adjustments */
    --y2a;
    --ya;
    --xa;

    /* Function Body */
    *yi = (float)0.;
    klo = 1;
    khi = 2;
L1:
    if (*x > xa[klo] && khi <= *n) {
	xx = *x;
	if (khi < *n) {
/* Computing MIN */
	    r__1 = *x, r__2 = xa[khi];
	    xx = dmin(r__1,r__2);
	}
	h__ = xa[khi] - xa[klo];
	a = (xa[khi] - xx) / h__;
	b = (xx - xa[klo]) / h__;
	a2 = a * a;
	b2 = b * b;
	*yi += (((float)1. - a2) * ya[klo] / (float)2. + b2 * ya[khi] / (
		float)2. + ((-(a2 * a2 + (float)1.) / (float)4. + a2 / (float)
		2.) * y2a[klo] + (b2 * b2 / (float)4. - b2 / (float)2.) * y2a[
		khi]) * h__ * h__ / (float)6.) * h__;
	++klo;
	++khi;
	goto L1;
    }
    return 0;
} /* splini_ */

/* ---------------------------------------------------------------- */
doublereal dnet_(dd, dm, zhm, xmm, xm)
real *dd, *dm, *zhm, *xmm, *xm;
{
    /* System generated locals */
    real ret_val;
    doublereal d__1, d__2;

    /* Builtin functions */
    integer s_wsle(), do_lio(), e_wsle();
    double log(), exp(), pow_dd();

    /* Local variables */
    static real ylog, a;

    /* Fortran I/O blocks */
    static cilist io___254 = { 0, 6, 0, 0, 0 };


/*       TURBOPAUSE CORRECTION FOR MSIS MODELS */
/*         Root mean density */
/*       8/20/80 */
/*          DD - diffusive density */
/*          DM - full mixed density */
/*          ZHM - transition scale length */
/*          XMM - full mixed molecular weight */
/*          XM  - species molecular weight */
/*          DNET - combined density */
    a = *zhm / (*xmm - *xm);
    if (*dm > (float)0. && *dd > (float)0.) {
	goto L5;
    }
    s_wsle(&io___254);
    do_lio(&c__9, &c__1, "DNET LOG ERROR", (ftnlen)14);
    do_lio(&c__4, &c__1, (char *)&(*dm), (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&(*dd), (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&(*xm), (ftnlen)sizeof(real));
    e_wsle();
    if (*dd == (float)0. && *dm == (float)0.) {
	*dd = (float)1.;
    }
    if (*dm == (float)0.) {
	goto L10;
    }
    if (*dd == (float)0.) {
	goto L20;
    }
L5:
    ylog = a * log(*dm / *dd);
    if (ylog < (float)-10.) {
	goto L10;
    }
    if (ylog > (float)10.) {
	goto L20;
    }
    d__1 = (doublereal) (exp(ylog) + (float)1.);
    d__2 = (doublereal) (1 / a);
    ret_val = *dd * pow_dd(&d__1, &d__2);
    goto L50;
L10:
    ret_val = *dd;
    goto L50;
L20:
    ret_val = *dm;
    goto L50;
L50:
    return ret_val;
} /* dnet_ */

/* ---------------------------------------------------------------- */
doublereal ccor_(alt, r__, h1, zh)
real *alt, *r__, *h1, *zh;
{
    /* System generated locals */
    real ret_val;

    /* Builtin functions */
    double exp();

    /* Local variables */
    static real e, ex;

/*        CHEMISTRY/DISSOCIATION CORRECTION FOR MSIS MODELS */
/*        ALT - altitude */
/*        R - target ratio */
/*        H1 - transition scale length */
/*        ZH - altitude of 1/2 R */
    e = (*alt - *zh) / *h1;
    if (e > (float)70.) {
	goto L20;
    }
    if (e < (float)-70.) {
	goto L10;
    }
    ex = exp(e);
    ret_val = *r__ / (ex + (float)1.);
    goto L50;
L10:
    ret_val = *r__;
    goto L50;
L20:
    ret_val = (float)0.;
    goto L50;
L50:
    ret_val = exp(ret_val);
    return ret_val;
} /* ccor_ */

/* ---------------------------------------------------------------- */
/* Subroutine */ int gtd6bk_()
{
} /* gtd6bk_ */

/*          MSISE 90 12-MAR-90 */
/*         TEMPERATURE */
/*         HE DENSITY */
/*         O DENSITY */
/*         N2 DENSITY */
/*         TLB */
/*         O2 DENSITY */
/*         AR DENSITY */
/*          H DENSITY */
/*          N DENSITY */
/*        SPARE */
/*          S PARAM */
/*          TURBO */
/*         LOWER BOUNDARY */







/*         TN1(2) */
/*         TN1(3) */
/*         TN1(4) */
/*         TN1(5) TN2(1) */
/*          TN2(2) */
/*          TN2(3) */
/*          TN2(4) TN3(1) */
/*          TN3(2) */
/*          TN3(3) */
/*          TN3(4) */
/*          TN3(5) SURFACE TEMP TSL */
/*          TGN3(2) SURFACE GRAD TSLG */
/*          TGN2(1) TGN1(2) */
/*          TGN3(1) TGN2(2) */
/*         MIDDLE ATMOSPHERE AVERAGES */


/* igrf.f -- translated by f2c (version 20061008).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#ifdef __cplusplus
extern "C" {
#endif
#include "f2c.h"

/* Common Block Declarations */

union {
    struct {
	doublereal umr, era, aquad, bquad;
    } _1;
    struct {
	doublereal umr, erad, aquad, bquad;
    } _2;
} igrf1_;

#define igrf1_1 (igrf1_._1)
#define igrf1_2 (igrf1_._2)

struct {
    doublereal sp[3];
} fidb0_;

#define fidb0_1 fidb0_

union {
    struct {
	doublereal x[3], h__[144];
    } _1;
    struct {
	doublereal xi[3], h__[144];
    } _2;
} igrf_;

#define igrf_1 (igrf_._1)
#define igrf_2 (igrf_._2)

union {
    struct {
	char name__[12];
	integer nmax;
	doublereal time, g[144];
    } _1;
    struct {
	char fil1[12];
	integer nmax;
	doublereal time, gh1[144];
    } _2;
} model_;

#define model_1 (model_._1)
#define model_2 (model_._2)

extern struct {
    doublereal umr;
} const_;

#define const_1 const_

union {
    struct {
	doublereal st0, ct0, sl0, cl0, ctcl, stcl, ctsl, stsl, ab[19];
	integer k, iy;
	doublereal bb[8];
    } _1;
    struct {
	doublereal st0, ct0, sl0, cl0, ctcl, stcl, ctsl, stsl, sfi, cfi, sps, 
		cps, shi, chi, hi, psi, xmut, a11, a21, a31, a12, a22, a32, 
		a13, a23, a33, ds3;
	integer k, iy;
	doublereal ba[8];
    } _2;
} c1_;

#define c1_1 (c1_._1)
#define c1_2 (c1_._2)

/* Table of constant values */

static doublereal c_b3 = 1.;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c__5 = 5;
static integer c_n1 = -1;
static integer c__0 = 0;
static integer c__25 = 25;

/* igrf.for, version number can be found at the end of this comment. */
/* ----------------------------------------------------------------------- */

/* Subroutines to compute IGRF parameters for IRI and all functions and */
/* subroutines required for this computation, including: */
/* 	igrf_sub, FINDB0, SHELLG, STOER, FELDG, FELDCOF, GETSHC, INTERSHC, */
/* 	EXTRASHC, INITIZE, GEODIP, SPHCAR, GEOMAG, and RECALC */

/* UNIT number for reading the IGRF coefficients (in GETSHC) is 14 */

/* Corrections: */
/* 11/01/91 SHELLG: lowest starting point for B0 search is 2 */
/*  1/27/92 Adopted to IGRF-91 coeffcients model */
/*  2/05/92 Reduce variable names: INTER(P)SHC,EXTRA(P)SHC,INITI(ALI)ZE */
/*  8/08/95 Updated to IGRF-45-95; new coeff. DGRF90, IGRF95, IGRF95S */
/*  5/31/00 Updated to IGRF-45-00; new coeff.: IGRF00, IGRF00s */
/* -Version-mm/dd/yy-Description (Person reporting the correction) */
/* 2000.01 05/07/01 initial version */
/* 2000.02 07/11/01 replace feldi(xi,h) by feldi (P. Wilkinson) */
/* 2000.02 07/11/01 variables EGNR, AGNR,OGNR not used (P. Wilkinson) */
/* 2000.01 10/28/02 replace TAB/6 blanks, enforce 72/line (D. Simpson) */
/* 2000.02 11/08/02 change unit for coefficients to 14 */
/* 2000.03 06/05/03 correct DIPL computation (V. Truhlik) */
/* 2005.00 04/25/05 CALL FELDI and DO 1111 I=1,7 (Alexey Petrov) */
/* 2005.01 11/10/05 added igrf_dip and geodip (MLAT) */
/* 2005.02 11/10/05 updated to IGRF-10 version */
/* 2005.03 12/21/06 GH2(120) -> GH2(144) */
/* 2007.00 05/18/07 Release of IRI-2007 */

/* Subroutine */ int igrf_sub__(doublereal *xlat, doublereal *xlong, 
	doublereal *year, doublereal *height, doublereal *xl, integer *icode, 
	doublereal *dipl, doublereal *babs)
{
    /* Builtin functions */
    double sqrt(doublereal), atan(doublereal);

    /* Local variables */
    static doublereal bab1, lati, dimo;
    extern /* Subroutine */ int feldg_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *);
    static doublereal beast, longi, bdown;
    extern /* Subroutine */ int shellg_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, doublereal *)
	    ;
    static doublereal bnorth;
    extern /* Subroutine */ int feldcof_(doublereal *, doublereal *), 
	    initize_();

/* ----------------------------------------------------------------------- */
/* INPUT: */
/*    xlat      geodatic latitude in degrees */
/*    xlong     geodatic longitude in degrees */
/*    year      decimal year (year+month/12.0-0.5 or */
/*                  year+day-of-year/365 or ../366 if leap year) */
/*    height    height in km */
/* OUTPUT: */
/*    xl        L value */
/*    icode      =1  L is correct; =2  L is not correct; */
/*               =3  an approximation is used */
/*    dipl      dip latitude in degrees */
/*    babs      magnetic field strength in Gauss */
/* ----------------------------------------------------------------------- */

    initize_();
    lati = *xlat;
    longi = *xlong;

/* ----------------CALCULATE PROFILES----------------------------------- */

    feldcof_(year, &dimo);
    feldg_(&lati, &longi, height, &bnorth, &beast, &bdown, babs);
    shellg_(&lati, &longi, height, &dimo, xl, icode, &bab1);
/*        DIP=ASIN(BDOWN/BABS)/UMR */
/*       DEC=ASIN(BEAST/SQRT(BEAST*BEAST+BNORTH*BNORTH))/UMR */
/*        DIPL=ATAN(0.5*TAN(DIP*UMR))/UMR */
    *dipl = atan(bdown / 2. / sqrt(bnorth * bnorth + beast * beast)) / 
	    igrf1_1.umr;
    return 0;
} /* igrf_sub__ */



/* Subroutine */ int igrf_dip__(doublereal *xlat, doublereal *xlong, 
	doublereal *year, doublereal *height, doublereal *dip, doublereal *
	dipl, doublereal *ymodip)
{
    /* Builtin functions */
    double asin(doublereal), cos(doublereal), sqrt(doublereal), d_sign(
	    doublereal *, doublereal *), atan(doublereal);

    /* Local variables */
    static doublereal h__, babs, dimo;
    extern /* Subroutine */ int feldg_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *);
    static doublereal beast, bdown, xlati, dipdiv, smodip, bnorth, xlongi;
    extern /* Subroutine */ int feldcof_(doublereal *, doublereal *), 
	    initize_();

/* ----------------------------------------------------------------------- */
/* INPUT: */
/*    xlat      geodatic latitude in degrees */
/*    xlong     geodatic longitude in degrees */
/*    year      decimal year (year+month/12.0-0.5 or */
/*                  year+day-of-year/365 or ../366 if leap year) */
/*    height    height in km */
/* OUTPUT: */
/*    dip       magnetic inclination (dip) in degrees */
/*    dipl      dip latitude in degrees */
/*    ymodip    modified dip latitude = asin{dip/sqrt[dip^2+cos(LATI)]} */
/* ----------------------------------------------------------------------- */

    initize_();

/* ----------------CALCULATE PROFILES----------------------------------- */

    xlati = *xlat;
    xlongi = *xlong;
    h__ = *height;
    feldcof_(year, &dimo);
    feldg_(&xlati, &xlongi, &h__, &bnorth, &beast, &bdown, &babs);
    *dip = asin(bdown / babs);
    dipdiv = *dip / sqrt(*dip * *dip + cos(xlati * igrf1_1.umr));
    if (abs(dipdiv) > 1.) {
	dipdiv = d_sign(&c_b3, &dipdiv);
    }
    smodip = asin(dipdiv);
/*       DEC=ASIN(BEAST/SQRT(BEAST*BEAST+BNORTH*BNORTH))/UMR */
/*       DIPL1=ATAN(0.5*TAN(DIP))/UMR */
    *dipl = atan(bdown / 2. / sqrt(bnorth * bnorth + beast * beast)) / 
	    igrf1_1.umr;
    *ymodip = smodip / igrf1_1.umr;
    *dip /= igrf1_1.umr;
    return 0;
} /* igrf_dip__ */



/* SHELLIG.FOR, Version 2.0, January 1992 */

/* 11/01/91 SHELLG: lowest starting point for B0 search is 2 */
/*  1/27/92 Adopted to IGRF-91 coeffcients model */
/*  2/05/92 Reduce variable-names: INTER(P)SHC,EXTRA(P)SHC,INITI(ALI)ZE */
/*  8/08/95 Updated to IGRF-45-95; new coeff. DGRF90, IGRF95, IGRF95S */
/*  5/31/00 Updated to IGRF-45-00; new coeff.: IGRF00, IGRF00s */
/* ********************************************************************* */
/*  SUBROUTINES FINDB0, SHELLG, STOER, FELDG, FELDCOF, GETSHC,        * */
/*       INTERSHC, EXTRASHC, INITIZE                                  * */
/* ********************************************************************* */
/* ********************************************************************* */


/* Subroutine */ int findb0_(doublereal *stps, doublereal *bdel, logical *
	value, doublereal *bequ, doublereal *rr0)
{
    /* Builtin functions */
    double d_sign(doublereal *, doublereal *), sqrt(doublereal);

    /* Local variables */
    static doublereal b;
    static integer i__, j, n;
    static doublereal p[32]	/* was [8][4] */, r1, r2, r3, zz, bq1, bq2, 
	    bq3, bold, bmin, rold, step;
    static integer irun;
    static doublereal step12;
    extern /* Subroutine */ int stoer_(doublereal *, doublereal *, doublereal 
	    *);
    static doublereal bdelta;

/* -------------------------------------------------------------------- */
/* FINDS SMALLEST MAGNETIC FIELD STRENGTH ON FIELD LINE */

/* INPUT:   STPS   STEP SIZE FOR FIELD LINE TRACING */
/*       COMMON/FIDB0/ */
/*          SP     DIPOLE ORIENTED COORDINATES FORM SHELLG; P(1,*), */
/*                 P(2,*), P(3,*) CLOSEST TO MAGNETIC EQUATOR */
/*          BDEL   REQUIRED ACCURACY  = [ B(LAST) - BEQU ] / BEQU */
/*                 B(LAST)  IS FIELD STRENGTH BEFORE BEQU */

/* OUTPUT:  VALUE  =.FALSE., IF BEQU IS NOT MINIMAL VALUE ON FIELD LINE */
/*          BEQU   MAGNETIC FIELD STRENGTH AT MAGNETIC EQUATOR */
/*          RR0    EQUATORIAL RADIUS NORMALIZED TO EARTH RADIUS */
/*          BDEL   FINAL ACHIEVED ACCURACY */
/* -------------------------------------------------------------------- */

    step = *stps;
    irun = 0;
L7777:
    ++irun;
    if (irun > 5) {
	*value = FALSE_;
	goto L8888;
    }
/* *********************FIRST THREE POINTS */
    p[8] = fidb0_1.sp[0];
    p[9] = fidb0_1.sp[1];
    p[10] = fidb0_1.sp[2];
    step = -d_sign(&step, &p[10]);
    stoer_(&p[8], &bq2, &r2);
    p[16] = p[8] + step * .5 * p[11];
    p[17] = p[9] + step * .5 * p[12];
    p[18] = p[10] + step * .5;
    stoer_(&p[16], &bq3, &r3);
    p[0] = p[8] - step * (p[11] * 2. - p[19]);
    p[1] = p[9] - step * (p[12] * 2. - p[20]);
    p[2] = p[10] - step;
    stoer_(p, &bq1, &r1);
    p[16] = p[8] + step * (p[19] * 20. - p[11] * 3. + p[3]) / 18.;
    p[17] = p[9] + step * (p[20] * 20. - p[12] * 3. + p[4]) / 18.;
    p[18] = p[10] + step;
    stoer_(&p[16], &bq3, &r3);
/* ******************INVERT SENSE IF REQUIRED */
    if (bq3 <= bq1) {
	goto L2;
    }
    step = -step;
    r3 = r1;
    bq3 = bq1;
    for (i__ = 1; i__ <= 5; ++i__) {
	zz = p[i__ - 1];
	p[i__ - 1] = p[i__ + 15];
/* L1: */
	p[i__ + 15] = zz;
    }
/* ******************INITIALIZATION */
L2:
    step12 = step / 12.;
    *value = TRUE_;
    bmin = 1e4;
    bold = 1e4;
/* ******************CORRECTOR (FIELD LINE TRACING) */
    n = 0;
L5555:
    p[16] = p[8] + step12 * (p[19] * 5. + p[11] * 8. - p[3]);
    ++n;
    p[17] = p[9] + step12 * (p[20] * 5. + p[12] * 8. - p[4]);
/* ******************PREDICTOR (FIELD LINE TRACING) */
    p[24] = p[16] + step12 * (p[19] * 23. - p[11] * 16. + p[3] * 5.);
    p[25] = p[17] + step12 * (p[20] * 23. - p[12] * 16. + p[4] * 5.);
    p[26] = p[18] + step;
    stoer_(&p[24], &bq3, &r3);
    for (j = 1; j <= 3; ++j) {
/*        DO 1111 I=1,8 */
	for (i__ = 1; i__ <= 7; ++i__) {
/* L1111: */
	    p[i__ + (j << 3) - 9] = p[i__ + (j + 1 << 3) - 9];
	}
    }
    b = sqrt(bq3);
    if (b < bmin) {
	bmin = b;
    }
    if (b <= bold) {
	bold = b;
	rold = 1. / r3;
	fidb0_1.sp[0] = p[24];
	fidb0_1.sp[1] = p[25];
	fidb0_1.sp[2] = p[26];
	goto L5555;
    }
    if (bold != bmin) {
	*value = FALSE_;
    }
    bdelta = (b - bold) / bold;
    if (bdelta > *bdel) {
	step /= 10.;
	goto L7777;
    }
L8888:
    *rr0 = rold;
    *bequ = bold;
    *bdel = bdelta;
    return 0;
} /* findb0_ */



/* Subroutine */ int shellg_0_(int n__, doublereal *glat, doublereal *glon, 
	doublereal *alt, doublereal *dimo, doublereal *fl, integer *icode, 
	doublereal *b0, doublereal *v)
{
    /* Initialized data */

    static doublereal rmin = .05;
    static doublereal rmax = 1.01;
    static doublereal step = .2;
    static doublereal steq = .03;
    static doublereal u[9]	/* was [3][3] */ = { .3511737,-.9148385,
	    -.1993679,.9335804,.358368,0.,.0714471,-.186126,.9799247 };

    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal), sqrt(doublereal), d_sign(
	    doublereal *, doublereal *), log(doublereal), exp(doublereal);

    /* Local variables */
    static doublereal d__;
    static integer i__, n;
    static doublereal p[800]	/* was [8][100] */, r__, t, z__, c0, c1, c2, 
	    c3, d0, d1, d2, e0, e1, e2, r1, r2, r3, ff, gg, fi, ct, rq, st, 
	    zq, xx, zz, bq1, bq2, bq3, r3h, hli, stp, arg1, arg2, bequ, rlat;
    static integer iequ;
    static doublereal term, rlon, step2, radik, step12, oterm;
    extern /* Subroutine */ int stoer_(doublereal *, doublereal *, doublereal 
	    *);
    static doublereal dimob0, oradik;

/* ----------------------------------------------------------------------- */
/* CALCULATES L-VALUE FOR SPECIFIED GEODAETIC COORDINATES, ALTITUDE */
/* AND GEMAGNETIC FIELD MODEL. */
/* REF: G. KLUGE, EUROPEAN SPACE OPERATIONS CENTER, INTERNAL NOTE */
/*      NO. 67, 1970. */
/*      G. KLUGE, COMPUTER PHYSICS COMMUNICATIONS 3, 31-35, 1972 */
/* ----------------------------------------------------------------------- */
/* CHANGES (D. BILITZA, NOV 87): */
/*   - USING CORRECT DIPOL MOMENT I.E.,DIFFERENT COMMON/MODEL/ */
/*   - USING IGRF EARTH MAGNETIC FIELD MODELS FROM 1945 TO 1990 */
/* ----------------------------------------------------------------------- */
/*  INPUT:  ENTRY POINT SHELLG */
/*             GLAT  GEODETIC LATITUDE IN DEGREES (NORTH) */
/*             GLON  GEODETIC LONGITUDE IN DEGREES (EAST) */
/*             ALT   ALTITUDE IN KM ABOVE SEA LEVEL */

/*          ENTRY POINT SHELLC */
/*             V(3)  CARTESIAN COORDINATES IN EARTH RADII (6371.2 KM) */
/*                     X-AXIS POINTING TO EQUATOR AT 0 LONGITUDE */
/*                     Y-AXIS POINTING TO EQUATOR AT 90 LONG. */
/*                     Z-AXIS POINTING TO NORTH POLE */

/*          DIMO     DIPOL MOMENT IN GAUSS (NORMALIZED TO EARTH RADIUS) */

/*          COMMON */
/*             X(3)    NOT USED */
/*             H(144)  FIELD MODEL COEFFICIENTS ADJUSTED FOR SHELLG */
/* ----------------------------------------------------------------------- */
/*  OUTPUT: FL           L-VALUE */
/*          ICODE        =1 NORMAL COMPLETION */
/*                       =2 UNPHYSICAL CONJUGATE POINT (FL MEANINGLESS) */
/*                       =3 SHELL PARAMETER GREATER THAN LIMIT UP TO */
/*                          WHICH ACCURATE CALCULATION IS REQUIRED; */
/*                          APPROXIMATION IS USED. */
/*          B0           MAGNETIC FIELD STRENGTH IN GAUSS */
/* ----------------------------------------------------------------------- */

/* -- RMIN, RMAX ARE BOUNDARIES FOR IDENTIFICATION OF ICODE=2 AND 3 */
/* -- STEP IS STEP SIZE FOR FIELD LINE TRACING */
/* -- STEQ IS STEP SIZE FOR INTEGRATION */

    /* Parameter adjustments */
    if (v) {
	--v;
	}

    /* Function Body */
    switch(n__) {
	case 1: goto L_shellc;
	}

    bequ = 1e10;
/* *****ENTRY POINT  SHELLG  TO BE USED WITH GEODETIC CO-ORDINATES */
    rlat = *glat * igrf1_1.umr;
    ct = sin(rlat);
    st = cos(rlat);
    d__ = sqrt(igrf1_1.aquad - (igrf1_1.aquad - igrf1_1.bquad) * ct * ct);
    igrf_1.x[0] = (*alt + igrf1_1.aquad / d__) * st / igrf1_1.era;
    igrf_1.x[2] = (*alt + igrf1_1.bquad / d__) * ct / igrf1_1.era;
    rlon = *glon * igrf1_1.umr;
    igrf_1.x[1] = igrf_1.x[0] * sin(rlon);
    igrf_1.x[0] *= cos(rlon);
    goto L9;

L_shellc:
/* *****ENTRY POINT  SHELLC  TO BE USED WITH CARTESIAN CO-ORDINATES */
    igrf_1.x[0] = v[1];
    igrf_1.x[1] = v[2];
    igrf_1.x[2] = v[3];
/* *****CONVERT TO DIPOL-ORIENTED CO-ORDINATES */
L9:
    rq = 1. / (igrf_1.x[0] * igrf_1.x[0] + igrf_1.x[1] * igrf_1.x[1] + 
	    igrf_1.x[2] * igrf_1.x[2]);
    r3h = sqrt(rq * sqrt(rq));
    p[8] = (igrf_1.x[0] * u[0] + igrf_1.x[1] * u[1] + igrf_1.x[2] * u[2]) * 
	    r3h;
    p[9] = (igrf_1.x[0] * u[3] + igrf_1.x[1] * u[4]) * r3h;
    p[10] = (igrf_1.x[0] * u[6] + igrf_1.x[1] * u[7] + igrf_1.x[2] * u[8]) * 
	    rq;
/* *****FIRST THREE POINTS OF FIELD LINE */
    step = -d_sign(&step, &p[10]);
    stoer_(&p[8], &bq2, &r2);
    *b0 = sqrt(bq2);
    p[16] = p[8] + step * .5 * p[11];
    p[17] = p[9] + step * .5 * p[12];
    p[18] = p[10] + step * .5;
    stoer_(&p[16], &bq3, &r3);
    p[0] = p[8] - step * (p[11] * 2. - p[19]);
    p[1] = p[9] - step * (p[12] * 2. - p[20]);
    p[2] = p[10] - step;
    stoer_(p, &bq1, &r1);
    p[16] = p[8] + step * (p[19] * 20. - p[11] * 3. + p[3]) / 18.;
    p[17] = p[9] + step * (p[20] * 20. - p[12] * 3. + p[4]) / 18.;
    p[18] = p[10] + step;
    stoer_(&p[16], &bq3, &r3);
/* *****INVERT SENSE IF REQUIRED */
    if (bq3 <= bq1) {
	goto L2;
    }
    step = -step;
    r3 = r1;
    bq3 = bq1;
    for (i__ = 1; i__ <= 7; ++i__) {
	zz = p[i__ - 1];
	p[i__ - 1] = p[i__ + 15];
/* L1: */
	p[i__ + 15] = zz;
    }
/* *****SEARCH FOR LOWEST MAGNETIC FIELD STRENGTH */
L2:
    if (bq1 < bequ) {
	bequ = bq1;
	iequ = 1;
    }
    if (bq2 < bequ) {
	bequ = bq2;
	iequ = 2;
    }
    if (bq3 < bequ) {
	bequ = bq3;
	iequ = 3;
    }
/* *****INITIALIZATION OF INTEGRATION LOOPS */
    step12 = step / 12.;
    step2 = step + step;
    steq = d_sign(&steq, &step);
    fi = 0.;
    *icode = 1;
    oradik = 0.;
    oterm = 0.;
    stp = r2 * steq;
    z__ = p[10] + stp;
    stp /= .75;
    p[7] = step2 * (p[0] * p[3] + p[1] * p[4]);
    p[15] = step2 * (p[8] * p[11] + p[9] * p[12]);
/* *****MAIN LOOP (FIELD LINE TRACING) */
    for (n = 3; n <= 3333; ++n) {
/* *****CORRECTOR (FIELD LINE TRACING) */
	p[(n << 3) - 8] = p[(n - 1 << 3) - 8] + step12 * (p[(n << 3) - 5] * 
		5. + p[(n - 1 << 3) - 5] * 8. - p[(n - 2 << 3) - 5]);
	p[(n << 3) - 7] = p[(n - 1 << 3) - 7] + step12 * (p[(n << 3) - 4] * 
		5. + p[(n - 1 << 3) - 4] * 8. - p[(n - 2 << 3) - 4]);
/* *****PREPARE EXPANSION COEFFICIENTS FOR INTERPOLATION */
/* *****OF SLOWLY VARYING QUANTITIES */
	p[(n << 3) - 1] = step2 * (p[(n << 3) - 8] * p[(n << 3) - 5] + p[(n <<
		 3) - 7] * p[(n << 3) - 4]);
/* Computing 2nd power */
	d__1 = p[(n - 1 << 3) - 8];
/* Computing 2nd power */
	d__2 = p[(n - 1 << 3) - 7];
	c0 = d__1 * d__1 + d__2 * d__2;
	c1 = p[(n - 1 << 3) - 1];
	c2 = (p[(n << 3) - 1] - p[(n - 2 << 3) - 1]) * .25;
	c3 = (p[(n << 3) - 1] + p[(n - 2 << 3) - 1] - c1 - c1) / 6.;
	d0 = p[(n - 1 << 3) - 3];
	d1 = (p[(n << 3) - 3] - p[(n - 2 << 3) - 3]) * .5;
	d2 = (p[(n << 3) - 3] + p[(n - 2 << 3) - 3] - d0 - d0) * .5;
	e0 = p[(n - 1 << 3) - 2];
	e1 = (p[(n << 3) - 2] - p[(n - 2 << 3) - 2]) * .5;
	e2 = (p[(n << 3) - 2] + p[(n - 2 << 3) - 2] - e0 - e0) * .5;
/* *****INNER LOOP (FOR QUADRATURE) */
L4:
	t = (z__ - p[(n - 1 << 3) - 6]) / step;
	if (t > 1.) {
	    goto L5;
	}
	hli = (((c3 * t + c2) * t + c1) * t + c0) * .5;
	zq = z__ * z__;
	r__ = hli + sqrt(hli * hli + zq);
	if (r__ <= rmin) {
	    goto L30;
	}
	rq = r__ * r__;
	ff = sqrt(zq * 3. / rq + 1.);
	radik = *b0 - ((d2 * t + d1) * t + d0) * r__ * rq * ff;
	if (r__ - rmax <= 0.) {
	    goto L44;
	} else {
	    goto L45;
	}
L45:
	*icode = 2;
/* Computing 2nd power */
	d__1 = r__ - rmax;
	radik -= d__1 * d__1 * 12.;
L44:
	if (radik + radik <= oradik) {
	    goto L10;
	}
	term = sqrt(radik) * ff * ((e2 * t + e1) * t + e0) / (rq + zq);
	fi += stp * (oterm + term);
	oradik = radik;
	oterm = term;
	stp = r__ * steq;
	z__ += stp;
	goto L4;
/* *****PREDICTOR (FIELD LINE TRACING) */
L5:
	p[(n + 1 << 3) - 8] = p[(n << 3) - 8] + step12 * (p[(n << 3) - 5] * 
		23. - p[(n - 1 << 3) - 5] * 16. + p[(n - 2 << 3) - 5] * 5.);
	p[(n + 1 << 3) - 7] = p[(n << 3) - 7] + step12 * (p[(n << 3) - 4] * 
		23. - p[(n - 1 << 3) - 4] * 16. + p[(n - 2 << 3) - 4] * 5.);
	p[(n + 1 << 3) - 6] = p[(n << 3) - 6] + step;
	stoer_(&p[(n + 1 << 3) - 8], &bq3, &r3);
/* *****SEARCH FOR LOWEST MAGNETIC FIELD STRENGTH */
	if (bq3 < bequ) {
	    iequ = n + 1;
	    bequ = bq3;
	}
/* L3: */
    }
L10:
    if (iequ < 2) {
	iequ = 2;
    }
    fidb0_1.sp[0] = p[(iequ - 1 << 3) - 8];
    fidb0_1.sp[1] = p[(iequ - 1 << 3) - 7];
    fidb0_1.sp[2] = p[(iequ - 1 << 3) - 6];
    if (oradik < 1e-15) {
	goto L11;
    }
    fi += stp / .75 * oterm * oradik / (oradik - radik);

/* -- The minimal allowable value of FI was changed from 1E-15 to 1E-12, */
/* -- because 1E-38 is the minimal allowable arg. for ALOG in our envir. */
/* -- D. Bilitza, Nov 87. */

L11:
    fi = abs(fi) * .5 / sqrt(*b0) + 1e-12;

/* *****COMPUTE L FROM B AND I.  SAME AS CARMEL IN INVAR. */

/* -- Correct dipole moment is used here. D. Bilitza, Nov 87. */

    dimob0 = *dimo / *b0;
    arg1 = log(fi);
    arg2 = log(dimob0);
/*      arg = FI*FI*FI/DIMOB0 */
/*      if(abs(arg).gt.88.0) arg=88.0 */
    xx = arg1 * 3 - arg2;
    if (xx > 23.) {
	goto L776;
    }
    if (xx > 11.7) {
	goto L775;
    }
    if (xx > 3.) {
	goto L774;
    }
    if (xx > -3.) {
	goto L773;
    }
    if (xx > -22.) {
	goto L772;
    }
/* L771: */
    gg = xx * .333338 + .30062102;
    goto L777;
L772:
    gg = ((((((((xx * -8.1537735e-14 + 8.3232531e-13) * xx + 1.0066362e-9) * 
	    xx + 8.1048663e-8) * xx + 3.2916354e-6) * xx + 8.2711096e-5) * xx 
	    + .0013714667) * xx + .015017245) * xx + .43432642) * xx + 
	    .62337691;
    goto L777;
L773:
    gg = ((((((((xx * 2.6047023e-10 + 2.3028767e-9) * xx - 2.1997983e-8) * xx 
	    - 5.3977642e-7) * xx - 3.3408822e-6) * xx + 3.8379917e-5) * xx + 
	    .0011784234) * xx + .014492441) * xx + .43352788) * xx + .6228644;
    goto L777;
L774:
    gg = ((((((((xx * 6.3271665e-10 - 3.958306e-8) * xx + 9.9766148e-7) * xx 
	    - 1.2531932e-5) * xx + 7.9451313e-5) * xx - 3.2077032e-4) * xx + 
	    .0021680398) * xx + .012817956) * xx + .43510529) * xx + .6222355;
    goto L777;
L775:
    gg = (((((xx * 2.8212095e-8 - 3.8049276e-6) * xx + 2.170224e-4) * xx - 
	    .0067310339) * xx + .12038224) * xx - .18461796) * xx + 2.0007187;
    goto L777;
L776:
    gg = xx - 3.0460681;
L777:
    *fl = exp(log((exp(gg) + 1.) * dimob0) / 3.);
    return 0;
/* *****APPROXIMATION FOR HIGH VALUES OF L. */
L30:
    *icode = 3;
    t = -p[(n - 1 << 3) - 6] / step;
    *fl = 1. / ((d__1 = ((c3 * t + c2) * t + c1) * t + c0, abs(d__1)) + 1e-15)
	    ;
    return 0;
} /* shellg_ */

/* Subroutine */ int shellg_(doublereal *glat, doublereal *glon, doublereal *
	alt, doublereal *dimo, doublereal *fl, integer *icode, doublereal *b0)
{
    return shellg_0_(0, glat, glon, alt, dimo, fl, icode, b0, (doublereal *)0)
	    ;
    }

/* Subroutine */ int shellc_(doublereal *v, doublereal *fl, doublereal *b0)
{
    return shellg_0_(1, (doublereal *)0, (doublereal *)0, (doublereal *)0, (
	    doublereal *)0, fl, (integer *)0, b0, v);
    }



/* Subroutine */ int stoer_(doublereal *p, doublereal *bq, doublereal *r__)
{
    /* Initialized data */

    static doublereal u[9]	/* was [3][3] */ = { .3511737,-.9148385,
	    -.1993679,.9335804,.358368,0.,.0714471,-.186126,.9799247 };

    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal q, dr, dx, dy, dz, rq, xm, ym, zm, wr, fli, dsq, dxm, 
	    dym, dzm;
    extern /* Subroutine */ int feldi_();

/* ******************************************************************* */
/* * SUBROUTINE USED FOR FIELD LINE TRACING IN SHELLG                * */
/* * CALLS ENTRY POINT FELDI IN GEOMAGNETIC FIELD SUBROUTINE FELDG   * */
/* ******************************************************************* */
/* *****XM,YM,ZM  ARE GEOMAGNETIC CARTESIAN INVERSE CO-ORDINATES */
    /* Parameter adjustments */
    --p;

    /* Function Body */
    zm = p[3];
    fli = p[1] * p[1] + p[2] * p[2] + 1e-15;
/* Computing 2nd power */
    d__1 = zm + zm;
    *r__ = (fli + sqrt(fli * fli + d__1 * d__1)) * .5;
    rq = *r__ * *r__;
    wr = sqrt(*r__);
    xm = p[1] * wr;
    ym = p[2] * wr;
/* *****TRANSFORM TO GEOGRAPHIC CO-ORDINATE SYSTEM */
    igrf_2.xi[0] = xm * u[0] + ym * u[3] + zm * u[6];
    igrf_2.xi[1] = xm * u[1] + ym * u[4] + zm * u[7];
    igrf_2.xi[2] = xm * u[2] + zm * u[8];
/* *****COMPUTE DERIVATIVES */
/*      CALL FELDI(XI,H) */
    feldi_();
    q = igrf_2.h__[0] / rq;
    dx = igrf_2.h__[2] + igrf_2.h__[2] + q * igrf_2.xi[0];
    dy = igrf_2.h__[3] + igrf_2.h__[3] + q * igrf_2.xi[1];
    dz = igrf_2.h__[1] + igrf_2.h__[1] + q * igrf_2.xi[2];
/* *****TRANSFORM BACK TO GEOMAGNETIC CO-ORDINATE SYSTEM */
    dxm = u[0] * dx + u[1] * dy + u[2] * dz;
    dym = u[3] * dx + u[4] * dy;
    dzm = u[6] * dx + u[7] * dy + u[8] * dz;
    dr = (xm * dxm + ym * dym + zm * dzm) / *r__;
/* *****FORM SLOWLY VARYING EXPRESSIONS */
    p[4] = (wr * dxm - p[1] * .5 * dr) / (*r__ * dzm);
    p[5] = (wr * dym - p[2] * .5 * dr) / (*r__ * dzm);
    dsq = rq * (dxm * dxm + dym * dym + dzm * dzm);
    *bq = dsq * rq * rq;
    p[6] = sqrt(dsq / (rq + zm * 3. * zm));
    p[7] = p[6] * (rq + zm * zm) / (rq * dzm);
    return 0;
} /* stoer_ */



/* Subroutine */ int feldg_0_(int n__, doublereal *glat, doublereal *glon, 
	doublereal *alt, doublereal *bnorth, doublereal *beast, doublereal *
	bdown, doublereal *babs, doublereal *v, doublereal *b)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal), sqrt(doublereal);

    /* Local variables */
    static doublereal d__, f;
    static integer i__, k, m;
    static doublereal s, t, x, y, z__;
    static integer ih;
    static doublereal cp;
    static integer il;
    static doublereal ct;
    static integer is;
    static doublereal sp, rq, st, rho, xxx, yyy, zzz, brho;
    static integer imax;
    static doublereal rlat;
    static integer last;
    static doublereal rlon, bxxx, byyy, bzzz;
    static integer ihmax;

/* ----------------------------------------------------------------------- */
/* CALCULATES EARTH MAGNETIC FIELD FROM SPHERICAL HARMONICS MODEL */
/* REF: G. KLUGE, EUROPEAN SPACE OPERATIONS CENTRE, INTERNAL NOTE 61, */
/*      1970. */
/* ----------------------------------------------------------------------- */
/* CHANGES (D. BILITZA, NOV 87): */
/*   - FIELD COEFFICIENTS IN BINARY DATA FILES INSTEAD OF BLOCK DATA */
/*   - CALCULATES DIPOL MOMENT */
/* ----------------------------------------------------------------------- */
/*  INPUT:  ENTRY POINT FELDG */
/*               GLAT  GEODETIC LATITUDE IN DEGREES (NORTH) */
/*               GLON  GEODETIC LONGITUDE IN DEGREES (EAST) */
/*               ALT   ALTITUDE IN KM ABOVE SEA LEVEL */

/*          ENTRY POINT FELDC */
/*               V(3)  CARTESIAN COORDINATES IN EARTH RADII (6371.2 KM) */
/*                       X-AXIS POINTING TO EQUATOR AT 0 LONGITUDE */
/*                       Y-AXIS POINTING TO EQUATOR AT 90 LONG. */
/*                       Z-AXIS POINTING TO NORTH POLE */

/*          COMMON BLANK AND ENTRY POINT FELDI ARE NEEDED WHEN USED */
/*            IN CONNECTION WITH L-CALCULATION PROGRAM SHELLG. */

/*          COMMON /MODEL/ AND /IGRF1/ */
/*               UMR     = ATAN(1.0)*4./180.   <DEGREE>*UMR=<RADIANT> */
/*               ERA     EARTH RADIUS FOR NORMALIZATION OF CARTESIAN */
/*                       COORDINATES (6371.2 KM) */
/*               AQUAD, BQUAD   SQUARE OF MAJOR AND MINOR HALF AXIS OF */
/*                       EARTH ELLIPSOID AS RECOMMENDED BY INTERNAT. */
/*                       ASTRONOMICAL UNION (6378.160, 6356.775 KM). */
/*               NMAX    MAXIMUM ORDER OF SPHERICAL HARMONICS */
/*               TIME    YEAR (DECIMAL: 1973.5) FOR WHICH MAGNETIC */
/*                       FIELD IS TO BE CALCULATED */
/*               G(M)    NORMALIZED FIELD COEFFICIENTS (SEE FELDCOF) */
/*                       M=NMAX*(NMAX+2) */
/* ----------------------------------------------------------------------- */
/*  OUTPUT: BABS   MAGNETIC FIELD STRENGTH IN GAUSS */
/*          BNORTH, BEAST, BDOWN   COMPONENTS OF THE FIELD WITH RESPECT */
/*                 TO THE LOCAL GEODETIC COORDINATE SYSTEM, WITH AXIS */
/*                 POINTING IN THE TANGENTIAL PLANE TO THE NORTH, EAST */
/*                 AND DOWNWARD. */
/* ----------------------------------------------------------------------- */

/* -- IS RECORDS ENTRY POINT */

/* *****ENTRY POINT  FELDG  TO BE USED WITH GEODETIC CO-ORDINATES */
    /* Parameter adjustments */
    if (v) {
	--v;
	}
    if (b) {
	--b;
	}

    /* Function Body */
    switch(n__) {
	case 1: goto L_feldc;
	case 2: goto L_feldi;
	}

    is = 1;
    rlat = *glat * igrf1_1.umr;
    ct = sin(rlat);
    st = cos(rlat);
    d__ = sqrt(igrf1_1.aquad - (igrf1_1.aquad - igrf1_1.bquad) * ct * ct);
    rlon = *glon * igrf1_1.umr;
    cp = cos(rlon);
    sp = sin(rlon);
    zzz = (*alt + igrf1_1.bquad / d__) * ct / igrf1_1.era;
    rho = (*alt + igrf1_1.aquad / d__) * st / igrf1_1.era;
    xxx = rho * cp;
    yyy = rho * sp;
    goto L10;

L_feldc:
/* *****ENTRY POINT  FELDC  TO BE USED WITH CARTESIAN CO-ORDINATES */
    is = 2;
    xxx = v[1];
    yyy = v[2];
    zzz = v[3];
L10:
    rq = 1. / (xxx * xxx + yyy * yyy + zzz * zzz);
    igrf_2.xi[0] = xxx * rq;
    igrf_2.xi[1] = yyy * rq;
    igrf_2.xi[2] = zzz * rq;
    goto L20;

L_feldi:
/* *****ENTRY POINT  FELDI  USED FOR L COMPUTATION */
    is = 3;
L20:
    ihmax = model_1.nmax * model_1.nmax + 1;
    last = ihmax + model_1.nmax + model_1.nmax;
    imax = model_1.nmax + model_1.nmax - 1;
    i__1 = last;
    for (i__ = ihmax; i__ <= i__1; ++i__) {
/* L8: */
	igrf_2.h__[i__ - 1] = model_1.g[i__ - 1];
    }
    for (k = 1; k <= 3; k += 2) {
	i__ = imax;
	ih = ihmax;
L1:
	il = ih - i__;
	f = 2. / (doublereal) (i__ - k + 2);
	x = igrf_2.xi[0] * f;
	y = igrf_2.xi[1] * f;
	z__ = igrf_2.xi[2] * (f + f);
	i__ += -2;
	if ((i__1 = i__ - 1) < 0) {
	    goto L5;
	} else if (i__1 == 0) {
	    goto L4;
	} else {
	    goto L2;
	}
L2:
	i__1 = i__;
	for (m = 3; m <= i__1; m += 2) {
	    igrf_2.h__[il + m] = model_1.g[il + m] + z__ * igrf_2.h__[ih + m] 
		    + x * (igrf_2.h__[ih + m + 2] - igrf_2.h__[ih + m - 2]) - 
		    y * (igrf_2.h__[ih + m + 1] + igrf_2.h__[ih + m - 3]);
/* L3: */
	    igrf_2.h__[il + m - 1] = model_1.g[il + m - 1] + z__ * igrf_2.h__[
		    ih + m - 1] + x * (igrf_2.h__[ih + m + 1] - igrf_2.h__[ih 
		    + m - 3]) + y * (igrf_2.h__[ih + m + 2] + igrf_2.h__[ih + 
		    m - 2]);
	}
L4:
	igrf_2.h__[il + 1] = model_1.g[il + 1] + z__ * igrf_2.h__[ih + 1] + x 
		* igrf_2.h__[ih + 3] - y * (igrf_2.h__[ih + 2] + igrf_2.h__[
		ih - 1]);
	igrf_2.h__[il] = model_1.g[il] + z__ * igrf_2.h__[ih] + y * 
		igrf_2.h__[ih + 3] + x * (igrf_2.h__[ih + 2] - igrf_2.h__[ih 
		- 1]);
L5:
	igrf_2.h__[il - 1] = model_1.g[il - 1] + z__ * igrf_2.h__[ih - 1] + (
		x * igrf_2.h__[ih] + y * igrf_2.h__[ih + 1]) * 2.;
	ih = il;
	if (i__ >= k) {
	    goto L1;
	}
/* L6: */
    }
    if (is == 3) {
	return 0;
    }
    s = igrf_2.h__[0] * .5 + (igrf_2.h__[1] * igrf_2.xi[2] + igrf_2.h__[2] * 
	    igrf_2.xi[0] + igrf_2.h__[3] * igrf_2.xi[1]) * 2.;
    t = (rq + rq) * sqrt(rq);
    bxxx = t * (igrf_2.h__[2] - s * xxx);
    byyy = t * (igrf_2.h__[3] - s * yyy);
    bzzz = t * (igrf_2.h__[1] - s * zzz);
    if (is == 2) {
	goto L7;
    }
    *babs = sqrt(bxxx * bxxx + byyy * byyy + bzzz * bzzz);
    *beast = byyy * cp - bxxx * sp;
    brho = byyy * sp + bxxx * cp;
    *bnorth = bzzz * st - brho * ct;
    *bdown = -bzzz * ct - brho * st;
    return 0;
L7:
    b[1] = bxxx;
    b[2] = byyy;
    b[3] = bzzz;
    return 0;
} /* feldg_ */

/* Subroutine */ int feldg_(doublereal *glat, doublereal *glon, doublereal *
	alt, doublereal *bnorth, doublereal *beast, doublereal *bdown, 
	doublereal *babs)
{
    return feldg_0_(0, glat, glon, alt, bnorth, beast, bdown, babs, (
	    doublereal *)0, (doublereal *)0);
    }

/* Subroutine */ int feldc_(doublereal *v, doublereal *b)
{
    return feldg_0_(1, (doublereal *)0, (doublereal *)0, (doublereal *)0, (
	    doublereal *)0, (doublereal *)0, (doublereal *)0, (doublereal *)0,
	     v, b);
    }

/* Subroutine */ int feldi_()
{
    return feldg_0_(2, (doublereal *)0, (doublereal *)0, (doublereal *)0, (
	    doublereal *)0, (doublereal *)0, (doublereal *)0, (doublereal *)0,
	     (doublereal *)0, (doublereal *)0);
    }



/* Subroutine */ int feldcof_(doublereal *year, doublereal *dimo)
{
    /* Initialized data */

    static char filmod[12*14+1] = "dgrf45.dat  dgrf50.dat  dgrf55.dat  dgrf6\
0.dat  dgrf65.dat  dgrf70.dat  dgrf75.dat  dgrf80.dat  dgrf85.dat  dgrf90.da\
t  dgrf95.dat  dgrf00.dat  igrf05.dat  igrf05s.dat ";
    static doublereal dtemod[14] = { 1945.,1950.,1955.,1960.,1965.,1970.,
	    1975.,1980.,1985.,1990.,1995.,2e3,2005.,2010. };

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_stop(char *
	    , ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    extern /* Subroutine */ int intershc_(doublereal *, doublereal *, integer 
	    *, doublereal *, doublereal *, integer *, doublereal *, integer *,
	     doublereal *), extrashc_(doublereal *, doublereal *, integer *, 
	    doublereal *, integer *, doublereal *, integer *, doublereal *);
    static doublereal f;
    static integer i__, j, l, m, n;
    static doublereal x, f0;
    static integer is, iu;
    static doublereal gh2[144], gha[144];
    static integer ier;
    static char fil2[12];
    static doublereal dte1, dte2;
    static integer iyea, nmax1, nmax2;
    static doublereal sqrt2;
    static integer numye;
    extern /* Subroutine */ int getshc_(integer *, char *, integer *, 
	    doublereal *, doublereal *, integer *, ftnlen);

/* ----------------------------------------------------------------------- */
/*  DETERMINES COEFFICIENTS AND DIPOL MOMENT FROM IGRF MODELS */

/*       INPUT:  YEAR    DECIMAL YEAR FOR WHICH GEOMAGNETIC FIELD IS TO */
/*                       BE CALCULATED */
/*       OUTPUT: DIMO    GEOMAGNETIC DIPOL MOMENT IN GAUSS (NORMALIZED */
/*                       TO EARTH'S RADIUS) AT THE TIME (YEAR) */
/*  D. BILITZA, NSSDC, GSFC, CODE 633, GREENBELT, MD 20771, */
/*       (301)286-9536   NOV 1987. */
/*  ### updated to IGRF-10 version -dkb- 11/10/2005 */
/* ----------------------------------------------------------------------- */
/* ### FILMOD, DTEMOD arrays +1 */
/* ### updated to 2005 */

/* ### numye = numye + 1 ; is number of years represented by IGRF */

    numye = 13;

/*  IS=0 FOR SCHMIDT NORMALIZATION   IS=1 GAUSS NORMALIZATION */
/*  IU  IS INPUT UNIT NUMBER FOR IGRF COEFFICIENT SETS */

    iu = 14;
    is = 0;
/* -- DETERMINE IGRF-YEARS FOR INPUT-YEAR */
    model_2.time = *year;
    iyea = (integer) (*year / 5.) * 5;
    l = (iyea - 1945) / 5 + 1;
    if (l < 1) {
	l = 1;
    }
    if (l > numye) {
	l = numye;
    }
    dte1 = dtemod[l - 1];
    s_copy(model_2.fil1, filmod + (l - 1) * 12, (ftnlen)12, (ftnlen)12);
    dte2 = dtemod[l];
    s_copy(fil2, filmod + l * 12, (ftnlen)12, (ftnlen)12);
/* -- GET IGRF COEFFICIENTS FOR THE BOUNDARY YEARS */
    getshc_(&iu, model_2.fil1, &nmax1, &igrf1_2.erad, model_2.gh1, &ier, (
	    ftnlen)12);
    if (ier != 0) {
	s_stop("", (ftnlen)0);
    }
    getshc_(&iu, fil2, &nmax2, &igrf1_2.erad, gh2, &ier, (ftnlen)12);
    if (ier != 0) {
	s_stop("", (ftnlen)0);
    }
/* -- DETERMINE IGRF COEFFICIENTS FOR YEAR */
    if (l <= numye - 1) {
	intershc_(year, &dte1, &nmax1, model_2.gh1, &dte2, &nmax2, gh2, &
		model_2.nmax, gha);
    } else {
	extrashc_(year, &dte1, &nmax1, model_2.gh1, &nmax2, gh2, &
		model_2.nmax, gha);
    }
/* -- DETERMINE MAGNETIC DIPOL MOMENT AND COEFFIECIENTS G */
    f0 = 0.;
    for (j = 1; j <= 3; ++j) {
	f = gha[j - 1] * 1e-5;
	f0 += f * f;
/* L1234: */
    }
    *dimo = sqrt(f0);
    model_2.gh1[0] = 0.;
    i__ = 2;
    f0 = 1e-5;
    if (is == 0) {
	f0 = -f0;
    }
    sqrt2 = sqrt(2.);
    i__1 = model_2.nmax;
    for (n = 1; n <= i__1; ++n) {
	x = (doublereal) n;
	f0 = f0 * x * x / (x * 4. - 2.);
	if (is == 0) {
	    f0 = f0 * (x * 2. - 1.) / x;
	}
	f = f0 * .5;
	if (is == 0) {
	    f *= sqrt2;
	}
	model_2.gh1[i__ - 1] = gha[i__ - 2] * f0;
	++i__;
	i__2 = n;
	for (m = 1; m <= i__2; ++m) {
	    f = f * (x + m) / (x - m + 1.);
	    if (is == 0) {
		f *= sqrt((x - m + 1.) / (x + m));
	    }
	    model_2.gh1[i__ - 1] = gha[i__ - 2] * f;
	    model_2.gh1[i__] = gha[i__ - 1] * f;
	    i__ += 2;
/* L9: */
	}
    }
    return 0;
} /* feldcof_ */



/* Subroutine */ int getshc_(integer *iu, char *fspec, integer *nmax, 
	doublereal *erad, doublereal *gh, integer *ier, ftnlen fspec_len)
{
    /* Format strings */
    static char fmt_667[] = "(a12)";

    /* System generated locals */
    integer i__1, i__2;
    olist o__1;
    cllist cl__1;

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(), 
	    f_open(olist *), s_rsle(cilist *), e_rsle(), do_lio(integer *, 
	    integer *, char *, ftnlen), f_clos(cllist *);

    /* Local variables */
    static doublereal g, h__;
    static integer i__, m, n, mm, nn;
    static char fout[55];

    /* Fortran I/O blocks */
    static icilist io___161 = { 0, fout, 0, fmt_667, 55, 1 };
    static cilist io___162 = { 1, 0, 1, 0, 0 };
    static cilist io___163 = { 1, 0, 1, 0, 0 };
    static cilist io___167 = { 1, 0, 1, 0, 0 };


/* =============================================================== */

/*       Version 1.01 */

/*       Reads spherical harmonic coefficients from the specified */
/*       file into an array. */

/*       Input: */
/*           IU    - Logical unit number */
/*           FSPEC - File specification */

/*       Output: */
/*           NMAX  - Maximum degree and order of model */
/*           ERAD  - Earth's radius associated with the spherical */
/*                   harmonic coefficients, in the same units as */
/*                   elevation */
/*           GH    - Schmidt quasi-normal internal spherical */
/*                   harmonic coefficients */
/*           IER   - Error number: =  0, no error */
/*                                 = -2, records out of order */
/*                                 = FORTRAN run-time error number */

/*       A. Zunde */
/*       USGS, MS 964, Box 25046 Federal Center, Denver, CO  80225 */

/* =============================================================== */
/* --------------------------------------------------------------- */
/*       Open coefficient file. Read past first header record. */
/*       Read degree and order of model and Earth's radius. */
/* --------------------------------------------------------------- */
    /* Parameter adjustments */
    --gh;

    /* Function Body */
    s_wsfi(&io___161);
    do_fio(&c__1, fspec, fspec_len);
    e_wsfi();
/* special for IRIWeb version */
/* 667  FORMAT('/usr/local/etc/httpd/cgi-bin/models/IRI/',A12) */
    o__1.oerr = 1;
    o__1.ounit = *iu;
    o__1.ofnmlen = 55;
    o__1.ofnm = fout;
    o__1.orl = 0;
    o__1.osta = "OLD";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    *ier = f_open(&o__1);
    if (*ier != 0) {
	goto L999;
    }
    io___162.ciunit = *iu;
    *ier = s_rsle(&io___162);
    if (*ier != 0) {
	goto L100001;
    }
    *ier = e_rsle();
L100001:
    if (*ier > 0) {
	goto L999;
    }
    io___163.ciunit = *iu;
    *ier = s_rsle(&io___163);
    if (*ier != 0) {
	goto L100002;
    }
    *ier = do_lio(&c__3, &c__1, (char *)&(*nmax), (ftnlen)sizeof(integer));
    if (*ier != 0) {
	goto L100002;
    }
    *ier = do_lio(&c__5, &c__1, (char *)&(*erad), (ftnlen)sizeof(doublereal));
    if (*ier != 0) {
	goto L100002;
    }
    *ier = e_rsle();
L100002:
    if (*ier > 0) {
	goto L999;
    }
/* --------------------------------------------------------------- */
/*       Read the coefficient file, arranged as follows: */

/*                                       N     M     G     H */
/*                                       ---------------------- */
/*                                   /   1     0    GH(1)  - */
/*                                  /    1     1    GH(2) GH(3) */
/*                                 /     2     0    GH(4)  - */
/*                                /      2     1    GH(5) GH(6) */
/*           NMAX*(NMAX+3)/2     /       2     2    GH(7) GH(8) */
/*              records          \       3     0    GH(9)  - */
/*                                \      .     .     .     . */
/*                                 \     .     .     .     . */
/*           NMAX*(NMAX+2)          \    .     .     .     . */
/*           elements in GH          \  NMAX  NMAX   .     . */

/*       N and M are, respectively, the degree and order of the */
/*       coefficient. */
/* --------------------------------------------------------------- */
    i__ = 0;
    i__1 = *nmax;
    for (nn = 1; nn <= i__1; ++nn) {
	i__2 = nn;
	for (mm = 0; mm <= i__2; ++mm) {
	    io___167.ciunit = *iu;
	    *ier = s_rsle(&io___167);
	    if (*ier != 0) {
		goto L100003;
	    }
	    *ier = do_lio(&c__3, &c__1, (char *)&n, (ftnlen)sizeof(integer));
	    if (*ier != 0) {
		goto L100003;
	    }
	    *ier = do_lio(&c__3, &c__1, (char *)&m, (ftnlen)sizeof(integer));
	    if (*ier != 0) {
		goto L100003;
	    }
	    *ier = do_lio(&c__5, &c__1, (char *)&g, (ftnlen)sizeof(doublereal)
		    );
	    if (*ier != 0) {
		goto L100003;
	    }
	    *ier = do_lio(&c__5, &c__1, (char *)&h__, (ftnlen)sizeof(
		    doublereal));
	    if (*ier != 0) {
		goto L100003;
	    }
	    *ier = e_rsle();
L100003:
	    if (*ier > 0) {
		goto L999;
	    }
	    if (nn != n || mm != m) {
		*ier = -2;
		goto L999;
	    }
	    ++i__;
	    gh[i__] = g;
	    if (m != 0) {
		++i__;
		gh[i__] = h__;
	    }
/* L2233: */
	}
/* L2211: */
    }
L999:
    cl__1.cerr = 0;
    cl__1.cunit = *iu;
    cl__1.csta = 0;
    f_clos(&cl__1);
    return 0;
} /* getshc_ */



/* Subroutine */ int intershc_(doublereal *date, doublereal *dte1, integer *
	nmax1, doublereal *gh1, doublereal *dte2, integer *nmax2, doublereal *
	gh2, integer *nmax, doublereal *gh)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, k, l;
    static doublereal factor;

/* =============================================================== */

/*       Version 1.01 */

/*       Interpolates linearly, in time, between two spherical */
/*       harmonic models. */

/*       Input: */
/*           DATE  - Date of resulting model (in decimal year) */
/*           DTE1  - Date of earlier model */
/*           NMAX1 - Maximum degree and order of earlier model */
/*           GH1   - Schmidt quasi-normal internal spherical */
/*                   harmonic coefficients of earlier model */
/*           DTE2  - Date of later model */
/*           NMAX2 - Maximum degree and order of later model */
/*           GH2   - Schmidt quasi-normal internal spherical */
/*                   harmonic coefficients of later model */

/*       Output: */
/*           GH    - Coefficients of resulting model */
/*           NMAX  - Maximum degree and order of resulting model */

/*       A. Zunde */
/*       USGS, MS 964, Box 25046 Federal Center, Denver, CO  80225 */

/* =============================================================== */
/* --------------------------------------------------------------- */
/*       The coefficients (GH) of the resulting model, at date */
/*       DATE, are computed by linearly interpolating between the */
/*       coefficients of the earlier model (GH1), at date DTE1, */
/*       and those of the later model (GH2), at date DTE2. If one */
/*       model is smaller than the other, the interpolation is */
/*       performed with the missing coefficients assumed to be 0. */
/* --------------------------------------------------------------- */
    /* Parameter adjustments */
    --gh;
    --gh2;
    --gh1;

    /* Function Body */
    factor = (*date - *dte1) / (*dte2 - *dte1);
    if (*nmax1 == *nmax2) {
	k = *nmax1 * (*nmax1 + 2);
	*nmax = *nmax1;
    } else if (*nmax1 > *nmax2) {
	k = *nmax2 * (*nmax2 + 2);
	l = *nmax1 * (*nmax1 + 2);
	i__1 = l;
	for (i__ = k + 1; i__ <= i__1; ++i__) {
/* L1122: */
	    gh[i__] = gh1[i__] + factor * (-gh1[i__]);
	}
	*nmax = *nmax1;
    } else {
	k = *nmax1 * (*nmax1 + 2);
	l = *nmax2 * (*nmax2 + 2);
	i__1 = l;
	for (i__ = k + 1; i__ <= i__1; ++i__) {
/* L1133: */
	    gh[i__] = factor * gh2[i__];
	}
	*nmax = *nmax2;
    }
    i__1 = k;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L1144: */
	gh[i__] = gh1[i__] + factor * (gh2[i__] - gh1[i__]);
    }
    return 0;
} /* intershc_ */



/* Subroutine */ int extrashc_(doublereal *date, doublereal *dte1, integer *
	nmax1, doublereal *gh1, integer *nmax2, doublereal *gh2, integer *
	nmax, doublereal *gh)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, k, l;
    static doublereal factor;

/* =============================================================== */

/*       Version 1.01 */

/*       Extrapolates linearly a spherical harmonic model with a */
/*       rate-of-change model. */

/*       Input: */
/*           DATE  - Date of resulting model (in decimal year) */
/*           DTE1  - Date of base model */
/*           NMAX1 - Maximum degree and order of base model */
/*           GH1   - Schmidt quasi-normal internal spherical */
/*                   harmonic coefficients of base model */
/*           NMAX2 - Maximum degree and order of rate-of-change */
/*                   model */
/*           GH2   - Schmidt quasi-normal internal spherical */
/*                   harmonic coefficients of rate-of-change model */

/*       Output: */
/*           GH    - Coefficients of resulting model */
/*           NMAX  - Maximum degree and order of resulting model */

/*       A. Zunde */
/*       USGS, MS 964, Box 25046 Federal Center, Denver, CO  80225 */

/* =============================================================== */
/* --------------------------------------------------------------- */
/*       The coefficients (GH) of the resulting model, at date */
/*       DATE, are computed by linearly extrapolating the coef- */
/*       ficients of the base model (GH1), at date DTE1, using */
/*       those of the rate-of-change model (GH2), at date DTE2. If */
/*       one model is smaller than the other, the extrapolation is */
/*       performed with the missing coefficients assumed to be 0. */
/* --------------------------------------------------------------- */
    /* Parameter adjustments */
    --gh;
    --gh2;
    --gh1;

    /* Function Body */
    factor = *date - *dte1;
    if (*nmax1 == *nmax2) {
	k = *nmax1 * (*nmax1 + 2);
	*nmax = *nmax1;
    } else if (*nmax1 > *nmax2) {
	k = *nmax2 * (*nmax2 + 2);
	l = *nmax1 * (*nmax1 + 2);
	i__1 = l;
	for (i__ = k + 1; i__ <= i__1; ++i__) {
/* L1155: */
	    gh[i__] = gh1[i__];
	}
	*nmax = *nmax1;
    } else {
	k = *nmax1 * (*nmax1 + 2);
	l = *nmax2 * (*nmax2 + 2);
	i__1 = l;
	for (i__ = k + 1; i__ <= i__1; ++i__) {
/* L1166: */
	    gh[i__] = factor * gh2[i__];
	}
	*nmax = *nmax2;
    }
    i__1 = k;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L1177: */
	gh[i__] = gh1[i__] + factor * gh2[i__];
    }
    return 0;
} /* extrashc_ */



/* Subroutine */ int initize_()
{
    /* Builtin functions */
    double atan(doublereal);

    /* Local variables */
    static doublereal erequ, erpol;

/* ---------------------------------------------------------------- */
/* Initializes the parameters in COMMON/IGRF1/ */

/*       UMR     = ATAN(1.0)*4./180.   <DEGREE>*UMR=<RADIANT> */
/*       ERA     EARTH RADIUS FOR NORMALIZATION OF CARTESIAN */
/*                       COORDINATES (6371.2 KM) */
/*       EREQU   MAJOR HALF AXIS FOR EARTH ELLIPSOID (6378.160 KM) */
/*       ERPOL   MINOR HALF AXIS FOR EARTH ELLIPSOID (6356.775 KM) */
/*       AQUAD   SQUARE OF MAJOR HALF AXIS FOR EARTH ELLIPSOID */
/*       BQUAD   SQUARE OF MINOR HALF AXIS FOR EARTH ELLIPSOID */

/* ERA, EREQU and ERPOL as recommended by the INTERNATIONAL */
/* ASTRONOMICAL UNION . */
/* ----------------------------------------------------------------- */
    igrf1_1.era = 6371.2;
    erequ = 6378.16;
    erpol = 6356.775;
    igrf1_1.aquad = erequ * erequ;
    igrf1_1.bquad = erpol * erpol;
    igrf1_1.umr = atan(1.) * 4. / 180.;
    return 0;
} /* initize_ */



/* Subroutine */ int geodip_(integer *iyr, doublereal *sla, doublereal *slo, 
	doublereal *dla, doublereal *dlo, integer *j)
{
    static doublereal r__, x, y, z__, pf, th, rm, xm, ym, zm, dco, col, sco, 
	    rlo, szm;
    extern /* Subroutine */ int geomag_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *), sphcar_(doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *);

/*  Calculates dipole geomagnetic coordinates from geocentric coordinates */
/*  or vice versa. */
/*                     J=0           J=1 */
/* 		INPUT:     J,SLA,SLO     J,DLA,DLO */
/* 		OUTPUT:     DLA,DLO       SLA,SLO */
/*  Last revision: November 2005 (Vladimir Papitashvili) */
/*  The code is modifed from GEOCOR written by V.Popov and V.Papitashvili */
/*  in mid-1980s. */
/*  Earth's radius (km) RE = 6371.2 */
/*  The radius of the sphere to compute the coordinates (in Re) */
/*        RH = (RE + HI)/RE */
    r__ = 1.;
    if (*j > 0) {
	goto L1234;
    }
    col = (90. - *sla) * const_1.umr;
    rlo = *slo * const_1.umr;
    sphcar_(&r__, &col, &rlo, &x, &y, &z__, &c__1);
    geomag_(&x, &y, &z__, &xm, &ym, &zm, &c__1, iyr);
    sphcar_(&rm, &th, &pf, &xm, &ym, &zm, &c_n1);
    szm = zm;
    *dlo = pf / const_1.umr;
    dco = th / const_1.umr;
    *dla = 90. - dco;
    return 0;
L1234:
    col = (90. - *dla) * const_1.umr;
    rlo = *dlo * const_1.umr;
    sphcar_(&r__, &col, &rlo, &xm, &ym, &zm, &c__1);
    geomag_(&x, &y, &z__, &xm, &ym, &zm, &c_n1, iyr);
    sphcar_(&rm, &th, &pf, &x, &y, &z__, &c_n1);
    szm = zm;
    *slo = pf / const_1.umr;
    sco = th / const_1.umr;
    *sla = 90. - sco;
    return 0;
} /* geodip_ */

/*  ********************************************************************* */
/* Subroutine */ int sphcar_(doublereal *r__, doublereal *teta, doublereal *
	phi, doublereal *x, doublereal *y, doublereal *z__, integer *j)
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal), atan2(doublereal, doublereal), sin(doublereal), 
	    cos(doublereal);

    /* Local variables */
    static doublereal sq;

/*   CONVERTS SPHERICAL COORDS INTO CARTESIAN ONES AND VICA VERSA */
/*    (TETA AND PHI IN RADIANS). */
/*                  J>0            J<0 */
/* -----INPUT:   J,R,TETA,PHI     J,X,Y,Z */
/* ----OUTPUT:      X,Y,Z        R,TETA,PHI */
/*  AUTHOR: NIKOLAI A. TSYGANENKO, INSTITUTE OF PHYSICS, ST.-PETERSBURG */
/*      STATE UNIVERSITY, STARY PETERGOF 198904, ST.-PETERSBURG, RUSSIA */
/*      (now the NASA Goddard Space Fligth Center, Greenbelt, Maryland) */
    if (*j > 0) {
	goto L3;
    }
/* Computing 2nd power */
    d__1 = *x;
/* Computing 2nd power */
    d__2 = *y;
    sq = d__1 * d__1 + d__2 * d__2;
/* Computing 2nd power */
    d__1 = *z__;
    *r__ = sqrt(sq + d__1 * d__1);
    if (sq != 0.) {
	goto L2;
    }
    *phi = 0.;
    if (*z__ < 0.) {
	goto L1;
    }
    *teta = 0.;
    return 0;
L1:
    *teta = 3.141592654;
    return 0;
L2:
    sq = sqrt(sq);
    *phi = atan2(*y, *x);
    *teta = atan2(sq, *z__);
    if (*phi < 0.) {
	*phi += 6.28318531;
    }
    return 0;
L3:
    sq = *r__ * sin(*teta);
    *x = sq * cos(*phi);
    *y = sq * sin(*phi);
    *z__ = *r__ * cos(*teta);
    return 0;
} /* sphcar_ */

/*  ********************************************************************* */
/* Subroutine */ int geomag_(doublereal *xgeo, doublereal *ygeo, doublereal *
	zgeo, doublereal *xmag, doublereal *ymag, doublereal *zmag, integer *
	j, integer *iyr)
{
    /* Initialized data */

    static integer ii = 1;

    extern /* Subroutine */ int recalc_(integer *, integer *, integer *, 
	    integer *, integer *);

/* CONVERTS GEOCENTRIC (GEO) TO DIPOLE (MAG) COORDINATES OR VICA VERSA. */
/* IYR IS YEAR NUMBER (FOUR DIGITS). */
/*                           J>0                J<0 */
/* -----INPUT:  J,XGEO,YGEO,ZGEO,IYR   J,XMAG,YMAG,ZMAG,IYR */
/* -----OUTPUT:    XMAG,YMAG,ZMAG        XGEO,YGEO,ZGEO */
/*  AUTHOR: NIKOLAI A. TSYGANENKO, INSTITUTE OF PHYSICS, ST.-PETERSBURG */
/*      STATE UNIVERSITY, STARY PETERGOF 198904, ST.-PETERSBURG, RUSSIA */
/*      (now the NASA Goddard Space Fligth Center, Greenbelt, Maryland) */
    if (*iyr == ii) {
	goto L1;
    }
    ii = *iyr;
    recalc_(&ii, &c__0, &c__25, &c__0, &c__0);
L1:
    if (*j < 0) {
	goto L2;
    }
    *xmag = *xgeo * c1_1.ctcl + *ygeo * c1_1.ctsl - *zgeo * c1_1.st0;
    *ymag = *ygeo * c1_1.cl0 - *xgeo * c1_1.sl0;
    *zmag = *xgeo * c1_1.stcl + *ygeo * c1_1.stsl + *zgeo * c1_1.ct0;
    return 0;
L2:
    *xgeo = *xmag * c1_1.ctcl - *ymag * c1_1.sl0 + *zmag * c1_1.stcl;
    *ygeo = *xmag * c1_1.ctsl + *ymag * c1_1.cl0 + *zmag * c1_1.stsl;
    *zgeo = *zmag * c1_1.ct0 - *xmag * c1_1.st0;
    return 0;
} /* geomag_ */

/*  ********************************************************************* */
/* Subroutine */ int recalc_(integer *iyr, integer *iday, integer *ihour, 
	integer *min__, integer *isec)
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal f1, f2, g10, g11, h11, dt, sq, sqq, sqr;

/*  If only IYR is given then CALL RECALC(IYR,0,25,0,0) */
/*  Modified to accept years from 1900 through 2010 using the DGRF & */
/*     IGRF-10 coeficients (updated by V. Papitashvili, November 2005) */
/*     IYR = YEAR NUMBER (FOUR DIGITS) */
/*     IHOUR = 25 */
/*  IYE AND IDE ARE THE CURRENT VALUES OF YEAR AND DAY NUMBER */
    c1_2.iy = *iyr;
/*      IF(IY.LT.1900) IY=1900 */
/*      IF(IY.GT.2010) IY=2010 */
/*  LINEAR INTERPOLATION OF THE GEODIPOLE MOMENT COMPONENTS BETWEEN THE */
/*  VALUES FOR THE NEAREST EPOCHS: */
    if (c1_2.iy < 1905) {
/* 1900-1905 */
	f2 = ((doublereal) c1_2.iy + (doublereal) (*iday) / 365. - 1900.) / 
		5.;
	f1 = 1. - f2;
	g10 = f1 * 31543. + f2 * 31464.;
	g11 = f1 * -2298. - f2 * 2298.;
	h11 = f1 * 5922. + f2 * 5909.;
    } else if (c1_2.iy < 1910) {
/* 1905-1910 */
	f2 = ((doublereal) c1_2.iy + (doublereal) (*iday) / 365. - 1905.) / 
		5.;
	f1 = 1. - f2;
	g10 = f1 * 31464. + f2 * 31354.;
	g11 = f1 * -2298. - f2 * 2297.;
	h11 = f1 * 5909. + f2 * 5898.;
    } else if (c1_2.iy < 1915) {
/* 1910-1915 */
	f2 = ((doublereal) c1_2.iy + (doublereal) (*iday) / 365. - 1910.) / 
		5.;
	f1 = 1. - f2;
	g10 = f1 * 31354. + f2 * 31212.;
	g11 = f1 * -2297. - f2 * 2306.;
	h11 = f1 * 5898. + f2 * 5875.;
    } else if (c1_2.iy < 1920) {
/* 1915-1920 */
	f2 = ((doublereal) c1_2.iy + (doublereal) (*iday) / 365. - 1915.) / 
		5.;
	f1 = 1. - f2;
	g10 = f1 * 31212. + f2 * 31060.;
	g11 = f1 * -2306. - f2 * 2317.;
	h11 = f1 * 5875. + f2 * 5845.;
    } else if (c1_2.iy < 1925) {
/* 1920-1925 */
	f2 = ((doublereal) c1_2.iy + (doublereal) (*iday) / 365. - 1920.) / 
		5.;
	f1 = 1. - f2;
	g10 = f1 * 31060. + f2 * 30926.;
	g11 = f1 * -2317. - f2 * 2318.;
	h11 = f1 * 5845. + f2 * 5817.;
    } else if (c1_2.iy < 1930) {
/* 1925-1930 */
	f2 = ((doublereal) c1_2.iy + (doublereal) (*iday) / 365. - 1925.) / 
		5.;
	f1 = 1. - f2;
	g10 = f1 * 30926. + f2 * 30805.;
	g11 = f1 * -2318. - f2 * 2316.;
	h11 = f1 * 5817. + f2 * 5808.;
    } else if (c1_2.iy < 1935) {
/* 1930-1935 */
	f2 = ((doublereal) c1_2.iy + (doublereal) (*iday) / 365. - 1930.) / 
		5.;
	f1 = 1. - f2;
	g10 = f1 * 30805. + f2 * 30715.;
	g11 = f1 * -2316. - f2 * 2306.;
	h11 = f1 * 5808. + f2 * 5812.;
    } else if (c1_2.iy < 1940) {
/* 1935-1940 */
	f2 = ((doublereal) c1_2.iy + (doublereal) (*iday) / 365. - 1935.) / 
		5.;
	f1 = 1. - f2;
	g10 = f1 * 30715. + f2 * 30654.;
	g11 = f1 * -2306. - f2 * 2292.;
	h11 = f1 * 5812. + f2 * 5821.;
    } else if (c1_2.iy < 1945) {
/* 1940-1945 */
	f2 = ((doublereal) c1_2.iy + (doublereal) (*iday) / 365. - 1940.) / 
		5.;
	f1 = 1. - f2;
	g10 = f1 * 30654. + f2 * 30594.;
	g11 = f1 * -2292. - f2 * 2285.;
	h11 = f1 * 5821. + f2 * 5810.;
    } else if (c1_2.iy < 1950) {
/* 1945-1950 */
	f2 = ((doublereal) c1_2.iy + (doublereal) (*iday) / 365. - 1945.) / 
		5.;
	f1 = 1. - f2;
	g10 = f1 * 30594. + f2 * 30554.;
	g11 = f1 * -2285. - f2 * 2250.;
	h11 = f1 * 5810. + f2 * 5815.;
    } else if (c1_2.iy < 1955) {
/* 1950-1955 */
	f2 = ((doublereal) c1_2.iy + (doublereal) (*iday) / 365. - 1950.) / 
		5.;
	f1 = 1. - f2;
	g10 = f1 * 30554. + f2 * 30500.;
	g11 = f1 * -2250. - f2 * 2215.;
	h11 = f1 * 5815. + f2 * 5820.;
    } else if (c1_2.iy < 1960) {
/* 1955-1960 */
	f2 = ((doublereal) c1_2.iy + (doublereal) (*iday) / 365. - 1955.) / 
		5.;
	f1 = 1. - f2;
	g10 = f1 * 30500. + f2 * 30421.;
	g11 = f1 * -2215. - f2 * 2169.;
	h11 = f1 * 5820. + f2 * 5791.;
    } else if (c1_2.iy < 1965) {
/* 1960-1965 */
	f2 = ((doublereal) c1_2.iy + (doublereal) (*iday) / 365. - 1960.) / 
		5.;
	f1 = 1. - f2;
	g10 = f1 * 30421. + f2 * 30334.;
	g11 = f1 * -2169. - f2 * 2119.;
	h11 = f1 * 5791. + f2 * 5776.;
    } else if (c1_2.iy < 1970) {
/* 1965-1970 */
	f2 = ((doublereal) c1_2.iy + (doublereal) (*iday) / 365. - 1965.) / 
		5.;
	f1 = 1. - f2;
	g10 = f1 * 30334. + f2 * 30220.;
	g11 = f1 * -2119. - f2 * 2068.;
	h11 = f1 * 5776. + f2 * 5737.;
    } else if (c1_2.iy < 1975) {
/* 1970-1975 */
	f2 = ((doublereal) c1_2.iy + (doublereal) (*iday) / 365. - 1970.) / 
		5.;
	f1 = 1. - f2;
	g10 = f1 * 30220. + f2 * 30100.;
	g11 = f1 * -2068. - f2 * 2013.;
	h11 = f1 * 5737. + f2 * 5675.;
    } else if (c1_2.iy < 1980) {
/* 1975-1980 */
	f2 = ((doublereal) c1_2.iy + (doublereal) (*iday) / 365. - 1975.) / 
		5.;
	f1 = 1. - f2;
	g10 = f1 * 30100. + f2 * 29992.;
	g11 = f1 * -2013. - f2 * 1956.;
	h11 = f1 * 5675. + f2 * 5604.;
    } else if (c1_2.iy < 1985) {
/* 1980-1985 */
	f2 = ((doublereal) c1_2.iy + (doublereal) (*iday) / 365. - 1980.) / 
		5.;
	f1 = 1. - f2;
	g10 = f1 * 29992. + f2 * 29873.;
	g11 = f1 * -1956. - f2 * 1905.;
	h11 = f1 * 5604. + f2 * 5500.;
    } else if (c1_2.iy < 1990) {
/* 1985-1990 */
	f2 = ((doublereal) c1_2.iy + (doublereal) (*iday) / 365. - 1985.) / 
		5.;
	f1 = 1. - f2;
	g10 = f1 * 29873. + f2 * 29775.;
	g11 = f1 * -1905. - f2 * 1848.;
	h11 = f1 * 5500. + f2 * 5406.;
    } else if (c1_2.iy < 1995) {
/* 1990-1995 */
	f2 = ((doublereal) c1_2.iy + (doublereal) (*iday) / 365. - 1990.) / 
		5.;
	f1 = 1. - f2;
	g10 = f1 * 29775. + f2 * 29692.;
	g11 = f1 * -1848. - f2 * 1784.;
	h11 = f1 * 5406. + f2 * 5306.;
    } else if (c1_2.iy < 2000) {
/* 1995-2000 */
	f2 = ((doublereal) c1_2.iy + (doublereal) (*iday) / 365. - 1995.) / 
		5.;
	f1 = 1. - f2;
	g10 = f1 * 29692. + f2 * 29619.4;
	g11 = f1 * -1784. - f2 * 1728.2;
	h11 = f1 * 5306. + f2 * 5186.1;
    } else if (c1_2.iy < 2005) {
/* 2000-2005 */
	f2 = ((doublereal) c1_2.iy + (doublereal) (*iday) / 365. - 2e3) / 5.;
	f1 = 1. - f2;
	g10 = f1 * 29619.4 + f2 * 29556.8;
	g11 = f1 * -1728.2 - f2 * 1671.8;
	h11 = f1 * 5186.1 + f2 * 5080.;
    } else {
/* 2005-2010 */
	dt = (doublereal) c1_2.iy + (doublereal) (*iday) / 365. - 2005.;
	g10 = 29556.8 - dt * 8.8;
	g11 = dt * 10.8 - 1671.8;
	h11 = 5080. - dt * 21.3;
    }
/*  NOW CALCULATE THE COMPONENTS OF THE UNIT VECTOR EzMAG IN GEO COORD */
/*  SYSTEM: */
/*  SIN(TETA0)*COS(LAMBDA0), SIN(TETA0)*SIN(LAMBDA0), AND COS(TETA0) */
/*         ST0 * CL0                ST0 * SL0                CT0 */
/* Computing 2nd power */
    d__1 = g11;
/* Computing 2nd power */
    d__2 = h11;
    sq = d__1 * d__1 + d__2 * d__2;
    sqq = sqrt(sq);
/* Computing 2nd power */
    d__1 = g10;
    sqr = sqrt(d__1 * d__1 + sq);
    c1_2.sl0 = -h11 / sqq;
    c1_2.cl0 = -g11 / sqq;
    c1_2.st0 = sqq / sqr;
    c1_2.ct0 = g10 / sqr;
    c1_2.stcl = c1_2.st0 * c1_2.cl0;
    c1_2.stsl = c1_2.st0 * c1_2.sl0;
    c1_2.ctsl = c1_2.ct0 * c1_2.sl0;
    c1_2.ctcl = c1_2.ct0 * c1_2.cl0;
/*  THE CALCULATIONS ARE TERMINATED IF ONLY GEO-MAG TRANSFORMATION */
/*  IS TO BE DONE  (IHOUR>24 IS THE AGREED CONDITION FOR THIS CASE): */
/*   5  IF (IHOUR.GT.24) RETURN */
    return 0;
} /* recalc_ */

#ifdef __cplusplus
	}
#endif

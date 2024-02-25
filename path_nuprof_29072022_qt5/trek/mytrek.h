#ifndef _MYTREK_H_
#define _MYTREK_H_

#include <math.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include "../splayn/spcub.h"
#include "../iri_3d/iri_3d_new.h"

#ifndef __PI
#define __PI
const double PI=3.14159265358979312;
#endif

#ifndef __PI2
#define __PI2
const double PI2=6.28318530717958624;
#endif
#ifndef __PI05
#define __PI05
const double PI05=1.57079632679489656;
#endif
#ifndef __RAD
#define __RAD
const double RAD=1.745329251994329548e-2;
#endif
#ifndef __R0
#define __R0
const double R0=63.70;
#endif
#ifndef __H0
#define __H0
const double H0=.6;
#endif
const double DB=868.588;
const double C=.2997925;
const double HM=5.;
const double STEP=.025;
const int maxKolOtr=5;
const int MaxPointTr=50000;

extern SPCUB *spN_H;

#define SIGN(x,y) ((y>0)? fabs(x) : -fabs(x))

#ifndef _PUTDAT_
#define _PUTDAT_

struct PUTDAT
      {
        int    iox;  /* РХО МНПЛЮКЭМНИ БНКМШ 0 - "Н", 1 - "У" */
        double fr;   /* ПЮАНВЮЪ ВЮЯРНРЮ,лцЖ                   */
        double time; /* ЛЦМНБЕММНЕ БПЕЛЪ Б ЛХМ                */
        double d1;   /* СЦНК ХГКСВЕМХЪ Я ОНБЕПУМНЯРХ гЕЛКХ    */
        double d2;   /* СЦНК ОПХУНДЮ КСВЮ МЮ гЕЛКЧ            */
        double x;    /* У - ЙННПДХМЮРЮ ОПХУНДЮ КСВЮ МЮ гЕЛКЧ  */
        double y;    /* С - ЙННПДХМЮРЮ ОПХУНДЮ КСВЮ МЮ гЕЛКЧ  */
        double s;    /* ОПНРЪФЕММНЯРЭ РПЮЯЯШ,ЙЛ               */
        double at;   /* ЦЕНЦПЮТХВЕЯЙХИ ЮГХЛСР РПЮЯЯШ          */
        double dev;  /* ДЕБХЮЖХЪ ОЕКЕМЦЮ Б РНВЙЕ ХГКСВЕМХЪ    */
        double a1;   /* azimuth izlucheniy                    */
        double a2;   /* azimuth priema                        */
        double p;    /* ЦПСООНБНИ ОСРЭ,ЙЛ                     */
        double df;   /* ДНОКЕПНБЯЙНЕ ЯЛЕЫЕМХЕ ВЮЯРНРШ,цЖ      */
        double l;    /* ХНМНЯТЕПМНЕ ОНЦКНЫЕМХЛЕ               */
        double xotr; /* ОПНЯРПЮМЯРБЕММШЕ ЙННПДХМЮРШ РНВЙХ     */
        double yotr; /* НРПЮФЕМХЪ                             */
        double zotr; /*                                       */
        double ls;   /* ОПНЯРПЮМЯРБЕММНЕ НЯКЮАКЕМХЕ,Да        */
        double pg;   /* ТЮГНБШИ ОСРЭ,ЙЛ                       */
        double ps;   /* ДКХМЮ РПЮЕЙРНПХХ,ЙЛ                   */
        double FHhop1;
        double FHhop2;
        double Ihop1;
        double Ihop2;
        double Dhop1;
        double Dhop2;
        double dhop1;
        double dhop2;   
        double ref;     
        unsigned long moda;

        PUTDAT()
        {
                iox=0;
                fr=.0;
                time=.0;
                d1=d2=-1.; // ОПХГМЮЙ МЕПЮЯЯВХРЮММШУ ДЮММШУ
                a1=a2=-1.;
                x=y=s=.0;
                at=dev=.0;
                p=pg=ps=.0;
                df=.0;
                l=ls=.0;
                xotr=yotr=zotr=.0;
                ref=dhop1=dhop2=.0;
                FHhop1=FHhop2=Ihop1=Ihop2=Dhop1=Dhop2=.0;
                moda=0;
        };

        bool operator < (PUTDAT const &other) const
        {
            return d1 < other.d1;
        };
      };

#define IOX(i)      ((putdat+(i))->iox)
#define FR(i)       ((putdat+(i))->fr)
#define TIME(i)     ((putdat+(i))->time)
#define D1(i)       ((putdat+(i))->d1)
#define D2(i)       ((putdat+(i))->d2)
#define A1(i)       ((putdat+(i))->a1)
#define A2(i)       ((putdat+(i))->a2)
#define X(i)        ((putdat+(i))->x)
#define Y(i)        ((putdat+(i))->y)
#define S(i)        ((putdat+(i))->s)
#define AT(i)       ((putdat+(i))->at)
#define DEV(i)      ((putdat+(i))->dev)
#define DF(i)       ((putdat+(i))->df)
#define L(i)        ((putdat+(i))->l)
#define XOTR(i)     ((putdat+(i))->xotr)
#define YOTR(i)     ((putdat+(i))->yotr)
#define ZOTR(i)     ((putdat+(i))->zotr)
#define LS(i)       ((putdat+(i))->ls)
#define PG(i)       ((putdat+(i))->pg)
#define PS(i)       ((putdat+(i))->ps)
#define P(i)        ((putdat+(i))->p)
#define Moda(i)     ((putdat+(i))->moda)
#define d_hop1(i)   ((putdat+(i))->dhop1)
#define d_hop2(i)   ((putdat+(i))->dhop2)
#define D_hop1(i)   ((putdat+(i))->Dhop1)
#define D_hop2(i)   ((putdat+(i))->Dhop2)
#define I_hop1(i)   ((putdat+(i))->Ihop1)
#define I_hop2(i)   ((putdat+(i))->Ihop2)
#define FH_hop1(i)  ((putdat+(i))->FHhop1)
#define FH_hop2(i)  ((putdat+(i))->FHhop2)
#define Ref(i)      ((putdat+(i))->ref)


#endif

class MyTrek
{
public:

    MyTrek(double f, double Fh, double H[3], double Dh[3][3], double Dh2[3][3][3], double Delt, double Eps, double Ep, double Ep1);
    MyTrek(double Delt, double Eps, double Ep, double Ep1);
    ~MyTrek();
    
    void copy_iri_model();

    int  treks(double f,
               double t,
               double d0,
               double alfa,
               int    ihop,
               int    n,
               PUTDAT *putdat);

    int  treks(double f,
               double d0,
               double alfa,
               int    ihop,
               int    n,
               PUTDAT *putdat);

    int  treks(double d0,
               double alfa,
               int    ihop,
               int    n,
               PUTDAT *putdat);

    int ionos(double f, double t, double r, int    n);

    void setDelt(double d){delt=d;};
    void setEps(double Eps){eps=Eps; e=e*eps;};
    void setEp(double e){ep=e;};
    void setEp1(double e){ep1=e;};
    double getDelt(){return delt;};
    double getEps(){return eps;};
    double getEp(){return ep;};
    double getEp1(){return ep1;};
    double getE(){return e;};
    void setFr(double f){fr=f; fr=f*f; u1=fh/fr; u=u1*u1;};
    double getFr(){return fr;};
    void setFh(double f, double H[3], double Dh[3][3], double Dh2[3][3][3])
    {
        fh=f;
        for(int i=0; i<3; i++)
        {
            h[i]=H[i];
            for(int j=0; j<3; j++)
            {
                dh[i][j]=Dh[i][j];
                for(int k=0; k<3; k++)
                    dh2[i][j][k]=Dh2[i][j][k];
            }
        }
    };
    double getFh(){return fh;};
    int getPointTr(){return pointTr;};
    double *getSTr(){return sTr;};
    double *getHTr(){return hTr;};
    void setTime(double t){tim=t;};
    double getTime(){return tim;};
    double &getV(){return v;};
    double &getPar(){return par;};
    double *getFpl(){return fpl;};
    double *getHpl(){return hpl;};
    /*
    double getHmF2(){return HmF2;};
    double getHmF1(){return HmF1;};
    double getHmE(){return HmE;};
    double getHmD(){return HmD;};
    double getHmEs(){return HmEs;};
    double getF0F2(){return F0F2;};
    double getF0F1(){return F0F1;};
    double getF0E(){return F0E;};
    double getF0D(){return F0D;};
    double getF0Es(){return F0Es;};
    double getFbEs(){return FbEs;};
    double getPEs(){return PEs;};
    double getHi(){return Hi;};
    double getFhTemp(){return fhTemp;};
    double getDTemp(){return DTemp;};
    double getITemp(){return ITemp;};
    */

private:

    IRI_3D *iri_3dbase;
    IRI_3D *iri_3dbase2;

    void coords(double aksf[3], double akglob[3],
            double aksfa[3], double akga[3],
            double aksfd[3], double akgd[3],
            double y8, double y14, double y9, double y15,
            int i, int key);

    int coors(double z[3], double akglob[3], double xa[3], double xd[3],
          double akga[3], double akgd[3],
          double r1, double r2, double sig,
          double *p, double *f, double *t,
          int    key);

    int soluts(double *x, double *y,
           int    n,
           double delt, double eps, double ep,
           double ep1,  double e);

    int func(double x, double *y, double *f, int    n);

    void ltv(double *x, double *y0, double *y1, double *f0, double *f1, double *h, int n, double e, double eps);
    void ltv(double *x, double *y0, double *f0, double *y1, double *f1, double *h, int n, double e, double eps, int n1, int n2, double *r);

    void ltv_i(double *x,
                       double *y00,
                       double *f00,
                       double *yp10,
                       double *fp10,
                       double *h,
                       int     n,
                       double e,
                       double eps,
                       int     n1,
                       int     n2,
                       int     *ini,
                       double *r);

    double dist(double fi0, double teta0, double fi1, double teta1);

    int ionosf(double fi,     // сферические координаты расположения луча
               double teta,   //
               double r,      //
               double &v,     // нормированный квадрат плазменной частоты
               double &vfi,   // его производные по fi, tets, r
               double &vteta, //
               double &vr, IonPar &p);   //
    int ionosf(double fi,     // сферические координаты расположения луча
               double teta,   //
               double r,      //
               double time,
               double &v,     // нормированный квадрат плазменной частоты
               double &vfi,   // его производные по fi, tets, r
               double &vteta, //
               double &vr,    //
               double &vt, IonPar &p);   //
    int ionosf(double fi,     // сферические координаты расположения луча
               double teta,   //
               double r,      //
               double &v,     // нормированный квадрат плазменной частоты
               double &vfi,   // его производные по fi, tets, r
               double &vteta, //
               double &vr,
               double &vff,
               double &vtt,
               double &vrr,
               double &vft,
               double &vfr,
               double &vtr, IonPar &p);    //
    int ionosf(double fi,     // сферические координаты расположения луча
               double teta,   //
               double r,      //
               double time,   // время с секундах, отсчитанное от момента основного профиля
               double &v,     // нормированный квадрат плазменной частоты
               double &vfi,   // его производные по fi, tets, r
               double &vteta, //
               double &vr,
               double &vt,    // производная v по времени
               double &vff,
               double &vtt,
               double &vrr,
               double &vft,
               double &vfr,
               double &vtr, IonPar &p);   //

    int nuprof(double fi,
                double teta,
                double r,
                double &n);
    int nuprof(double fi,
                double teta,
                double r,
                double time,
                double &n);
    


    double v,vp[3],vpp[3][3],dvt,s,par,
           dmrtf[3],dmv,ov,sa2,ak,anorm,
           fh,h[3],dh[3][3],dh2[3][3][3],
           fot,tot,rot,
           fpl[100],hpl[100],
           fr,fr2,
           tim,
           u,u1,
           amy,amy0,dmca0,
           sf,cf,st,ct;
    double delt, eps, ep, ep1, e;
    double sTr[MaxPointTr],hTr[MaxPointTr];
    int pointTr;

};


extern MyTrek *mytrek_ext;// тот класс создается, в основном, для вычисления и отображеия профиля электронной концентрации

#endif

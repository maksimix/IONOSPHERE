/***************************************************************/
/***************************************************************/
/*                                                             */
/* Головная функция, организующая постороение лучевой траекто- */
/* рии в сферически слоистой горизотнально-неоднородной        */
/* магнитоактивной ионосфере.                                  */
/*                                                             */
/*VGG                                                          */
/***************************************************************/
using namespace std;
#include <iostream>
#include <iomanip>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <sys/timeb.h>
#include "paths.h"
#include "mysolt.h"
#include "../antenn_omp/antenn.h"


#define STR50 "\n+======================================+\n"
#define STR51 "|Initial step:%6.3f                   |\n"
#define STR52 "|Local accuracy:%10.7f             |\n"
//#define STR53 "|Node number:%2d                        |\n"
#define STR54 "|Range accuracy:%8.4f               |\n"
#define STR55 "|Range limits:%8.2f                 |\n"
#define STR56 "|Elevation angle step:%5.2f            |\n"
#define STR59 "|Azimuth   angle step:%5.2f            |\n"
//#define STR57 "|Number of integration subdivisions:%2d |\n"
#define STR58 "+======================================+\n"

#define STR10 "+===========================+"
#define STR11 "|  Effects of polarization  |"
#define STR12 "|---------------------------|"
#define STR13 "|  Lp  |  Lr  |  Ku  |  Knd |"
#define STR14 "|------+------+------+------|"
#define STR15 "|%6.2lf|%6.2lf|%6.2lf|%6.2lf|"
#define STR16 "+===========================+"

#define STR60 "\n+====================================================================+\n"
#define STR61 "|  Maximum Usable Frequency          GMT time:%02d:%02d:%02d.%02d            |\n"
#define STR62 "|--------------------------------------------------------------------|\n"
#define STR63 "|  MUFo:%6.2f  |  MUFx:%6.2f  | Moda:%s      |\n"
#define STR64 "|---------------+---------------+------------------------------------|\n"
#define STR65 "+====================================================================+\n"
#define STR66 "| FminEs:%6.2f | FmaxEs:%6.2f | Hop:%2d                         |\n"

#define STR20 "\n+=========================================+\n"
#define STR21 "| Path characteristics     GMT time:%02d:%02d |\n"
#define STR22 "|-----------------------------------------|\n"
#define STR23 "|  f  |   E   | E/Nois |  E_Es  |E_Es/Nois|\n"
#define STR24 "|-----+-------+--------+--------+---------|\n"
#define STR25 "|%5.2f|%7.2f|%8.2f|%8.2f|%8.2f |\n"
#define STR26 "+=========================================+\n"
#define STR27 "|%5.2f|       |        |%8.2f|%8.2f |\n"
#define STR28 "|%5.2f|       |        |        |         |\n"

#define STR30 "+===============+"
#define STR31 "|  Polarization |"
#define STR32 "|---------------|"
#define STR33 "|  a/b |   psi  |"
#define STR34 "|------+--------|"
#define STR35 "|%6.3f|%8.3f|"
#define STR36 "+===============+"

#define STR40 "\n+====================================================\
==============+\n"
#define STR41 "|    Transmitter   |     Reciever     | Path length |\
 Path azimuth |\n"
#define STR42 "|==================+==================|%10.2f   |\
%11.3f   |\n"
#define STR43 "|Longitude:%8.3f|Longitude:%8.3f|-------------+\
--------------|\n"
#define STR44 "|Latitude :%8.3f|Latitude :%8.3f| Month:%5.1f |\
   W     IG   |\n"
#define STR444 "|Latitude :%8.3f|Latitude :%8.3f| Month:%5.1f |\
      Year    |\n"
#define STR4444 "|Latitude :%8.3f|Latitude :%8.3f| Month:%5.1f |\
  F10.7  IG   |\n"
#define STR45 "|Power    :%8.1e|Passband :%8.3f|  %s  | %5.1f  %5.1f |\n"
#define STR47 "|Power    :%8.1e|Passband :%8.3f|  %s  |%10d    |\n"
#define STR46   "+====================================================\
==============+\n"

#define STR0 "\n+======================================================\
===========================================+"
#define STR2 "|------------------------------------------------------\
-------------------------------------------|"
#define STR1 "|            Ray characteristics                       GMT time:\
%02d:%02d:%02d.%02d                       |"
#define STR4 "|------+-+------+------+------+-------+-------+------+\
------+------+-----+------------------------|"
#define STR6 "+====================================================\
=============================================+"
#define STR3 "|  F   | |  d1  |  d2  |  T   |   Df  |  DEV  |  L   |\
  Ls  |  E   | Les |          Moda          |"
#define STR5 "|%6.3lf|%c|%6.2lf|%6.2lf|%6.3lf|%7.3lf|%7.3lf|\
%6.1lf|%6.1lf|%6.1lf|%5.1lf|%s|"

//#define STR80 "\n   t       f      E      E/Nois    s0"
#define STR81 "\n %6.3f %6.3f %7.2f %7.2f %7.2f %7.2f %7.2f %8.2f %8.2f %s"
#define STREPS "\ndelt0=%8.1lg  eps=%8.1lg  ep=%8.1lg  ep1=%8.1lg"

/*==============================================================*/

int main(int argc, char *argv[])
{
 double  s0,alf,alf1,s1,lon0,lat0,lon1,lat1,dlon,
         w,W,ig,IG,ames,ptr,b,
         t,t1,t2,t3,time,tmre,dt,
         time1,time2,dtime,
         Fam,Du,Dl,Vd,SFam,Sdu,Sdl,Svd,
         emp,epom,epom_i,sig_i;
  double alfa,d0,delt0,eps,ep,ep1; /////////////////////////
  double e=.0625;
  int    n,io,ix,ih,ihm,kolf;
  int    i,j,id;
  const  double l10=.1*log(10.);
  double *f =NULL,
         *fb=NULL,
         lp[10],lr[10],ku[10],knd[10],
         l[10],ls[10],pgr[10],pgg[10],dopf[10],di[10],dk[10],
         *e_r =NULL,
         *e_es=NULL,
         *epm =NULL,
         mm[10],psi[10],
         l_es[10]={.0,.0,.0,.0,.0,.0,.0,.0,.0,.0},
         fBeg,fEnd,dF; // начальная, конечная и шаг по частоте
  double fmpch=.0,
         fmpcho=.0,
         fmpchx=.0,
         fmp[6],fm_es[6],f_es[6],fmpch_es;
  double sinE,cosE;
  double *d_b=NULL,
         *d_e=NULL,
         dbeg,dend,dbegMUF,dendMUF;
  long   nfr,ox1,ox2,mes,hop1,hop2,ifr,
         ikor,ik,ir;
  long   it1,it2,it3,hou1,hou2,hou3,min1,min2,min3,
         sek1,sek2,sek3;
  char   *month[12]={" January "," February","  March  ","  April  ",
                     "    May  ","   June  ","   July  ","  August ",
                     "September"," October "," November"," December"};
  char   mod[25];
  char   inform[80];
  char   tempS[256];
  FILE   *in,*out, *tempFile;
  MySolt *mySolt=0;
  timeval tv;
  double T1,T2,DT;
  COR  *cor;
  INFR infr;
  ANT_TRAN  a1;
  ANT_REC   a2;
  const char otho[]=
  {"\npaths 5.0     Copyright(c) Vertogradov G.G. 14.07.2016\
  \n            tel (863)2359516, vertogradovgg@gmail.com vgg@bmail.ru\
  \n                      Rostov-on-Don, Russia\
  \n                     Rostov State University\
  \n                     RadioPhysics Departament\
  \n                        SIGNAL laboratory\
  \n                         \n"};
  PUTDAT *putdat;
  double eps1,epsa;
  double eps2;
  double rmax;
  double dd0,aa0;
  double d1;
  int    keyMod,keyvod,keypri,keypr,keyh,keynois,
         keymp,keyini,keypol,keyel,keyFr,keyOut;
  long   hou,min,sek,msek;
  int    iyear;
/*--------------------------------------------------------------*/
  printf("%s",otho);
  fflush(stdout);

  if ((argc>1 || argc>2) && strcmp(*(argv+1),"con")!=0
                                && strcmp(*(argv+1),"CON")!=0)
    in=fopen(*(argv+1),"rt");
  else
    in=stdin;

  keyEs=0;

  if (!in)
    {
      printf("\nInput File:%s error open\n",*(argv+1));
      exit(EXIT_FAILURE);
    }

  fscanf(in,"%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
         &keyvod,&keynu,&keyMod,&keyl2,&keyEs,&keynois,&keyugl,
         &keypri,&keypr,&keyh,&keymp,&keytr,&keysol,&keympr,&keyini);

  printf("\nkeypri=%d keyini=%d",keypri,keyini);
  printf("\n000 keytr=%d",keytr);

  if (abs(keypri)>1 && (keytr<0 || keysol<0 || keympr<0))
    keytr=keysol=keympr=0;

  if (keytr<0) keysol=keympr=0;

  if ((argc>2 || argc>3) && strcmp(*(argv+2),"con")!=0
                         && strcmp(*(argv+2),"CON")!=0)
    {
      out=fopen(*(argv+2),"at");
      keyOut=1;
    }
  else
    {
      keyOut=0;
      if (keysol<0 || keytr<0 || keympr<0)
        out=fopen("rayr_pri.dat","wt");
      else
        out=stdout;
    }

  if (!out)
    {
      printf("\nOutput File:%s error open\n",*(argv+2));
      exit(EXIT_FAILURE);
    }

  if (argc<4 || argc<3) keyini=-1;
                         /* если во входной строке не указано */
                         /* имя файла для сохранения парамет- */
                         /* ров модели ДАСФ, то эти параметры */
                         /* не сохраняются                    */
  if (argc>3 && keyini==-1) /* открываем файл для сохранения МПЧ слоев по скачкам */
  {
      tempFile=fopen(*(argv+3),"at");
      //fprintf(tempFile,STR80);
  }
  else
      tempFile=0;

  fscanf(in,"%lg%lg%lg%lg%lg%lg%lg%lg%lg%lg",&delt0,&eps,&ep,&ep1,&eps1,&eps2,&epsa,&dd0,&aa0,&rmax);
  fprintf(out,STREPS,delt0,eps,ep,ep1);

  RMax=rmax;
  e=e*eps;
  eps1*=.01;
  eps2*=.01;
  rmax*=.01;
  dd0*=RAD;
  epsa*=RAD;
  aa0*=RAD;

  fscanf(in,"%lg%lg%lg%lg%lg%lg%d%lg%lg%lg%lg%lg",
         &lon0,&lat0,&z0,&lon1,&lat1,&z1,&iyear,&ames,&w,&ig,&ptr,&b);


  if (z1<.0)
  {
      double sao=sin(lat0*RAD);
      double cao=cos(lat0*RAD);
      s0=lon1;
      alf=lat1;
      z1=.0;
      double slf=sin(alf*RAD);
      double clf=cos(alf*RAD);
      double ss=sin(.01*s0/R0);
      double cs=cos(.01*s0/R0);
      lon1=atan2(slf*ss,(cs*cao-clf*ss*sao))+lon0*RAD; // долготы
      double cdlon=cos(lon1-lon0*RAD);
      lat1=PI05-atan2((cs*cao-clf*ss*sao),          // широты
                         (cdlon*(cs*sao+clf*ss*cao)));
      if (cdlon<.0)
          lat1-=PI;
      lat1/=RAD;
      lon1/=RAD;
  }


  infr.trassa.lon0 =lon0;
  infr.trassa.lat0 =lat0;
  infr.trassa.lon1 =lon1;
  infr.trassa.lat1 =lat1;
  infr.trassa.month=ames; //
  infr.trassa.w    =w;    // число солнечных пятен (0...1000), поток 10.7 (отрицателен) или год (1900...)
  infr.trassa.P    =ptr;
  infr.trassa.band =b;
  mes=ames;

  teta0=90.-lat0;
  fi0=lon0;
  
  fprintf(out,"\nИСХОДНАЯ ТОЧКА: fi0=%8.3f  teta0=%8.3f  year=%d",fi0,teta0,iyear);

  lon0 *=RAD;  lat0 *=RAD;
  lon1 *=RAD;  lat1 *=RAD;
  dlon=lon1-lon0;
  z0=z0*.01+R0;
  z1=z1*.01+R0;
  printf("\nz0=%f  z1=%f",z0,z1);

  s0=sin(lat0)*sin(lat1)+cos(lat0)*cos(lat1)*cos(dlon);
  s0=R0*atan2(sqrt(1.-s0*s0),s0);
  alf =atan2(cos(lat1)*sin(dlon),sin(lat1)*cos(lat0)-
             sin(lat0)*cos(lat1)*cos(dlon));
  alf1=atan2(-cos(lat0)*sin(dlon),sin(lat0)*cos(lat1)-
             sin(lat1)*cos(lat0)*cos(dlon));

  printf("\n S0=%7.1f  Alf0=%8.3f  Alf1=%8.3f",s0*100.,alf/RAD,alf1/RAD);

  fi0   *=RAD;
  teta0 *=RAD;

  if (eps2<.0 && s0>2.5 || eps2<-2.5 && s0<2.5)
    if (s0>5.)   eps2=.2*s0;
    else
      if (s0<2.5) eps2=-2.5;
      else        eps2=.0;
  if (keyugl<=0)
  {
    if (s0>25.)  dend=.25*PI;
    else
      if (s0>2.5)  dend=.50*PI;
      else         dend=.5*PI;  //dend=.75*PI;
    dendMUF=dend;
  }

  infr.trassa.s0  =s0*100.;
  infr.trassa.alf0=alf/RAD;
  infr.trassa.alf1=alf1/RAD;

  sMinIon=-20.;
  sMaxIon=2000.;
  alfIon=.0;

  fscanf(in,"%lg%lg%lg",&sMinIon,&sMaxIon,&alfIon);

  fprintf(out,STR40);
  fprintf(out,STR41);
  fprintf(out,STR42,s0*100.,alf/RAD);
  fprintf(out,STR43,lon0/RAD,lon1/RAD);
  if (w>.0 && w<1000.)
      fprintf(out,STR44,lat0/RAD,lat1/RAD,ames);
  else
  {
      if (w==.0 && ig==.0)
          fprintf(out,STR444,lat0/RAD,lat1/RAD,ames);
      else
          fprintf(out,STR4444,lat0/RAD,lat1/RAD,ames);
  }
  if (w==.0)
      fprintf(out,STR47,ptr,b,*(month+mes-1),iyear);
  else
      fprintf(out,STR45,ptr,b,*(month+mes-1),fabs(w),ig);
  fprintf(out,STR46);
  //cout<<flush;
  fflush(out);

  fprintf(out,STR50);
  fprintf(out,STR51,delt0);
  fprintf(out,STR52,eps);
  //fprintf(out,STR53,n_uz);
  fprintf(out,STR54,eps1*100.);
  fprintf(out,STR55,eps2*100.);
  fprintf(out,STR56,dd0/RAD);
  fprintf(out,STR59,aa0/RAD);
  //fprintf(out,STR57,icc);
  fprintf(out,STR58);
  //cout<<flush;
  fflush(out);

  get_ant(in,out,&a1,&a2);

  keypol=a1.type && a2.type && out!=stdout && keypr;
  keyel =!a1.type && !a2.type && out!=stdout && keypr;
  infr.trassa.typeAntT=a1.type;
  infr.trassa.typeAntR=a2.type;

  fscanf(in,"%ld%ld%ld",&it1,&it2,&it3);

  hou1=it1/10000l;
  hou2=it2/10000l;
  hou3=it3/10000l;
  min1=(it1-hou1*10000l)/100l;
  min2=(it2-hou2*10000l)/100l;
  min3=(it3-hou3*10000l)/100l;
  sek1=it1-hou1*10000l-min1*100l;
  sek2=it2-hou2*10000l-min2*100l;
  sek3=it3-hou3*10000l-min3*100l;
  t1=hou1*3600.+min1*60.+sek1;
  t2=hou2*3600.+min2*60.+sek2;
  t3=hou3*3600.+min3*60.+sek3;
  dt=t3;
  if (t1>t2)
    t1-=86400.; // теперь полночь содержится внутри интервала моделирования

  fscanf(in,"%d%ld%ld%ld%ld",&keyFr,&hop1,&hop2,&ox1,&ox2);
  // nfr -1 - частоты задаются интервалом и шагом
  //      0 - частоты не задаются
  //     >0 - список частот
  if (keyFr<0)
    {
      fscanf(in,"%lg%lg%lg",&fBeg,&fEnd,&dF);
      nfr=(long)((fEnd-fBeg)/dF+1.05);
    }
  else
    nfr=keyFr;

  if (nfr>0)
    {
      fb  =new double[nfr];
      f   =new double[nfr];
      e_r =new double[nfr];
      e_es=new double[nfr];
      epm =new double[nfr];
      for(i=0; i<nfr; i++)
        if (keyFr>0)
          {
            fscanf(in,"%lg",(fb+i));
            if (*(fb+i)<1. && !keymp)
              keymp=1;
            *(f+i)=*(fb+i);
          }
        else
          *(f+i)=*(fb+i)=fBeg+dF*i;
    }
  else
    keyini=-1; // если частот нет, то и нечего запоминать в ДАСФ-файле

  infr.kfr=nfr;
  infr.kzap=0;
  infr.fr=fb;

  if (hop1==0)   hop1=1;
  if (hop1>hop2) hop2=hop1;

  if (nfr>0)
    {
      d_b=new double[nfr*hop2*2];
      d_e=new double[nfr*hop2*2];
    }
  else
    {
      d_b=new double[hop2*2];
      d_e=new double[hop2*2];
    }

  if (keyugl>0)
   {
      for(i=hop1-1; i<hop2; i++)
        {

          fscanf(in,"%lg%lg",&dbeg,&dend);
          dbeg *=RAD;
          dend *=RAD;
          dbegMUF=dbeg;
          dendMUF=dend;

          if (nfr>0)
            for(ifr=0; ifr<nfr || !ifr; ifr++)
              {
                *(d_b+2*(hop2*ifr+i))=*(d_b+2*(hop2*ifr+i)+1)=dbeg;
                *(d_e+2*(hop2*ifr+i))=*(d_e+2*(hop2*ifr+i)+1)=dend;
              }
          else
            {
                *(d_b+2*i)=*(d_b+2*i+1)=dbeg;
                *(d_e+2*i)=*(d_e+2*i+1)=dend;
            }
        }
   }

  fscanf(in,"%ld%ld%ld",&it1,&it2,&it3);

  hou1=it1/10000l;
  hou2=it2/10000l;
  hou3=it3/10000l;
  min1=(it1-hou1*10000l)/100l;
  min2=(it2-hou2*10000l)/100l;
  min3=(it3-hou3*10000l)/100l;
  sek1=it1-hou1*10000l-min1*100l;
  sek2=it2-hou2*10000l-min2*100l;
  sek3=it3-hou3*10000l-min3*100l;
  time1=hou1*3600.+min1*60.+sek1;
  time2=hou2*3600.+min2*60.+sek2;
  dtime=hou3*3600.+min3*60.+sek3;
  if (time1>time2)
    time1-=86400.; // теперь полночь содержится внутри интервала моделирования
  if (t1<time1 || t2>time2)
  {
      fprintf(out,"Не веpно заданы вpеменные интевалы моделирования\n");
      exit(EXIT_FAILURE);
  }
  //cout<<endl<<"it1="<<it1<<" it2="<<it2<<" it3="<<it3<<" time1="<<time1<<" time2="<<time2<<" dtime="<<dtime;
  infr.timeb=t1;
  infr.timek=t1;
  infr.trassa.tBeg =time1;
  infr.trassa.tEnd =time2;
  infr.trassa.tStep=dtime;
  infr.popo=.0;
  infr.popx=.0;

  mytrek_ext=new MyTrek(delt0,eps,ep,ep1);

  infils(in,out);

  cout<<endl<<"011111111111111"<<flush;

  W=w;
  IG=ig;
  inions(in,out,iyear,ames,W,IG,rmax,keyvod,keyMod,keyEs,time1,time2,dtime,infr);

  cout<<endl<<"111111111111111"<<flush;
   if (keyugl<=0)
   {
       for(i=hop1-1; i<hop2; i++)
         {

           double h0=H0+R0;
           double s1=s0/(2.*(i+1)*R0);
           dbeg=atan((h0*cos(s1)-R0)/(h0*sin(s1)))-dd0;
           printf("\ndbeg=%f h0=%f",(dbeg+dd0)/RAD,h0-R0);
           if (dbeg<0) dbeg=.0*RAD;
           dbegMUF=dbeg;
           h0=hm;
           s1=s0/(2.*(i+1)*R0);
           dend=atan((h0*cos(s1)-R0)/(h0*sin(s1)));
           printf("\ndend=%f h0=%f",dend/RAD,h0-R0);
           dendMUF=dend;

           if (nfr>0)
             for(ifr=0; ifr<nfr || !ifr; ifr++)
               {
                 *(d_b+2*(hop2*ifr+i))=*(d_b+2*(hop2*ifr+i)+1)=dbeg;
                 *(d_e+2*(hop2*ifr+i))=*(d_e+2*(hop2*ifr+i)+1)=dend;
               }
           else
             {
                 *(d_b+2*i)=*(d_b+2*i+1)=dbeg;
                 *(d_e+2*i)=*(d_e+2*i+1)=dend;
             }
         }
   }

   cout<<endl<<"211111111111111"<<flush;

  infr.tid.kolTid=koltid;

  fscanf(in,"%d",&n);
  fprintf(out,"\n\nNumber diff. equation:%2d\n",n);

  putdat=(PUTDAT*)malloc(sizeof(PUTDAT)*hop2*maxKor);

  if (keyini>=0)
  {
      if (keyini!=1 && !readIndexDasf(*(argv+3)))
      {
          printf("\nError in DASF-File");
          exit(EXIT_FAILURE);
      }
 
      init_fil(*(argv+3),infr,keyini);
      if (nfr)
        cor=new COR[nfr];
  }


  mySolt=new MySolt(s0,alf,delt0,eps,ep,ep1,n,eps1,dd0,epsa,aa0,putdat);
  mySolt->setFh(fh,h,dh,dh2);

  gettimeofday(&tv,NULL);
  T1=tv.tv_sec+tv.tv_usec/1000000.0;
  printf("\n111 keytr=%d",keytr);
  for(t=t1; t<=t2; t +=dt)
  { /* t */
      double tim=t; // время для ПИВ отсчитывается от 0 (от полночи текущего дня)
      mySolt->setTime(t);
      prion(out,lat0,lon0,lat1,lon1,tim,W,IG,keypri,keyEs);
      if (t<.0)
        time=t+86400.;
      else
        time=t;
      hou=(long)(time/3600.);
      min=(long)((time-hou*3600.)/60.);
      sek=(long)(time-hou*3600.-min*60.);
      msek=(long)((time-hou*3600.-min*60.-sek)*100.);
      while(hou>24) hou -=24;

      time/=3600.;

      if (keymp<2)
          sprintf(tempS,"%6.3f  %4d",time,keymp);
      else
          sprintf(tempS,"%6.3f  %4d",time,hop2-hop1+1);
      
      if (keymp)
      {
          double eps=.00001,
                 e=.0625*eps,
                 MUF=.0;
            
          if (keyOut)
          {
             sprintf(inform,"\nCalculat MUF, time: %02ld:%02ld:%02ld.%02ld\n",
                     hou,min,sek,msek);
             printf("%s",inform);
             fflush(stdout);
          }
        //oxTrk=-1; // при поиске МПЧ компоненты не учитываются
        
        fprintf(out,STR60);
        fprintf(out,STR61,hou,min,sek,msek);
        fprintf(out,STR62);

        fmpch=fmpcho=fmpchx=0;
        if (keympr<0) keytr=-1;

        mySolt->setFlagMpch(true);
        for(ih=hop1; ih<=hop2 && (fmpch<=.0 || keymp>1); ih++)
        {
            mySolt->setHop(ih);
            mySolt->setDmin(dbegMUF);
            mySolt->setDmax(dendMUF);
            //hopTrk=ih; // только для отображения
            int ihm=ih-1;
            *mod='\0';
            iox=0;
            fmpcho=mpchs(mySolt);
            iox=1;
            fmpchx=mpchs(mySolt);
            //printf("\nih=%d  fmpcho=%f  fmpchx=%f",ih,fmpcho,fmpchx);
            
            if (fmpchx>.0)
            {
                fmpch=fmpchx;
                fmp[ihm]=fmpchx;
                fprintf(out,STR63,fmpcho,fmpchx,moda(Moda(ihm),mod));
                
                if (fmpch<MUF)
                {
                    if (keymp==1)
                      break;
                }
                else
                    MUF=fmpch;

                sprintf(tempS+strlen(tempS),"  %5.2f  %5.2f",fmpchx,fmpcho);
            }
            else
              sprintf(tempS+strlen(tempS),"      n      n");
        }

        mySolt->setFlagMpch(false);

        if (MUF>.0)
        {
            fmpch=MUF;
            fmpcho=fmpch;
            fmpchx=fmpch;
        }
        for(i=0; i<nfr; i++)
        {
            if (*(fb+i)<1.)
              *(f+i)=*(fb+i)*fmpchx;
        }

        if (keympr<0)
        {
            //keytr=0;
            //if (keysol>=0)
            //  draw_sol(1);
        }
        /*
        fmpch_es=.0;
        if (keyes>=0)
          {
            double MUF_Es=.0;

            fprintf(out,STR64);

            for(ih=hop1;ih<=hop2; ih++)
              {
                ihm=ih-1;
                mpch_es(s0,&fm_es[ihm],&f_es[ihm],ih);

                if (f_es[ihm]>.0 && f_es[ihm]>fm_es[ihm])
                  {
                    fprintf(out,STR66,fm_es[ihm]-pop1,f_es[ihm]+pop2,ih);
                    if (f_es[ihm]<MUF_Es)
                      {
                        if (keymp==1)
                          break;
                      }
                    else
                      MUF_Es=f_es[ihm];
                  }
              }
            fmpch_es=MUF_Es;
          }
        */
        fprintf(out,STR65);
        fflush(out);
        //cout<<flush;
      }

      if (nfr>0 && (keymp==0 || keymp>0 && fmpch>0))
      { /* f */
          if (keyOut)
          {
                sprintf(inform,"Calculate path, time: %02ld:%02ld:%02ld.%02ld\n",
                        hou,min,sek,msek);
                printf("%s",inform);
                fflush(stdout);
                //cout<<inform<<flush;
          }
          if (keypr)
          {
              fprintf(out,STR0);
              if (keypol) fprintf(out,STR10);
              if (keyel)  fprintf(out,STR30);
              fprintf(out,"\n");
              fprintf(out,STR1,hou,min,sek,msek);
              if (keypol) fprintf(out,STR11);
              if (keyel)  fprintf(out,STR31);
              fprintf(out,"\n");
              fprintf(out,STR2);
              if (keypol) fprintf(out,STR12);
              if (keyel)  fprintf(out,STR32);
              fprintf(out,"\n");
              fprintf(out,STR3);
              if (keypol) fprintf(out,STR13);
              if (keyel)  fprintf(out,STR33);
              fprintf(out,"\n");
          }
          
          for(ifr=0; ifr<nfr; ifr++)
          { /* ifr */
              //frTrk=f[ifr]; // только для графического отбражения
              ///////////////////////////////////////////
              sinE=cosE=.0; // квадратуры суммарного поля
              ///////////////////////////////////////////
              if (keyOut)
              {
                    sprintf(inform,"Calculate path, fr: %6.3f MHz\n",f[ifr]);
                    printf("%s",inform);
                    fflush(stdout);
                    //cout<<inform<<flush;
              }

              if (keypr)
              {
                  fprintf(out,STR4);
                  //fflush(out);
                  if (keypol) fprintf(out,STR14);
                  if (keyel)  fprintf(out,STR34);
                  fprintf(out,"\n");
              }

              if (keyini>=0)
              {
                  (cor+ifr)->mpchx=fmpchx;
                  (cor+ifr)->fr  =f[ifr];
                  (cor+ifr)->time=t;
              }
              else
              {
                  e_r[ifr] =.0;
                  e_es[ifr]=.0;
              }
              
              //tmre=.2617994*(time-3.)+lon1;
              tmre=.2617994*time+lon1; // время по Гринвичу

              while(tmre<.0)  tmre +=PI2;
              while(tmre>PI2) tmre -=PI2;
              
              grss(f[ifr],lon1,lat1,tmre,mes,Fam,Du,Dl,Vd,SFam,Sdu,Sdl,Svd);

              epom=Fam-65.5+20.*log10(f[ifr])+10.*log10(b);
              
              ssno(f[ifr],tmre,mes,lat1,epom_i,sig_i);
              
              epom_i +=20.*log10(b);
              epom=10.*log10(exp(l10*epom)+((keynois)? exp(l10*epom_i) : .0));

              if (keyini>=0)
                (cor+ifr)->epom=epom;
              epm[ifr]=epom;
              ikor=-1;
              double fr=f[ifr];
              mySolt->setFr(fr);
              
              for(ih=hop1; ih<=hop2; ih++)
              { /* ih */
                  //hopTrk=ih; // только для отображения
                  ihm=ih-1;
                  mySolt->setHop(ih);
                  for(ik=ox1; ik<=ox2; ik++)
                  { /* ik */
                      n=0;
                      iox=ik;
                      *mod='\0';
                      { /* solt */
                          if (keysol<0 || keytr<0)
                          {
                              if (keytr>=0) keytr=-1;
                              //draw_sol(0);
                          }
                          dbeg=*(d_b+2*(hop2*ifr+ihm)+ik);
                          dend=*(d_e+2*(hop2*ifr+ihm)+ik);                 

                          //n=solt(dbeg,dend,alf,s0,ih,delt0,eps,ep,ep1,e,eps1,eps2,epsa,dd0,aa0,putdat);
                          mySolt->setDmin(dbeg);
                          mySolt->setDmax(dend);
                          n=mySolt->solt();
                          //printf("\nn=%d fr=%f dbeg=%f  dend=%f h0=%f dd0=%f ih=%d",n,fr,dbeg/RAD,dend/RAD,h0,dd0/RAD,ih);
                          /*
                          for(i=0; i<n; i++)
                          {
                              for(int j=0; j<ih; j++)
                              {
                                  IOX( ihm*i+j)=iox;
                                  FR(  ihm*i+j)=fr;
                                  TIME(ihm*i+j)=tim;
                              }
                              outtrs(out,putdat+i*ih,ih);
                          }
                          */
                          if (!keyugl)
                          {
                              *(d_b+2*(hop2*ifr+ihm)+ik)=__max(dbeg,D1(ih*0+0)*RAD-2.*dd0);
                              *(d_e+2*(hop2*ifr+ihm)+ik)=D1(ih*(n-1)+0)*RAD+2.*dd0;
                          }
                      } /* solt */

                      if (n)
                      { /* n */

                          abspol(f[ifr],alf,alf1,ik,ih,n,&a1,&a2,
                                 lp,lr,ku,knd,mm,psi,putdat);

                          for(ir=0; ir<n; ir++)
                          {
                               if (S(ih*ir+ihm)<=.0)
                                   continue;
                               emp=104.8-L(ih*ir+ihm)-LS(ih*ir+ihm)-lp[ir]-lr[ir]+
                                   ku[ir]+knd[ir]+10.*log10(ptr);

                               //printf("\n******************pgg=%8.3f",pgg[ir]);
                               sinE+=exp(.5*l10*emp)*sin(PI2*fr*pgg[ir]/.3);
                               cosE+=exp(.5*l10*emp)*cos(PI2*fr*pgg[ir]/.3);
                               //if (!es_otr || es_otr && ir<n-1)
                               //  e_r[ifr] +=exp(l10*emp);

                               e_es[ifr]+=exp(l10*(emp-l_es[ir]));

                               if (keyini>=0)
                               {
                                   if (D1(ih*ir)<-90.) // корень на самом деле не найден
                                       continue;
                                   if (ikor<RAY-1)
                                   {
                                       ikor++;
                                       (cor+ifr)->di[ikor]=D1(ih*ir)*RAD;
                                       (cor+ifr)->ai[ikor]=A1(ih*ir)*RAD;
                                       (cor+ifr)->dk[ikor]=D2(ih*ir+ihm)*RAD;
                                       (cor+ifr)->ak[ikor]=A2(ih*ir+ihm)*RAD;
                                       (cor+ifr)->e[ikor] =emp;
                                       (cor+ifr)->l_es[ikor] =l_es[ir];
                                       (cor+ifr)->p[ikor] =P(ih*ir+ihm);
                                       (cor+ifr)->pg[ikor]=
                                           (ik==0)? PG(ih*ir+ihm) : -PG(ih*ir+ihm);
                                       (cor+ifr)->df[ikor]=DF(ih*ir+ihm);
                                       (cor+ifr)->moda[ikor]=Moda(ih*ir+ihm);
                                       printf("\n1###### ikor=%2d d2=%6.2f  a2=%8.3f",ikor,(cor+ifr)->dk[ikor]/RAD,(cor+ifr)->ak[ikor]/RAD);
                                   }
                                   else
                                     if (emp>(cor+ifr)->e[ikor])
                                     {
                                         (cor+ifr)->di[ikor]=D1(ih*ir)*RAD;
                                         (cor+ifr)->ai[ikor]=A1(ih*ir)*RAD;
                                         (cor+ifr)->dk[ikor]=D2(ih*ir+ihm)*RAD;
                                         (cor+ifr)->ak[ikor]=A2(ih*ir+ihm)*RAD;
                                         (cor+ifr)->e[ikor] =emp;
                                         (cor+ifr)->l_es[ikor] =l_es[ir];
                                         (cor+ifr)->p[ikor] =P(ih*ir+ihm);
                                         (cor+ifr)->pg[ikor]=
                                             (ik==0)? PG(ih*ir+ihm) : -PG(ih*ir+ihm);
                                         (cor+ifr)->df[ikor]=DF(ih*ir+ihm);
                                         shell((cor+ifr)->e,
                                               (cor+ifr)->l_es,
                                               (cor+ifr)->di,
                                               (cor+ifr)->ai,
                                               (cor+ifr)->dk,
                                               (cor+ifr)->ak,
                                               (cor+ifr)->p,
                                               (cor+ifr)->pg,
                                               (cor+ifr)->df,
                                               (cor+ifr)->moda,ikor+1);
                                         printf("\n2###### d2=%6.2f  a2=%8.3f",(cor+ifr)->dk[ikor]/RAD,(cor+ifr)->ak[ikor]/RAD);
                                     }
                               }
                               else
                                 ikor++;

                               if (keypr)
                               {
                                   if (D1(ih*ir)<-90) // корень на самом деле не найден
                                       continue;
                                   if (l[ir]>999.9)
                                     l[ir]=999.9;
                                   if (l_es[ir]>999.9)
                                     l_es[ir]=999.9;
                                   if (emp<-999.9)
                                     emp=-999.9;
                                   fprintf(out,STR5,f[ifr],
                                                    ((ik)? 'x' : 'o'),
                                                    D1(ih*ir),D2(ih*ir+ihm),
                                                    P(ih*ir+ihm)/300.,
                                                    DF(ih*ir+ihm),
                                                    DEV(ih*ir+ihm),
                                                    L(ih*ir+ihm),LS(ih*ir+ihm),emp,
                                                    l_es[ir],
                                                    moda(Moda(ih*ir+ihm),mod));

                                   if (keypol)
                                     fprintf(out,STR15,lp[ir],lr[ir],
                                                       ku[ir],knd[ir]);
                                   if (keyel)
                                     fprintf(out,STR35,mm[ir],psi[ir]/RAD);
                                   fprintf(out,"\n");
                                   fflush( out );
                               }
                          } /* ir */
                      }  /* n */
                    } /* ik */
                } /* ih */

              if (keyini>=0)
                {
                  (cor+ifr)->k=ikor+1;
                  shell((cor+ifr)->e,
                        (cor+ifr)->l_es,
                        (cor+ifr)->di,
                        (cor+ifr)->ai,
                        (cor+ifr)->dk,
                        (cor+ifr)->ak,
                        (cor+ifr)->p,
                        (cor+ifr)->pg,
                        (cor+ifr)->df,
                        (cor+ifr)->moda,
                        (cor+ifr)->k);
                }
              else
                {
                  if (e_r[ifr] >.0) e_r[ifr] =10.*log10(e_r[ifr]);
                  if (e_es[ifr]>.0) e_es[ifr]=10.*log10(e_es[ifr]);
                  if (e_r[ifr] <-999.9) e_r[ifr]=-999.9;
                  if (e_es[ifr]<-999.9) e_es[ifr]=-999.9;
                }

              cosE=sinE*sinE+cosE*cosE;
              //cout<<endl<<cosE;
              if (cosE>.0)
                  cosE=10.*log10(cosE);
              if (tempFile)
                  fprintf(tempFile,STR81,(double)hou+((double)min+(double)sek/60.)/60.,f[ifr],e_r[ifr],e_r[ifr]-epm[ifr],e_es[ifr],e_es[ifr]-epm[ifr],cosE,cosE-epm[ifr],s0*100.,tempS);
          } /* ifr */

          if(keypr)
          {
              fprintf(out,STR6);
              //fflush( out );
              if (keypol) fprintf(out,STR16);
              if (keyel)
              {
                  fprintf(out,STR36);
                  fprintf(out,"\n");
                  fflush(out);
                  //cout<<flush;
              }
          }

          if (keyini>=0)
          {
              infr.timek=t;
              wr_fil(*(argv+3),infr,keyini,cor);
          }
          else
          {
              if (keypr<=0)
                {
                  fprintf(out,STR20);
                  fprintf(out,STR21,hou,min);
                  fprintf(out,STR22);
                  fprintf(out,STR23);
                  fprintf(out,STR24);

                  for(ifr=0; ifr<nfr; ifr++)
                    {
                        if (e_r[ifr]!=.0)
                        {
                            fprintf(out,STR25,f[ifr],e_r[ifr],e_r[ifr]-epm[ifr],
                                    e_es[ifr],e_es[ifr]-epm[ifr]);
                            fflush( out );
                        }
                        else
                            if (e_es[ifr]!=.0)
                            {
                                fprintf(out,STR27,f[ifr],e_es[ifr],e_es[ifr]-epm[ifr]);
                                fflush( out );
                            }
                            else
                            {
                                fprintf(out,STR28,f[ifr]);
                                fflush( out );
                            }
                    }
                  fprintf( out,STR26 );
                  fflush( out );
                  //cout<<flush;
                }
          }
      } /* f */
      else
        if (tempFile)
            fprintf(tempFile,"\n%s",tempS);

  } /* t */

  gettimeofday(&tv,NULL);
  T2=tv.tv_sec+tv.tv_usec/1000000.0;
  DT=T2-T1;

  printf("\ntime,ms=%8.3f\n",DT*1000.);
  fflush(stdout);
  fprintf(out,"\ntime,ms=%8.3f\n",DT*1000.);
  fflush(out);

  if (keyini>=0)
  {
      delete[] cor;
      writeIndexDasf(*(argv+3));
      if (readIndexDasf(*(argv+3)))
      {
          printf("\nError in DASF-File");
          exit(EXIT_FAILURE);
      }
  }

  //if (keytr<0 || keympr<0)
    //draw_sol(1);

  if (nfr>0)
  {
      delete[] f;
      delete[] fb;
      delete[] epm;
      delete[] e_r;
      delete[] e_es;
  }
  delete[] d_b;
  delete[] d_e;
  
  fclose(out);
  if (tempFile)
      fclose(tempFile);
  //outtrs(out,putdat,-1);

  delete mytrek_ext;
  delete mySolt;
  free(putdat);

  if (!spN_H)
      delete spN_H;

  return 0;
}


void drawIon(double *fpl, double *hpl, int nf, int npoin, double hMin, double hMax, double fMax)
{
}

void drawTrek(double *sTr, double *hTr, long pointTr)
{
}

void drawInf(char *inf)
{
}


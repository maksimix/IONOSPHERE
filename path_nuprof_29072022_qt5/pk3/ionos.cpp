#include <math.h>
#include "paths.h"

int ionos(double f,
	  double t,
	  double r,
	  int    n)
/***************************************************************/
/*                                                             */
/*	������� ��������� �������� �������� ����������         */
/*      �������	� ��� �����B����� �� ����������	�����������    */
/*	��� ������� ��������� ���������	� ��������� � inions   */
/*                                                             */
/*VGG                                                          */
/***************************************************************/
{
   double rd[3],rexp,r1,g,r2,r3,drtf[3],g2,dr,df,dt,
          tid0,rc[3],rff,rtt,rrr,rft,rfr,rtr,fo;
   double vt=.0;
   double nu=.0;

   int i;

/*--------------------------------------------------------------*/

   dr=r-R0;
   df=f-fi0;
   dt=t-teta0;

   if (r<h0)
     return 1;
   else
       if (mod<10)
       {
           switch (mod)
           {
               case 1: r1=(r-h0)/ym;
                       v=f02*r1*(2.-r1)/fr2;
                       vp[2]=2.*f02*(1.-r1)/(ym*fr2);
                       vpp[2][2]=-2.*f02/(ym*ym*fr2);
                       //printf("\n%6.1f  %6.4f",100.*dr,sqrt(v));
                       break;
      
               case 2: v=.0;
                       vp[2]=.0;
                       vpp[2][2]=.0;
                       for(i=0; i<klay; i++)
                         {
                           r1=(r-hl[i])/yl[i];
                           rexp=exp(-r1);
                           r1=fl[i]*exp(al[i]*(1.-r1-rexp));
                           v +=r1;
                           r2=al[i]*(rexp-1.)/yl[i];
                           r3=r1*r2;
                           vp[2] +=r3;
                           vpp[2][2] +=r3*r2-r1*al[i]*rexp/(yl[i]*yl[i]);
                         }
                       v=(v-par)/fr2;
                       vp[2]     /=fr2;
                       vpp[2][2] /=fr2;
                       break;
      
               case 3: for(i=0; i<klay; i++)
                         {
                           if (r>al[i] && i!=klay-1) continue;
                           par=1.-2.*fmod(i,2.);
                           r1=(hl[i]-yl[i])/r;
                           r2=(hl[i]-r)/yl[i];
                           r3=r1*r2;
                           v=fl[i]*(1.-par*r3*r3)/fr2;
                           r1=hl[i]/yl[i]-1.;
                           r2=2.*fl[i]*par*r1*hl[i]/(r*r);
                           vp[2]=r2*r3/fr2;
                           vpp[2][2]=-r2*r1*(3.*hl[i]-2.*r)/(r*r*fr2);
                           if (r==h0) v=.0;
                           break;
                         }
                       break;
      
               case 4:
      
               case 5:
      
               case 6:
                       spN_H->spcub(r,v,vp[2],vpp[2][2]);
                       v         /=fr2;
                       vp[2]     /=fr2;
                       vpp[2][2] /=fr2;
                       break;
      
           }
      
           r1=gx*st;
           r2=2.*v;
           r3=gx*ct*df+gy;
      
           g=1.+r1*df+gy*dt;
           g2=g*g;
      
           if (n>8)
             {
               vpp[0][0]=r2*r1*r1;
               vpp[0][1]=r2*(r1*r3+g*gx*ct);
               vpp[0][2]=2.*vp[2]*g*r1;
               vpp[1][0]=vpp[0][1];
               vpp[1][1]=r2*(gy*gy-g*r1*df);
               vpp[1][2]=2.*vp[2]*g*r3;
               vpp[2][0]=vpp[0][2];
               vpp[2][1]=vpp[1][2];
               vpp[2][2]=vpp[2][2]*g2;
             }
      
           r2 *=g;
           v *=g2;
           vp[0]=r2*r1;
           vp[1]=r2*r3;
           vp[2]=vp[2]*g2;
       }
       else
       {
           if (n>8)
           {
               ionosf(f,t,100.*r,tim,v,vp[0],vp[1],vp[2],vt,vpp[0][0],vpp[1][1],vpp[2][2],
                      vpp[0][1],vpp[0][2],vpp[1][2]);
               vpp[2][2]*=10000.;
               vpp[0][2]*=100.;
               vpp[1][2]*=100.;
               vpp[0][0]/=fr2;
               vpp[1][1]/=fr2;
               vpp[2][2]/=fr2;
               vpp[0][1]/=fr2;
               vpp[0][2]/=fr2;
               vpp[1][2]/=fr2;
           }
           else
           {
               vpp[0][0]=vpp[0][1]=vpp[0][2]=vpp[1][1]=vpp[1][2]=vpp[2][2]=.0;
               vt=.0;
               ionosf(f,t,100.*r,tim,v,vp[0],vp[1],vp[2],vt);
               //printf("\n v=%f r=%f",sqrt(v),100.*(r-R0));
           }
           vp[2]*=100.;
           v/=fr2;
           vp[0]/=fr2;
           vp[1]/=fr2;
           vp[2]/=fr2;
           vt   /=fr2;
           dvt   =vt;
       }

     if(keynu==0 && mod==10)
     {
        nuprof(f,t,100.*r,tim,nu);      //IRI model
        s=nu/(2.*fr*PI);
     }
     else
     {
        s=(exp(12.7-15.8*(r-R0))+exp(-6.17-.42*(r-R0)))/(2.*fr*PI);
     }

     if(v<.0)
     {
	 v=.0;
	 vp[0]=.0;
	 vp[1]=.0;
         vp[2]=.0;
         vt=.0;
         dvt=.0;
	 return 0;
     }

     if (koltid)
     {
	 r1=df*st;
	 r2=df*ct;

	 for(i=0; i<koltid; i++)
	   {
	     fo=-om[i]*tim+pr[i]*dr+(pt[i]*dt+pf[i]*r1)*r+fit[i];
	     rc[i]=-de[i]*cos(fo);
	     rd[i]=-de[i]*sin(fo);
	   }

	 tid0=.0;
	 drtf[0]=.0;
	 drtf[1]=.0;
	 drtf[2]=.0;
	 dvt=.0;

	 for(i=0; i<koltid; i++)
	   {
	     drtf[0] +=rd[i]*pf[i];
	     drtf[1] +=rd[i]*(pt[i]+pf[i]*r2);
	     drtf[2] +=rd[i]*(pr[i]+pt[i]*dt+pf[i]*r1);

	     dvt +=rd[i]*om[i];

	     tid0 +=rc[i];
	   }

	 tid0=1.-tid0;

	 drtf[0] *=r*st;
	 drtf[1] *=r;

         dvt=-v*dvt;
         dvt=vt*tid0-v*dvt;

	 if(n>8)
	   {
	     rff=.0;
	     rtt=.0;
	     rrr=.0;
	     rft=.0;
	     rfr=.0;
	     rtr=.0;

	     for(i=0; i<koltid; i++)
	       {
		 r1=r*pf[i]*st;
		 r2=r*(pt[i]+pf[i]*ct*df);
		 r3=pr[i]+pt[i]*dt+pf[i]*df*st;

		 rff +=rc[i]*r1*r1;
		 rtt +=rc[i]*r2*r2-rd[i]*r1*df;
		 rrr +=rc[i]*r3*r3;
		 rft +=rc[i]*r1*r2+rd[i]*r*pf[i]*ct;
		 rfr +=rc[i]*r1*r3+rd[i]*pf[i]*st;
		 rtr +=rc[i]*r2*r3+rd[i]*(pt[i]+pf[i]*ct*df);
	       }

	     vpp[0][0]=vpp[0][0]*tid0+2.*vp[0]*drtf[0]+v*rff;
	     vpp[1][1]=vpp[1][1]*tid0+2.*vp[1]*drtf[1]+v*rtt;
	     vpp[2][2]=vpp[2][2]*tid0+2.*vp[2]*drtf[2]+v*rrr;
	     vpp[0][1]=vpp[0][1]*tid0+vp[0]*drtf[1]+vp[1]*drtf[0]+v*rft;
	     vpp[0][2]=vpp[0][2]*tid0+vp[0]*drtf[2]+vp[2]*drtf[0]+v*rfr;
	     vpp[1][2]=vpp[1][2]*tid0+vp[1]*drtf[2]+vp[2]*drtf[1]+v*rtr;
	     vpp[1][0]=vpp[0][1];
	     vpp[2][0]=vpp[0][2];
	     vpp[2][1]=vpp[1][2];
	   }

	 vp[0]=v*drtf[0]+vp[0]*tid0;
	 vp[1]=v*drtf[1]+vp[1]*tid0;
	 vp[2]=v*drtf[2]+vp[2]*tid0;

	 v *=tid0;
     }

     return 0;

}  /* ionos */
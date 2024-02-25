#ifndef __SPCUB_H
#define __SPCUB_H

#include <fstream>

//VGG 11.1998

#define __max(x,y) ((x)>(y)? (x) : (y))
#define __min(x,y) ((x)<(y)? (x) : (y))

long progon(double* x, double* a, double* b, double* c, double* d,
            long n, double eps);


enum GRAN {DxDx=0x1,D2xD2x=0x2,DxD2x=0x4,D2xDx=0x8};

class SPCUB
  {
    protected:
      long    n;      // ���������� ����� � ��������;
      double* x;      // �������� ����������� ����������� �������;
      double* f;      // �������� ������� � ����� �������;      
    private:
      double* df;     // �������� ����������� ������� � ����� �������;
      double  grana;  // ��������� ������� �� ����� ������� ��������;
      double  granb;  // ��������� ������� �� ������ ������� ��������;
      long    nm;     // n-1;
      GRAN    key;    // ��� ��������� �������:
                      //     1 - ������ ������ �����������;
                      //     2 - ������ ������ �����������;
                      //     4 - ����� ������, � ������ ������ �����������;
                      //     8 - ����� ������, � ������ ������ �����������.
      long     i;     // ����������, ������������ ��� ���������� ��������
                      // ������-������� ��� ���������� �������� ���������.

      double t,dx;    // ������� ����������
      double fi[4],dfi[4],ddfi[4];

    public:
      SPCUB(long n, double grana=.0, double granb=.0, GRAN key=D2xD2x);
      ~SPCUB();
      void setN(long N){n=N; nm=N-1;};
      long getN(){return n;};
      void setGran(double ga, double gb){grana=ga; granb=gb;};
      void getGran(double &ga, double &gb){ga=grana; gb=granb;};
      void setTypeGran(GRAN k){key=k;};
      GRAN getTypeGran(){return key;};
      void   setCarrierX(double arg, long j){x[j]=arg;};
      double getCarrierX(long j){return x[j];};
      void   setCarrier(double fun, long j){f[j]=fun;};
      double getCarrier(long j){return f[j];};
      double getCarrierDX(long j){return df[j];};
      long form();
      long spcub(double x, double& f);
      long spcub(double x, double& f, double& df);
      long spcub(double x, double& f, double& df, double& ddf);
      long spcub(double x, double& f, long &i);
      long spcub(double x, double& f, double& df, long &i);
      long spcub(double x, double& f, double& df, double& ddf, long &i);
    friend
      long progon(double* x, double* a, double* b, double* c, double* d,
                  long n, double eps);
  };

class SPCUB3
  {
      //public:
      //static int count;
    protected:
      double* x;            // �������� ����������� ����������� ������� �� x;
      double* y;            // �������� ����������� ����������� ������� �� y;
      double* z;            // �������� ����������� ����������� ������� �� z;
      double* f;            // �������� ������� � ����� ������� f[ix][iy][iz];
      long    nx,ny,nz;     // ���������� ����� � ��������;      
    //private:
      double *dfx,*dfy,*dfz,// �������� ����������� ������� � ����� �������;
             *dfxy,*dfxz,
             *dfyz,*dfxyz;
      double  *granXa,       // ��������� ������� �� ����� ������� �������� (��� ������������� �� x);
              *granYa,       // �.�. �� ��������������� ������ ����
              *granZa;
      double  *granXb,       // ��������� ������� �� ������ ������� �������� (��� ������������� �� x);
              *granYb,       // �.�. �� ��������������� ������ ����
              *granZb;
      double  *granX[4],*granY[4],*granZ[4], // ��������� ������� ����� ��������������� ����� ����
              granXYZ[8]; // ��������� ������� � �������� ����
      long    maxXYZ;       // ������������ �� nx, ny, nz
      long    nXY,nXZ,nYZ,nXYZ;
      long    nmx,nmy,nmz;  // n-1;
      GRAN    keyX,   // ��� ��������� �������:
              keyY,   //     1 - ������ ������ �����������;
              keyZ;   //     2 - ������ ������ �����������;
                      //     4 - ����� ������, � ������ ������ �����������;
                      //     8 - ����� ������, � ������ ������ �����������.
      long    ix,iy,iz;    // ����������, ������������ ��� ���������� ��������
                           // ������-������� ��� ���������� �������� ���������.
      long    ixOld,iyOld,izOld;
      double  xOld,yOld,zOld;

    private: 
      double fbx[4],fby[4],fbz[4],dfbx[4],dfby[4],dfbz[4], // ����� ������� ����������
             ddfbx[4],ddfby[4],ddfbz[4],C[4][4][4],        // ����������� ��� ���������� ��������
             s1,s2,s3,s4,s5,s6,s7,s8,s9,                   // ������-�������
             dx,dy,dz,
             tx,ty,tz;

    public:
      SPCUB3(long nx, long ny, long nz,
             double granXa=.0, double granXb=.0, GRAN keyX=D2xD2x,
             double granYa=.0, double granYb=.0, GRAN keyY=D2xD2x,
             double granZa=.0, double granZb=.0, GRAN keyZ=D2xD2x,
             double granX=.0, double granY=.0, double granZ=.0, double granXYZ=.0);
      SPCUB3(SPCUB3 &sp);
      SPCUB3();
      ~SPCUB3();
      void setN(long Nx,long Ny,long Nz){nx=Nx; nmx=Nx-1; ny=Ny; nmy=Ny-1; nz=Nz; nmz=Nz-1;};
      void getN(long &Nx,long &Ny,long &Nz){Nx=nx; Ny=ny; Nz=nz;};
      void setGranXab(double ga, double gb, long jy, long jz){*(granXa+nz*jy+jz)=ga; *(granXb+nz*jy+jz)=gb;};
      void setGranYab(double ga, double gb, long jx, long jz){*(granYa+nz*jx+jz)=ga; *(granYb+nz*jx+jz)=gb;};
      void setGranZab(double ga, double gb, long jx, long jy){*(granZa+ny*jx+jy)=ga; *(granZb+ny*jx+jy)=gb;};
      void getGranXab(double &ga, double &gb, long jy, long jz){ga=*(granXa+nz*jy+jz); gb=*(granXb+nz*jy+jz);};
      void getGranYab(double &ga, double &gb, long jx, long jz){ga=*(granYa+nz*jx+jz); gb=*(granYb+nz*jx+jz);};
      void getGranZab(double &ga, double &gb, long jx, long jy){ga=*(granZa+ny*jx+jy); gb=*(granZb+ny*jx+jy);};
      void setTypeGran(GRAN kX, GRAN kY, GRAN kZ){keyX=kX; keyY=kY; keyZ=kZ;};
      void getTypeGran(GRAN &kX, GRAN &kY, GRAN &kZ){kX=keyX; kY=keyY; kZ=keyZ;};
      void setGranX(double g, long axis, long jx){*(granX[axis]+jx)=g;};
      void setGranY(double g, long axis, long jy){*(granY[axis]+jy)=g;};
      void setGranZ(double g, long axis, long jz){*(granZ[axis]+jz)=g;};
      void setGranXYZ(double g, long jXYZ){granXYZ[jXYZ]=g;};
      double getGranX(long axis, long jx){return *(granX[axis]+jx);};
      double getGranY(long axis, long jy){return *(granY[axis]+jy);};
      double getGranZ(long axis, long jz){return *(granZ[axis]+jz);};
      double getGranXYZ(long jXYZ){return granXYZ[jXYZ];};
      void setCarrierX(double arg, long j){x[j]=arg;};
      void setCarrierY(double arg, long j){y[j]=arg;};
      void setCarrierZ(double arg, long j){z[j]=arg;};
      double getCarrierX(long j){return x[j];};
      double getCarrierY(long j){return y[j];};
      double getCarrierZ(long j){return z[j];};
      void setCarrier(double fun, long jx, long jy, long jz){*(f+(jx*ny+jy)*nz+jz)=fun;};
      void setCarrierDX(double dfun, long jx, long jy, long jz){*(dfx+(jx*ny+jy)*nz+jz)=dfun;};
      void setCarrierDY(double dfun, long jx, long jy, long jz){*(dfy+(jx*ny+jy)*nz+jz)=dfun;};
      void setCarrierDZ(double dfun, long jx, long jy, long jz){*(dfz+(jx*ny+jy)*nz+jz)=dfun;};
      void setCarrierDXY(double dfun, long jx, long jy, long jz){*(dfxy+(jx*ny+jy)*nz+jz)=dfun;};
      void setCarrierDYZ(double dfun, long jx, long jy, long jz){*(dfyz+(jx*ny+jy)*nz+jz)=dfun;};
      void setCarrierDXZ(double dfun, long jx, long jy, long jz){*(dfxz+(jx*ny+jy)*nz+jz)=dfun;};
      void setCarrierDXYZ(double dfun, long jx, long jy, long jz){*(dfxyz+(jx*ny+jy)*nz+jz)=dfun;};
      double getCarrier(long jx, long jy, long jz){return *(f+(jx*ny+jy)*nz+jz);};
      double getCarrierDX(long jx, long jy, long jz){return *(dfx+(jx*ny+jy)*nz+jz);};
      double getCarrierDY(long jx, long jy, long jz){return *(dfy+(jx*ny+jy)*nz+jz);};
      double getCarrierDZ(long jx, long jy, long jz){return *(dfz+(jx*ny+jy)*nz+jz);};
      double getCarrierDXY(long jx, long jy, long jz){return *(dfxy+(jx*ny+jy)*nz+jz);};
      double getCarrierDXZ(long jx, long jy, long jz){return *(dfxz+(jx*ny+jy)*nz+jz);};
      double getCarrierDYZ(long jx, long jy, long jz){return *(dfyz+(jx*ny+jy)*nz+jz);};
      double getCarrierDXYZ(long jx, long jy, long jz){return *(dfxyz+(jx*ny+jy)*nz+jz);};

      long form();
      long spcub(double x, double y, double z, double& f,
                 long &keyX, long &keyY, long &keyZ);
      long spcub(double x, double y, double z, double& f,
                 double& dfx, double& dfy, double& dfz,
                 long &keyX, long &keyY, long &keyZ);
      long spcub(double x, double y, double z, double& f,
                 double& dfx, double& dfy, double& dfz,
                 double& dfxx, double& dfyy, double& dfzz,
                 double& dfxy, double& dfxz, double& dfyz,
                 long &keyX, long &keyY, long &keyZ);
      long spcub(double x, double y, double z, double& f,
                 double& dfx, double& dfy, double& dfz,
                 double& dfxx, double& dfyy, double& dfzz,
                 double& dfxy, double& dfxz, double& dfyz, double& dfxyz,
                 long &keyX, long &keyY, long &keyZ);
      long spcub(double x, double y, double z, double& f,
                 long &keyX, long &keyY, long &keyZ, long &ix, long &iy, long &iz);
      long spcub(double x, double y, double z, double& f,
                 double& dfx, double& dfy, double& dfz,
                 long &keyX, long &keyY, long &keyZ, long &ix, long &iy, long &iz);
      long spcub(double x, double y, double z, double& f,
                 double& dfx, double& dfy, double& dfz,
                 double& dfxx, double& dfyy, double& dfzz,
                 double& dfxy, double& dfxz, double& dfyz,
                 long &keyX, long &keyY, long &keyZ, long &ix, long &iy, long &iz);
      long spcub(double x, double y, double z, double& f,
                 double& dfx, double& dfy, double& dfz,
                 double& dfxx, double& dfyy, double& dfzz,
                 double& dfxy, double& dfxz, double& dfyz, double& dfxyz,
                 long &keyX, long &keyY, long &keyZ, long &ix, long &iy, long &iz);

      long getIx(){return ix;};
      long getIy(){return iy;};
      long getIz(){return iz;};
  };

#endif
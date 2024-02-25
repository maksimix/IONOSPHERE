#ifndef DRAWPOLIGONMEM_V_H

#define DRAWPOLIGONMEM_V_H

#ifndef DRAWBASE_H
#include "drawbase.h"
#endif
#ifndef QCOLOR_H
#include <qcolor.h>
#endif
#ifndef QWMATRIX_H
#include <qwmatrix.h>
#endif

#include <qptrlist.h>

#ifndef __ListDouble__
#define __ListDouble__
struct ListDouble
{
    ListDouble(double *Y, int nx=0, int N=0)
    {
        flag=true;
        setY(Y,nx,N);
    };
    ~ListDouble()
    {
        countMem-=n*sizeof(double);
        if (y>0)
            delete[] y;
    };

    double *getY() {return y;};
    bool   getFlag(){return flag;};
    void   setFlag(bool b){flag=b;};
    void   setY(double *Y, int nx, int N)
    {
        nX=nx;
        n=N;
        if (n>0)
        {
            countMem+=n*sizeof(double);
            y=new double[n];
            for(int i=0; i<n; i++)
                y[i]=Y[i];
        }
        else
            y=0;
    };
    int getNX(){return nX;};
    int getN(){return n;};
    static long countMem;
private:
    int nX; // ����� ������� (������)
    int n;
    bool flag;
    double *y;
};
#endif

class DrawPoligonMemV : public DrawBase
{
public:
    DrawPoligonMemV( QWidget *parent,
                     //char *infX, char *infY,
                     const QString &infX, const QString &infY,
                     double xmin, double xmax, double ymin, double ymax,
                     long ir=1, long ipgr=1, long krx=8, long kry=8);
    ~DrawPoligonMemV();
    void setY(double *Y,long n);
    void reset();
    void upDate();
    void setXBegDx(double x_beg, double dx){xBeg=x_beg; Dx=dx;};
    void setYBegDy(double y_beg, double dy){yBeg=y_beg; Dy=dy;};
    void setClear(bool clear){keyClear=clear;};
    void setColor(bool c){keyColor=c;};
    bool getClear(){return keyClear;};
    void   setMinAmp(double a){minAmp=a;};
    double getMinAmp(){return minAmp;};
    double getNormAmp(){return normAmp;};
    void   setNormAmp(double a){normAmp=a;};
private:
    long    x0,y0,x1,y1;
    long    color;
    double  sizex,sizey;
    int  nX; // ������� ���������� ��������
    QPtrList <ListDouble> listDouble;
    double xBeg,Dx,yBeg,Dy;
    double minAmp, normAmp;
    bool keyClear;
    bool keyColor; // true - ������� �����������
    bool keyPainter;
    bool keyCircle;
    long draw(QPainter &p, bool keyClear);
protected:
    virtual void paintEvent(QPaintEvent *);
};

#endif

using namespace std;
#include "drawpoligonmemfull.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <QImage>
#include <QPainter>

long ListDouble::countMem=0;

DrawPoligonMemFull::DrawPoligonMemFull(QWidget *parent,
                                       //char *infX, char *infY,
                                       const QString &infX, const QString &infY,
                                       double xMin, double xMax, double yMin, double yMax,
                                       long iR,long iPgr, long kRx, long kRy) :

           DrawMemBase(parent, infX, infY, xMin, xMax, yMin, yMax,
                       iR,iPgr, kRx, kRy)
{
    keyColor=true;
    kolOut=0;
    Dx=Dy=.0;
    xBeg=yBeg=.0;
    keyPainter=true;
    keyVert=false;
    keyCircle=false;
    keyInvert=true;
    keyOrNotROP=true;
    nX=0;
    minAmp=.0;
    normAmp=1.;
    setColorFon(QColor(255,255,255));
    setColorAxe(QColor(0,0,0));
    setColorSetka(QColor(150,150,150));
    setColorText(QColor(0,0,0));

    flagX=false;
    flagFon=true;
}

DrawPoligonMemFull::~DrawPoligonMemFull()
{
    //cout<<endl<<"~DrawPoligonMemFull countMem="<<ListDouble::countMem<<flush;
    for(list <ListDouble*>::iterator i=listDouble.begin(); i!=listDouble.end(); i++)
        delete *i;
    listDouble.clear();
}

void DrawPoligonMemFull::reset()
{
    nX=0;
    keyCircle=false;
    //std::cout<<std::endl<<"1 countMem="<<listDouble.size()<<flush;

    if (!listDouble.empty())
    {
        for(list <ListDouble*>::iterator i=listDouble.begin(); i!=listDouble.end(); i++)
            delete *i;
        //std::cout<<std::endl<<"countMem="<<ListDouble::countMem<<flush;
        listDouble.clear();
    }
    keyPainter=true;
    //std::cout<<std::endl<<"2 countMem="<<listDouble.size()<<flush;
    repaint();
}
/*
void DrawPoligonMemFull::setY(double *Y, long N)
{
    listDouble.insert(listDouble.count(), new ListDouble(Y,nX,N));
    nX++;
    if (nX)
        keyPainter=false;  // ������ ���� ����� ��������������
    repaint(false);
}
*/
void DrawPoligonMemFull::setY(double *Y, long N)
{
    flagX=false;

    //cout<<endl<<"setY(double *Y, long N)"<<flush;

    if (keyCircle)
    {
        delete *listDouble.begin();
        listDouble.pop_front();
    }
    //std::cout<<std::endl<<"0 DrawPoligonMemFull::setY countMem="<<ListDouble::countMem<<std::flush;
    listDouble.push_back(new ListDouble(Y,nX,N));
    //std::cout<<std::endl<<"1 DrawPoligonMemFull::setY countMem="<<ListDouble::countMem<<std::flush;
    if (keyCircle)
    {
        keyPainter=true;
        list<ListDouble*>::iterator iList=listDouble.begin();

        int i=0;
        for(int k=0; k<listDouble.size(); k++,iList++)
        {
            (*iList)->setNX(k);
        }
    }
    else
    {
        nX++;
        if (nX)
            keyPainter=false;  // ������ ���� ����� ��������������
    }
    //std::cout<<std::endl<<"2 DrawPoligonMemFull::setY countMem="<<ListDouble::countMem<<std::flush;
    //cout<<endl<<"setY(double *Y, long N) listDouble.count()="<<listDouble.count()<<" listDouble.first().getNX()="<<listDouble.first().getNX()<<flush;
    repaint();
}

void DrawPoligonMemFull::setY(double X1, double X2, double *Y, long N)
{
    flagX=true;

    if (flagX && !keyInvert)
        keyPainter=true;

    if (keyCircle)
    {
        delete *listDouble.begin();
        listDouble.pop_front();
    }
    listDouble.push_back(new ListDouble(X1,X2,Y,nX,N));
    if (keyCircle)
    {
        keyPainter=true;
        list<ListDouble*>::iterator iList=listDouble.begin();

        int i=0;
        for(int k=0; k<listDouble.size(); k++,iList++)
        {
            (*iList)->setNX(k);
            //std::cout<<std::endl<<"k="<<k<<"  iList="<<(long)iList<<std::flush;
        }
    }
    else
    {
        nX++;
        if (nX && keyInvert)
            keyPainter=false;  // ������ ���� ����� ��������������
    }
    //std::cout<<std::endl<<"DrawPoligonMemFull::setY countMem="<<ListDouble::countMem<<std::flush;
    repaint();
}

void DrawPoligonMemFull::paintEvent(QPaintEvent *e)
{
    //cout<<endl<<"1 DrawPoligonMemFull::paintEvent(QPaintEvent *e)  flagFon="<<flagFon<<flush;
    if (keyPainter || keyCircle) // ���� ���������� ������ ���� �����, �������������� ��� ���� ��� �������������
    {
        //cout<<endl<<"2 DrawPoligonMemFull::paintEvent(QPaintEvent *e)"<<flush;
        DrawMemBase::paintEvent(e);
    }
    
    QPainter p;

    p.begin(pix);
    if (keyVert)
        drawVert(p);
    else
        draw(p);
    drawMetka(p);
    p.end();

    if (flagFon)
    {
        p.begin(this);
        //p.setCompositionMode(QPainter::RasterOp_NotSourceXorDestination);
        //p.setOpacity(1.0);
        p.drawImage(0, 0, *pix);
        p.setCompositionMode(QPainter::RasterOp_NotSourceXorDestination);
        //p.setOpacity(0.7);
        p.drawImage(0, 0, *pixSetka);
        p.setCompositionMode(QPainter::CompositionMode_SourceOver);
        p.end();
    }
}


long DrawPoligonMemFull::draw(QPainter &p)
//
// ������� ������������� ��� �����������
//
{
  QPoint  point;
  QRect   rFill;
  QPen    pen=p.pen();
  long    i,j,k;
  QColor  colorPoint;
  list<ListDouble*>::iterator iList=listDouble.begin();
  double *iY;

  //cout<<endl<<"1 DrawPoligonMemFull::draw(QPainter &p) listDouble.size()="<<listDouble.size()<<flush;
  
  if (!error || !listDouble.size())
      return 1;

  //cout<<endl<<"2 DrawPoligonMemFull::draw(QPainter &p) listDouble.begin()->getNX()="<<(*listDouble.begin())->getNX()<<flush;
  
  sizex=xmax-xmin;
  sizey=ymax-ymin;

  if (keyPainter)
  {
      iList=listDouble.begin();
      k=0;
      //cout<<endl<<"21 DrawPoligonMemFull::draw(QPainter &p) k="<<k<<flush;
  }
  else
  {
      iList=listDouble.end();
      iList--;
      k=nX-1;
      //cout<<endl<<"22 DrawPoligonMemFull::draw(QPainter &p) k="<<k<<flush;
  }

  for(; k<nX && listDouble.size(); k++,iList++)
  {
      //cout<<endl<<"3 DrawPoligonMemFull::draw(QPainter &p) k="<<k<<flush;
      if (iList==listDouble.begin())
          x0=(xBeg+Dx*k-xmin)*nx/sizex+ix;
      //cout<<endl<<"30 DrawPoligonMemFull::draw(QPainter &p) listDouble.count()="<<listDouble.count()<<flush;
      x1=(xBeg+Dx*((*iList)->getNX()+1)-xmin)*nx/sizex+ix;
      //cout<<endl<<"31 DrawPoligonMemFull::draw(QPainter &p)"<<flush;

      if (x1<ix && x0<ix || x1>ix+nx && x0>ix+nx)
      {
          x0=x1;
          continue;
      }
      else
      {
          if (x1<ix) x1=ix;
          if (x0<ix) x0=ix;
          if (x1>=ix+nx) x1=ix+nx-1;
          if (x0>=ix+nx) x0=ix+nx-1;
      }
      if (x0==x1)
      {
          continue;
      }
      y0=-(yBeg-ymin)*ny/sizey+iy;
      //cout<<endl<<"32 DrawPoligonMemFull::draw(QPainter &p)"<<flush;
      //if (keyOrNotROP)
      //    p.setCompositionMode(QPainter::RasterOp_NotSourceXorDestination);
      QImage pix(x1-x0,ny,QImage::Format_ARGB32_Premultiplied);
      QPainter pp(&pix);
      //cout<<endl<<"33 DrawPoligonMemFull::draw(QPainter &p)"<<flush;
      double amp, ampTemp;
      amp=-1.;
      for(j=0,iY=(*iList)->getY(); j<(*iList)->getN(); j++, iY++)
      {
          //cout<<endl<<"4 DrawPoligonMemFull::draw(QPainter &p) j="<<j<<flush;
          y1=-(yBeg+Dy*j-ymin)*ny/sizey+iy;
          if (y1>iy && y0>iy || y1<iy-ny && y0<iy-ny)
              y0=y1;
          else
          {
              ampTemp=(*iY-minAmp)/normAmp;
              if (ampTemp<.0)
                  ampTemp=.0;
              else
                  if (ampTemp>1.)
                      ampTemp=1.;
              if (y1>=iy) y1=iy;
              if (y0>=iy) y0=iy;
              if (y1<=iy-ny) y1=iy-ny+1;
              if (y0<=iy-ny) y0=iy-ny+1;
    
              if (y0!=y1)
              {
                  if (amp<.0)
                      amp=ampTemp;
                  if (keyColor)
                  {
                    color=510*amp;
                    if (color<0)
                      color=0;
                    if (color>510)
                      color=510;
                    color&=0x1ff;
                    if (color>255)
                    {
                        colorPoint=QColor(color-255,510-color,0);
                    }
                    else
                    {
                        colorPoint=QColor(0,color,255-color);
                    }
                  }
                  else
                  {
                    color=255*amp;
                    if (color<0)
                      color=0;
                    if (color>255)
                      color=255;
                    color&=0x1ff;
                    colorPoint=QColor(255-color,255-color,255-color);
                  }

                  if (y0>y1)
                      rFill.setCoords(x0-x0,y1-iy+ny,x1-x0,y0-iy+ny);
                  else
                      rFill.setCoords(x0-x0,y0-iy+ny,x1-x0,y1-iy+ny);
                  //colorPoint.setAlpha(128);
                  pp.setBrush(colorPoint);
                  pen.setCapStyle(Qt::SquareCap);
                  //pp.setPen(pen);
                  pp.setPen(colorPoint);
                  if (x0>=ix && x1<ix+nx && y1<=iy && y0>iy-ny)
                  {
                      pp.drawRect(rFill);
                      pp.fillRect(rFill,colorPoint);
                  }
                  y0=y1;
                  amp=-1.;
              }
              else
                  if (amp<ampTemp)
                      amp=ampTemp;
          }
      }
      p.drawImage((int)x0,(int)(iy-ny),pix);
      x0=x1;
  }
  
  //p.setCompositionMode(QPainter::CompositionMode_SourceOver);

  keyPainter=true;
  return 0;
}

long DrawPoligonMemFull::drawVert(QPainter &p)
//
// ������� ������������� ��� �����������
//
{
  QPoint  point;
  QRect   rFill;
  QPen    pen=p.pen();
  long    i,j,k;
  QColor  colorPoint;
  list<ListDouble*>::iterator iList=listDouble.begin();
  double *iY;
  double X1,X2;

  if (!error || !listDouble.size())
      return 1;

  X1=(*listDouble.rbegin())->getX2()-(ymax-ymin);

  sizex=xmax-xmin;
  sizey=ymax-ymin;

  if (keyPainter)
  {
      iList=listDouble.begin();
      k=0;
  }
  else
  {
      iList=listDouble.end();
      iList--;
      k=nX-1;
  }

  keyCircle=false;
  kolOut=0;
  printf("\nfalse !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  //for(; k<nX && iList; k++,iList=listDouble.next())
  for(; k<listDouble.size(); k++,iList++)
  {
      //std::cout<<std::endl<<" k="<<k<<" X1="<<X1<<" listDouble.count()="<<listDouble.count()<<"  "<<(long)iList<<std::flush;
      //printf("\niList->getNX()=%d",iList->getNX());
      if (iList==listDouble.begin())
      {
          if (flagX)
          {
              X2=(*iList)->getX1();
              y0=-(X2-X1-ymin)*(ny-otst)/sizey+iy;
              //std::cout<<std::endl<<" k="<<k<<" X1="<<X1<<" listDouble.count()="<<listDouble.count()<<"  "<<(long)iList<<std::flush;
          }
          else
              y0=-(yBeg+Dy*k-ymin)*(ny-otst)/sizey+iy;
          if (!keyInvert)
              y0=ny-y0+otst;
      }

      if (flagX)
      {
          //std::cout<<std::endl<<" k="<<k<<" X1="<<X1<<" X2="<<X2<<" ddd="<<(bool)(listDouble.getFirst()==listDouble.getLast())<<std::flush;
          X2=(*iList)->getX2();
          y1=-(X2-X1-ymin)*(ny-otst)/sizey+iy;
      }
      else
          y1=-(yBeg+Dy*((*iList)->getNX()+1)-ymin)*(ny-otst)/sizey+iy;
      if (!keyInvert)
          y1=ny-y1+otst;
      
      //printf("\ny0=%d  y1=%d  %d  %d",y0,y1,iy,iy-ny);
      if ( !flagX && (keyInvert && (y1<iy-ny+otst || y0<iy-ny+otst) || !keyInvert && (y1>iy || y0>iy)) ||
            flagX && (!keyInvert && (y1<iy-ny+otst || y0<iy-ny+otst) || keyInvert && (y1>iy || y0>iy)) )
      {
          if (kolOut>1)
              keyCircle=true;
          kolOut++;
          //printf("\ntrue !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
      }
      //else
      //{
      //    keyCircle=false;
      //    printf("\nfalse !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
      //}

      if (y1>iy && y0>iy || y1<iy-ny+otst && y0<iy-ny+otst)
      {
          y0=y1;
          continue;
      }
      else
      {
          if (y1>=iy) y1=iy;
          if (y0>=iy) y0=iy;
          if (y1<=iy-ny+otst) y1=iy-ny+otst+1;
          if (y0<=iy-ny+otst) y0=iy-ny+otst+1;
      }
      if (y0==y1)
      {
          continue;
      }
      x0=(xBeg-xmin)*(nx-otst)/sizex+ix;

      //if (keyOrNotROP)
      //    p.setCompositionMode(QPainter::RasterOp_NotSourceXorDestination);

      QImage pix((nx-otst-1),labs(y0-y1),QImage::Format_ARGB32_Premultiplied);
      QPainter pp(&pix);

      double amp, ampTemp;
      amp=-1.;
      for(j=0,iY=(*iList)->getY(); j<(*iList)->getN(); j++, iY++)
      {
          x1=(xBeg+Dx*j-xmin)*(nx-otst)/sizex+ix;
          //printf("\nx0=%d  x1=%d",x0,x1);
          if (x1<ix && x0<ix || x1>ix+(nx-otst)-1 && x0>ix+(nx-otst)-1)
              x0=x1;
          else
          {
              ampTemp=(*iY-minAmp)/normAmp;
              if (ampTemp<.0)
                  ampTemp=.0;
              else
                  if (ampTemp>1.)
                      ampTemp=1.;
              if (x1<ix) x1=ix;
              if (x0<ix) x0=ix;
              if (x1>=ix+(nx-otst)-1) x1=ix+(nx-otst)-1;
              if (x0>=ix+(nx-otst)-1) x0=ix+(nx-otst)-1;
    
              if (x0!=x1)
              {
                  if (amp<.0)
                      amp=ampTemp;
                  if (keyColor)
                  {
                    color=510*amp;
                    if (color<0)
                      color=0;
                    if (color>510)
                      color=510;
                    color&=0x1ff;
                    if (color>255)
                    {
                        colorPoint=QColor(color-255,510-color,0);
                    }
                    else
                    {
                        colorPoint=QColor(0,color,255-color);
                    }
                  }
                  else
                  {
                    color=255*amp;
                    if (color<0)
                      color=0;
                    if (color>255)
                      color=255;
                    color&=0x1ff;
                    colorPoint=QColor(255-color,255-color,255-color);
                  }

                  if (y0>y1)
                      rFill.setCoords(x0-ix,y0-y0,x1-ix,y0-y1);
                  else
                      rFill.setCoords(x0-ix,y0-y0,x1-ix,y1-y0);
                  colorPoint.setAlpha(128);
                  pp.setBrush(colorPoint);
                  pen.setCapStyle(Qt::SquareCap);
                  //pp.setPen(pen);
                  //pp.setPen(colorPoint);
                  if (x0>=ix && x1<=ix+(nx-otst)-1 && y1<=iy && y0>iy-ny+otst)
                  {
                      pp.drawRect(rFill);
                      pp.fillRect(rFill,colorPoint);
                  }
                  x0=x1;
                  amp=-1.;
              }
              else
                  if (amp<ampTemp)
                      amp=ampTemp;
          }
      }
      if (keyInvert)
          p.drawImage((int)ix+1,(int)y1,pix);
      else
          p.drawImage((int)ix+1,(int)y0,pix);
      y0=y1;
  }
  
  //p.setCompositionMode(QPainter::CompositionMode_SourceOver);

  keyPainter=true;

  if (keyCircle)
  {
      kolOut--;
      for(int i=0; i<kolOut; i++)
      {
          if (!keyInvert)
              listDouble.pop_front();
          else
              listDouble.pop_back();
      }
      //printf("\ncount=%d",kolOut);
  }

  kolOut=listDouble.size();

  return 0;
}

void DrawPoligonMemFull::upDate()
{
  update();
}

void DrawPoligonMemFull::reDraw()
{
    repaint();
}

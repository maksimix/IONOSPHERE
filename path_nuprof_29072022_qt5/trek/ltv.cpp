#include "mytrek.h"

void MyTrek::ltv(double *x,
                 double *y0,
                 double *y1,
                 double *f0,
                 double *f1,
                 double *h,
                 int    n,
                 double e,
                 double eps)
/*******************************************************************/
/*     ФУНКЦИЯ ОСУЩЕСТВЛЯЕТ ОДИН ШАГ ИНТЕГРИРОВАНИЯ СИСТЕМЫ        */
/*     n ДИФ. УРАВНЕНИЙ ПЕРВОГО ПОРЯДКА МЕТОДОМ ЧЕТВЕРТОГО ПОРЯДКА */
/*     ПУТЕМ ПОСЛЕДОВАТЕЛЬНОГО УВЕЛИЧЕНИЯ ТОЧНОСТИ РЕЗУЛЬТАТА.     */
/*                                                                 */
/* x    -НЕЗАВИСИМАЯ ПЕРЕМЕННАЯ;                                   */
/* y0,f0 -НАЧАЛЬНЫЕ ЗНАЧЕНИЯ ФУНКЦИИ И ПРОИЗВОДНЫХ;                */
/* y1,f1 -КОНЕЧНЫЕ ЗНАЧЕНИЯ;                                       */
/* n    -ЧИСЛО УРАВНЕНИЙ;                                          */
/* h    -ШАГ ИНТЕГРИРОВАНИЯ, ОН ЖЕ ПОДБИРАЕТСЯ ПРОЦЕДУРОЙ ПО       */
/*       ПАРАМЕТРАМ e И eps, ТАК ЧТО ЛОКАЛЬНАЯ ОШИБКА СТАНОВИТСЯ   */
/*       БОЛЬШЕ e И МЕНЬШЕ eps;                                    */
/* func -УКАЗАТЕЛЬ НА ФУНКЦИЮ, ВЫЧИСЛЯЮЩУЮ ПРОИЗВОДНЫЕ.            */
/*                                                                 */
/*VGG                                                              */
/*******************************************************************/
{
  double y2[22],f2[22],r,x0;
  int    i,let;


      let=1;
      r=DBL_MAX;

      while(r>eps)
      {
          for(int i=0; i<n; i++)
            y2[i]=y0[i]+*h*f0[i]/3.;
          x0=*x+*h/3.;

          if (func(x0,y2,f2,n))
            {
              *h *=.5;
              let=0;
              continue;
            }

         for(int i=0; i<n; i++)
            y2[i]=y0[i]+*h*(f0[i]+f2[i])/6.;

          if (func(x0,y2,f2,n))
            {
              *h *=.5;
              let=0;
              continue;
            }

          for(int i=0; i<n; i++)
            y2[i]=y0[i]+*h*(f0[i]+3.*f2[i])/8.;
          x0=*x+*h*.5;

          if (func(x0,y2,f1,n))
            {
              *h *=.5;
              let=0;
              continue;
            }

          for(int i=0; i<n; i++)
            y2[i]=y0[i]+*h*(f0[i]-3.*f2[i]+4.*f1[i])*.5;
          x0=*x+*h;

          if (func(x0,y2,f2,n))
            {
              *h *=.5;
              let=0;
              continue;
            }

          r=.0;
          for(int i=0; i<n; i++)
            {
              y1[i]=y0[i]+*h*(f0[i]+4.*f1[i]+f2[i])/6.;
              r=(r>fabs(y1[i]-y2[i]))? r : fabs(y1[i]-y2[i]);
            }

          if (r>eps || func(x0,y1,f1,n))
            {
              *h *=.5;
              let=0;
              continue;
            }

      }


  if (r<e && let) *h *=2.;
  *x=x0;

  return;

} /* ltv */
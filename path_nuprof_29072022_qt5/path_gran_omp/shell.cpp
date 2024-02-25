#include <math.h>

void shell(double *a1, double *a2, double *a3,
           double *a4, double *a5, double *a6,
           double *a7, double *a8, double *a9,
           unsigned long *a10, long n)
/***************************************************************/
/* Функция предназначена для упорядочивания массива a1 по      */
/* убыванию его элементов методом Шелла, одновременно          */
/* переставляются элементы сопутствующих массивов a2,a3,a4,a5  */
/*                                                             */
/* n - количество элементов в массивах.                        */
/*                                                             */
/*VGG  версия 06.03.92                                         */
/***************************************************************/

{
  long    i,j,l,nd,d;
  unsigned long y;
  double x;

  d=1;
  while (d<=n) d *=2;
  d=(d-1)/2;
  while (d>0)
    {
      nd=n-d;
      for(i=0; i<nd; i++)
        {
          j=i;
          do
            {
              l=j+d;
              if (*(a1+l)>*(a1+j))
                {
                  x=*(a1+j);
                  *(a1+j)=*(a1+l);
                  *(a1+l)=x;
                  x=*(a2+j);
                  *(a2+j)=*(a2+l);
                  *(a2+l)=x;
                  x=*(a3+j);
                  *(a3+j)=*(a3+l);
                  *(a3+l)=x;
                  x=*(a4+j);
                  *(a4+j)=*(a4+l);
                  *(a4+l)=x;
                  x=*(a5+j);
                  *(a5+j)=*(a5+l);
                  *(a5+l)=x;
                  x=*(a6+j);
                  *(a6+j)=*(a6+l);
                  *(a6+l)=x;
                  x=*(a7+j);
                  *(a7+j)=*(a7+l);
                  *(a7+l)=x;
                  x=*(a8+j);
                  *(a8+j)=*(a8+l);
                  *(a8+l)=x;
                  x=*(a9+j);
                  *(a9+j)=*(a9+l);
                  *(a9+l)=x;
                  y=*(a10+j);
                  *(a10+j)=*(a10+l);
                  *(a10+l)=y;
                }
              j -=d;
            }
          while(j>=0);
        }
      d=(d-1)/2;
    }
} /* shell */
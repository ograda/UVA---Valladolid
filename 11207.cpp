//Anderson Zudio de Moraes
//AC em 26/11/2012

#include<stdio.h>
#include<stdlib.h>
double min(double a,double b)
{
 if(a<b) return a;
 else
  return b;
}
main()
{
 int n;
 while(scanf("%d",&n)==1&&n!=0)
  {
   int a,resp;
   double max=0.0,t1,t2,t3;
   for(a=0;a<n;a++)
    {
     double w,h;
     scanf("%f %f",&w,&h);
     t1=min(w/2,h/2);
     t2=min(w/4,h);
     t3=min(w,h/4);
     if(t1>max)
      {max=t1;resp=a;}
     if(t2>max)
      {max=t2;resp=a;}
     if(t3>max)
      {max=t3;resp=a;}
    }
    printf("%d\n",resp+1);
  }
 return 0;
}

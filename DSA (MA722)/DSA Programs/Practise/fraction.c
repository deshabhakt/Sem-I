#include<stdio.h>
#include<math.h>
#define M acos(-1.0)
int main()
{
    double a=(22.0/7);
    printf(">%1.51f \n",a);
    printf(">%1.51f \n",M);
    a =(3.3/2);
    printf(">%1.50f \n",a);
    a = (5.0/3);
    printf(">%1.60f \n",a);
    return 0;
}
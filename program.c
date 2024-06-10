#include <stdio.h>
int main(){
printf("TESTTEXTOUTPUT\n");
double A=1.000000;
double B=10.000000;
double C=9.000000;
double D=0;
C=A+B*A-B;
printf("IIIIIIIIIIIIIIIIIIIIII\n");
printf("A=%f\n",A);
printf("B=%f\n",B);
printf("C=%f\n",C);
printf("IIIIIIIIIIIIIIIIIIIIII\n");
if (A != B)
{
printf("BRNOTEQUAL\n");
printf("A=%f\n",A);
}
else
{
printf("BREQUAL\n");
printf("B=%f\n",B);
}
double E=10.000000;
double L = 0;
while(L!=E)
{
++L;
printf("L=%f\n",L);
}
}
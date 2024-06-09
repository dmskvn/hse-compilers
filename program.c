#include <stdio.h>
int main(){
printf("TESTTEXTOUTPUT");
double A=1.000000;
double B=10.000000;
double C=9.000000;
double D=0;
C=A+B*A-B;
printf("IIIIIIIIIIIIIIIIIIIIII");
printf("A=%f",A);
printf("B=%f",B);
printf("C=%f",C);
printf("IIIIIIIIIIIIIIIIIIIIII");
if (A != B)
{
printf("BRNOTEQUAL");
printf("A=%f",A);
}
else
{
printf("BREQUAL");
printf("B=%f",B);
}
double E=10.000000;
double L = 0;
while(L!=E)
{
++L;
printf("L=%f",L);
}
}
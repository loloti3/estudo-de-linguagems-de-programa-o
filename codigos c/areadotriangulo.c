#include<stdio.h>
#include<math.h>
void calculac2(float h,float c1,float *c2){
 *c2=sqrt((pow(h,2)-pow(c1,2)));
}
float area_triangulo (float c1 , float c2){
  float a;
  a=(c1*c2)/2;
  return a;
}
int main (){
  float h,c1,c2,a;
  scanf("%f%f",&h,&c1);//pegar os valores calcular o C2
  calculac2(h,c1,&c2);
  printf("H=%.2f\nc1=%.2f\nc2=%.2f\n",h,c1,c2);
  a=area_triangulo(&c1,&c2);
  printf("a=%.2f",a);
  return 0;
}
#include <stdio.h>
//contar quantos planaltos
int main (){
  int num=0,j,numcompara,cont=0,cont2=0;
  scanf("%d",&num);
  for(j=0;j<4;j++){
    numcompara=num;
    scanf("%d",&num);
    if(numcompara==num)
      cont++;
    else
      cont=0;
    if(cont==1)
      cont2++;
  }
  printf("%d",cont2);
}
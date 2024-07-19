#include<stdio.h>
# define lim 2
# define col 2

int main (){
  int j,num,i;
  float V[lim][col],soma=0;
  char x;
  for (j=0;j<lim;j++){
    for(i=0;i<col;i++){
      scanf("%f",&V[j][i]);
    }
  }
  scanf("%d",&num);
  scanf(" %c",&x);
    for(j=0;j<lim;j++){
      soma+=V[j][num];
    }
  if(x=='S')
  printf("soma das colunas:%.1f\n",soma);
  if(x=='M')
  printf("media das colunas:%.1f\n",soma/lim);
  return 0;
  
}
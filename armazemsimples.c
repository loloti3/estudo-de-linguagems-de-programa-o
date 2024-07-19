#include<stdio.h>
#define lim 3
#define col 4
int main (){
 int  prod [lim][col],soma=0;
 float preco[col],precoprod,precoarma;
 int j,i;
  printf("digite a quantidade de produtos:\n");
  for(j=0;j<lim;j++){
    printf("Armazem %d:\n",j+1);
    for(i=0;i<col;i++){
     printf("Produto %d:",i+1);
     scanf("%d",&prod[j][i]);
    }
  }
  printf("\ndigite os precos\n");
  for(j=0;j<col;j++){
    printf("Produto %d:",j+1);
    scanf("%f",&preco[j]);
  }
  printf("Estoque:\n");
  for(i=0;i<col;i++){
    printf("produto %d:\n",i+1);
    for(j=0;j<lim;j++){
      printf("Armazem %d: %d\n",j+1,prod[j][i]);
    }  
  }
  printf("Quantidade total de produtos por armazem:\n");
  for(i=0;i<lim;i++){
    soma=0;
    for(j=0;j<col;j++){
      soma+=prod[i][j];
    } 
    printf("Armazem %d: %d\n",i+1,soma);
  }
  printf("Quantidade total de produtos por tipo:\n");
  for(i=0;i<col;i++){
    soma=0;
    for(j=0;j<lim;j++){
      soma+=prod[j][i];
    } 
    printf("produto %d: %d\n",i+1,soma);
  }
  printf("custo total por armazem:\n");
  for(i=0;i<lim;i++){
    precoarma=0;
    for(j=0;j<col;j++){
      precoarma+=preco[j]*prod[i][j];
    } 
    printf("Armazem %d: %.2f\n",i+1,precoarma);
  }
  printf("custo total por Produto:\n");
  for(i=0;i<col;i++){
    precoprod=0;
    for(j=0;j<lim;j++){
      precoprod+=preco[i]*prod[j][i];
    } 
    printf("produto %d: %.2f\n",i+1,precoprod);
  } 
  return 0;
}
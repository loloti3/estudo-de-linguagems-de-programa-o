#include<stdio.h>
#include<string.h>
int main (){
  char vet[5],v[5];
  int a,b,j,i,cont=0;
  scanf("%s%s",vet,v);
  b=strlen(vet);
  a=strlen(v);
    if(b!=a){
      printf("\n");//saber que passou
      if(strcmp(vet,v)==0)
      printf("%s e %s sao anagramas",vet,v);
    }else{
      //printf("\n");
      for(j=0;j<a;j++){
        //printf("\n");
        cont=0;
        for(i=0;i<a;i++){
        if(vet[j]==v[i])
          cont++;
        }
        if(cont>1 || cont==0){
          break;
        }
      }
    }
  if(cont==1)
    printf("%s e %s sao anagramas",vet,v);
  return 0;
}
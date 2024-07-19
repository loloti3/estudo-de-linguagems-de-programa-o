#include<stdio.h>
#include<string.h>
int main (){
  char vet[30],vet1[30],vet2[30];
  int j,i,a,d=0,b;
  printf("digite duas palavras\n");
  scanf("%s%s",vet,vet1);
  strcpy(vet2,vet1);
  a=strlen(vet);
  b=strlen(vet1);
  if(b!=a){//retirar logo pelo tamanho
    d++;
  }
  else{
    for(j=0;j<a;j++){ //vet=c
      for(i=0;i<a;i++){//vet1=a,vet1=s,vet1=c
        if(vet[j]==vet1[i]){//vet=c vet1=c
          //vet2[d]=vet1[i];//vet2=c
          vet1[i]='0';
          break;
        }
      }
    }
    for(j=0;j<a;j++){
      if(vet1[j]!='0'){
        d++;
        break;
      }    
    }
  }
  printf("%s\n",vet1);//ter certeza
  if(d==0)
    printf("%s e %s sao anagramas",vet,vet2);
  else 
    printf("%s e %s nao sao anagramas",vet,vet2);
  return 0;
}
#include <stdio.h>
#include <string.h>
/*1-ler quantos RAs
  2-ler o RA
  3-verificar se o RA é valido
  4-printar a senha 
*/
int main() {
char vet[101];
int j,n,i,cont,v;
  scanf("%d",&n);
  for(j=0;j<n;j++){
    scanf("%s",vet);
    cont=strlen(vet);
    if(cont!=20|| vet[0]!='R' || vet[1]!='A'){
      printf("INVALID DATA\n");
    }
    else{
    v=0;
    for(i=2;i<20;i++){
      if(vet[i]!=48)
        v=1;
      if(v){
      printf("%c",vet[i]);
      }
    }
    printf("\n");  
  }
  }
    return 0;
}

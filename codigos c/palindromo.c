#include<stdio.h>
#include<string.h>
int alindromo(char v[]){
  char v2[21];
  int j,a,b,cont=1;
  a=strlen(v);
  strcpy(v2,v);
  b=a;
  for(j=0;j<b;j++){
    a=a-1;
    /*printf("v= %c\n",v[j]);
    printf("v2= %c\n",v2[a]); */
    if(v[j]!=v2[a]){
      cont=0;
      break;
    } 
  }
  return cont;
}
int main (){
  char v[21];
  int a;
  scanf("%s",&v);
  a=alindromo(v);
  printf("%d",a);
  return 0;
}
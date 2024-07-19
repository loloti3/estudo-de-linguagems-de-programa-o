

#include<stdio.h>
int main(){
  int j,num,numantes,numdepois;
  printf("hello world\n");
  //imprimir fibonacci 1,1,2,3,5,8....
  num=1;
  numantes=1;
  numdepois=0;
  for(j=0;j<10;j++){
    num=numantes+numdepois;//num=1,numa=1,numd=0
    numdepois=numantes;//numd=1
    numantes=num;//numa=1
    printf("%d\n",num);
  }
  return 0;
}
#include<stdio.h>

int main (){
 int m,n,j,i;
  scanf("%d%d",&m,&n);
  int matriz[m][n];
  for(j=0;j<m;j++){
    for(i=0;i<n;i++){
      scanf("%d",&matriz[j][i]);
      printf("%d",matriz[j][i]);
    }
  }
  return 0;
}
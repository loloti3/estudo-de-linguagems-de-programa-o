#include <stdio.h>
void func1 (int vet1[][4]){
     int i,j;
    for(j=0;j<4;j++){
        printf("Produto %d\n",j+1);
            for(i=0;i<3;i++){
                printf("Armazem%d :%d\n",i+1,vet1[i][j]);
          }       
    }
 }
 void func2 (int vet1[3][4]){
    int i,j;
    for(i=0;i<3;i++){
        printf("Armazem %d\n",i+1);
        for(j=0;j<4;j++){
            printf("Produto %d: %d\n",j+1,vet1 [i][j]);
       }
    }
 }
 void func3 (int vet1[3][4]){
    int soma,i,j;
     for(i=0;i<3;i++){
        soma=0;
        for(j=0;j<4;j++){
           soma=soma+vet1[i][j];
            if(j==3)
               printf("Armazem %d:%d\n",i+1,soma);
        }
     }
 }
 void func4 (int vet1[3][4]){
     int soma1,i,j;
      for(j=0;j<4;j++){
         soma1=0;
         for(i=0;i<3;i++){
                  soma1=soma1+vet1[i][j];
                if(i==2){
                    printf("produto %d:%d\n",j+1,soma1);
                }
            }
      }
 }
 void func5 (int vet1[3][4],float vet2[4]){
     int i,j;
     float soma2;
          for(i=0;i<3;i++){
              soma2=0;
              for(j=0;j<4;j++){
                  soma2+=vet1[i][j]*vet2[j];
                }
            printf("Armazem %d:R$%.2f\n",i+1,soma2);
          }
 }
 void func6 (int vet1[3][4],float vet2[4]){
     float soma2;
     int i,j;
          for(j=0;j<4;j++){
              soma2=0;
              for(i=0;i<3;i++){
                  soma2+=vet1[i][j]*vet2[j];
              }
              printf("Produto %d:R$%.2f\n",j+1,soma2);
          }
 }
 void func7 (int vet1[3][4]){
 int n,m,i,j,lc;
 char x;
        printf("digite o armazem e o produto que deseja alterar\n");
        scanf("%d%d",&n,&m);
        while((n<1||n>3)||(m<1||m>4)){
        printf("resposta invalida\ndigite o armazem e o produto que deseja alterar novamente\n");
        scanf("%d%d",&n,&m);
        }
        printf("quantidade atual do produto:%d\n",vet1[n-1][m-1]);
        printf("Deseja alterar os valores:\nS-sim\nN-nao\n");
        scanf(" %c",&x);
        if(x=='s'){
              printf("digite o novo valor\n");
              scanf("%d",&lc);
              vet1[n-1][m-1]=lc;
               }
          }
 void func8 (int vet1[3][4],float vet2[4]){
 int i,p;
 char z;
 float r;
printf("digite o numero do produto que deseja alterar\n");
scanf("%d",&p);
  while(p<0||p>4){
  printf("valor invalido\ndigite o numero do produto novamente\n");
  scanf("%d",&p);
  }
      printf("valor atual do produto:%.2f\n ",vet2[p-1]);
      printf("Deseja alterar o valor\n S-sim\n N-nao\n ");
      scanf(" %c",&z);
        if (z=='s'){
        printf("digite o novo preco do produto:\n");
        scanf("%f",&r);
          while(r<0){
          printf("valor invalido\ndigite um novo valor maior ou igual a zero");
          scanf("%f",&r);
          }
           vet2[p-1]=r;
           }
        }
 void func9 (int vet1[3][4]){
    int i,j;
    for(i=0;i<3;i++){
        printf("Digite o estoque:\nArmazem %d\n",i+1);
        for(j=0;j<4;j++){
            printf("Produto %d :",j+1);
            scanf("%d",&vet1[i][j]);

         }
    }
 }
 void func10 (float vet2[4]){
 int j;
 printf("digite o preco R$\n");
    for (j=0;j<4;j++){
        printf("produto %d: ",j+1);
        scanf ("%f",&vet2[j]);
    }
 }
int main (){
    float vet2[4];
    int vet1[3][4],a;
    func9(vet1);
    func10(vet2);
   while(1){
   printf("MENU\n1 - Estoque por produto\n2 - Estoque por armazem\n3 - Total em cada armazem\n4 - Total de cada produto\n5 - Custo total por armazem\n6 - Custo total por produto\n7 - Alterar quantidade de um produto\n8 - Alterar custo de um produto\n0 - Sair\n");
   scanf ("%d",&a);
       if(a==1){
       func1(vet1);
       }
       if(a==2){
          func2(vet1);
       }
        if(a==3){
             func3(vet1);
        }
        if(a==4){
              func4(vet1);
         }
        if(a==5){
        func5(vet1,vet2);
        }
        if(a==6){
        func6(vet1,vet2);
        }

        if(a==7){
        func7(vet1);
        }

        if(a==8){
        func8(vet1,vet2);
        }
        if(a==0){
        break;
        }
}
return 0;}

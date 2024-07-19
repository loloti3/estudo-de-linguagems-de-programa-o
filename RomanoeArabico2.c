#include<stdio.h>
#include<string.h>
//Leticia Lopes de Olivera
int romano(char vet[],int *z){
  int a=0;
  switch(vet[*z]){
    case('M'):
    a=1000;
    break;
    case('D'):
    a=500;
    break;
    case('C'):
    a=100;
    break;
    case('L'):
    a=50;
    break;
    case('X'):
    a=10;
    break;
    case('V'):
    a=5;
    break;
    case('I'):
    a=1;
    break;
  }
  return a;
}
int romano2(char vet[]){
  int a,anterior,c=0,j,d=0;
  int roma=0;
  for(j=0;vet[j]!='\0';j++){
    c=j+1;
    a=romano(vet,&j);
    anterior=romano(vet,&c);
    if(anterior>a)
      d=d+a;
    else
    roma=roma+a;
  }
  roma=roma-d;
  return roma;
}
void arabico(char w[],int *num, int flag){
   int d=0;
    int num1 = *num;
    while(*num != 0){
        if (*num >= 1000){
           *num=*num-1000;
           w[d]='M';
           d++;
          w[d]='\0';
        }
        else if (*num >= 900){
           *num=*num-900;
           w[d]='C';
           d++;
          w[d]='M';
           d++;
          w[d]='\0';
        }        
        else if (*num >= 500){           
           *num=*num-500;
           w[d]='D';
            d++;
          w[d]='\0';
        }
        else if (*num >= 400){
           *num=*num-400;
           w[d]='C';
            d++;
           w[d]='D';
            d++;
          w[d]='\0';
        }
        else if (*num >= 100){
           *num=*num-100; 
            w[d]='C';
            d++;
          w[d]='\0';
        }
        else if (*num >= 90){
           *num=*num-90;
            w[d]='X';
            d++;
            w[d]='C';
            d++;
          w[d]='\0';
        }
        else if (*num >= 50){
          *num=*num-50;
            w[d]='L';
            d++;
          w[d]='\0';
        }
        else if (*num >= 40){           
           *num=*num-40;
           w[d]='X';
            d++;
          w[d]='L';
            d++;
          w[d]='\0';
        }
        else if (*num >= 10){
           *num=*num-10; 
           w[d]='X';
            d++;
          w[d]='\0';
        }
        else if (*num >= 9){
           *num=*num-9;
          w[d]='I';
            d++;
          w[d]='X';
            d++;
          w[d]='\0';
        }
        else if (*num >= 5){
           *num=*num-5;
           w[d]='V';
            d++;
          w[d]='\0';
        }
        else if (*num >= 4){
           *num=*num-4;
             w[d]='I';
             d++;
             w[d]='V';
             d++;
          w[d]='\0';
        }
        else if (*num >= 1){
           *num=*num-1;
            w[d]='I';
            d++;
          w[d]='\0';
        }
    }
    if(flag){
      printf("%d = %s\n\n", num1, w);
    }
}
int main (){ 
  char vet[30],vet1[30],vet2[30];
  int menu = -1,j,roma,num1,z,d,regras;
  while(menu != 0){
    z=0;
    printf("1 - Converter para algarismos romanos\n2 - Converter para algarismos arabicos\n0 - Sair\n");
    scanf("%d",&menu);
    if(menu > 2 || menu <= 0)
      break;
    if(menu==2){
      printf("Digite o numero romano que deseja saber o valor: ");
      scanf("%s",vet);
      //strupr(vet);
      if(strlen(vet)>30){
        printf("\nvalor invalido a quantidade maxima de letras eh 30\n"); 
        z=2; regras=1;
         printf("Isso pode te ajudar:\n\n");
      }
      else {
       for(j=0;vet[j]!='\0';j++){
           if(romano(vet,&j)==0){
              printf("%c - Nao exite este algarismo Romano.\n",vet[j]);
              z=1;
            }else
            printf("%c - %d\n",vet[j],romano(vet,&j));
        }
        printf("\n"); 
      }
      if(z==1){
        printf("O valor %s e invalido\n",vet);z=1;
        printf("Deseja ver a tabela de numeros romanos e algumas regras ? se sim digite 1, se nao digite outro valor.\n");
        scanf("%d",&regras);
        printf("\n");
      }
      else{
        roma=romano2(vet);
        d=roma;
        arabico(vet1,&d, 0);
      }
      if (strcmp(vet,vet1)!=0 && z==0){
        z=1;
        printf("O valor %s e invalido\nA forma coreta de %d em romano eh %s\n",vet,roma,vet1);
        printf("Deseja ver a tabela de numeros romanos e algumas regras ? se sim digite 1, se nao digite outro valor.\n");
        scanf("%d",&regras);
        printf("\n");
      }
      if(regras==1)
          printf("Tabela de valores:\n-----------------\n| I - 1 | V - 5 |\n-----------------\n| X- 10 | L- 50 |\n-----------------\n| C-100 | D-500 |\n-----------------\n| M - 1000      |\n-----------------\nRegras:\n1-Os numerais romanos sao escritos da esquerda para a direita, do maior para o menor valor.\n2-Quando um numeral menor precede um numeral maior, voce subtrai o valor do numeral menor do valor do numeral maior.Exemplo:IV:V(5)-I(1)=4\n3-Apenas as letras M, X e I podem se repetir em uma sequencia de ate 3 elementos seguidos.\n4-Apenas as letras C, X e I podem anteceder letras de valores maiores que elas.\n5-O numeral romano maximo que pode ser representado e 3999 (MMMCMXCIX).\nSelecione a opção 2 do menu e tente novamente:)\n\n");
      if(z==0){
        roma=romano2(vet);
        printf("%s = %d\n",vet,roma);
      }
    }
    if(menu==1){
      printf("Digite o numero que deseja saber a forma romana: ");
      while (scanf("%d",&num1)==0 || (num1<1 || num1>3999)){
        scanf("%*[^\n]");
        printf("Valor invalido :(\nDigite outro valor.\n");
      }
      d=num1;
      arabico(vet2,&num1, 1);
    }    
  }
  return 0;
}
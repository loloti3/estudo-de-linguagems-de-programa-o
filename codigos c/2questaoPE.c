
#include <stdio.h>
#include <string.h>

void retiraCaracter(char vet[], char c){
    int i, j=0;
    for (i=0; i<strlen(vet); i++){
        if (vet[i] != c){
            vet[j] = vet[i]; 
            j++;
        }
    }
    vet[j] = '\0';
}

int main() {
    // Write C code here
    char palavra[31],ca;
    printf("Digite a palavra: ");
    scanf("%s", palavra);
    printf("Digite o caractere: ");
    scanf(" %c", &ca);
    retiraCaracter(palavra, ca);
    printf("%s", palavra);

    return 0;
}
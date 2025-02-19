#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>

// Declaração das funções. Aqui acho possível ele perguntar sobre void e int e sua diferença na função e também pq eu declarei ela dessas formas, achei que ficaria mais legível
//caso fossem declaradas assim no início, além de deixar mais claro o tipo de dado que ela vai retornar
int binDec(long long);
int octDec(int);
int hexDec(char*);
void decBin(int);
void decOct(int);
void decHex(int);

int main() {
    setlocale(LC_ALL, "Portuguese");
    int casos, num;
    char binary[100], *endptr;
    
    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("1. Decimal para Binario\n");
        printf("2. Decimal para Octal\n");
        printf("3. Decimal para Hexadecimal\n");
        printf("4. Binario para Decimal\n");
        printf("5. Octal para Decimal\n");
        printf("6. Hexadecimal para Decimal\n");
        printf("7. Sair\n");
        printf("Opcao: ");
        scanf("%d", &casos);
        
        switch (casos) {
            case 1:
                printf("Digite um numero decimal: ");
                scanf("%d", &num);
                decBin(num);
                break;
            case 2:
                printf("Digite um numero decimal: ");
                scanf("%d", &num);
                decOct(num);
                break;
            case 3:
                printf("Digite um numero decimal: ");
                scanf("%d", &num);
                decHex(num);
                break;
            case 4:
                printf("Digite um numero binario: ");
                scanf("%s", binary);
                printf("Decimal: %d\n", binDec(strtol(binary, &endptr, 2)));
                break;
            case 5:
                printf("Digite um numero octal: ");
                scanf("%o", &num);
                printf("Decimal: %d\n", num);
                break;
            case 6:
                printf("Digite um numero hexadecimal: ");
                scanf("%x", &num);
                printf("Decimal: %d\n", num);
                break;
            case 7:
                exit(0);
            default:
                printf("Opcao invalida!\n");
        }
    }
    system("pause");
    return 0;
}


// A partir daqui que as funções aparecem de fato, o cálculo não é muito diferente do que a gente faz na mão

int binDec(long long n) {
    int dec = 0, i = 0, resto;
    while (n != 0) {
        resto = n % 10;
        n /= 10;
        dec += resto * pow(2, i);
        ++i;
    }
    return dec;
}

int octDec(int oct) {
    int dec = 0, i = 0;
    while (oct != 0) {
        dec += (oct % 10) * pow(8, i);
        ++i;
        oct /= 10;
    }
    return dec;
}

int hexDec(char* hex) {
    int dec = 0, i = 0;
    while (hex[i] != '\0') {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec += (hex[i] - '0') * pow(16, strlen(hex) - i - 1);
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec += (hex[i] - 'A' + 10) * pow(16, strlen(hex) - i - 1);
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            dec += (hex[i] - 'a' + 10) * pow(16, strlen(hex) - i - 1);
        }
        ++i;
    }
    return dec;
}

void decBin(int num) {
    int bin[32], i = 0;
    while (num > 0) {
        bin[i] = num % 2;
        num /= 2;
        ++i;
    }
    printf("Binario: ");
    for (int j = i - 1; j >= 0; --j) {
        printf("%d", bin[j]);
    }
    printf("\n");
}

void decOct(int num) {
    printf("Octal: %o\n", num);
}

void decHex(int num) {
    printf("Hexadecimal: %X\n", num);
}
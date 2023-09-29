#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char * decimalToAnyBase(int decimalNumber, int base);
char * reverse(char * s);
char * concat(char * str1, char * str2);
int anyBaseToDecimal(char * number, int base);
int count(char * teste);
char * toHexDigit(int number);
int toDecNumber(char hexDigit);

int main(){
    int choice;
    int base;

    do{
        printf("Escolha a base default:\n");
        printf("0 - Encerrar\n");
        printf("1 - Decimal\n");
        printf("2 - Hexadecimal\n");
        printf("3 - Octal\n");
        scanf("%d", &choice);

        switch(choice){
            case 0:
                return 0;
                break;
            case 1:
                base = 10;
                break;
            case 2:
                base = 16;
                break;
            case 3:
                base = 8;
                break;
            default:
                system("cls");
                printf("Escolha invalida.\n\n");
                continue;
        }

        int secondchoice = 0;

        do{
            system("cls");
            printf("Digite o numero para converter: (negativo para voltar)");
            scanf("%d", &secondchoice);

            if(secondchoice < 0)
                break;

            switch(base){
            case 10:
                printf();
                printf();
                break;
            case 16:
                printf();
                printf();
                break;
            case 8:
                printf();
                printf();
                break;
        }

        }while(secondchoice >= 0);

        system("cls");
    }while(choice != 0);

    char * converted = decimalToAnyBase(1000, 8);
    printf("%s\n", converted);

    //int convertedDecimal = anyBaseToDecimal("3E8", 16);
    //printf("%d", convertedDecimal);

    free(converted);

    return 0;
}

char * decimalToAnyBase(int decimalNumber, int base){ 
    char * converted = NULL;
    int integerDivision = decimalNumber;

    do{
        int rest = integerDivision % base;
        integerDivision = integerDivision / base;

        if(base == 16 && rest > 9){
            char * number = toHexDigit(rest);
            converted = concat(converted, number);
            free(number);
        }
        else{
        char intToStr[50];
        sprintf(intToStr, "%d", rest);
        converted = concat(converted, intToStr);
        }      
    }while(integerDivision != 0);

    return reverse(converted);
}

char * reverse(char * s)
{
    int length = count(s);
    char * aux = malloc(sizeof(char) * length+1);
    int auxInt = 0;

    for(int i=length-1;i>=0;i--){
        aux[auxInt] = s[i];
        auxInt++;
    }

    aux[auxInt] = '\0';

    return aux;
}

char * concat(char * str1, char * str2){
    int count;

    if(str1 == NULL){
        count = 0;
        str1 = realloc(str1, sizeof(char) * strlen(str2));
    }
    else{
        count = strlen(str1);
    	str1 = realloc(str1, sizeof(char) * (strlen(str1)+strlen(str2)));
    }
    
    for(int i=0; str2[i] != '\0';i++){

        str1[count] = str2[i];
        count++;
    }

    str1[count] = '\0';

    return str1;
}

int anyBaseToDecimal(char * number, int base){
    char * numberAux = reverse(number);

    int converted = 0;
    int aux = 0;

    for(int i=0;numberAux[i] != '\0'; i++)
    {
        int aux2;
        if(base == 16 && numberAux[i] >= 65 && numberAux[i] <= 70)
            aux2 = toDecNumber(numberAux[i]);
        else
            aux2 = numberAux[i] - '0';
        converted += (int)((aux2) * pow(base, aux));
        aux++;
    }

    return converted;
}

int count(char * teste){
    int sum = 0;

    for(int i=0;teste[i]!='\0';i++)
        sum++;

    return sum;
}

char * toHexDigit(int number){
    char * numberAux = malloc(sizeof(char) * 2);

    numberAux[1] = '\0';

    switch(number){
        case 10:
            numberAux[0] = 'A';
            break;
        case 11:
            numberAux[0] = 'B';
            break;
        case 12:
            numberAux[0] = 'C';
            break;
        case 13:
            numberAux[0] = 'D';
            break;
        case 14:
            numberAux[0] = 'E';
            break;
        case 15:
            numberAux[0] = 'F';
            break;
    }

    return numberAux;
}

int toDecNumber(char hexDigit){
    switch(hexDigit){
        case 'A':
            return 10;
        case 'B':
            return 11;
        case 'C':
            return 12;
        case 'D':
            return 13;
        case 'E':
            return 14;
        case 'F':
            return 15;
    }
}
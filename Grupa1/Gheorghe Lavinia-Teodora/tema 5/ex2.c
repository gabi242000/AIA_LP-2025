#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s[101];
int p;

void cripteaza(char s[], int key) {
    char *cuv, cezar[101] = "";
    cuv = strtok(s, " ");

    printf("Textul criptat cu ajutorul codului Cezar este:\n");
    while(cuv != NULL) {
        for(int i = 0; cuv[i] != '\0'; i++) {
            if((islower(cuv[i]) && (int)cuv[i] + key > (int)'z') || (isupper(cuv[i]) && (int)cuv[i] + key > (int)'Z'))
                 cuv[i] = (char)((int)cuv[i] - 26 + key);
            else cuv[i] = (char)((int)cuv[i] + key);
        }
        printf("%s ", cuv);
        strcat(cezar, cuv);
        strcat(cezar, " ");
        cuv = strtok(NULL, " ");
    }
    strcpy(s, cezar);
}

void decripteaza(char s[], int key) {
    char *cuv, decript[101] = "";
    cuv = strtok(s, " ");
    printf("Verificare - textul decriptat este:\n");
    while(cuv != NULL) {
        for(int i = 0; cuv[i] != '\0'; i++) {
            if((islower(cuv[i]) && (int)cuv[i] + key < (int)'a') || (isupper(cuv[i]) && (int)cuv[i] + key < (int)'A'))
               cuv[i] = (char)((int)cuv[i] + 26 - key);
            else cuv[i] = (char)((int)cuv[i] - key);
        }
        printf("%s ", cuv);
        cuv = strtok(NULL, " ");
    }


}

int main() {
    printf("Introduceti un text:\n");
    fgets(s, 101, stdin);
    s[strcspn(s, "\n")] = '\0';
    printf("Introduceti un numar: ");
    scanf("%d", &p);
    cripteaza(s, p);
    printf("\n");
    decripteaza(s, p);

    return 0;
}
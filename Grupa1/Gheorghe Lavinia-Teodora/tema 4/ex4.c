#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s[101], *cuv;
int p;

int main() {
    printf("Introduceti un text: ");
    fgets(s, 101, stdin);
    s[strcspn(s, "\n")] = '\0';

    printf("Introduceti un numar: ");
    scanf("%d", &p);
    cuv = strtok(s, " ");

    printf("Textul criptat cu ajutorul codului Cezar este: \n");
    while(cuv != NULL) {
        for(int i = 0; cuv[i] != '\0'; i++) {
            //in caz ca valoarea adunarii rezulta valoarea unui caracter care nu este litera
            if((islower(cuv[i]) && (int)cuv[i] + p > (int)'z') || (isupper(cuv[i]) && (int)cuv[i] + p > (int)'Z'))
              //la adunare scad cele 26 de litere, pentru a rezulta tot o litera
              cuv[i] = (char)((int)cuv[i] - 26 + p);
            else cuv[i] = (char)(cuv[i] + p);
        }
        printf("%s ", cuv);
        cuv = strtok(NULL, " ");
    }

    return 0;
}
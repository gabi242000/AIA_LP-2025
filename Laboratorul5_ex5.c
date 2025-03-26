#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char sir[101];
    int p;
    printf("Introdu un sir: ");
    fgets(sir,101,stdin);
    printf("Introdu pozitia: ");
    scanf("%d",&p);
    for (int i = 0; sir[i] != '\0'; i++) {
        if (sir[i] >= 'a' && sir[i] <= 'z') {
            sir[i] = (sir[i] - 'a' + p) % 26 + 'a';
        }
        else if (sir[i] >= 'A' && sir[i] <= 'Z') {
            sir[i] = (sir[i] - 'A' + p) % 26 + 'A';
        }
    }
    printf("Textul criptat: %s", sir);
    return 0;
}
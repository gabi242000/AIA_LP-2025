#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char s[25], S[25];
    int l;
    printf("Introduce-ti sirul:");
    fgets(s, 25, stdin);
    l = strlen(s);
    for (int i = 0; i < l; i++){
        S[i] = toupper(s[i]);
    }
    printf("Sirul scris cu litere mari este: %s",S);
    return 0;
}
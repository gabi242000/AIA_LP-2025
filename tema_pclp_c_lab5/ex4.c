#include <stdio.h>
#include <string.h>

int main() {
    char sir[100];
    int p;
    printf("Va rog introduceti un sir, iar apoi valoarea p: ");
    fgets(sir, 100, stdin);
    sir[strlen(sir) - 1] = '\0';
    scanf("%d", &p);
    for(int i = 0; i < strlen(sir); i++) {
        if (sir[i] == 'Z') {
            sir[i] = 'A';
            sir[i] = sir[i] + (p-1);
        }else if (sir[i] == 'z') {
            sir[i] = 'a';
            sir[i] = sir[i] + (p-1);
        }else if(sir[i] != ' ')
            sir[i] = sir[i] + p;
    }
    printf("%s\n", sir);
    return 0;
}

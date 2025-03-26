#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int x, l; 
    printf("Introduceti un sir de caractere: ");
    scanf("%s", s);
    printf("Introdu margina de shiftare:");
    scanf("%d", x);
    l = strlen(s);

    for(int i = 0; i < l; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = ((s[i] - 'a' + x) % 26) + 'a';
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = ((s[i] - 'A' + x) % 26) + 'A';
        }
    }
    
    printf("Sirul procesat este: %s", s);

    return 0;
}

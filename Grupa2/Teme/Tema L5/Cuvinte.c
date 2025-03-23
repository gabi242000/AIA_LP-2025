#include <stdio.h>
#include <string.h>

int e_vocala(char c) {
    return strchr("aeiou", c) != NULL;
}

int main() {
    char s[100];
    int i, ok = 1;

    printf("introdu cuvantul: ");
    fgets(s, sizeof(s), stdin);

    s[strcspn(s, "\n")] = 0;

    if (s[0] != 'z' || strlen(s) % 2 != 0) {
        ok = 0;
    } else {
        for (i = 0; s[i + 1] != '\0'; i++) {
            if (e_vocala(s[i]) && e_vocala(s[i + 1])) {
                ok = 0;
                break;
            }
        }
    }

    if (ok)
        printf("Cuvant frumos!\n");
    else
        printf("Cuvant urat!\n");

    return 0;
}

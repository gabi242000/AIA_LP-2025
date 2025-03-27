#include <stdio.h>
#include <string.h>
#include <ctype.h>

int este_vocala(char c) {
    return strchr("aeiouAEIOU", c) != NULL;
}

int este_cuvant_frumos(char *cuvant) {
    int lungime = strlen(cuvant);
    
    if (lungime % 2 != 0 || cuvant[0] != 'z') {
        return 0;
    }

    for (int i = 0; i < lungime - 1; i++) {
        if (este_vocala(cuvant[i]) == este_vocala(cuvant[i + 1])) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char text[1000], cuvant[100];
    fgets(text, sizeof(text), stdin);
    
    char *p = strtok(text, " ");
    while (p) {
        if (este_cuvant_frumos(p)) {
            printf("%s\n", p);
        }
        p = strtok(NULL, " ");
    }

    return 0;
}

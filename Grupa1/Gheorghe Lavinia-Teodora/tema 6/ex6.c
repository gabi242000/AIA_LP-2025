#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *a, *b, *c;
int size_a, size_b, size_c;

int main() {
    printf("Introduceti dimensiunea primului sir: ");
    scanf("%d", &size_a);
    getchar();

    a = (char*)malloc((size_a + 1) * sizeof(char));
    if(a == NULL) {
        printf("Eroare la alocarea memoriei primui sir\n");
        return 1;
    }

 
    printf("Introduceti primul sir:\n");
    fgets(a, (size_a + 1), stdin);
    a[strcspn(a, "\n")] = '\0';

    printf("Introduceti dimensiunea celui de-al doilea sir: ");
    scanf("%d", &size_b);
    getchar();

    b = (char*)malloc((size_b + 1) * sizeof(char));
    if(b == NULL) {
        printf("Eroare la alocarea memoriei primui sir\n");
        return 1;
    }

    printf("Introduceti al doilea sir:\n");
    fgets(b, (size_b + 1), stdin);    
    b[strcspn(b, "\n")] = '\0';

    size_c = size_a + size_b;
    c = (char*)malloc((size_c + 1) * sizeof(char));
    if(c == NULL) {
        printf("Eroare la alocarea memoriei primui sir\n");
        return 1;
    }

    strcpy(c, a);
    strcat(c, b);

    printf("Rezultatul concatenarii celor doua siruri este: \n");
    printf("%s", c);

    free(a);
    free(b);
    free(c);
    return 0;
    
}
#include <stdio.h>
#include <ctype.h>

int main() {
    char sir[1000];
    printf("Introduceti un sir de caractere: ");
    fgets(sir, sizeof(sir), stdin); 

    for (int i = 0; sir[i] != '\0'; i++) {
        sir[i] = toupper(sir[i]); 
    }
    
    printf("Sirul nou este: %s\n", sir);
    return 0;
}

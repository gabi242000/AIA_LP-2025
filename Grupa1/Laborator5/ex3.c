#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char cuv[100];
    int len, vocala, frumos= 1;
    
    printf("Introduceti un cuvant: ");
    scanf("%s", cuv);
    
    len = strlen(cuv);
    
    if (len % 2 != 0) {
        frumos= 0;
    }

    else if (tolower(cuv[0]) != 'z') {
        frumos= 0;
    }
    
    else {
        for (int i = 1; i < len; i++) {
            vocala = tolower(cuv[i]) == 'a' || tolower(cuv[i]) == 'e' || 
                       tolower(cuv[i]) == 'i' || tolower(cuv[i]) == 'o' || 
                       tolower(cuv[i]) == 'u';
            int inainte_de_vocala = tolower(cuv[i-1]) == 'a' || tolower(cuv[i-1]) == 'e' || 
                                tolower(cuv[i-1]) == 'i' || tolower(cuv[i-1]) == 'o' || 
                                tolower(cuv[i-1]) == 'u';
            
            if ((vocala && inainte_de_vocala) || (!vocala && !inainte_de_vocala)) {
                frumos= 0;
                break;
            }
        }
    }
    
    if (frumos) {
        printf("Cuvantul este frumos!\n");
    } else {
        printf("Cuvantul nu este frumos!\n");
    }
    
    return 0;
}

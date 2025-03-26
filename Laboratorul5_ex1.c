#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*1.Se dă un șir de caractere format din litere mici, litere mari și spații. Să se transforme toate literele cuvântului în litere mari, 
după care să se afișeze șirul modificat.*/
int main(){
    char s[101];
    int i;
    printf("Introdu un sir de caractere: ");
    fgets(s,101,stdin);
    printf("Sirul de caractere introdus este: %s",s);
    for(i=0; s[i]!='\0';i++) {
        s[i]=toupper(s[i]);
    }
    printf("Sirul modificat este: %s",s);
    return 0;
}
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char s[100];
    printf("Introdu sirul: ");
    fgets(s,100,stdin);
    int lungime=strlen(s);
    if(lungime>0 && s[lungime-1]=='\n');
    {
        s[lungime-1]='\0';

    }

    for (int i = 0; s[i] != '\0'; i++) {
        if (islower(s[i])) {
            s[i] = toupper(s[i]);

        }
        printf("%c",s[i]);
    }
    printf("\n");
    return 0;
}


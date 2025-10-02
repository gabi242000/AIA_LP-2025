#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char s[200];
    fgets(s,200,stdin);
    for(int i=0;i<strlen(s);i++)
        if(islower(s[i])) s[i]=toupper(s[i]);

    printf("%s",s);

}
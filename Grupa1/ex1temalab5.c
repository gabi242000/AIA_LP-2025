#include <stdio.h>
#include <ctype.h>

int main(){
    char sir[100];
    printf("Introduceti un sir: ");
    fgets(sir, sizeof(sir), stdin);

    for(int i=0;sir[i]!='\0';i++){
        sir[i]=toupper(sir[i]);
    }
    printf("%s", sir);
    return 0;
}
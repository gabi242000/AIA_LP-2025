#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char sir[100];
    gets(sir);
    for(int i=0;i<=strlen(sir);i++){
        sir[i]=tolower(sir[i]);
    }
    printf("%s",sir);
    return 0;
}
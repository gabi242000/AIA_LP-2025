#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char X[255],*p;
    fgets(X,255,stdin);
    X[strcspn(X,"\n")]=0;
    p= strtok(X," ");
    while(p!=NULL)
    {
        for(int i=0;i<strlen(p);i++)
            p[i]=toupper(p[i]);
        printf("%s ",p);
        p=strtok(NULL," ");
    }
    return 0;
}
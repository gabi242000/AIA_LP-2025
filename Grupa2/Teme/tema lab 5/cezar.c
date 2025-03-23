#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[100];
    int p,i;
    printf("introdu sirul: ");
    fgets(s,100,stdin);
    printf("introdu p: ");
    scanf("%d",&p);
    for (i=0;i<strlen(s)-1;i++){
        if (isalpha(s[i])){
            if (islower(s[i]))
                if (s[i]+p>'z')
                    s[i]='a'-('z'-s[i]+1)+p;
                else
                    s[i]=s[i]+p;
            if (isupper(s[i]))
                if (s[i]+p>'Z')
                    s[i]='A'-('Z'-s[i]+1)+p;
                else
                    s[i]=s[i]+p;
        }
    }
    printf("%s",s);
    return 0;
}

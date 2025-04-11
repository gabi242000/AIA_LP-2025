#include <stdio.h>
#include <string.h>
#include <ctype.h>
void criptare(char s[], int key)
{
    int n=strlen(s), i;
    for(i=0;i<n;i++)
        if(isalpha(s[i]))
            s[i]=s[i]+key;
}
void decriptare(char s[], int key)
{
    int n=strlen(s), i;
    for(i=0;i<n;i++)
            if(isalpha(s[i]-key))
            s[i]=s[i]-key;
}
int main()
{
    char sir[200],sir2[200];
    int key;
    printf("introduceti un sir de caractere\n");
    fgets(sir,200,stdin);
    sir[strcspn(sir,"\n")]=0;
    printf("intorudeti cheia: ");
    scanf("%d", &key);
    strcpy(sir2,sir);
    criptare(sir,key);
    printf("sirul criptat:\n %s\n", sir);
    decriptare(sir,key);
    printf("sirul decriptat:\n %s", sir);
    if(strcmp(sir,sir2)==0)
        printf("\nprocedura s-a desfasurat cu succes!");
    else
        printf("\nprocedura a esuat!");
    return 0;
}

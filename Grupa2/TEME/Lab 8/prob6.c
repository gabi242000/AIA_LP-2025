#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *s1, *s2, *s3;
    int n1, n2;

    printf("Cate caractere are primul sir?\n");
    scanf("%d", &n1);
    printf("Cate caractere are al doilea sir?\n");
    scanf("%d", &n2);
    s1=(char*)malloc(n1 * sizeof(char));
    if(s1 == NULL)
    {
        printf("Eroare la alocarea memoriei primului sir\n");
        return 1;
    }
    s2=(char*)malloc(n2 * sizeof(char));
    if(s2 == NULL)
    {
        printf("Eroare la alocarea memoriei celui de al doilea sir\n");
        return 1;
    }
    printf("Introdu %d caractere primului sir.\n", n1);
    scanf("%s", s1);
    printf("Introdu %d caractere celui de al doilea sir.\n", n2);
    scanf("%s", s2);

    s3=(char*)malloc((n1+n2) * sizeof(char));
    if(s3 == NULL)
    {
        printf("Eroare la alocarea memoriei celui de al treilea sir.\n");
        return 1;
    }
    strcpy(s3, strcat(s1, s2));
    printf("Al treilea sir este:\n");
    printf("%s", s3);
    return 0;
}
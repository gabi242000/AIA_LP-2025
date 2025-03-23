#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int i, p;
    char s[100];
    printf("Introduceti propozitia : ");
    fgets(s, 100, stdin);
    printf("Introduceti valoarea lui p : ");
    scanf("%d", &p);
    s[strcspn(s, "\n")] = 0;
    for (i = 0; i <= strlen(s) - 1; i++)
        s[i] = s[i] + p;
    
    printf("Sirul codat este : ");
    printf("%s",s);
    return 0;
}
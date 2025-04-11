#include <stdio.h>
#include <string.h>
#include <ctype.h>
void cripteaza(char s[], int key)
{
    for (int i = 0; i <= strlen(s) - 1; i++)
        if (s[i] != ' ')
            s[i] = s[i] + key;

    printf("Sirul codat este : ");
    printf("%s", s);
}

void decripteaza(char s[], int key)
{
    for (int i = 0; i <= strlen(s) - 1; i++)
        if (s[i] != ' ')
            s[i] = s[i] - key;

    printf("Sirul decodat este : ");
    printf("%s", s);
}

int main()
{
    int i, key;
    char s[100], s2[100];
    printf("Introduceti propozitia : ");
    fgets(s, 100, stdin);
    printf("Key : ");
    scanf("%d", &key);
    cripteaza(s, key);
    printf("\n");
    strcpy(s2, s);
    decripteaza(s2, key);
    return 0;
}

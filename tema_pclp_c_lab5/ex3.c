#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    printf("Va rog introduceti un cuvant: ");
    scanf("%s", &s);
    int ok = 0;
    if(s[0] == 'z' && strlen(s) % 2 == 0)
        for (int i = 0; i < strlen(s) - 1; i++) {
            if(strchr("aeiou", s[i]) != strchr("aeiou", s[i+1]))
                ok = 1;
        }
    else
        ok = 0;
    if(ok)
        printf("Ati ales un cuvant frumos");
    else
        printf("Ati ales un cuvant urat");

    return 0;
}

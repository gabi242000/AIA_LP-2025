#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char *s1, *s2, *s3;
    s1 = (char *) malloc(26 * sizeof(char));
    s2 = (char *) malloc(26 * sizeof(char));
    s3 = (char *) malloc(52 * sizeof(char));
    scanf("%s", s1);
    scanf("%s", s2);
    s3[0] = '\0';
    strcat(s3, s1);
    strcat(s3, s2);
    printf("%s", s3);
    free(s1);
    free(s2);
    free(s3);
    return 0;
}
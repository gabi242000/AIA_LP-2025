#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    char sir[101];
    gets(sir);
    for (int i = 0; i < strlen(sir); i++) {
        if (sir[i] >= 'a' && sir[i] <= 'z') {
            sir[i] = toupper(sir[i]);
        }
    }
    printf("%s", sir);
    return 0;
}

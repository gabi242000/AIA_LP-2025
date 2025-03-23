#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s[101];

int main() {

	fgets(s, 101, stdin);

	for (int i = 0; i < strlen(s); i++)
		s[i] = toupper(s[i]);

	printf("%s", s);

	return 0;
}
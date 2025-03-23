#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s[101];
int p;

int main() {

	fgets(s, 101, stdin);
	scanf("%d", &p);

	if (strlen(s) > 0 && s[strlen(s) - 1] == '\n') {
		s[strlen(s) - 1] = '\0';
	}

	for (int i = 0; i < strlen(s); i++)
		if (s[i] != ' ')
			s[i] += p;

	printf("%s", s);

	return 0;
}
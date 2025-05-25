#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s[101], aux;
int x, y;

int main() {

	scanf("%s", s);
	scanf("%d %d", &x, &y);

	aux = s[x];
	s[x] = s[y];
	s[y] = aux;

	printf("%s", s);

	return 0;
}

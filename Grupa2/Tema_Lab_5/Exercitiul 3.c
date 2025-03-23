#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s[101];

int frumos = 0;

int main() {

	scanf("%s", s);
	
	if (s[0] == 'z')
		if (strlen(s) % 2 == 0)
			for (int i = 0; i < strlen(s); i++)
				if ((i % 2 == 1 && strchr("aeiou", s[i] != 0)) || (i % 2 == 0 && strchr("aeiou", s[i] == 0)))
					frumos = 1;

	if (frumos)
		printf("Este un cuvant frumos!");
	else
		printf("Nu este un cuvant frumos!");

	return 0;
}
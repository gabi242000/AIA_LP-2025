#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int cripteaza(char s[], int key) {
	int i;
	for (i = 0; i < strlen(s); i++) {
		if (isalpha(s[i])) {
			if (isupper(s[i])) {
				s[i] = ((s[i] - 'A' + key) % 26) + 'A';
			}
			else {
				s[i] = ((s[i] - 'a' + key) % 26) + 'a';
			}
		}
	}
	return 0;
}

int decripteaza(char s[], int key) {
	int i;
	for (i = 0; i < strlen(s); i++) {
		if (isalpha(s[i])) {
			if (isupper(s[i])) {
				s[i] = ((s[i] - 'A' - key + 26) % 26) + 'A';
			}
			else {
				s[i] = ((s[i] - 'a' - key + 26) % 26) + 'a';
			}
		}
	}
	return 0;
}

int main() {

	char s[100];
	int key;

	printf("Introduceti textul: ");
	fgets(s, sizeof(s), stdin);

	s[strcspn(s, "\n")] = 0;

	printf("Introduceti cheia: ");
	scanf("%d", &key);

	cripteaza(s, key);
	printf("Textul criptat: %s\n", s);

	decripteaza(s, key);
	printf("Textul decriptat: %s\n", s);

	return 0;
}

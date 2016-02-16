#include <stdio.h>

int main(int argc, char const *argv[]) {
	if (argc < 2) {
		printf("ERROR: You need at least one argument.\n");
		return 1;
	}

	int i = 0;
	int j = 0;
	char letter;
	for (j = 1; j < argc; j++) {
		for (i = 0, letter = argv[j][i]; argv[j][i] != '\0'; ++i, letter = argv[j][i]) {
			if (letter >= 'A' && letter <= 'Z') {
				letter -= 'A' - 'a';
			}

			if ('a' == letter) {
				printf("%d: 'A'\n", i);
			} else if ('e' == letter) {
				printf("%d: 'E'\n", i);
			} else if ('i' == letter) {
				printf("%d: 'I'\n", i);
			} else if ('o' == letter) {
				printf("%d: 'O'\n", i);
			} else if ('u' == letter) {
				printf("%d: 'U'\n", i);
			} else if ('y' == letter) {
				if (i > 2) {
					printf("%d: 'Y'\n", i);
				}
			} else {
				printf("%d: %c is not a vowel\n", i, letter);
			}
		}
	}
	return 0;
}
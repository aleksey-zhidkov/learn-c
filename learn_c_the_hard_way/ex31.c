#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
	int i = 0;

    char* n= NULL;
	while (i < 100) {
		usleep(300000);
		i++;
		printf("%d===============\n", i);
		if (i == 3) {
			printf("%c\n", *n);
		}
	}
	
	return 0;
}
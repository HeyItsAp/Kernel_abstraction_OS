#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]){
	int x;
	if (argc > 1){
		x = atoi(argv[1]);	
	} else {
		exit(1);
	}
	char word[100];
	printf("Enter a word:");
	scanf("%99s", &word); // Waits for keyboard input.
	printf("\n");
	for (int i = 0; i < x; i++)printf("%s\n", word);

	return 0;
}

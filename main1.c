#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char const *argv[]){
	int x = argv[0];
	printf("Enter a word: \n");
	char word = getchar(); // Waits for keyboard input.

	for (int i = 0; i < x; i++)printf("%c\n", word);
}

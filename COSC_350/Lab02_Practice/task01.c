#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1

void err_sys(char* str) {
	printf("%s", str);
	exit(1);
}

int main()
{
	int nbyte;
	char buffer[BUFFER_SIZE];

	while(( nbyte = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0)
		if(write(STDOUT_FILENO, buffer, nbyte) != nbyte)
			err_sys("Write error");

	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int st_to_int(char *); // function prototype

int main(int argc, char* argv[])
{
	int i, num;
	int esum = 0;
	int osum = 0;

	if (argc <= 1) { 
		printf("Must enter 1 or more arguments");
		return 1;
	}

	for(int i = 0; i < argc; i++) {
		num = st_to_int(argv[i]);
		if ((num % 2) == 0)
			esum = esum + num;
		else
			osum = osum + num;
	}

	printf("The sum of even numbers is: %d\n", esum);
	printf("The sum of odd numbers is: %d\n", osum);

	return 0;
}

// convert numerical c-string to an integer
int st_to_int(char * str) {
	int num = 0;
	int i = 0;
	int negative = 0;

	// check signs
	if (str[0] == '-') {
		i = 1;
		negative = 1;
	}

	if (str[0] == '+') {
		i = 1;
	}

	// conversion
	while (str[i] != '\0')
	{
		num = 10 * num + (str[i] - '0'); // conversion math
		i++;
	}

	if (negative == 1)
		num = num * -1;

	return num;
}

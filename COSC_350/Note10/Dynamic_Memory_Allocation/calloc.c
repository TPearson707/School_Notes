/* calloc.c */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	typedef struct {
		int age;
		char name[20];
	} data;

	data* bob;

	bob = (data*) calloc(2, sizeof(data));
	
	if (bob != NULL) {
		bob[0].age = 22;
		strcpy(bob[0].name, "Robert");

		bob[1].age = 25;
		strcpy(bob[1].name, "Christine");

		printf("%s is %d years old\n", bob[0].name, bob[0].age);
		printf("%s is %d years old\n", bob[1].name, bob[1].age);

		// let temp point to data bob is pointing to to prevent mem leaks
		data* temp = (data*)realloc(bob, 3 * sizeof(data)); // resize to size 3
		if (temp == NULL) {
			free(bob);
			return 1;
		} else
			bob = temp; // if successful set bob = to newly sized ptr

		bob[2].age = 27;
		strcpy(bob[2].name, "Altair");

		printf("%s is %d years old\n", bob[2].name, bob[2].age);

	}
		
	free(bob);
	return 0;
}

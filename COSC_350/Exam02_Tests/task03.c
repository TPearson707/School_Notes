#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    srand(time(0));

    char* str = (char*) calloc(n, sizeof(char*));

    for (int i = 0; i < n; i++)
        str[i] = rand() % 26 + 'a';
    
    printf("%s\n", str);

    int m;
    char buffer[1];
    read(0, buffer, 1);
    m = atoi(buffer);
    m = m + n;

    char* temp = (char*) realloc(str, m * sizeof(char*));

    if (!str) {
        free(temp);
        exit(1);
    } else
        str = temp;

    for (int i = n; i < m; i++) 
        str[i] = rand() % 26 + 'a';

    printf("%s\n", str);

    free(str);

    return 0;
}

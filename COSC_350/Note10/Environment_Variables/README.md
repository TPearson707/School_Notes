## Current questions
    * N/A

## environ.c & envp.c
    * do the same thing
    * environ.c utilizes extern to grab the environ table from elsewhere
    * envp.c uses the alternative name envp to grab the table from the arguments in cli 

## Setters and Getters in environmental variables
    * #include <stdlib.h>
    * char *getenv(const char *)
    * int setenv (const char *name, const char *new_value, int rewrite)
    * int putenv(const char *) // puts new env variable during runtime
    * void unsetenv(const char *name)

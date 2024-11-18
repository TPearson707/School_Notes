## rval_ptr: typeless pointer. This pointer is available to other threads in the process by      calling pthread_join() 

#include <pthread>
void pthread_exit(void *rval_ptr);

## compiling
    * gcc -c example.c
    * gcc -pthread -o example example.o

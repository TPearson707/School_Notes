## Contiguous Allocation
* IDea: Files are stored in consecutive blocks
* D: can lead to external fragmentation, and it's difficult to resize files as they grow

## LL Allocation
* Idea: Each file 
*: Random acces slow because system must follow pointers from the beginning
LL with fat
* idea: FAT stores the pointers to the next blocks in a table rather than in each block
* D: FAT must be loaded into memory, which can be slow for large disks, and still suffers from slow random access

## I-Node Allocation
* Idea: A structure (i-node) contains pointers to the file's blocks, allowing direct access to file data blocks
* D: Indirect blocks may be needed for large files, increasing the overhead of managing large files

## why do we say that system calls perform unuffers I/O while lib functions perform buffered I/O

* A: Sysstem calls are run on kernel's ode, it use kernal's space but library functions run on user's space, it use process's own space

* Write C program that reads sequence of pos or neg nums from command line and prints their sum of even numbers and sum of odd number to the screen. Need to define st_to_int

./evenoddsumup -5 +9 11 8 +10 -4 7 +22 -12 -15

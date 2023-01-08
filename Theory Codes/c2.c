#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    int a = 10;
    //there is only 1 process
    fork();
    //there are 2 processes after this
    fork();
    //there are 4 processes after this
    printf("process id:%d value of a: %d\n",getpid(),a);
    return 0;
}
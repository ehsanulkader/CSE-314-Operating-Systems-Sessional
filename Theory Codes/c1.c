#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    int a = 10;
    //there is only 1 process
    fork();
    //there are 2 processes after this
    printf("%d",a);
    return 0;
}
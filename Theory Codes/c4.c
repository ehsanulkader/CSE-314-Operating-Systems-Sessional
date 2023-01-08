#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    if(rc == 0)
        printf("In child %d\n",getpid());
    else if(rc > 0)
        printf("In parent %d\n",getpid());
    return 0;
}

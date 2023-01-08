#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    if(rc == 0) {
        printf("In child %d\n",getpid());
        int i = 100000;
        while(i--) {
            
        }
    } else {
        wait(); //will wait for the children to finish
        printf("In parent %d\n",getpid());
    }
    return 0;
}

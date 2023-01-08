#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
   if (rc == 0) { // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        char *myargs[3];
        myargs[0] = strdup("ls");
        myargs[1] = NULL;
        execvp(myargs[0], myargs);
        printf("hello, I am child (pid:%d)\n, printing after execvp() call", (int) getpid());
    } else {
        // parent goes down this path (main)
        int wc = wait(NULL);
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",rc, wc, (int) getpid());
    }
    return 0;
}
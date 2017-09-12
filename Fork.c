#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    int i;
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
    if (pid == 0)
    {
	printf("eu sou o pai e esse é meu pid: %d\n",getpid());
    }
    else
    {
    printf("eu sou o filho e esse é meu pid: %d\n",getpid());
    }

    exit(0);
}

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.

// Let us create a global variable to change it in threads
int g = 0;

void* myThreadFun(void* vargp)
{
    // Store the value argument passed to this thread
    int myid = getpid();

    // Let us create a static variable to observe its
    // changes
    static int s = 0;

    // Change static and global variables
    ++s;
    ++g;

    // Print the argument, static and global variables
    printf("Thread ID: %d, Static: %d, Global: %d\n", myid, ++s, ++g);

    return NULL;
}

int main()
{
    int i;
    pthread_t tid;

    // Let us create three threads
    for (i = 0; i < 3; i++)
        pthread_create(&tid, NULL, myThreadFun, NULL);

    pthread_exit(NULL);
    return 0;
}
// Compile with `gcc foo.c -Wall -std=gnu99 -lpthread`, or use the makefile
// The executable will be named `foo` if you use the makefile, or `a.out` if you use gcc directly

#include <pthread.h>
#include <stdio.h>

int i = 0;
// --------- the change ---------- // 
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex for synchronizing access to i
// --------- the change ---------- // 

// Note the return type: void*
void* incrementingThreadFunction(){
    // --------- the change ---------- // 
    pthread_mutex_lock(&mutex);
    // --------- the change ---------- // 

    // TODO: increment i 1_000_000 times
    for (int j = 0; j < 1000000; j++)
    {
        i++;
    }

    // --------- the change ---------- // 
    pthread_mutex_unlock(&mutex);
    // --------- the change ---------- // 
    
    return NULL;
}

void* decrementingThreadFunction(){
    // --------- the change ---------- // 
    pthread_mutex_lock(&mutex);
    // --------- the change ---------- // 

    // TODO: decrement i 1_000_000 times
    for (int j = 0; j < 1000000; j++) {
        i--;
    }

    // --------- the change ---------- // 
    pthread_mutex_unlock(&mutex);
    // --------- the change ---------- // 

    return NULL;
}


int main(){
    // TODO: 
    // start the two functions as their own threads using `pthread_create`
    // Hint: search the web! Maybe try "pthread_create example"?
    pthread_t incrementingThread;
    pthread_t decrementingThread;
    pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL);
    pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL);
    
    // TODO:
    // wait for the two threads to be done before printing the final result
    // Hint: Use `pthread_join`    
    pthread_join(incrementingThread, NULL);
    pthread_join(decrementingThread, NULL);
    
    printf("The magic number is: %d\n", i);
    return 0;
}

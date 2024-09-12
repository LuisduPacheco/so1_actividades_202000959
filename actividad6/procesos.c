#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg) {
    printf("Hilo creado en el proceso %d\n", getpid());
    return NULL;
}

int main() {
    pid_t pid;
    pthread_t thread;

    pid = fork();
    if (pid == 0) { /* proceso hijo */
        fork();

        pthread_create(&thread, NULL, thread_function, NULL);
        pthread_join(thread, NULL);
    }
    
    fork();

    // Para verificar los procesos únicos creados
    printf("Proceso PID: %d\n", getpid());

    return 0;
}

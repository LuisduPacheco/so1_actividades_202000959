#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();  // Crear un proceso hijo

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        printf("Proceso hijo (PID: %d) terminado.\n", getpid());
        _exit(0);
    } else {
        printf("Proceso padre (PID: %d) está esperando 60 segundos.\n", getpid());
        sleep(60);

        wait(NULL);
        printf("Proceso hijo recolectado, el padre termina.\n");
    }

    return 0;
}

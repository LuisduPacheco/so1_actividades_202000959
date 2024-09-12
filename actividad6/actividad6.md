# Procesos e Hilos

## Nombre: Luis Eduardo De León Pacheco

## Carnet: 202000959

**1. ¿Cuantos procesos son creados por el siguiente programa?**

El proceso padre es el inicial, luego el el primer fork() crea un segundo proceso, el siguiente fork() se ejecuta por los dos primeros procesos el padre y el primer hijo por lo que hay 4 procesos, el último fork() se ejecuta por los procesos padre y los hijos por lo que hay 8 procesos al final incluyendo el principal y los hijos.
Hay 8 procesos en total. 

**2. Utilizando un sistema Linux, escriba un programa en C que cree un proceso hijo (fork) que finalmente se convierta en un proceso zombie. Este proceso zombie debe permanecer en el sistema durante al menos 60 segundos.** 

Ejecutando le código c, zombie.c:

```bash
luis@luis-System-Product-Name:~/Escritorio/Semestre-2024/SegundoSemestre/SistemasOperativos/Actividades/actividad6$ ./zombie
Proceso padre (PID: 11183) está esperando 60 segundos.
Proceso hijo (PID: 11184) terminado.
```

Finalizado:

```bash
luis@luis-System-Product-Name:~/Escritorio/Semestre-2024/SegundoSemestre/SistemasOperativos/Actividades/actividad6$ ./zombie
Proceso padre (PID: 11183) está esperando 60 segundos.
Proceso hijo (PID: 11184) terminado.
Proceso hijo recolectado, el padre termina.
```

Viendo los procesos:

```bash
luis@luis-System-Product-Name:~/Escritorio/Semestre-2024/SegundoSemestre/SistemasOperativos/Actividades/actividad6$ ps aux | grep 'Z'
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
luis        6659  0.0  0.0      0     0 ?        Z    07:23   0:00 [sd_espeak-ng-mb] <defunct>
luis       11184  0.0  0.0      0     0 pts/0    Z+   08:08   0:00 [zombie] <defunct>
luis       11250  0.0  0.0   6628  2304 pts/1    S+   08:08   0:00 grep --color=auto Z
luis@luis-System-Product-Name:~/Escritorio/Semestre-2024/SegundoSemestre/SistemasOperativos/Actividades/actividad6$ ps aux | grep 'Z'
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
luis        6659  0.0  0.0      0     0 ?        Z    07:23   0:00 [sd_espeak-ng-mb] <defunct>
luis       11394  0.0  0.0   6628  2304 pts/1    S+   08:11   0:00 grep --color=auto Z
```

**Usando el siguiente código como referencia, completar el programa para que sea
ejecutable y responder las siguientes preguntas:
• ¿Cuántos procesos únicos son creados?
• ¿Cuántos hilos únicos son creados?**

Son creados 6 procesos.

Son 2 hilos creados.

```bash
luis@luis-System-Product-Name:~/Escritorio/Semestre-2024/SegundoSemestre/SistemasOperativos/Actividades/actividad6$ ./procesos
Proceso PID: 13121
Proceso PID: 13123
Hilo creado en el proceso 13124
Hilo creado en el proceso 13122
Proceso PID: 13122
Proceso PID: 13124
Proceso PID: 13128
Proceso PID: 13127
```

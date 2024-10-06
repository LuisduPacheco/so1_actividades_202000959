# Completely Fair Scheduler

## Nombre: Luis Eduardo De León Pacheco

## Carnet: 202000959

El Completely Fair Scheduler (CFS) es el algoritmo de planificación por defecto en Linux desde la versión 2.6.23 del kernel, diseñado para ofrecer una distribución justa del tiempo de CPU entre las tareas. A diferencia de los algoritmos de planificación tradicionales que usan valores discretos de tiempo de ejecución o prioridades fijas, el CFS busca garantizar que cada tarea reciba una proporción justa de CPU basada en su "valor de cortesía" (o nice value).
Características principales:

1. Distribución proporcional del tiempo de CPU: El CFS asigna el tiempo de CPU a las tareas según su valor nice. Estos valores van de -20 a +19, donde los números más bajos indican mayor prioridad. Las tareas con un valor nice bajo reciben más tiempo de CPU que las tareas con un valor nice alto.

2. Latencia objetivo: El CFS no asigna tiempos fijos de ejecución, sino que usa un concepto llamado latencia objetivo. Esta es un intervalo de tiempo durante el cual cada tarea debería ejecutarse al menos una vez, dependiendo de la carga del sistema. Si hay muchas tareas, el intervalo de latencia objetivo puede aumentar.

3. Tiempo de ejecución virtual (vruntime): El CFS utiliza una métrica llamada tiempo de ejecución virtual para llevar el control de cuánto tiempo ha sido ejecutada cada tarea. Este tiempo virtual se ajusta según la prioridad de la tarea: las de baja prioridad tienen un tiempo virtual que crece más rápido, mientras que las de alta prioridad lo hacen más lentamente. El scheduler selecciona siempre la tarea con el menor tiempo virtual para ejecutarse a continuación.

4. Uso de un árbol rojo-negro: En lugar de utilizar una cola simple para ordenar las tareas, el CFS emplea un árbol rojo-negro, que es un tipo de estructura de datos de búsqueda binaria balanceada. Cada tarea se inserta en el árbol según su valor de vruntime, y el árbol permite una búsqueda eficiente de la tarea con el menor vruntime en tiempo O(log N). Esta tarea es la que se ejecuta a continuación.

5. Preemptivo: Si una tarea de mayor prioridad se vuelve elegible para ejecutarse (por ejemplo, tras finalizar una operación de E/S), esta puede interrumpir a una tarea de menor prioridad que esté en ejecución.

6. Balance de carga y soporte para NUMA: CFS es eficiente en sistemas con múltiples procesadores, utilizando técnicas avanzadas para balancear la carga entre núcleos. También tiene en cuenta las características de los sistemas NUMA (Non-Uniform Memory Access), evitando migrar tareas entre núcleos si esto puede causar penalizaciones en el acceso a memoria.

### Funcionamiento:

El CFS realiza una planificación basada en el valor vruntime. Cuando una tarea se ejecuta, su vruntime se incrementa en proporción a su uso de CPU. Las tareas que han recibido menos tiempo de CPU tendrán un vruntime menor, lo que les da prioridad en la siguiente asignación de CPU. A través del árbol rojo-negro, el CFS puede seleccionar rápidamente la tarea con el menor vruntime para que sea ejecutada. Si una tarea de mayor prioridad se vuelve activa, el sistema la ejecutará antes que una de menor prioridad, lo que garantiza una respuesta ágil para tareas interactivas o de E/S.

Esta estructura permite que el CFS sea justo y eficiente, asegurando que las tareas se ejecuten de manera equitativa y que las de mayor prioridad obtengan más tiempo de CPU, todo mientras minimiza las operaciones de búsqueda y mantiene un buen rendimiento en sistemas con múltiples procesadores.

**Referencias:**

    Libro en la página 234​.
    
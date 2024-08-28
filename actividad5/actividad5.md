# Conceptos de Sistemas Operativos

## Nombre: Luis Eduardo De León Pacheco

## Carnet: 202000959

## Tipos de Kernel y sus diferencias

1. **Monolítico**:
   - **Descripción**: El kernel monolítico es un tipo de kernel en el cual todos los servicios del sistema operativo (manejo de memoria, procesos, sistemas de archivos, etc.) se ejecutan en un solo espacio de memoria. Es un único programa grande donde todas las funcionalidades están integradas.
   - **Ventajas**: Mayor eficiencia debido a la comunicación rápida entre los componentes.
   - **Desventajas**: Más propenso a fallos y difícil de mantener o actualizar.

2. **Microkernel**:
   - **Descripción**: Este tipo de kernel minimalista reduce el número de funcionalidades que se ejecutan en modo kernel. Sólo las funciones más esenciales (como la gestión de procesos y la comunicación entre procesos) se ejecutan en el kernel, mientras que otros servicios del sistema operativo se ejecutan en el espacio de usuario.
   - **Ventajas**: Mayor estabilidad y seguridad debido a que los fallos en un servicio no afectan al kernel.
   - **Desventajas**: Puede tener un rendimiento inferior debido a la sobrecarga de la comunicación entre procesos.

3. **Híbrido**:
   - **Descripción**: Combina elementos de los kernels monolíticos y microkernel. Mantiene la estructura de un kernel monolítico, pero modulariza algunos componentes para mejorar la flexibilidad y la estabilidad.
   - **Ventajas**: Balance entre rendimiento y modularidad.
   - **Desventajas**: Complejidad en la implementación y mantenimiento.

4. **Exokernel**:
   - **Descripción**: Un enfoque minimalista donde el kernel se encarga de la asignación de recursos y la protección, mientras que las aplicaciones gestionan directamente los recursos de hardware.
   - **Ventajas**: Permite un mayor control y personalización por parte de las aplicaciones.
   - **Desventajas**: Mayor complejidad para los desarrolladores de aplicaciones.

## User Mode vs Kernel Mode

- **User Mode**:
  - **Descripción**: Es el modo en el que se ejecutan las aplicaciones de usuario. Las aplicaciones tienen acceso limitado a los recursos del sistema y no pueden ejecutar instrucciones de bajo nivel ni interactuar directamente con el hardware.
  - **Ventajas**: Mejora la seguridad y estabilidad del sistema, ya que las aplicaciones maliciosas o defectuosas no pueden causar daños críticos.
  - **Desventajas**: Limitación en el acceso directo a los recursos del hardware.

- **Kernel Mode**:
  - **Descripción**: Es el modo en el que el kernel del sistema operativo opera. Tiene acceso completo a todo el hardware y puede ejecutar cualquier instrucción de la CPU. El kernel mode es necesario para realizar operaciones críticas, como la gestión de memoria, el control de dispositivos, y la comunicación entre procesos.
  - **Ventajas**: Permite el control total del sistema y es necesario para la ejecución de las funciones del sistema operativo.
  - **Desventajas**: Si ocurre un error en el kernel mode, puede comprometer todo el sistema.

## Interruptions vs Traps

- **Interrupciones (Interruptions)**:
  - **Descripción**: Son señales enviadas por el hardware o el software que indican al procesador que debe detener temporalmente su tarea actual para atender un evento de mayor prioridad. Las interrupciones pueden ser generadas por dispositivos de hardware (como teclados, ratones, discos) o por eventos internos del sistema operativo.
  - **Ejemplo**: Una interrupción de teclado cuando se presiona una tecla.

- **Traps**:
  - **Descripción**: Son un tipo específico de interrupción generada por el software cuando ocurre un evento que requiere la intervención del kernel, como una excepción o una solicitud de servicio del sistema operativo (syscall). A diferencia de las interrupciones, las traps son provocadas por instrucciones dentro del programa en ejecución.
  - **Ejemplo**: Un trap ocurre cuando un programa intenta dividir por cero o cuando una aplicación solicita acceso a un recurso protegido.


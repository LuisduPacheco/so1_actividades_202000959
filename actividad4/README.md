# Saludo Service

Este servicio imprime un saludo y la fecha actual en intervalos de un segundo.

## Instalación

1. Crear el script `saludo.sh` y hacerlo ejecutable. Este archivo puede ir en cualquier ruta donde pueda ser accedido, para hacerlo ejecutable se usa: sudo chmod +x saludo.sh

2. Crear el archivo de servicio `saludo.service`. Este archivo se debe crear en la ruta /etc/systemd/system/

3. Recargar `systemd`, habilitar e iniciar el servicio. Después de crear el archivo de servicio, recarga systemd para que reconozca el nuevo servicio utilizando: sudo systemctl daemon-reload


## Verificación

- Para verificar el estado del servicio: `sudo systemctl status saludo.service`
- Para ver los logs del servicio: `sudo journalctl -u saludo.service -f`

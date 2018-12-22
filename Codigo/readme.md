## COMPILACION DEL CODIGO:
g++ main.cpp agenda.cpp profesor.cpp -o ./main.exe

## ARCHIVO PARA CARGAR LOS DATOS:
datos.bin

## PARA LOGEARSE:
~~~
USUARIO: profesor1
CONTRASEÑA: 1234
~~~

## COMENTARIOS:
Tras la realización, comprobación, y testeo del código nos hemos percatado de dos fallos que afectan al sistema de gestión:

1. Somos conscientes de que existe un fallo con la limpieza del bufer tras añadir diversos alumnos, guardar los datos, salir del sistema y, tras su ejecución y carga de los datos, se muestra que el nombre del alumno se concatena con el dni posterior. Estamos trabajando para una solución disponible en la entrega final, ya que desconocemos su localización en el código.

2. Una de las funciones de caracter restrictivo respecto al dni no funciona como esperábamos, ya que permite la duplicación del dni a la hora de modificar. Estamos trabajando en ello para una solución disponible en la entrega final, ya que todas las posible correciones que conocíamos han resultado fallidas.

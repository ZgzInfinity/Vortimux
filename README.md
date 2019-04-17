
# Vortimux
Un generador y validador de tarjetas de credito

![alt text](https://i.ibb.co/MNgn859/tarjetas.jpg)


## Descripción
Vortimux es un generador y validador de tarjetas de credito implementado en lenguaje C++ destinado a generar códigos de tarjetas
de credito válidas, y a poder verificar con total seguridad si una tarjeta de credito concreta es o no válida.

## Diseño

Inicialmente Vortimux presenta una pantalla introductoria al usuario donde informa de su nombre, su cometido, y detalles de su
creador. Para poder continuar con la ejecución el usuario deberá presionar exclusivamente la tecla INTRO, en caso contrario, 
Vortimux permanecerá a la espera de forma indefinida hasta que dicha tecla sea pulsada.

![alt text](https://i.ibb.co/6JV0SDN/6.png)

Una vez que el usuario presiona la tecla INTRO, se muestra una pantalla de carga donde Vortimux recopila información perteneciente a tareas y actividades de sesiones de ejecución anteriores.

![alt text](https://i.ibb.co/MVLBHBH/8.png)

### Menú de opciones

Posteriormente a la carga de los datos, Vortimux muestra por pantalla al usuario un menú con las posibles acciones que es capaz de
realizar y permanece a la espera de que el usuario le proporcione una a través de la entrada estándar. Vortimux seguirá pidiendo
trabajo hasta que el usuario introduzca el comando de fin de ejecución. 

A continuación se describen cada una de las órdenes que Vortimux es capaz de realizar:

![alt text](https://i.ibb.co/KwBPSj4/2.png)

#### 1 - Generación de tarjetas de credito

Esta orden es ejecutada cuando el usuario introduce por teclado el código de orden 1. Tras introducir dicha orden, Vortimux
genera una tarjeta de credito aleatoria válida empleando el algoritmo de Luhn. Vortimux solicita al usuario que introduzca por teclado uno de los posibles tipos que es capaz de generar tal y como que se muestra en la imagen:

![alt text](https://i.ibb.co/tzjjRSR/3.png)

Tras cada generación Vortimux comprueba si el código de esa tarjeta ya lo había generado antes. Si esa tarjeta ya existe procede a generar otra, y si no existe la guarda en
un fichero de datos donde residen todas las tarjetas que ha generado el usuario. Si la generación de la tarjeta ha ido 
correctamente, muestra por pantalla el siguiente mensaje.

![alt text](https://i.ibb.co/6DDCGyb/0.jpg)

#### 2 - Validación de tarjetas de credito

Esta orden es ejecutada cuando el usuario introduce por teclado la orden 2. Tras introducir dicha orden, Vortimux solicita al
usuario que introduzca por medio de teclado el código de la tarjeta de credito de la que desea conocer su validez. Para poder
determinar si es o no válida emplea el algoritmo de Luhn. A continuación se muestran dos capturas de los resultados devueltos 
por Vortimux tras efectuar la verificación de una tarjeta válida y otra inválida, respectivamente. Vortimux solo valida tarjetas
de 16 dígitos.

![alt text](https://i.ibb.co/8gPkPjw/2.png)

![alt text](https://i.ibb.co/1vwHLLy/1.jpg)


#### 3 - Lectura de tarjetas de un fichero

Esta orden se ejecuta cuando el usuario teclea la orden 3. Tras recibir esta orden Vortimux solicita al usuario que introduzca
un fichero de texto que almacena una secuencia concreta de tarjetas de credito. Como resultado de esta tarea Vortimux muestra
por pantalla un listado de las tarjetas de credito residentes en ese fichero, a razón de una por línea, en la que ofrece 
detalles de la posición que ocupa en el fichero, su código numérico, y si es o no válida. En la siguiente imagen se muestra el 
formato con el que Vortimux devuelve la salida. Las tarjetas a validar deben de estar formadas por códigos de 16 dígitos.

![alt text](https://i.ibb.co/VYd8Tgg/3.png)

#### 4 - Generar secuencia de tarjetas válidas

Esta orden es ejecutada cuando el usuario teclea la orden 4. Es muy parecida a la primera orden pero con la diferencia de que el
usuario debe introducir por teclado cuántas tarjetas desea generar exactamente. Una vez que la tarea concluye adecuadamente 
muestra por pantalla un listado con todas las tarjetas que se han generado. 

![alt text](https://i.ibb.co/DK6953H/1.png)

#### 5 - Formateo de los ficheros

Esta orden es ejecutada cuando el usuario teclea la orden 5. Como se ha explicado anteriormente, Vortimux guarda la traza de 
ejecución de comandos que le son solicitados en una serie de ficheros auxiliares. Con esta orden el usuario puede borrar
todo la actividad anteriormente realizada y comenzar de nuevo. Cuando el formateo del contenido de los ficheros se efectua bien,
Vortimux devuelve el siguiente mensaje por pantalla.

![alt text](https://i.ibb.co/XkZJyHJ/4.png)



### Detalles de implementación

Para poder llevar a cabo el almacenamiento de las tarjetas en ficheros se ha optado por usar tres ficheros disitintos, uno para
las tarjetas generadas, otro para las tarjetas válidas y otro para las inválidas con el objetivo de agilizar la búsqueda. Cuando
Vortimux carga los datos genera tres árboles binarios de búsqueda a modo de diccionarios, a razón de uno por fichero, para poder
guardar las tarjetas en cuestión. De este modo se consigue eficiencia en tiempo de ejecución en la búsqueda y en la inserción.

Tras la ejecución de una tarea, Vortimux guarda los resultados obtenidos en el árbol correspondiente. Cuando el usuario teclea 
la orden de fin de ejecución, la orden 0, Vortimux copia el contenido de los árboles binarios recorriendolos en 
in-orden a los ficheros con la finalidad de que éstos queden ordenados tal y como se muestra en la siguiente captura.

![alt text](https://i.ibb.co/4mtrCsG/10.jpg)

El arbol binario de búsqueda se ha implementado de forma que cada nodo es una tarjeta que se identifica por medio de su código
numérico dado que son únicas. El árbol está ordenado de modo que para cada tarjeta, las que tengan un código menor estén en los
subárboles izquierdos y las que son mayores en los derechos, de esta manera se maximiza la eficiencia de operaciones como la
búsqueda de una tarjeta. 

En la siguiente imagen se muestra como Vortimux almacena las tarjetas de credito en los árboles binarios sustituyendo los 
dígitos de los nodos por los códigos de las tarjetas.

![alt text](https://i.ibb.co/SwBhvZX/arbol.png)

### Consideraciones de desarrollo y ejecución 

Para implementar el programa se ha usado CODEBLOCKS, entorno de programación disponible para cualquier sistema operativo, 
junto con una librería adicional externa llamada conio.h, no disponible para Linux, solo disponible para Windows. Para tener 
una mejor visualización del programa ajustar las dimensiones de la consola a 120 de ancho por 30 alto. 

En la primera ejecución Vortimux no dispone de los ficheros con los que trabajar. Por ello se recomienda pulsar la opción 0 para
que los genere de manera automática.

Por motivos de apariencia y estética Vortimux solo puede validar tarjetas de hasta 16 dígitos.

### Documentación 

Para poder llevar a cabo el diseño y la implementaación del programa se ha tenido que buscar la información pertinente sobre el 
funcionamiento del algoritmo de luhn. Paralelamente se ha realizado una exhaustiva batería de pruebas para confirmar que todo
funciona adecuadamente.

URL de búsqueda de información: https://es.wikipedia.org/wiki/Algoritmo_de_Luhn

URL de verificador de tarjetas online para comprobar resultados: http://www.validcreditcardnumber.com/


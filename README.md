# Proyecto: Flight reservation system
Daniel Contreras Chávez A01710608

## Enlace de los videos
https://drive.google.com/drive/folders/17cPKdWCWrrnNSmbplhe1AcWV_0VxrL6J?usp=sharing

## Descripción del proyecto

El proyecto va a consistir de un sistema de reservación de vuelos, los cuales van a estar almacenados y listados en un archivo csv, el usuario podrá ingresar su ciudad de salida y además filtrar dichos vuelos por precio.
Para lograr esto se utilizarán:
- Vectores
- listas ligadas
- Algoritmos de ordenamiento: Se usará un shell sort
- Algoritmos de búsqueda
- Lectura y escritura de archivos csv

## Descripción del avance 1

En este avance se definirán las bases para plantear el proyecto y los algoritmos que serán usados mediante la escritura de este archivo Readme.md y se empezará a crear una base de datos con vuelos.

## Descripción del avance 2

En este avance se implementará un tipo de dato abstracto, que en este caso son las listas ligadas, las que guardarán objetos de tipo vuelos.

### Cambios sobre el primer avance

1. cambio 1: En menu.h, ya no utilizo la función de showInfo con un for, si no que ahora la integro dentro de la función de toString de mis listas
2. Cambio 2: los datos que se muestran ordenados ya no provienen de un vector, si no que provienen de una lista ligada.

## Descripción del avance 3

En este avance se evalúa la complejidad del programa y se implementa la escritura de archivos.

### Cambios sobre el segundo avance

1. Cambio 1: La función vectorToList fue eliminada completamente.
2. Cambio 2: En lugar de mostrar todos los vuelos al mismo tiempo, ahora se mostrarán uno por uno.
3. Cambio 3: Por motivos de funcionalidad, el showInfo de la clase flights cambió de ser tipo void a regresar un string.
4. Cambio 4: El archivo sorts.h fue renombrado a flightManagement.h para tener un nombre menos ambiguo y más acorde al código.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o tercer_avance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./tercer_avance` 

## Descripción de las entradas del avance de proyecto

El proyecto requiere una entrada de archivo de tipo csv, donde estarán guardados los vuelos, y sus características (nombre, duración, precio, hora de llegada/salida), cada una de estas estará separada por comas. Los datos serán strings, enteros (para la duración), y floats (para el precio y la hora de llegada/salida). Además, se hay que asegurarse de que al final del archivo csv no haya ningún salto de línea que indique que hay valores vacíos o algo por el estilo, pues el código quebraría.

## Descripción de las salidas del avance de proyecto

Las salidas dependerán de lo que quiera hacer el usuario, una vez elegida origen, se mostrarán los vuelos que salgan de ese lugar, el usuario obtendrá una lista con los vuelos ordenados por precio. Una vez seleccionado el vuelo, se generará un archivo de texto (ticket) donde saldrán los detalles del vuelo seleccionado por el usuario.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

Ya que se usará el shell sort, que en el mejor de los casos tiene una complejidad de O(nlog (n)) y en el peor de los casos O(n(log(n))^2).

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.

Dentro de mi clase de "list.h" con la lista ligada, la complejidad de cada uso es:
1. addFirst(T val): Su complejidad siempre es de O(1), pues agrega un elemento al inicio de la lista.
2. add(T val): Esta función agrega elementos al final de la lista, en el peor de los casos su complejidad es de O(n) al tener que recorrer toda la lista.
3. getsize(): Como lo único que hace es retornar un valor y no requiere iterar por alguna estructura, su complejidad es de O(1).
4. toString(): De igual manera, como recorre por cada uno de los elementos de la lista, su complejidad es de O(n).

En caso de los vectores utilizados en el programa en "flightManagement.h":
1. swap(): Complejidad de O(1) ya que solo involucra una simple operación.
2. showCities(): Crea un vector de los nombres únicos de las ciudades, que en el peor caso podría ser O(nlog n), luego itera por cada una de las ciudades en el nuevo vector para mostrarlas, que tomaría complejidad de O(n), por lo que tomando la mayor complejidad, sería de O(nlog n)
3. destinationList(): Ya que itera por todos los elementos del vector para saber cuál coincide con el criterio de búsqueda, la complejidad es de O(n).
4. getDestinations(): Complejidad de O(n) ya que se itera entre cada uno de los elementos del vector para extraer los valores de los destinos.

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.

Debido a que la función que tiene una mayor complejidad en el peor caso posible es la función sort(), que en el peor caso tiene una complejidad de O(n(log(n))^2), entonces se puede concluir que la complejidad temporal final del program es de O(n(log(n))^2).

Finalmente, asumiendo que la complejidad espacial requerida para cada operación es proporcional al número de vuelos, se puede concluir que la complejidad espacial es de O(n).

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

Para este proyecto se usará el shell sort ya que es un algoritmo con una eficiencia bastante buena, y ya que se trabajará con bases de datos bastante grandes, no será tan difícil implementarlo, además, en el peor de los casos (O(nlog(n)^2)), se comporta mejor que otros ordenamientos como el bubble o el insertion sort, que en el peor de los casos son O(n^2).

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.

Para el uso de vectores:
1. Los vectores proporcionan acceso aleatorio a los elementos en tiempo constante. Esta propiedad es beneficiosa cuando el sistema necesita acceder y manipular rápidamente elementos en posiciones específicas, como ordenar y mostrar vuelos.
2. Los vectores pueden cambiar de tamaño dinámicamente, lo que permite manejar un número variable de vuelos. Esto es importante en un sistema de gestión de vuelos en el que el número de vuelos puede cambiar con el tiempo.
3. Los vectores son eficientes para las operaciones de ordenación, lo que es evidente en el código donde la función de ordenación de la clase FlightManagement se aplica a un vector de vuelos basado en sus precios.

Para el uso de listas:
1. Las listas enlazadas son excelentes para insertar y eliminar elementos en tiempo constante, especialmente al principio o en medio de la lista. En el código, las funciones addFirst y add de la clase List se utilizan para añadir vuelos a la lista enlazada.
2. Las listas enlazadas pueden ser adecuadas para ciertos escenarios de iteración, especialmente cuando la operación principal implica recorrer la lista. En el código, la función showFlights itera sobre la lista enlazada para mostrar los detalles de los vuelos.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.

En el caso de los vectores, al ser estructuras de datos de tipo estático, facilitan los mecanismos para consultar información de estos, mediante acceso por índices y ciclos for para iterar por el vector.

En el caso de las listas, se declara una variable que pueda guardar el "índice" o la "posición" en donde se encuentra el vuelo, y en base a eso, recorrer la lista el número de veces necesario hasta llegar a esa posición, y consultar la información de ese nodo específico, es decir, se accede a todos los nodos hasta llegar al deseado, a diferencia de los vectores donde se puede acceder aleatoriamente con el índice específico de un elemento. Esto se puede observar en el archivo "flightManagement.h" en las funciones showFlights(), createTicket() y en el archivo "list.h" en la función toString().
 
#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.

El proyecto cuenta con un archivo csv, del cual se extraen los valores con los que se crearán los objetos de tipo vuelo, que posteriormente serán insertados en un vector, donde el usuario elegirá el criterio de ordenamiento y serán ordenados en un vector.
Posteriormente los objetos dentro del vector serán insertados en la lista ligada para mostrar cada uno de ellos.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta

Dentro del proyecto el mecanismo de escritura de archivo se puede observar en la función createTicket() dentro del archivo "flightManagement.h". El método hace uso de la función toString() del archivo "list.h", que recorre la lista el número de veces necesarias hasta llegar al vuelo que el usuario desea reservar. Finalmente obtiene los detalles de ese vuelo y los escribe en un archivo de salida llamado "Ticket.txt".

- [1. Formato de entrega](#1-formato-de-entrega)
  - [1.1. C++](#11-c)
    - [1.1.1. Cómo compilar](#111-cómo-compilar)
    - [1.1.2. Cómo realizar las inclusiones](#112-cómo-realizar-las-inclusiones)
      - [1.1.2.1. Con directorios](#1121-con-directorios)
      - [1.1.2.2. Sin directorios](#1122-sin-directorios)
    - [1.1.3. Aclaración sobre TADs](#113-aclaración-sobre-tads)
  - [1.2. Java](#12-java)
    - [1.2.1. Cómo compilar](#121-cómo-compilar)
    - [1.2.2. Cómo ejecutar](#122-cómo-ejecutar)
    - [1.2.3. Cómo realizar las importaciones](#123-cómo-realizar-las-importaciones)
      - [1.2.3.1. Con directorios](#1231-con-directorios)
      - [1.2.3.2. Sin directorios](#1232-sin-directorios)


# 1. Formato de entrega
El formato de entrega del obligatorio va a constar de un archivo zip que en su interior contenga únicamente archivos con extensiones “.cpp” y “.h” en caso de C/C++ o “.java” en caso de utilizar Java. También podrán existir directorios para organizar mejor el código y poder reutilizar implementaciones en varios ejercicios.

## 1.1. C++
En el caso de C/C++, la estructura dentro del zip tendrá el siguiente formato:
```
├── directorioA
├── directorioB
...
├── directorioZ
├── ejercicio1.cpp
├── ejercicio2.cpp
… 
└── ejercicioX.cpp
```

Por ejemplo, si tuviéramos 4 ejercicios, un posible zip a entregar podría tener:
```
├── funciones
│   └── enteros.cpp
├── tads
│   └── avl.cpp
├── ejercicio1.cpp
├── ejercicio2.cpp
├── ejercicio3.cpp
└── ejercicio4.cpp
```

Notar que es obligatorio que en la raíz del zip se encuentren los archivos “ejercicioX.cpp”. Los directorios para funciones auxiliares y TADs pueden llamarse de cualquier forma y no son obligatorios. Un ejemplo donde no se utilizan directorios auxiliares podría ser:
```
├── enteros.cpp
├── avl.cpp
├── ejercicio1.cpp
├── ejercicio2.cpp
├── ejercicio3.cpp
└── ejercicio4.cpp
```

### 1.1.1. Cómo compilar
La forma de compilar cada ejercicio es la vista en el curso, pasando por parámetro el archivo raíz “ejercicioX.cpp”, siendo X el número de ejercicio, e indicando en el parámetro “-o” el nombre del archivo compilado:
`g++ ejercicioX.cpp -o ejercicioX`

### 1.1.2. Cómo realizar las inclusiones
Las inclusiones parten del archivo “raíz” del programa, es decir, el “ejercicioX.cpp”.
Dependiendo de si los archivos a incluir se encuentran en el mismo directorio o no, es cómo se realizará la inclusión.
#### 1.1.2.1. Con directorios
Dado el siguiente caso:
```
├── funciones
│   └── enteros.cpp
├── tads
│   └── avl.cpp
..
```
Se definen las inclusiones de la siguiente manera:
```C++
#include "tads/avl.cpp"
#include "funciones/enteros.cpp"
```

#### 1.1.2.2. Sin directorios
Dado el caso en el que no se usan directorios:
```
├── enteros.cpp
├── avl.cpp
…
```
Se definen las inclusiones de la siguiente manera:
```C++
#include "avl.cpp"
#include "enteros.cpp"
```

### 1.1.3. Aclaración sobre TADs
Lo mas correcto seria especificar el TAD en un archivo `.h` (tad.h) y especificar el comportamiento en un archivo `cpp` (tad.cpp). Sin embargo, para simplificar, podemos definir todo en el archivo `.cpp`. Esta separacion se hace para poder utilizar muchas implementaciones y cambiarlas en tiempo de compilacion, no en codigo. Como no nos va a interesar cambiar la implementacion en tiempo de compilacion, vamos a definir todo directamente en el `.cpp`.

## 1.2. Java
En el caso de Java, la estructura dentro del zip tendrá el siguiente formato:
```
├── directorioA
├── directorioB
...
├── directorioZ
├── Ejercicio1.java
├── Ejercicio2.java
… 
└── EjercicioX.java
```

Por ejemplo, si tuviéramos 4 ejercicios, un posible zip a entregar podría tener:
```
├── funciones
│   └── Enteros.java
├── tads
│   └── AVL.java
├── Ejercicio1.java
├── Ejercicio2.java
├── Ejercicio3.java
└── Ejercicio4.java
```
Notar que es obligatorio que en la raíz del zip se encuentren los archivos “EjercicioX.java”. Los directorios para funciones auxiliares y TADs pueden llamarse de cualquier forma y no son obligatorios. Un ejemplo donde no se utilizan directorios auxiliares podría ser:
```
├── Enteros.java
├── AVL.java
├── Ejercicio1.java
├── Ejercicio2.java
├── Ejercicio3.java
└── Ejercicio4.java
```

### 1.2.1. Cómo compilar
La forma de compilar cada ejercicio es la vista en el curso, pasando por parámetro el archivo raíz `EjercicioX.java`, siendo X el número de ejercicio:
```shell
javac EjercicioX.java
```

### 1.2.2. Cómo ejecutar
La forma de ejecutar el archivo una vez compilado es:
```shell
java EjercicioX
```
### 1.2.3. Cómo realizar las importaciones
Las importaciones parten del archivo “raíz” del programa, es decir, el “EjercicioX.java”.
Dependiendo de si los archivos a incluir se encuentran en el mismo directorio o no, es cómo se realizan.
#### 1.2.3.1. Con directorios
Dado el siguiente caso:
```
├── funciones
│   └── Enteros.java
├── tads
│   └── AVL.java
..
```
Se definen las importaciones de la siguiente manera:
```java
import tads.AVL;
import funciones.Enteros;
```
Para que esto funcione es importante definir los paquetes java de las clases que se 
encuentran en esos directorios. 
Dado el ejemplo anterior, la clase Enteros.java debe definir su paquete al comienzo del archivo:
```java
package funciones;
```
De la misma forma lo debe hacer la clase AVL.java:
```java
package tads;
```
Las clases de la raíz, “EjercicioX.java” por ejemplo, no deben tener definido un paquete.

#### 1.2.3.2. Sin directorios
Dado el caso en el que no se usan directorios:
```
├── Enteros.java
├── AVL.java
..
```
No es necesario definir ninguna importación. Es importante que ninguna clase del directorio raíz tenga definido un paquete al comienzo de la misma.

# Indice
- [Instalacion](#instalacion)
- [WSL](#wsl)
- [Instalar Compiladores](#instalar-compiladores)
- [Compilar, Ejecutar, y Debuggear](#compilar-ejecutar-y-debuggear)
  - [C++](#c)
    - [Compilar](#compilar)
    - [Ejecutar](#ejecutar)
    - [Debuggear](#debuggear)
  - [Java](#java)
    - [Compilar](#compilar-1)
    - [Ejecutar](#ejecutar-1)
    - [Debuggear](#debuggear-1)
- [Comandos basicos de la terminal](#comandos-basicos-de-la-terminal)

# Instalacion
Vamos a estar utilizando sistemas operativos *nix para llevar a cabo el curso. Esto es unix/linux/macOs

Los que utilicen Windows 10 deberan [instalar WSL](#wsl) y una distribucion de linux (recomiendo Ubuntu)

En ambos casos vamos a tener que [instalar los compiladores](#instalar-compiladores) para los lenguajes que tengamos ganas


# WSL
[Instrucciones de Microsoft](https://docs.microsoft.com/en-us/windows/wsl/install-win10#manual-installation-steps)

1. Abrir powershell COMO ADMINISTRADOR y escribir 
```powershell
dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
```
 - De aca podemos salta al paso 6 ), pero es recomendable hacer los pasos en el medio ya que va a andar mejor

2. 
```powershell
dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart
```
3. Reiniciar la compu
4. 1. [Descargar actualizacion](https://wslstorestorage.blob.core.windows.net/wslblob/wsl_update_x64.msi), es chiquita, deberia ser muy rapido
   2. Instalar la actualizacion
5. En una terminal de powershell
```powershell
wsl --set-default-version 2
```
6. Descargar distribucion de linux. 
    - Vamos a la [Microsoft Store](https://aka.ms/wslstore) 
    - Buscamos la distribucion que tengamos ganas
    - En principio utilicen Ubuntu que es de las mas comunes
      - De todas formas la unica diferencia es que capaz alguna viene con mas programas instalados, y utilizan un package manager distinto (en vez de `apt`)

# Instalar Compiladores
- C++ - Podemos elegir el compilador `clang++` o `g++`
  - Ubuntu: `sudo apt install -y clang` o `sudo apt install -y g++`
    - Lo que significa cada comando
      - `sudo` nos da permisos de administrador ("Super User DO")
      - `apt install` apt es el package manager (como un app store) install es el comando para instalar un paquete
      - `-y` esto es opcional, le estamos diciendo que aceptamos todo, sino antes de instalar nos va a pregutnar si aceptamos y tenemos que poner `yes`
      - `clang` o `g++` el paquete que queremos instalar
  - MacOS: 
    - Abren una terminal y escriben `clang++` o `g++` y dan enter
    - Esto va a hacer que salte un prompt preguntando si quieren instalar las "command line tools", le dan que si y queda instalado
- Java
  - Ubuntu: `sudo apt install -y openjdk-16-jdk`
  - MacOS: seguir instrucciones para instalar [zulu-xx-jdk](https://docs.azul.com/core/zulu-openjdk/install/macos)

# Compilar, Ejecutar, y Debuggear
En ambos casos vamos a trabajar todo el codigo en unico archivo para simplificar. Esto va a significar codigo repetido, ya que vamos a tener que tener el TAD en el mismo archivo que nuestra solucion, pero a la hora de compilar les va a ser mas facil

## C++

### Compilar
Ambos compiladores funcionan igual, los ejemplos los vamos a escribir con `clang++`, pero basta sustituirlo por `g++` para utilizar el otro compilador
En la terminal estando parados sobre la misma carpeta que el archivo que queremos compilar
```
clang++ ./archivo.cpp -o ejecutable
```
### Ejecutar
Para ejecutar el programa, parados sorbe la misma carpeta que el archivo que queremos ejecutar
- Si queremos hacer el input a mano `./ejecutable`
- Si queremos que el input lo tome de un .txt `./ejecutable < ./input.txt`
- Si queremos que el output lo escriba en un archivo `./ejecutable > ./output.txt`
- Si queremos que el input lo tome de un archivo y el output lo escriba en un archivo `./ejecutable < ./input.txt > ./output.txt`

### Debuggear
Para debuggear debemos instalar un debugger, si estan en mac ya deberian tener instalado `lldb`, sino si lo escriben en una terminal y dan enter deberia instalarselo

Si estan en linux
- Si usan clang `sudo apt install -y lldb`
- Si usan g++ `sudo apt install -y gdb`

Luego si hacemos F5 en vscode, deberia saltar un cartel que nos dice que no tenemos una configuracion y nos ofrece una automaticamente

Siempre tenemos el viejo y querido
```c++
cout << "mi variable" << variable << endl;
```

## Java

### Compilar
En la terminal estando parados sobre la misma carpeta que el archivo que queremos compilar
```
javac ./ejemplo.java
```
Esto nos va a generar un archivo `ejemplo.class`

### Ejecutar
Para ejecutar el programa, parados sorbe la misma carpeta que el archivo que queremos ejecutar
- Si queremos hacer el input a mano `java ./ejemplo`
- Si queremos que el input lo tome de un .txt `java ./ejemplo < ./input.txt`
- Si queremos que el output lo escriba en un archivo `java ./ejemplo > ./output.txt`
- Si queremos que el input lo tome de un archivo y el output lo escriba en un archivo `ejemplo ./ejemplo < ./input.txt > ./output.txt`


### Debuggear
Abrimos el archivo en visual studio code, presionamos F5

Tenemos tambien el viejo y querido `System.out.println("mi variable: " + variable);`

# Comandos basicos de la terminal
| Comando                           | Descripcion                                                                                                                 |
| --------------------------------- | --------------------------------------------------------------------------------------------------------------------------- |
| `cd <directory>`                  | Change Directory: nos movemos a \<directory>                                                                                |
| `cd ..`                           | Nos movemos una carpeta para arriba                                                                                         |
| `ls`                              | List: lista los elementos de la carpeta que estamos parados                                                                 |
| `cat <file1> <file2> ... <filen>` | Concatenate: imprime los archivos que le pasamos en la terminal                                                             |
| `echo "cualquier mensaje"`        | Imprime el mensaje en la terminal                                                                                           |
| `<comando1> \| <comando2>`        | Toma el output del comando1 y lo ingresa como input al comando2                                                             |
| `<comando> < <archivo>`           | Ejecuta comando y le pasa el archivo como input (linea por linea, es decir, entre cada linea es como que presionemos enter) |
| `<comando> > <archivo>`           | Ejecuta el comando y guarda el output en el archivo                                                                         |

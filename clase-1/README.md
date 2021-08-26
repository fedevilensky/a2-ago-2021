# Codigo visto el 19 de agosto
Ademas del codigo visto en clase se agrego el esqueleto de Set y Map. Estos se corresponden con los TADs vistos en el teorico

Cosas que les quedan por hacer
- Terminar el codigo de `AVL`
- Implementar una version del TAD `Set` utilizando `AVL`
- Idem `Map` (en clase lo vimos como map o como tabla)

----------------------------------
Sobre Map, adentro usa la estructura `Pair`, en cualquiera de los dos lenguajes funciona igual. Adentro guarda una clave que pertenece al dominio, y un valor que pertenece al codominio. Cuando comparamos un objeto del tipo `Pair`, solo toma en cuenta el valor de la clave. 

Por ejemplo en C++ :
```c++
Pair p1 = Pair("clave", 42);
Pair p2 = Pair("clave", 58);
cout << p1 == p2; //imprime true porque la clave es la misma
```

En java:
```java
Pair p1 = new Pair("clave", 42);
Pair p2 = new Pair("clave", 58);
System.out.print(p1.compareTo(p2)) // imprime 0, porque la clave es la misma
```

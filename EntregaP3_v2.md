<center><b><font size="6">PROGRAMACIÓN III</font></b></center>

<center><b><font size="3">INFORME DE LA PRÁCTICA 2</center>
<center>(FUERZA BRUTA/GREEDY)</center>

----



**Nombre de los participantes:**

 - Marcos Jesús Santana Pérez
 - Chetani Mesa Guzmán
 - Ían Marrero Martín



**Descripción del problema a resolver:**

- <p align="justify">Por medio de combinaciones sin repetición, donde si importa el orden y los elementos son cogidos de n en n, queremos obtener el mayor valor generado de entre todas las permutaciones.



**Lenguajes de programación escogidos:**

- JAVA v1.8.0_191
- PYTHON v2.7
- C





























----

 <p style="background-color:rgb(240, 240, 240);"><b><font size="5">Estrategia de Fuerza Bruta</font>



<p align="justify"><b>1. Nombre de los ficheros que contienen el algoritmo de fuerza bruta implementado

- JAVA =>/[Pr3](https://github.com/Ian-M-M/Programacion-3/tree/master/Pr3)/[Java](https://github.com/Ian-M-M/Programacion-3/tree/master/Pr3/Java)/[src](https://github.com/Ian-M-M/Programacion-3/tree/master/Pr3/Java/src)/[Max](https://github.com/Ian-M-M/Programacion-3/tree/master/Pr3/Java/src/Max)/Main.java

- PYTHON =>/[Pr3](https://github.com/Ian-M-M/Programacion-3/tree/master/Pr3)/[Python](https://github.com/Ian-M-M/Programacion-3/tree/master/Pr3/Python)/main.py

- C =>



<p align="justify"><b>2. Copia de pantalla del fragmento de código que implementa el algoritmo de fuerza bruta (en los 3 lenguajes).


- JAVA

> <p align="justify">Nota: en java usamos BigInteger como portador de la concatenación de valores del array elementos (en el orden indicado por el array indices), puesto que el valor generado por dicha concatenación puede ser muy grande, incluso superior al que puede contener un long.

```java
public BigInteger Iterador (String [] elementos){
    int[] indices; // orden a mostrar de elementos
    Permutator p = new Permutator (elementos.length);
    BigInteger maximo = BigInteger.ZERO;
    while (p.hasMore ()) {
        indices = p.getNext ();//obtenemos siguiente permutacion
        BigInteger n = lstToBigInteger(elementos, indices);
        if(n.compareTo(maximo) > 0){// comprobamos si el nuevo n es mayor que maximo
            maximo = n;
        }
    }
    return maximo;
} 
```



- PYTHON

```python
# maximo contiene el valor mas grande encontrado hasta el momento
maximo = 0
# Hacemos una primera medida del time clock
time.clock()
for permutacion in itertools.permutations(lst):
    # Construimos el numero a partir de la lista permutada
    n = etc.lstToInt(permutacion)
    # Comprobamos si el nuevo n es mayor que maximo
    if n > maximo:
        maximo = n
```



- C

```c

```



<p align="justify"><b>3. Nombre de los ficheros que contienen el iterador (sólo en los lenguajes en los que hayan tenido que implementar el iterador)


- JAVA =>/[Pr3](https://github.com/Ian-M-M/Programacion-3/tree/master/Pr3)/[Java](https://github.com/Ian-M-M/Programacion-3/tree/master/Pr3/Java)/[src](https://github.com/Ian-M-M/Programacion-3/tree/master/Pr3/Java/src)/[Itertools](https://github.com/Ian-M-M/Programacion-3/tree/master/Pr3/Java/src/Itertools)/Permutator.java
- C =>



<p align="justify"><b>4. Explicación del iterador de permutaciones o combinaciones utilizado en cada lenguaje (en caso de haber utilizado un iterador disponible en el lenguaje, referenciar la página Web de documentación del iterador utilizado; en caso de haberlo programado, referenciar la página Web que describe el algoritmo implementado, o explicar el algoritmo implementado).


- JAVA => http://people.rennes.inria.fr/Arnaud.Gotlieb/resources/Java_exp/min/perm.htm
- PYTHON =>

- C =>Mismo algoritmo implementado en java, pero adaptado a C.



<p align="justify"><b>5. Formato del fichero de entrada del programa

Formato ".txt"



<p align="justify"><b>6. Copia de pantalla que muestre el uso del programa desde consola activando la opción que muestra el tiempo consumido en la ejecución del programa (en los tres lenguajes)


- JAVA =>

- PYTHON =>

- C =>



----

<p style="background-color:rgb(240, 240, 240)"><b><font size="5">Información adicional</font>






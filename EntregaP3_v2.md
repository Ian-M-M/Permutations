<center><b><font size="6">PROGRAMACIÓN III</font></b></center>

<center><b><font size="3">INFORME DE LA PRÁCTICA 2</center>
<center>(FUERZA BRUTA/GREEDY)</center>

----



**1. Nombre de los participantes:**

 - Marcos Jesús Santana Pérez
 - Chetani Mesa Guzmán
 - Ían Marrero Martín



**2. Descripción del problema a resolver:**

<p align="justify">Por medio de combinaciones sin repetición, donde si importa el orden y los elementos son cogidos de n en n, queremos obtener el mayor valor generado de entre todas las permutaciones.



**3. Lenguajes de programación escogidos:**

- JAVA v1.8.0_191
- PYTHON v2.7
- C





























----

 <p style="background-color:rgb(240, 240, 240);"><b><font size="5">Estrategia de Fuerza Bruta</font>


<p align="justify" style="color: #FF6666"><b>IMPORTANTE: PARA SABER COMO COMPILAR Y EJECUTAR EN CADA LENGUAJE, VER APARTADO DE INFORMACIÓN ADICIONAL AL FINAL DEL DOCUMENTO.


<p align="justify"><b>4. Nombre de los ficheros que contienen el algoritmo de fuerza bruta implementado

- JAVA =>/Pr3/Java/src/Max/Main.java

- PYTHON => /Pr3/Python/main.py

- C =>/Pr3/C/main.c



<p align="justify"><b>5. Copia de pantalla del fragmento de código que implementa el algoritmo de fuerza bruta (en los 3 lenguajes).

- JAVA

```java
public long BruteForce (String [] elementos){
    int[] indices; // orden a mostrar elementos[]
    Permutator p = new Permutator (elementos.length);
    long maximo = 0; // numero mas grande generado
    long n = 0;
    while (p.hasMore ()) {
        indices = p.getNext (); // obtenemos el orden que da lugar a la nueva 										// permutacion
        n = ToLong(elementos, indices); // permutacion actual
        if(n > maximo){ // comprobamos si el nuevo n es mayor que maximo
            maximo = n;
        }
    }
    return maximo;
}
```

- PYTHON

```python
def BruteForce (linea):
    lst = etc.lstStringToInt(linea)
    # maximo contiene el valor mas grande encontrado hasta el momento
    maximo = 0
    for permutacion in itertools.permutations(lst):
        # Construimos el numero a partir de la lista permutada
        n = etc.lstToInt(permutacion)
        # Comprobamos si el nuevo n es mayor que maximo
        if n > maximo:
            maximo = n
return maximo
```

- C

```C
long long BruteForce (char **elementos,int tamElementos,int * nDigElementos) {
	int *indices = malloc(tamElementos*sizeof(int));
	Permutator(tamElementos);
	long long maximo = 0;
	long long valor = 0;
	while(hasMore()) {
		indices = getNext();
		valor = ToLong(elementos, indices, tamElementos, nDigElementos);
		if (valor > maximo) {
      		maximo = valor;
  		}
	}
	return maximo;
}
```





<p align="justify"><b>6. Nombre de los ficheros que contienen el iterador (sólo en los lenguajes en los que hayan tenido que implementar el iterador)

- JAVA =>/Pr3/Java/src/Itertools/Permutator.java
- C =>/Pr3/C/permutator.c




<p align="justify"><b>7. Explicación del iterador de permutaciones o combinaciones utilizado en cada lenguaje (en caso de haber utilizado un iterador disponible en el lenguaje, referenciar la página Web de documentación del iterador utilizado; en caso de haberlo programado, referenciar la página Web que describe el algoritmo implementado, o explicar el algoritmo implementado).
- JAVA

<p align="justify">El código del iterador fue desarrollado en base al código que se encuentra en la siguiente página web: 

http://people.rennes.inria.fr/Arnaud.Gotlieb/resources/Java_exp/min/perm.htm

<p align="justify">En nuestra adaptación nos deshicimos de los métodos que nunca se llegaban a utilizar, cambiamos los tipos "BigInteger" por "long", y pusimos comentarios que muestran que se pretende hacer en cada momento con mayor claridad.

<p align="justify">Cabe decir que el algoritmo empleado para generar las permutaciones, fue descrito por Kenneth H.Rosen en su libro <i>"Discrete Mathematics and Its Applications,2nd edition (NY: McGraw-Hill, 1991), pp. 282-284"</i>, y como sabemos que puede ser algo tedioso encontrar dicho libro, ofrecemos capturas de pantalla de las páginas del libro donde se habla del algoritmo.



![](C:\Users\carta\Desktop\Entrega_P3_v2\pag 435 Permutation generator.PNG)



![](C:\Users\carta\Desktop\Entrega_P3_v2\pag 436 Permutation generator.PNG)











- PYTHON

<p align="justify">El itertools es muy parecido al que se emplea en Java y C.</p><p>Se basa en una lista que contiene los índices que referencian al array
    pertinente, la idea es ir moviendo los <b>índices</b>
de derecha a izquierda, además de ayudarse de una lista llamada cycle que cuenta las veces que se ha
devuelto el elemento en esa posición. A continuación se verá mejor:

```python
pool = tuple(iterable)
n = len(pool)
r = n if r is None else r
if r > n:
    return
indices = range(n)
cycles = range(n, n-r, -1)
```

<p align ="justify">La primera parte del algoritmo se encarga de preparar el terreno, ya que hace una copia de la lista pasada, coge la longitud de dicha lista, y en caso de necesitar <b>r</b>, la crea y guarda. Una vez hecho esto se crea índices, que es un rango que va desde [0, n], ambos inclusive. También se crea cycles, que va a contener el rango que va de <b>n</b> a <b>r</b>.<p>La forma de devolver una permutación es la siguiente:</p>

```python
yield tuple(pool[i] for i in indices[:r])
```

<p align="justify"><b>yield</b> hace lo mismo que un <b>return</b> pero con la capacidad de que si se llama otra vez a la función, esta continua su ejecución desde la instrucción siguiente al <b>yield</b>.
	<p align="justify">
        El <b>while</b> que sigue funciona como un bucle infinito 			que se encarga de generar el resto de permutaciones:
	</p> 
</p>

```python
while n:
    for i in reversed(range(r)):
        cycles[i] -= 1
    	if cycles[i] == 0:
        	indices[i:] = indices[i+1:] + indices[i:i+1]
        	cycles[i] = n - i
    	else:
        	j = cycles[i]
        	indices[i], indices[-j] = indices[-j], indices[i]
        	yield tuple(pool[i] for i in indices[:r])
        	break
    else:
    	return
```

<p align="justify">
    Dentro del <b>while</b> se recorre de derecha a izquierda la 		lista <b>cycles</b> que va a "contar" las veces que se han usado     los indices para verlo con claridad vamos a separar el <b>if</b> 	  y el <b>else</b> del for:
    <p align="justify">
        Nota: Tener en cuenta que antes que nada se decrementa el 			contador que contiene <b>cycles</b> en la posición <b>i</b>:
	</p>
</p>

```python
cycles[i] -= 1
```

<p align="justify">Ahora veamos ese <b>if</b> de cerca:</p>

```python
if cycles[i] == 0:
    indices[i:] = indices[i+1:] + indices[i:i+1]
    cycles[i] = n - i
```

<p align="justify">
    Lo que ocurrirá cuando <b>cycles[i] == 0</b>, es que lo que 		había en la posición <b>i</b> se irá al final de la lista y lo 		que había de <b>i</b> a la derecha, pues se moverá una posición 	a la izquierda. Ej: si tuviéramos la lista [4, 5, 6, 7] y 			quisiéramos hacer esta operación de desplazamiento masivo en la 	posición i = 1, veriamos lo siguiente:
	<p align="center">
        [4, <b>5</b>, 6, 7]  >> [4, <b>6</b>, <b>7</b>, 5]
	</p>
	<p align="justify">
    Además de esta migración de elementos también se reinicia el 		valor inicial de <b>cycles[i]</b>.
    	<p align="justify">
            Bien ahora vendría lo que ocurrirá cuando <b>cycles[i]				</b> tenga un valor distinto de 0, es decir que es una 				que no hemos hecho:
		</p>
	</p>
</p>

```python
else:
    j = cycles[i]
    indices[i], indices[-j] = indices[-j], indices[i]
    yield tuple(pool[i] for i in indices[:r])
    break
```

<p align="justify">
    Aquí se hace un swap entre la posición <b>i</b> y <b>-j</b>, 		este último no es apunte a alguna posición negativa, sino que 		python cuenta las posiciones negativas como si leyese la lista 		de derecha a izquierda, es decir, es la forma que tiene de leer 	las posiciones invertidas.
    <p align="justify">
        El ultimo <b>else</b> pertenece al <b>for</b> e indica que 			cuando se ejecute el <b>for</b> sin ejecutar ningún break, 			se hará el <b>return</b>.
	</p>
</p>



- C 

Mismo algoritmo implementado en java, pero adaptado a C.























<p align="justify"><b>8. Formato del fichero de entrada del programa

El fichero contendrá cada elemento de un conjunto separado por una coma. Cada conjunto de elementos se pondrá en una linea nueva.

Formato:

```
[elemento1],[elemento2]
[elemento1],[elemento2],[elemento3],[elemento4]
```



> Nota:
>
> Tanto en Java (que usa el tipo long) como en C (que usa tipo long long) para representar el valor que queremos obtener, tenemos la limitación de que solo se pueden representar 2^63-1 números, por encima del 0 (numeros de 19 cifras). Dicho esto, se recomienda no usar elementos cuya suma de cifras sea mayor a 18.



<p align="justify"><b>9. Copia de pantalla que muestre el uso del programa desde consola activando la opción que muestra el tiempo consumido en la ejecución del programa (en los tres lenguajes)

- JAVA

![java](C:\Users\carta\Desktop\Entrega_P3_v2\java.png)












- PYTHON

![python](C:\Users\carta\Desktop\Entrega_P3_v2\python.png)




- C 

![C](C:\Users\carta\Desktop\Entrega_P3_v2\C.png)











----

<p style="background-color:rgb(240, 240, 240)"><b><font size="5">Información adicional</font>


- JAVA

> Instrucciones de compilación y ejecución con Java:
>
> 1. COMPILACIÓN:
>
>    **javac -sourcepath src -d build src/\*\*/\*.java**
>
>    **[ -sourcepath src ]**  selecciona src como carpeta donde se encuentra el codigo fuente.
>
>    **[-d build src/\*\*/\*.java]** selecciona build como directorio donde se guardaran los archivos compilados y src/\*\*/\*.java indica los archivos que se quieren compilar.
>
> 2. EJECUCIÓN:
>    **java -cp .:build:\*\*/\*.class Max.Main**
>    con la instruccion anterior podemos ejecutar todos los archivos de la carpeta build, e indicarle que Max.Main es donde se encuentra el main de nuestro programa.
>    A la derecha del Max.Main podemos indicarle diversos parámetros al programa.
>
>
> 3. PARÁMETROS ADMITIDOS:
>
>    - **-di**: (Debug Input) Permite mostrar el contenido del fichero pasado por parámetro.
>
>    - **-f file**: Indica al programa el input del que se van a obtener los conjuntos de elementos.
>
>    - **-do**: (Debug Output) Permite mostrar el valor máximo obtenido combinando los elementos del conjunto.
>
>    - **-t**: Permite mostrar el tiempo que se ha tardado en calcular el valor máximo.



- PYTHON

> Instrucciones de ejecución con python:
>
> 1. INTERPRETACIÓN:
>
>    **python main.py** ó **python2 main.py**
>    A la derecha del main.py van los parámetros del programa.
>
>
> 2. PARÁMETROS ADMITIDOS:
>
>    - **-di**: (Debug Input) Permite mostrar el contenido del fichero pasado por parámetro.
>
>    - **-f file**: Indica al programa el input del que se van a obtener los conjuntos de elementos.
>
>    - **-do**: (Debug Output) Permite mostrar el valor máximo obtenido combinando los elementos del conjunto.
>
>    - **-t**: Permite mostrar el tiempo que se ha tardado en calcular el valor máximo.
>    - **-h**: Despliega un menú de ayuda, que ofrece información acerca de los parámetros que se pueden utilizar.



- C

> Instrucciones de compilación y ejecución con C:
>
> 1. COMPILACIÓN:
>
>    **gcc \*.c -o nombre_del_programa**
>
> 2. EJECUCIÓN:
>    **./nombre_del_programa**
>    A la derecha del main.c van los parámetros del programa.
>
>
> 3. PARÁMETROS ADMITIDOS:
>
> - **<u>--di</u>**: (Debug Input) Permite mostrar el contenido del fichero pasado por parámetro.
>
> - **-f file**: Indica al programa el input del que se van a obtener los conjuntos de elementos.
>
> - **<u>--do</u>**: (Debug Output) Permite mostrar el valor máximo obtenido combinando los elementos del conjunto.
>
> - **-t**: Permite mostrar el tiempo que se ha tardado en calcular el valor máximo.
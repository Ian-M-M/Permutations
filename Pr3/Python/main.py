import itertools
import time
import etc

path = etc.obtenerPath()

fichero = etc.abrirFichero(path)

print ("--------------------------------------------")

for linea in etc.lectura(fichero):

    lst = etc.lstStringToInt(linea)
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
    # Hacemos la segunda llamada al time.clock para calcular el tiempo que se tarda en hacer las permutaciones
    etc.paraTimer()
    print ("Mayor Permutacion => "), (maximo)
    print ("--------------------------------------------")

etc.cerrarFichero(fichero)

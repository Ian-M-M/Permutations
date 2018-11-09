import itertools
import time
import LeerFichero
import lista

path = LeerFichero.obtenerPath()

fichero = LeerFichero.abrirFichero(path)

print ("--------------------------------------------")

for linea in LeerFichero.lectura(fichero):

    lst = lista.lstStringToInt(linea)
    # maximo contiene el valor mas grande encontrado hasta el momento
    maximo = 0
    # Hacemos una primera medida del time clock
    time.clock()

    for permutacion in itertools.permutations(lst):

        # Construimos el numero a partir de la lista permutada
        n = lista.lstToInt(permutacion)
        # Comprobamos si el nuevo n es mayor que maximo
        if n > maximo:
            maximo = n
    # Hacemos la segunda llamada al time.clock para calcular el tiempo que se tarda en hacer las permutaciones
    print ("Tiempo => "), (time.clock()), ("s")
    print ("Mayor Permutacion => "), (maximo)
    print ("--------------------------------------------")

LeerFichero.cerrarFichero(fichero)

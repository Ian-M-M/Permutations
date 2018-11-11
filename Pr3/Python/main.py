import etc
import itertools

"""
    NextIteration => Calcula las permutaciones posibles de 'linea', y devuelve la N mayor de estas combinaciones,
    siendo N => la combinacion de una permutacion tal que si linea es [1,2] N sera igual a  21.Todo esto aplicando
    un algoritmo de fuerza bruta
"""
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

fichero = etc.abrirFichero (etc.obtenerPath() )

print ("--------------------------------------------")

for linea in etc.lectura(fichero):

    # Hacemos una primera medida del time clock
    etc.time.clock()

    maximo = BruteForce(linea)

    # Hacemos la segunda llamada al time.clock para calcular el tiempo que se tarda en hacer las permutaciones
    etc.paraTimer()
    print ("Mayor Permutacion => "), (maximo)
    print ("--------------------------------------------")
etc.cerrarFichero(fichero)

import argparse

import etc
import itertools

"""
    ProcesaArgumentos => Funcion que procesa los argumentos que se usan al ivocar al programa.
"""


def ProcesaArgumentos():
    parser = argparse.ArgumentParser()
    parser.add_argument("-t","--time", action='store_true',
                        help="Muestra el tiempo que se tarda en ejecutar dichas hacer las permutaciones.")
    parser.add_argument("-f", "--file", required=True,
                        help="Se usara F para calcular las permutaciones y ejecutar el programa.")
    parser.add_argument("-di", action='store_true',
                        help="Muestra el contenido del input.")
    parser.add_argument("-do"   , action='store_true',
                        help="Muestra el contenido del output.")

    args = parser.parse_args()

    if args.time:
        global flagT
        flagT = 1
    if args.file:
        global flagF
        flagF = 1
    if args.di:
        global flagDi
        flagDi = 1
    if args.do:
        global flagDo
        flagDo = 1

    return args


"""
    NextIteration => Calcula las permutaciones posibles de 'linea', y devuelve la N mayor de estas combinaciones,
    siendo N => la combinacion de una permutacion tal que si linea es [1,2] N sera igual a  21.Todo esto aplicando
    un algoritmo de fuerza bruta
"""



def BruteForce(lst):

    # maximo contiene el valor mas grande encontrado hasta el momento
    maximo = 0

    for permutacion in itertools.permutations(lst):

        # Construimos el numero a partir de la lista permutada
        n = etc.lstToInt(permutacion)
        # Comprobamos si el nuevo n es mayor que maximo
        if n > maximo:
            maximo = n
    return maximo

def optDo(linea):
    lst = etc.lstStringToInt(linea)
    print "n elementos => ", lst
    if flagT == 1:
        # Hacemos una primera medida del time clock
        etc.time.clock()
    maximo = BruteForce(lst)

    if flagT == 1:
        # Hacemos la segunda llamada al time.clock para calcular el tiempo que se tarda en hacer las permutaciones
        etc.paraTimer()
    if flagDo == 1:
        print ("Mayor Permutacion => "), (maximo)


def optDi(fichero):
    global path
    print "Nombre del fichero => ",etc.obtnerArchivo(path)
    print "-----------------------------"
    for linea in fichero:
        print linea.rstrip('\n')
    etc.cerrarFichero(fichero)


flagF = 0
flagT = 0
flagDi = 0
flagDo = 0

args = ProcesaArgumentos()

if (flagT == 0) and (flagF == 0) and (flagDi == 0) and (flagDo == 0):
    print "Para que el programa funciones correctemente use alguno de los comandos disponibles, 'python main.py -h'"
    exit(1)

path = ""
if flagF != 0:
    path = args.file

fichero = etc.abrirFichero(etc.obtenerPath(path))

if flagDi == 1:
    ficheroAux = fichero
    optDi(fichero)
    print "-----------------------------"

if flagDo == 1:

    fichero = etc.abrirFichero(etc.obtenerPath(path))

    for linea in etc.lectura(fichero):
        if flagDo == 1:
            optDo(linea)
            print "-----------------------------"

etc.cerrarFichero(fichero)


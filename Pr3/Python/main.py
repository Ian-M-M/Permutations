import argparse

import etc
import itertools

"""
    ProcesaArgumentos => Funcion que procesa los argumentos que se usan al invocar al programa.
"""
def ProcesaArgumentos():
    # creamos el objeto que contedra las opciones
    parser = argparse.ArgumentParser()

    # agregamos las opciones
    parser.add_argument("-t","--time", action='store_true',
                        help="Muestra el tiempo que se tarda en ejecutar dichas hacer las permutaciones.")
    parser.add_argument("-f", "--file", required=True,
                        help="Se usara F para calcular las permutaciones y ejecutar el programa.")
    parser.add_argument("-di", action='store_true',
                        help="Muestra el contenido del input.")
    parser.add_argument("-do"   , action='store_true',
                        help="Muestra el contenido del output.")
    # establecemos que queremos que actuen como opciones del programa
    args = parser.parse_args()

    # establecemos que ocurrira con cada opcion, cuando esta se active.
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
   optDo => funcion que se encarga de ejecutar la funcion -do y/o -t, debug output 
"""
def optDo(linea):

    # obtenemos la lista de enteros de 'linea'
    lst = etc.lstStringToInt(linea)
    # Comprobamos que se halla activado la opcion -do para mostrar el contenido de linea
    if flagDo == 1:
        print "n elementos => ", "{",
        for i in lst:
            print i,
        print "}"

    if flagT == 1:
        # Hacemos una primera medida del time clock
        etc.time.clock()
    # Calculamos el maximo mediante fuerza bruta.
    maximo = BruteForce(lst)

    if flagT == 1:
        # Hacemos la segunda llamada al time.clock para calcular el tiempo que se tarda en hacer las permutaciones
        etc.paraTimer()
    if flagDo == 1:
        # Mostramos la mayor permutacion
        print ("Mayor Permutacion => "), (maximo)



"""
    BruteForce => funcion que implementa el algoritmo de fuerza bruta para el problema propuesto
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


# flags necesarios para saber que modos se activaron
flagF = 0
flagT = 0
flagDi = 0
flagDo = 0

args = ProcesaArgumentos()

# En caso de no tener ningun modo activado, nos salimos
if (flagT == 0) and (flagF == 0) and (flagDi == 0) and (flagDo == 0):
    print "Para que el programa funciones correctemente use alguno de los comandos disponibles, 'python main.py -h'"
    exit(1)

# tomamos la ruta del archivo
path = args.file

# abrimos el archivos
fichero = etc.abrirFichero(etc.obtenerPath(path))

if flagDi == 1:
    print "Nombre del fichero => ", path
    etc.optDi(fichero)
    print "--------------------------------------------------"

if flagDo == 1 or flagT == 1:

    if flagDi == 1:
        # si hemos activado el modo -di necesitamos abrir el fichero de nuevo
        fichero = etc.abrirFichero(etc.obtenerPath(path))
    # recorremos el archivo con los elementos a permutar
    for linea in etc.lectura(fichero):
        optDo(linea)
        print "--------------------------------------------------"

etc.cerrarFichero(fichero)
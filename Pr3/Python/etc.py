import os
import time
"""
    lstStringToInt(linea) => Convierte la lista
    de Strings a lista de enteros
"""
def lstStringToInt(linea):
    lst = linea.split(",")
    # Lista de strings a lista de integers
    lst = [int(i) for i in lst]
    mostrarlst(lst)
    return lst

"""
    mostrarlst(lst) => muestra la cantidad de elementos de 'lst'
    y el contenido
"""
def mostrarlst(lst):
    print ("n elem => "), (len(lst)), (" => "), (lst)

"""
    lstToInt(permutacion) => Convierte la lista 'permutacion' a
    un unico numero entero positivo
"""
def lstToInt(permutacion):
    n = "".join(str(e) for e in permutacion)
    int(n)
    return n
"""
    obtenerPath => Obtiene el path del fichero de lectura
    del que obtendremos los valores a permutar 
"""
def obtenerPath():
    """"
     'os.path.pardir' => Cambias el directorio de trabajo a la
     carpeta padre donde esta el archivo de lectura
     'os.path.join' => Construimos el path que accede al archivo de lectura
    """
    path = os.path.join(os.path.pardir, "Permutaciones.txt")
    return path
"""
    abrirFichero => Abre el fichero de lectura
"""
def abrirFichero(path):
    return open(path, 'r')


"""
    cerrarFichero => Cierra el fichero de lectura
"""
def cerrarFichero (fichero):
    fichero.close #:type fichero: object
"""
    lectura => Lee linea a linea el fichero de lectura
"""
def lectura(fichero):
    for linea in fichero:
        yield linea
"""
"""
def comienzaTimer():
    return time.clock()
"""
"""
def paraTimer():
    print "Tiempo => ", time.clock()," s"
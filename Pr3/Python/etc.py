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
    return lst

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
def obtenerPath(path):
    """"
     'os.path.pardir' => Cambias el directorio de trabajo a la
     carpeta padre donde esta el archivo de lectura
     'os.path.join' => Construimos el path que accede al archivo de lectura
    """
    return os.path.abspath(path)

def obtnerArchivo(path):
    return os.path.basename(path)

"""
    abrirFichero => Abre el fichero de lectura
"""
def abrirFichero(path):
    return open(path, 'r')


"""
    cerrarFichero => Cierra el fichero de lectura
"""
def cerrarFichero (fichero):
    fichero.close
"""
    lectura => Lee linea a linea el fichero de lectura
"""
def lectura(fichero):
    for linea in fichero:
        yield linea

"""
"""
def paraTimer():
    print "Tiempo => ", time.clock()," s"


"""
    optDi => funcion que se encarga de realizar la funcion -di, debug input.
"""
def optDi(fichero):

    print "--------------------------------------------------"
    for linea in fichero:
        print linea.rstrip('\n')
    cerrarFichero(fichero)
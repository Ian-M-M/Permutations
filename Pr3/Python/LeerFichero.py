import os

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

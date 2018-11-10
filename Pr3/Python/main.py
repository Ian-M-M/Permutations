import etc
import Iterator

path = etc.obtenerPath()

fichero = etc.abrirFichero(path)

print ("--------------------------------------------")

for linea in etc.lectura(fichero):
    Iterator.NextIteration(linea)

etc.cerrarFichero(fichero)

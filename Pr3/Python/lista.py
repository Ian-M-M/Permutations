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
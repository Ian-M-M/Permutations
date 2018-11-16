package Max;
import static Max.etc.*;
import Itertools.Permutator;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;

public class Main {
    public static void main(String[] args) throws FileNotFoundException, IOException{
        Main clase= new Main();
        GetParam(args); // se leen los parametros pasados al programa y se activan
                        // los flag correspondientes
        if(di_flag)Input(); // debug input
        if(!do_flag && !t_flag)System.exit(0);
        FileReader fichero = new FileReader(path); // fichero a leer
        BufferedReader br = new BufferedReader(fichero);  // cargamos el fichero en un buffer
        String linea="";

        while((linea = br.readLine()) != null){
            String [] elementos = linea.split(","); // elementos obtenidos del fichero
            if(t_flag)ComienzaTimer(); // comenzamos a contar el tiempo de ejecucion
            long maximo = clase.BruteForce(elementos); // algoritmo de fuerza bruta
            if(t_flag)ParaTimer(); // calculamos el tiempo de ejecucion
            if(do_flag)Output(elementos, maximo); // debug output
            if(t_flag)T_Output(); // se muestran los tiempos de ejecucion
        }
        br.close(); // cerramos el buffer
    }


    /*
      BruteForce(String[] elementos): Calcula la permutacion que se corresponde
      con el numero mas grande que se puede generar y lo devuelve.
    */
    public long BruteForce (String [] elementos){
        int[] indices; // orden a mostrar de elementos
        Permutator p = new Permutator (elementos.length);
        long maximo = 0; // numero mas grande generado
        long n = 0;
        while (p.hasMore ()) {
            indices = p.getNext (); // obtenemos el orden que da lugar a la nueva permutacion
            n = ToLong(elementos, indices); // permutacion actual
            if(n > maximo){ // comprobamos si el nuevo n es mayor que maximo
                maximo = n;
            }
        }
        return maximo;
    }
}

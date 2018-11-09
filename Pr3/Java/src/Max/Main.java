package Max;
import static Max.etc.*;
import Itertools.Permutator;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;
import java.text.DecimalFormat;

public class Main {
    public static void main(String[] args) throws FileNotFoundException, IOException{        
        Main clase= new Main();        
        String path = "../Permutaciones.txt";
        FileReader fichero = new FileReader(path);
        BufferedReader br = new BufferedReader(fichero);// cargamos el fichero en un buffer
        String linea="";

        while((linea = br.readLine()) != null){
            String [] elementos = linea.split(",");//elementos obtenidos del fichero
            ComienzaTimer();//Comenzamos a contar el tiempo de ejecucion
            BigInteger maximo = clase.Iterador(elementos);//iterador
            ParaTimer();//Calculamos el tiempo de ejecucion
            Output(elementos, maximo);//info a imprimir por pantalla
        }
        br.close();
    }    
    
    public BigInteger Iterador (String [] elementos){
        int[] indices; // orden a mostrar de elementos
        Permutator p = new Permutator (elementos.length);
        BigInteger maximo = BigInteger.ZERO;
        while (p.hasMore ()) {
            indices = p.getNext ();
            BigInteger n = lstToBigInteger(elementos, indices);
            if(n.compareTo(maximo) > 0){// comprobamos si el nuevo n es mayor que maximo
                maximo = n;
            }
        }
        return maximo;
    } 
}
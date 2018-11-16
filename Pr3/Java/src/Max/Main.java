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

        GetParam(args);

        if(di_flag)Input();
        if(!do_flag && !t_flag)System.exit(0);
        FileReader fichero = new FileReader(path);
        BufferedReader br = new BufferedReader(fichero);// cargamos el fichero en un buffer
        String linea="";

        while((linea = br.readLine()) != null){
            String [] elementos = linea.split(",");//elementos obtenidos del fichero
            if(t_flag)ComienzaTimer();//Comenzamos a contar el tiempo de ejecucion
            long maximo = clase.BruteForce(elementos);//iterador
            if(t_flag)ParaTimer();//Calculamos el tiempo de ejecucion
            if(do_flag)Output(elementos, maximo);//info a imprimir por pantalla
            if(t_flag)T_Output();
        }
        br.close();
    }


        public long BruteForce (String [] elementos){
        int[] indices; // orden a mostrar de elementos
        Permutator p = new Permutator (elementos.length);
        long maximo = 0;
        while (p.hasMore ()) {
            indices = p.getNext ();// obtenemos el orden que da lugar a la permutacion
            long n = ToLong(elementos, indices);
            if(n > maximo){// comprobamos si el nuevo n es mayor que maximo
                maximo = n;
            }
        }
        return maximo;
    }
}

package Max;
import java.io.BufferedReader;
import java.io.FileReader;
import java.text.DecimalFormat;
import javax.sound.midi.SysexMessage;

public class etc {
    // Punteros
    public static boolean f_flag=false, t_flag=false, di_flag=false, do_flag=false;
    public static String path="";


    /*
      GetParam(String[]args): Lee los parametros pasados al programa, por medio
      del array "args". De esta forma se identifican y se activan los flags
      correspondientes, que permiten activar unas operaciones u otras.
    */
    public static void GetParam(String [] args){
        if (args.length==0) System.exit(1);
        for (int i = 0; i < args.length; i++) {
            if(args[i].equals("-f")){
                f_flag=true;
                path=args[i+1];
            }
            if(args[i].equals("-t"))t_flag=true;
            if(args[i].equals("-di"))di_flag=true;
            if(args[i].equals("-do"))do_flag=true;
        }
        if (!f_flag){
            System.err.println("Ha de introducir un fichero");
            System.exit(1);
        }
    }


    /*
      Input(): Es llamado cuando se usa la opcion -di. Tiene la funcion de mostrar
      por pantalla el contenido del fichero pasado al programa por parametros.
    */
    public static void Input(){
        try{
            System.out.println(path);
            FileReader fichero = new FileReader(path);
            BufferedReader br = new BufferedReader(fichero);// cargamos el fichero en un buffer
            String linea="";
            while((linea = br.readLine()) != null){
                System.out.println(linea);
            }
            br.close();
            System.out.println("-------------------------------------------------");
        }catch (Exception e){
            System.err.println("Error al leer input");
        }
    }

    // Variables para medir el tiempo
    private static long timer;
    private static double tiempoTranscurrido;


    /*
      ComienzaTimer(): Toma el valor del instante actual y lo guarda en "timer".
    */
    public static void ComienzaTimer(){
        timer = System.nanoTime();
    }


    /*
      ParaTimer(): Calcula el tiempo transcurrido desde el momento en que se
      asigno un valor a "timer" hasta el momento actual y se guarada en la variable
      "tiempoTranscurrido".
    */
    public static void ParaTimer(){
        tiempoTranscurrido = (System.nanoTime() - timer)/(1000000000.);
    }


    /*
      ToLong(): usando "indices" se escogen las posiciones de los elementos del
      conjunto "elementos" que dan lugar a la permutacion correspondiente, que
      sera devuelta con formato long.
    */
    public static long ToLong(String [] elementos, int [] indices){
        StringBuffer permutacion = new StringBuffer();
        for (int i = 0; i < indices.length; i++) {
            permutacion.append (elementos[indices[i]]);
        }
        return Long.parseLong(permutacion.toString());
    }

    public static int contador=1;//nº de veces que se llama al timer


    /*
      Output(String [] elementos, long maximo): Es llamado cuando -do ha sido
      solicitado. Su funcion será la de imprimir por pantalla el mayor numero
      obtenido gracias al algoritmo de fuerza bruta "maximo". Adicionalmente
      imprime por pantalla los elementos del conjunto "elementos".
    */
    public static void Output(String [] elementos, long maximo){
        System.out.print("Elementos [" + elementos.length + "] => { ");
        for (int i = 0; i < elementos.length; i++) {
            System.out.print(elementos[i] + " ");
        }
        System.out.println("}");
        System.out.println("Maxima permutacion => " + maximo);
        if(!t_flag)System.out.println("-------------------------------------------------");
    }


    /*
      T_Output: imprime por pantalla el tiempo transcurrido desde que se llamo a
      la funcion ComienzaTimer
    */
    public static void T_Output(){
        DecimalFormat df = new DecimalFormat("#.#########");
        if(!do_flag){
            System.out.print(contador + ".");
            contador++;
        }
        System.out.println("Tiempo => " + df.format(tiempoTranscurrido) + "s");
        System.out.println("-------------------------------------------------");
    }
}

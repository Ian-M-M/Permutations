package Max;

import java.math.BigInteger;
import java.text.DecimalFormat;

public class etc {
    
    // TIMERS //////////////////////////////////////////////////////////////////
    
    private static long timer;
    private static double tiempoTranscurrido;
    
    public static void ComienzaTimer(){
        timer = System.nanoTime();
    }
    
    public static void ParaTimer(){
        tiempoTranscurrido = (System.nanoTime() - timer)/(1000000000.);     
    }
    
    // LST OPERATIONS //////////////////////////////////////////////////////////
    
    public static long ToLong(String [] elementos, int [] indices){
        StringBuffer permutacion = new StringBuffer();
        for (int i = 0; i < indices.length; i++) {
            permutacion.append (elementos[indices[i]]);
        }        
        return Long.parseLong(permutacion.toString());
    }
    
    // OUTPUT //////////////////////////////////////////////////////////////////
    
    public static void Output(String [] elementos, long maximo){
        System.out.print("Elementos [" + elementos.length + "] => { ");
        for (int i = 0; i < elementos.length; i++) {
            System.out.print(elementos[i] + " ");            
        }
        System.out.println("}");
        
        DecimalFormat df = new DecimalFormat("#.#########");
        System.out.println("Tiempo => " + df.format(tiempoTranscurrido) + "s");
        
        System.out.println("Maxima permutacion => " + maximo);
        System.out.println("-------------------------------------------------");  
    }
    
}

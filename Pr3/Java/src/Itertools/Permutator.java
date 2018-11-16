package Itertools;

public class Permutator {
    private int[] a;
    private long numLeft;
    private long total;

    /*
      Pemutador(int n): Crea e inicializa el array "a" de tamaño "n" igual al numero de
      elementos, que tendra las posiciones de los elementos a permutar y Calcula
      el numero de iteraciones totales.
    */
    public Permutator (int n) {
        if (n < 1) throw new IllegalArgumentException ("Min 1");
        a = new int[n]; // array que tendra las posiciones a mostrar de los elementos
        total = getFactorial (n); // nº de iteraciones totales (n! porque estamos permutando)
        reset ();
    }

    /*
      reset(): Inicializa el array con las posiciones de la 1º permutacion.
    */
    public void reset () {
        for (int i = 0; i < a.length; i++) {
          a[i] = i;
        }
        numLeft = total; // nº de permutaciones restantes
    }

    /*
      hasMore(): Devuelve true si quedan iteraciones restantes, false en caso
      contrario.
    */
    public boolean hasMore () {
        return numLeft > 0;
    }

    /*
      getFactorial(int n): Calcula el factorial de "n" y lo devuelve.
    */
    private static long getFactorial (int n) {
        long fact = 1;
        for (int i = n; i > 1; i--) {
          fact = fact * i;
        }
        return fact;
    }

    /*
      getNext(): devuelve el array "a" con las posiciones permutadas de elementos.
    */
    public int[] getNext () {
        if (numLeft == total) {
          numLeft = numLeft - 1;
          return a;
        }

        int temp;

        // 1º Buscamos una j tal que a[j] < a[j+1]
        int j = a.length - 2;
        while (a[j] > a[j+1]) {
          j--;
        }

        // 2º Buscamos una k tal que a[j] < a[k]
        int k = a.length - 1;
        while (a[j] > a[k]) {
          k--;
        }

        // 3º Swap entre a[j] y a[k]
        temp = a[k];
        a[k] = a[j];
        a[j] = temp;

        // 4º Hacemos swap entre todos los valores a[s] y a[r]
        int r = a.length - 1;
        int s = j + 1;

        while (r > s) {
          temp = a[s];
          a[s] = a[r];
          a[r] = temp;
          r--;
          s++;
        }

        numLeft = numLeft - 1;
        return a;
    }
}

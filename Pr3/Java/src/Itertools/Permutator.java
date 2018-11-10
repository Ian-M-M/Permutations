package Itertools;
import java.math.BigInteger;

public class Permutator {
    private int[] a;
    private long numLeft;
    private long total;

    //-----------------------------------------------------------
    // Constructor. WARNING: Don't make n too large.
    // Recall that the number of permutations is n!
    // which can be very large, even when n is as small as 20 --
    // 20! = 2,432,902,008,176,640,000 and
    // 21! is too big to fit into a Java long, which is
    // why we use BigInteger instead.
    //----------------------------------------------------------

    public Permutator (int n) {
        if (n < 1) throw new IllegalArgumentException ("Min 1");
        a = new int[n]; // array con las posiciones de los elementos
        total = getFactorial (n);
        reset ();
    }

    //------
    // Reset
    //------

    public void reset () {
        for (int i = 0; i < a.length; i++) {
          a[i] = i;
        }
        numLeft = total; // nº de permutaciones restantes
    }

    //-----------------------------
    // Are there more permutations?
    //-----------------------------

    public boolean hasMore () {
        return numLeft > 0;
    }

    //------------------
    // Compute factorial
    //------------------

    private static long getFactorial (int n) {
        long fact = 1;
        for (int i = n; i > 1; i--) {
          fact = fact * i;
        }
        return fact;
    }

    //--------------------------------------------------------
    // Generate next permutation (algorithm from Rosen p. 284)
    //--------------------------------------------------------

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
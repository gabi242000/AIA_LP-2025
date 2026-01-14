package game;

import java.util.Random;

public class HintSystem {

    private Random rand = new Random();

    private final int TOTAL_HINTS = 10;
    private int[] usedHints = new int[TOTAL_HINTS];
    private int usedCount = 0;

    public void hint(int secret, int guess) {

        if (usedCount == TOTAL_HINTS) {
            resetHints();
            System.out.println("🔄 Toate indiciile au fost folosite. Reincep ciclul de indicii.");
        }

        int nrHint;
        do {
            nrHint = rand.nextInt(TOTAL_HINTS) + 1;
        } while (isUsed(nrHint));

        usedHints[usedCount++] = nrHint;

        System.out.println("🧩 Indiciu:");

        switch (nrHint) {

            case 1 -> System.out.println("• Numarul este " + (secret % 2 == 0 ? "par." : "impar."));
            case 2 -> System.out.println("• Suma cifrelor este " + sumDigits(secret));
            case 3 -> System.out.println("• Numarul este " + (secret > guess ? "mai mare" : "mai mic") + " decat " + guess);
            case 4 -> System.out.println("• Numarul este " + (isPrime(secret) ? "prim." : "compus."));
            case 5 -> System.out.println("• Ultima cifra este " + (secret % 10));
            case 6 -> {
                int digits = String.valueOf(secret).length();
                System.out.println("• Numarul are " + digits + " cifre.");
            }
            case 7 -> {
                int root = (int) Math.sqrt(secret);
                int lower = root * root;
                int upper = (root + 1) * (root + 1);
                System.out.println("• Numarul se afla intre patratele perfecte " + lower + " și " + upper + ".");
            }
            case 8 -> System.out.println("• Daca il scrii in binar, are " + Integer.bitCount(secret) + " biti de 1.");
            case 9 -> System.out.println("• Numarul este mai aproape de " + closestSquare(secret) + " decat de urmatorul patrat.");
            case 10 -> {
                if (secret >= 10) { 
                    int tens = (secret / 10) % 10;
                    if (tens >= 5)
                        System.out.println("• Cifra zecilor este mai mare sau egală cu 5.");
                    else
                        System.out.println("• Cifra zecilor este mai mica decât 5.");
                } else {
                    System.out.println("• Numarul are o singură cifra, deci nu are cifra zecilor.");
                }
            }
        }
    }

    private boolean isUsed(int hint) {
        for (int i = 0; i < usedCount; i++) {
            if (usedHints[i] == hint)
                return true;
        }
        return false;
    }

    public void resetHints() {
        usedCount = 0;
    }

    private int sumDigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    private boolean isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) return false;
        return true;
    }

    private int closestSquare(int n) {
        int root = (int) Math.sqrt(n);
        int lower = root * root;
        int upper = (root + 1) * (root + 1);
        return (n - lower < upper - n) ? lower : upper;
    }
}

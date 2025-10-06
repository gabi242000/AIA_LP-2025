

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ex2 {
    public static void main(String[] args) {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader bfr = new BufferedReader(isr);
        int[] numere = new int[3];

        try {
            for (int i = 0; i < 3; i++) {
                System.out.print("nr " + (i + 1) + ": ");
                numere[i] = Integer.parseInt(bfr.readLine());
            }

            int suma = numere[0] + numere[1] + numere[2];
            double media = suma / 3.0;
            int minim = Math.min(numere[0], Math.min(numere[1], numere[2]));
            int maxim = Math.max(numere[0], Math.max(numere[1], numere[2]));

            System.out.println("suma: " + suma);
            System.out.println("media aritmetica: " + media);
            System.out.println("minim: " + minim);
            System.out.println("maxim: " + maxim);

        } catch (NumberFormatException e) {
            System.out.println("nu sunt numere intregi");
        } catch (IOException e) {
            System.out.println("eroare");
        }
    }
}

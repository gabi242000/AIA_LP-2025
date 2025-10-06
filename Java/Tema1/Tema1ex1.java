package Tema1;

import java.io.*;

public class Tema1ex1 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        System.out.println("Introduceti un sir de caractere : ");
        String sir = br.readLine();

        try {
            int numar = Integer.parseInt(sir);
            System.out.println("Numărul introdus este: " + numar);

            if (numar % 2 == 0) {
                System.out.println("Numărul este par.");
            } else {
                System.out.println("Numărul este impar.");
            }
        } catch (NumberFormatException e) {
            System.out.println("Nu este un număr valid.");
        }
    }
}

package Tema2;

import java.io.*;

public class Ex2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        System.out.print("Introduceti un numar natural: ");
        int numar = Integer.parseInt(br.readLine());

        int maxDigit = 0;
        int minDigit = 9;
        int copie = numar;

        if (numar == 0) {
            maxDigit = minDigit = 0;
        } else {
            while (copie > 0) {
                int cifra = copie % 10;
                if (cifra > maxDigit) maxDigit = cifra;
                if (cifra < minDigit) minDigit = cifra;
                copie /= 10;
            }
        }

        System.out.println("Cifra maxima este: " + maxDigit);
        System.out.println("Cifra minima este: " + minDigit);
    }
}


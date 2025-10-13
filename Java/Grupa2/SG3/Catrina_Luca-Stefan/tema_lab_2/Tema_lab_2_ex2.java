package lab_2_java;

import java.util.Scanner;

public class Tema_lab_2_ex2 {

	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Introduceți un număr natural: ");
        int n = sc.nextInt();

        int max = 0;
        int min = 9;
        int copie = n;

        while (copie > 0) {
            int cifra = copie % 10;
            if (cifra > max) max = cifra;
            if (cifra < min) min = cifra;
            copie /= 10;
        }

        System.out.println("Cea mai mare cifră: " + max);
        System.out.println("Cea mai mică cifră: " + min);
        sc.close();
    }
	
}

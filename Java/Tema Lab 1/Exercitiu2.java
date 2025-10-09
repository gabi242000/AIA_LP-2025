package Tema1;
import java.io.*;
public class Exercitiu2 {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Introduceti primul numar: ");
        int a = Integer.parseInt(br.readLine());

        System.out.print("Introduceti al doilea numar: ");
        int b = Integer.parseInt(br.readLine());

        System.out.print("Introduceti al treilea numar: ");
        int c = Integer.parseInt(br.readLine());

        int suma = a + b + c;
        double media = suma / 3.0;

        int max = Math.max(a, Math.max(b, c));
        int min = Math.min(a, Math.min(b, c));

        System.out.println("\nRezultate:");
        System.out.println("Suma = " + suma);
        System.out.println("Media aritmetica = " + media);
        System.out.println("Cel mai mare numar = " + max);
        System.out.println("Cel mai mic numar = " + min);
    }
}

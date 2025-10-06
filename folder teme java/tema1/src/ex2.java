import java.io.*;
import java.lang.Math;
public class ex2 {
    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        System.out.println("Va rog introduceti primul numar: ");
        int a = Integer.parseInt(br.readLine());
        System.out.println("Va rog introduceti al doilea numar: ");
        int b = Integer.parseInt(br.readLine());
        System.out.println("Va rog introduceti al treilea numar: ");
        int c = Integer.parseInt(br.readLine());
        int suma = a + b + c;
        System.out.println("Suma celor 3 numere este: " + suma);
        float media = (float) suma / 3;
        System.out.println("Media celor 3 numere este: " + media);
        int maxim= Math.max(a, b);
        System.out.print("Maximul celor 3 numere este: " + Math.max(c, maxim));
    }
}

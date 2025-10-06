package Tema1;

import java.io.*;

public class Tema1ex2 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Introdu primul număr: ");
		int a = Integer.parseInt(br.readLine());
		System.out.print("Introdu al doilea număr: ");
		int b = Integer.parseInt(br.readLine());
		System.out.print("Introdu al treilea număr: ");
		int c = Integer.parseInt(br.readLine());
		int suma = a + b + c;
		double media = suma / 3.0;
		int maxim = a;
		if (b > maxim)
			maxim = b;
		if (c > maxim)
			maxim = c;
		int minim = a;
		if (b < minim)
			minim = b;
		if (c < minim)
			minim = c;
		System.out.println("Suma celor 3 numere este : " + suma);
		System.out.printf("Media = %.2f%n", media);
		System.out.println("Cel mai mare număr este : " + maxim);
		System.out.println("Cel mai mic este : " + minim);
	}
}
package tema_1;

import java.io.*;

public class Exercitiu_2 {

	public static void main(String[] args) throws IOException{
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		
		System.out.println("Introduceti primul numar natural: ");
		int a = Integer.parseInt(br.readLine());
		
		System.out.println("Introduceti al doilea numar natural: ");
		int b = Integer.parseInt(br.readLine());
		
		System.out.println("Introduceti al treilea numar natural: ");
		int c = Integer.parseInt(br.readLine());
		
		System.out.println("Suma celor trei numere este: " + Suma(a, b, c));
		System.out.println("Media aritmetica este: " + Medie_Aritm(a, b ,c));
		Comparare(a, b, c);

	}

	public static int Suma(int a, int b, int c) {
		int suma = a + b + c;
		return suma;
	}
	
	public static double Medie_Aritm(int a, int b, int c) {
		double ma = Suma(a, b, c) / 3.0;
		return ma;
	}
	
	public static void Comparare(int a, int b, int c) {
		int nr_max = a, nr_min = a;
		if(b > nr_max)
			nr_max = b;
		else if(b < nr_min)
			     nr_min = b;
		if(c > nr_max)
			nr_max = c;
		else if(c < nr_min)
			nr_min = c;
		
		System.out.println("Numarul maxim este: " + nr_max);
		System.out.println("Numarulul minim este: " + nr_min);
	}
}

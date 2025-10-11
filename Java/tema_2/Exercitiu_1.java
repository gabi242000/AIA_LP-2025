package tema_2;
import java.io.*;
import java.util.*;

public class Exercitiu_1 {

	public static void main(String[] args) throws IOException{
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("Introduceti dimensiunea vectorului: ");
		int n  = scanner.nextInt();
		
		int[] v = new int[n];
		
		citire(scanner, v, n);
		
		if(suma_pare(v,n) == 0)
			System.out.println("Nu exista elemente pare in vector!");
		else 
			System.out.println("Suma elementelor pare din vector este: " + suma_pare(v,n));
	}
	
	public static void citire(Scanner scanner, int v[], int n) {
		System.out.println("Introduceti vectorul: ");
		
		for(int i = 0; i < v.length; i++)
			v[i] = scanner.nextInt();	
	}
	
	public static int suma_pare(int v[], int n) {
		int suma = 0;
		for(int i = 0; i < v.length; i++) {
			if(v[i] % 2 == 0) 
				suma += v[i];
		}
		return suma;
	}
	

}

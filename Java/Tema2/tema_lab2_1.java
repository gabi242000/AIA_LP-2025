package Tema_Lab;
import java.io.*;
import java.util.Scanner;
public class tema_lab2_1 {
	public static int citesteNumar(String mesaj) {
        Scanner scanner = new Scanner(System.in);
        System.out.print(mesaj);
        return scanner.nextInt();
    }
	public static void citesteVector(int n, int v[]) throws IOException {
		for (int i=0;i<n;i++)
			v[i] = citesteNumar("Elementul " + i + ": ");
	}
	
	public static int calcSuma(int n, int v[]) throws IOException{
		int suma=0;
		for (int i=0;i<n;i++)
			if (v[i]%2==0) {
				System.out.print(v[i] + " ");
				suma += v[i];
			}
		return suma;
	}
	public static void main(String[] args) throws IOException{
		int n=citesteNumar("Introdu dimensiunea: ");
		int v[] = new int[n];
		citesteVector(n,v);
		System.out.println("Suma: "+ calcSuma(n,v));
	}
}

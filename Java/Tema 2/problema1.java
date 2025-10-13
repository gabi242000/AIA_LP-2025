package Problema_1;
import java.io.*;

public class problema1{
	public static void main (String[] args) throws IOException {
		int n;
		int a = 0;
		int suma;	
			
		System.out.println("Introdu dimensiunea vectorului: ");
		
		n = citireNr();
		
		int v[] = new int[n];
		int pare[] = new int [n];
		
		for (int i = 0; i < n; i++) {
			v[i] = citireNr();
			if (v[i] % 2 == 0) {
				pare[a] = v[i];
				a++;
			}
		}
		
		suma = sumaNr (pare, a);
		
		for (int i = 0; i < a; i++) {
			System.out.print(pare[i] + " ");
		}
		
		System.out.print("\n");
		
		System.out.println("Suma elementelor pare este:" + suma);
		
	}
	
	public static int citireNr () throws IOException {
		InputStreamReader isr = new InputStreamReader (System.in);
		BufferedReader br = new BufferedReader (isr);
		String s = br.readLine();
		return Integer.parseInt(s);
	}
	
	public static int sumaNr (int v[], int n) throws IOException {
		int suma = 0;
		
		for (int i = 0; i < n; i++) {
			suma += v[i];
		}
		
		return suma;
	}
}
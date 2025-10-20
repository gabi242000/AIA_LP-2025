package EX1;

import java.io.IOException;
import java.util.Scanner;

public class EX1 {
	
	public static int[][] citireMatrice() 
	{
		Scanner scanner = new Scanner(System.in);

		System.out.println("Introduceti dimensiunea matricei: ");
		int x = scanner.nextInt();
		System.out.println("Numerele introduse sunt: " + x);
		System.out.println("Introduceti matricea ");
		
		int matr[][] = new int[x][x];
		
		for(int i = 0; i < x; i++)
		{
			for(int j = 0; j < x; j++)
				matr[i][j] = scanner.nextInt();
		}
		
		for(int i = 0; i < x; i++)
		{
			for(int j = 0; j < x; j++)
				System.out.print(matr[i][j] + " ");
			System.out.println();
		}
		return matr;
	}
	
	public static int sumeEgaleLinii(int a[][], int dif)
	{
		
		int suma = 0;
		int suma2 = 0;
		for (int i = dif; i < a.length; i++)
			suma += a[dif][i];
		
		for(int i = dif; i < a.length ; i++)
		{
			suma2 = 0;
			for(int j = dif; j < a[i].length; j++){
					suma2 += a[i][j];
				}
			if(suma != suma2)
			{
				suma2 = -1;
				return suma2;
			}
			
		}

		return suma2;
	}
	
	public static int sumeEgaleColoane(int a[][], int dif)
	{
		
		int suma = 0, suma2 = 0;
		for (int i = dif; i < a.length; i++)
			suma += a[i][dif];
		
		for(int i = dif; i < a.length; i++)
		{
			suma2 = 0;
			for(int j = dif; j < a[i].length; j++){
					suma2 += a[j][i];
				}
			if(suma != suma2)
			{
				suma2 = -1;
				return suma2;
			}
		}

		return suma2;
	}
	
	public static int sumaDiagPrincipala(int a[][], int dif)
	{
		int suma = 0;
		for(int i = dif; i < a.length; i++){
			suma += a[i][i];
		}

		return suma;
	}
	
	public static int sumaDiagSecundara(int a[][], int dif)
	{
		int suma = 0;
		for(int i = dif; i < a.length; i++){
			for(int j = dif; j < a[i].length; j++){
				if(i + j == a.length + dif - 1) {
					suma += a[i][j];
				}
			}
		}
		return suma;
	}
	
	public static void main (String [] args) throws IOException{
		int a[][] = citireMatrice();
		int dif, suma = 0;
		if (a.length % 2 == 0) {
			dif = 1;
		}
		else {
			dif = 0;
		}
		int b = sumeEgaleLinii(a, dif);
		int c = sumeEgaleColoane(a, dif);
		int d = sumaDiagPrincipala(a, dif);
		int e = sumaDiagSecundara(a, dif);
		if(b == c && c==d && d==e){
			System.out.println();
			System.out.println("Matrice magica");
			for (int i = dif; i < a.length - dif; i++)
				suma += a[dif][i];
			}
		else{
			System.out.println();
			System.out.println("Matrice nemagica");
			}
		}

}

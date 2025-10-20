package tema_3;
import java.io.*;
import java.util.*;

public class Exercitiu_1 {

	public static void main(String[] args) throws IOException{
		int a[][] = citireMatrice();
		
		int n = a.length;
		int poz_start = 0, poz_final = n - 1;
		boolean mp = false;
		
		while(poz_final > 1) {
			if(n % 2 == 0) {
				poz_start ++;
				poz_final --;
			}
			
			int suma = MatriceMagicaPartial(a, poz_start, poz_final);
			if(suma != 0) {
				System.out.println("Matricea este magica partial!");
				System.out.println("Suma comuna este: " + suma);
				mp = true;
				break;
			}
			else {
				poz_start ++;
				poz_final --;
			}
		}
		
		if(mp == false)
			System.out.println("Matrice nemagica!");
		

	}
	
	public static int [][] citireMatrice() throws IOException {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Introduceti dimensiunea matricei: ");
		int n = sc.nextInt();
		
		int [][] matrice = new int[n][n];
		System.out.println("Introduceti matricea: ");
		for(int i = 0; i < n; i++) 
			for(int j = 0; j < n; j++)
				matrice[i][j] = sc.nextInt();
		
		return matrice;
	}
	
	public static int MatriceMagicaPartial(int [][] matrice, int start, int finish) {
		int suma_referinta = 0;
		
		for(int j = start; j <= finish; j++) 
			suma_referinta += matrice[start][j];
		
		for(int i = start; i <= finish; i++) {
			int suma_linie = 0;
			for(int j = start; j <= finish; j++)
				suma_linie += matrice[i][j];
			if(suma_linie != suma_referinta)
				return 0;
		}
		
		for(int j = start; j <= finish; j++) {
			int suma_coloana = 0;
			for(int i = start; i <= finish; i++)
				suma_coloana += matrice[i][j];
			if(suma_coloana != suma_referinta)
				return 0;
		}
		
		int suma_diag_princ = 0, suma_diag_sec = 0;
		for(int i = start; i <= finish; i++) {
			suma_diag_princ += matrice[i][i];
			suma_diag_sec += matrice[i][finish - (i - start)];
		}
		if(suma_diag_princ != suma_referinta || suma_diag_sec != suma_referinta)
			return 0;
		
		return suma_referinta;
	}

}






















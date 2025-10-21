package teme;
import java.io.*;
import java.util.Scanner;
public class tema_3 {
	public static int citesteNr () {
		Scanner sc = new Scanner (System.in);
		return sc.nextInt();
		}
	public static int sumaLinie(int mat[][], int linie, int n) {
		int suma=0;
		for (int j=0;j<n;j++)
			suma += mat[linie][j];
		return suma;
	}
	
	public static int sumaColoana(int mat[][], int coloana, int n) {
		int suma=0;
		for (int j=0;j<n;j++)
			suma += mat[j][coloana];
		return suma;
	}
	
	public static int sumaDP(int mat[][], int n) {
		int suma=0;
		for (int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if (i==j)
					suma += mat[i][j];
		return suma;
	}
	
	public static int sumaDS(int mat[][], int n) {
		int suma=0;
		for (int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if (i+j==n-1)
					suma += mat[i][j];
		return suma;
	}
	
	public static void main (String[] args) throws IOException{
		
		int n,i,j,sumaL,sumaC,sumaDp,sumaDs,ok=1;
		System.out.print("n=");
		n=citesteNr();
		int [][] m= new int[n][n];
		for (i=0;i<n;i++)
			for(j=0;j<n;j++) {
				System.out.print("m[" + i + "][" + j +"]= ");
				m[i][j]=citesteNr();
			}
		
		int [][] a= new int[n-2][n-2];
		
		for (i=0;i<n-2;i++)
			for(j=0;j<n-2;j++)
				a[i][j]=m[i+1][j+1];
		n=n-2;
		System.out.println();
		System.out.println("Submatricea: ");
		for (i=0;i<n;i++) {
			for(j=0;j<n;j++)
				System.out.print(a[i][j]+ " ");
			System.out.println();
		}
		sumaL=sumaLinie(a,0,n);
		for (i=0;i<n;i++)
			if (sumaLinie(a,i,n)!=sumaL)
				ok=0;
		
		sumaC=sumaColoana(a,0,n);
		for (j=0;j<n;j++)
			if (sumaColoana(a,j,n)!=sumaC)
				ok=0;
		
		sumaDp=sumaDP(a,n);
		sumaDs=sumaDS(a,n);
		
		if (ok==1 && sumaL == sumaC && sumaL == sumaDp && sumaL == sumaDs)
			System.out.println("Matrice partial magica, Suma= " + sumaL);
		else
			System.out.println("Matrice nemagica");
		
	}
}
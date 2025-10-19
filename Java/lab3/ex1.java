package tema3;
import java.io.*;
import java.util.Scanner;
public class mat {
	public static void main(String args[]) throws IOException
	{
		System.out.println("Introduceti dimensiunea matricei");
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int [][]a= new int [n][n];
		System.out.println("Introduceti elementele matricei");
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				a[i][j]=s.nextInt();
			}
		int m=n-1;
		while(m%2!=0)
		{
			m--;
		}
		int b[][]=submat(a);
		boolean egal=true;
		int ref=sumlin(b,0);
		for(int i=1;i<b.length;i++)
		{
			if(sumlin(b,i)!=ref)
			{
				egal=false;
				break;
			}
		}
		for(int i=0;i<b.length;i++)
		{
			if(sumcol(b,i)!=ref)
			{
				egal=false;
				break;
			}
		}
		if(sumdiag1(b)!=ref)
			egal=false;
		if(sumdiag2(b)!=ref)
			egal=false;
		if(egal==true)
			System.out.println("Matrice partial magica");
		else
			System.out.println("Matrice nemagica");
	}
	public static int [][] submat(int [][]matrice) 
	{
		int [][]sub=new int [matrice.length-2][matrice.length-2];
		for(int i=1;i<matrice.length-1;i++)
			for(int j=1;j<matrice.length-1;j++)
			{
				sub[i-1][j-1]=matrice[i][j];
			}
		return sub;
	}
	public static int sumlin(int [][]matrice, int x)
	{
		int suma=0;
		for(int i=0;i<matrice.length;i++)
		{
			suma+=matrice[x][i];
		}
		return suma;
	}
	public static int sumcol(int [][]matrice, int x)
	{
		int suma=0;
		for(int i=0;i<matrice.length;i++)
		{
			suma+=matrice[i][x];
		}
		return suma;
	}
	public static int sumdiag1(int [][]matrice)
	{
		int suma=0;
		for(int i=0;i<matrice.length;i++)
		{
			suma+=matrice[i][i];
		}
		return suma;
	}
	public static int sumdiag2(int [][]matrice)
	{
		int suma=0;
		for(int i=0;i<matrice.length;i++)
		{
			suma+=matrice[i][matrice.length-i-1];
		}
		return suma;
	}
}

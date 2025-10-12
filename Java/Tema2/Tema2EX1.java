package Team2;

import java.io.*;
import java.util.Scanner;

public class Tema2EX1 {
	public static void main(String[] args) throws IOException
	{
		Scanner scanner = new Scanner(System.in);
		System.out.println("Introduceti dimensiunea vectorului: ");
		int x = scanner.nextInt();
		System.out.println("Introduceti vectorul ");
		
		int v[] = new int[x]; 
		for(int i = 0; i < v.length; i++)
			v[i] = citire();
		
		for(int i = 0; i < v.length; i++) 
		{
			if(v[i] % 2 == 0)
				System.out.println("v(" + i + ")= " + v[i]);
		}
		System.out.println("Suma elementelor pare este: " + sumaElemPare(v));
	}
	
	public static int citire() throws IOException
	{
		Scanner scanner = new Scanner(System.in);
		int x = scanner.nextInt();
		return x;
	}
	
	public static int sumaElemPare(int[] vector) throws IOException
	{
		int suma = 0;
		for(int i = 0; i <vector.length; i++)
		{
			if(vector[i] % 2 == 0)
				suma += vector[i];
		}
		return suma;
				
	}
	
}



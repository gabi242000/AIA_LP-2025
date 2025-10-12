package Team2;

import java.io.*;
import java.util.Scanner;

public class Tema2EX2 {
	public static void main(String[] args) throws IOException
	{
		Scanner scanner = new Scanner(System.in);
		System.out.println("Introduceti numarul: ");
		int x = scanner.nextInt();
		int min = x % 10, max = x % 10;
		while(x > 9){
			x = x / 10;
			int digit = x % 10;
			if(digit > max)
				max = digit;
			if(digit < min)
				min = digit;
		}
		System.out.println("Cea mai mica cifra din numar este: " + min);
		System.out.println("Cea mai mare cifra din numar este: " + max);
	}
	
}



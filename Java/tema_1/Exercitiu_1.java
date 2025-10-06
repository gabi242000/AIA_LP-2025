package tema_1;

import java.io.*;

public class Exercitiu_1 {

	public static void main(String[] args) throws IOException{
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		
		System.out.println ("Introduceti:");
		
		String s = br.readLine();
		
		
		
		try {
			int n = Integer.parseInt(s);
			
			if(n >= 0) {
				if (n % 2 == 0) 
					System.out.println("Numarul " + n + " este par");
				else 
					System.out.println("Numarul " + n + " este impar");
			} else 
				System.out.println("Numarul introdus nu este un numar natural!");
			
		} catch (NumberFormatException error) {
			System.out.println("Valoarea introdusa nu este un numar natural valid!");
		}
	}
}

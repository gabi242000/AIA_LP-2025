package tema_2;
import java.io.*;
import java.util.*;

public class Exercitiu_2 {

	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("Introduceti un numar natural: ");
		int n = scanner.nextInt();
		
		cifra_min_max(n);
	}
	
	public static void cifra_min_max(int n) {
		int cmin = n % 10;
		int cmax = n % 10;
		
		while(n != 0) {
			if(n % 10 > cmax)
				cmax = n % 10;
			else if(n % 10 < cmin)
				cmin = n % 10;
			n /= 10;
		}
		
		System.out.println("Cifra minima a numarului este: " + cmin);
		System.out.println("Cifra maxima a numarului este: " + cmax);
		
	}

}

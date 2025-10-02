package lab_1_java;

import java.io.*;

public class tema_lab_1_ex2 {
	
public static void main(String[] args) throws IOException {
		
		InputStreamReader isr = new InputStreamReader(System.in);
		
		BufferedReader br = new BufferedReader(isr);
		
		System.out.println("---Introduceti trei numere de la tastatura---");
		
		int sum = 0, count = 2, i = 2, maxim = 0, minim = 0;
		
		System.out.println("Introduceti primul numar: ");
		
		String s1 = br.readLine();
		int n1 = Integer.parseInt(s1);
		
		maxim = n1;
		minim = n1;
		
		sum += n1;
		
		while(i != 0) {
		
			System.out.println("Introduceti al " + count + "-lea numar: ");
			
			String s = br.readLine();
			int n = Integer.parseInt(s);
			if(n > maxim)
				maxim = n;
			if(n < minim)
				minim = n;
			sum += n;
			i--;
			count++;
		}
		
		System.out.println("Suma celor 3 numere este: " + sum);
		System.out.println("Media aritmetica a celor 3 numere este: " + (float) sum/3);
		System.out.println("Cel mai mare numar este: " + maxim);
		System.out.println("Cel mai mic numar este: " + minim);
	}
}


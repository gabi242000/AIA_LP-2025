package lab_1_java;

import java.io.*;

public class tema_lab_1_ex1 {

	public static void main(String[] args) throws IOException {
		
		InputStreamReader isr = new InputStreamReader(System.in);
		
		BufferedReader br = new BufferedReader(isr);
		
		System.out.println("Introduceti un numar natural: ");
		
		String s = br.readLine();
		float n = Float.parseFloat(s);
		int N = (int) n;
		
		int natural = 0;
		
		if(n >= 0 && n == N)
			natural = 1;

		if(natural == 1 && n % 2 == 0)
			System.out.println("Numarul este natural par");
		else if(natural == 1 && n % 2 == 1)
			System.out.println("Numarul este natural impar");
		else
			System.out.println("Numarul este invalid");
	}

}

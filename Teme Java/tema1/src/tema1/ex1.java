package tema1;

import java.io.*;

public class ex1 {
	public static void main(String[] args) throws IOException {
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		System.out.println("Introduceti un sir de caractere : ");
		String s = br.readLine();

		if (isNumeric(s)) {
			int numar = Integer.parseInt(s);
			System.out.println("Numărul introdus este: " + numar);
			if (numar % 2 == 0) {
				System.out.println("Numărul este par.");
			} else {
				System.out.println("Numărul este impar.");
			}
		} else {
			System.out.println("Nu este un număr valid.");
		}
	}

	public static boolean isNumeric(String s) {
		try {
			Integer.parseInt(s);
			return true;
		} catch (NumberFormatException e) {
			return false;
		}
	}

}

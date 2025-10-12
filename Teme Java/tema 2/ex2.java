package tema2;

import java.io.*;

public class ex2 {
	public static void main(String[] args) throws IOException {
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		System.out.println("Introduceti un numar natural nenul : ");
		String s = br.readLine();
		int n = Integer.parseInt(s);
		int cmin = 999999;
		int cmax = -99999;

		while (n != 0) {
			int c = n % 10;
			if (c > cmax)
				cmax = c;
			if (c < cmin)
				cmin = c;
			n = n / 10;
		}
		System.out.println("Cea mai mica cifra este : " + cmin);
		System.out.println("Cea mai mare cifra este  : " + cmax);
	}
}
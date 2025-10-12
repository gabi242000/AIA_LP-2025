package tema2;

import java.io.*;

public class ex1 {
	InputStreamReader isr = new InputStreamReader(System.in);
	BufferedReader br = new BufferedReader(isr);

	public static void main(String[] args) throws IOException {
		citestevector();

	}

	public static int citestenr() throws IOException {
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		String s = br.readLine();
		return Integer.parseInt(s);
	}

	public static void citestevector() throws IOException {
		System.out.println("Dati dimensiunea vectorului : ");
		int a = citestenr();
		System.out.println("Dimensiune vector: " + a);
		int v[] = new int[a];
		for (int i = 0; i < v.length; i++) {
			v[i] = citestenr();
		}
		sumapare(v);

	}

	public static void sumapare(int v[]) throws IOException {
		{
			int s = 0;
			for (int i = 0; i < v.length; i++)
				if (v[i] % 2 == 0) {
					s = s + v[i];
					System.out.println("v[" + i + "]=" + v[i]);
				}
			System.out.println("Suma elementelor pare din vector este : " + s);
		}
	}
}

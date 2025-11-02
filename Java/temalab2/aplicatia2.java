package temalab2;
import java.io.*;

public class aplicatia2 {

	public static void main(String[] args)throws IOException {
		System.out.print("Introduceti un numar natural: ");
		int n= citesteNr();
		
		int cifraMax=0;
		int cifraMin=9;
		int dublura= n;
		
		while (n !=0) { //parcurgem fiecare cifra
			int c= n%10; //extragem ultima cifra
			if(c>cifraMax)
				cifraMax=c;
			if(c<cifraMin)
				cifraMin=c;
			n/=10;
		}
		
		System.out.println("\nPentru numărul " + dublura + ":");
		System.out.println("Cifra maximă este: " + cifraMax);
		System.out.println("Cifra minimă este: " + cifraMin);
	}
	public static int citesteNr() throws IOException {
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		String s = br.readLine();
		return Integer.parseInt(s);
	}
}

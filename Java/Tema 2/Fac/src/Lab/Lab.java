package Lab;
import java.io.*;
public class Lab {
	//Ex 1
/*	public static void main(String[] args)throws IOException {
			System.out.println("Introdu nr de caractere din vector: ");
			int n = citestemi();
			int V[] = new int[n];
			int i, S = 0;
			System.out.println("Vectorul tau va fi(introdu de la tastatura): ");
			for(i = 0; i < V.length; i++) { 
				System.out.println("Elementul " + (i+1) + " : ");
				V[i] = citestemi();
			}
			System.out.println("Elementele pare: ");
			for(i = 0; i < V.length; i++) {
				if(V[i] % 2 == 0) {
					System.out.println(V[i]);
					S = V[i] + S;
				}
			}
			System.out.println("Suma elem pare din vect este: " + S);
	
	} */
	
	//Ex 2
/*	public static void main(String[] args)throws IOException {
		System.out.println("Introdu un numar: ");
		int n = citestemi();
		int M, m;
		M = n % 10; m = n % 10;
		n /= 10;
		while(n != 0) {
			if(M < n % 10)
				M = n%10;
			if(m > n % 10)
				m = n % 10;
			n /= 10;
		}
		System.out.println("Cel mai mic digit este: " + m);
		System.out.println("Cel mai mare digit este: " + M);
	} */
	
	//Necesar la ambele Ex
	public static int citestemi()throws IOException{
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		String s = br.readLine();
		return Integer.parseInt(s);
	}
}
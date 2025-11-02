package temalab2;
import java.io.*;

public class aplicatia1 {

	public static void main(String[] args)throws IOException {
		System.out.print("Introduceti dimensiunea vectorului: ");
		int n= citesteNr();
		
		int[] v= new int[n]; //declara si initializeaza vectorul cu n elemente
		citesteVector(v); //apeleaza metoda care citeste elementele vectorului
		
		System.out.println("\nElementele pare din vector sunt: ");
		int suma= sumaPare(v);
		
		System.out.println("Suam elementelor pare este: " + suma);
	}
	
	//citirea unui nr intreg de la tastatura
	public static int citesteNr()throws IOException {
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		String s = br.readLine();
		return Integer.parseInt(s);
	}
	
	//citirea elementelor vectorului
	public static void citesteVector(int[] v) throws IOException {
		for (int i = 0; i < v.length; i++) {
			System.out.print("v[" + i + "] = ");
			v[i] = citesteNr(); // Citește elementul i
		}
	}
	public static int sumaPare(int[] v) {
		int suma = 0;
		for (int i = 0; i < v.length; i++) {
			if (v[i] % 2 == 0) { // Verifică dacă este par
				System.out.println(v[i]); // Afișează elementul par
				suma += v[i]; // Adună la sumă
			}
		}
		return suma; // Returnează suma elementelor pare
	}
}

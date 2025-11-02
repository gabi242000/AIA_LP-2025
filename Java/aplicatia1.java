package temalab1;
import java.io.*;

//tema 1

public class aplicatia1 {

	public static void main(String[] args)throws IOException {
		
		String s;
		int nr;
		
		System.out.print("Introduceti un numar natural: ");
		InputStreamReader isr= new InputStreamReader(System.in);
		BufferedReader br= new BufferedReader(isr);
		s= br.readLine();
		
		//verificam daca sirul contine doar cifre
		if( s.matches("[0-9]+")) { //doar cifre
			nr= Integer.parseInt(s);
			System.out.println("Numarul introdus este: "+ nr);
			
			if(nr%2==0) 
				System.out.println("Numarul este par");
			else
				System.out.println("Numarul este impar.");
					
			}
		else {
			System.out.println("Valoarea introdusa nu este valida!");
			
				
			}
		}
	}





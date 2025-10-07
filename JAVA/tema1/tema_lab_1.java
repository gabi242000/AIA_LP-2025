package tema_lab;
import java.io.*;
public class tema_lab_1 {
	public static void main(String[] args) throws IOException{
		InputStreamReader isr=new InputStreamReader(System.in);
		BufferedReader br=new BufferedReader(isr);
		System.out.println("introdu un sir de caractere: ");
		String t = br.readLine();
		try {
			int n= Integer.parseInt(t);
			if (n>=0) {
				System.out.println("nr introdus este " + n);
				if( n%2==0) 
					System.out.println("nr este par");
					
				else System.out.println("nr este impar");	
			}
		}catch (NumberFormatException e) {
			System.out.println("valoare introdusa nu este un nr nat valid!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		}
	}
}

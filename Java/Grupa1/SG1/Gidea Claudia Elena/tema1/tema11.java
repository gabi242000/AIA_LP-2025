package tema1;
import java.io.*;
import java.util.Scanner;
public class tema {
public static void main(String args[]) throws IOException
{
	InputStreamReader isr = new InputStreamReader(System.in);
	BufferedReader br=new BufferedReader(isr);
	System.out.println("Introduceti un numar valid: ");
	String s= br.readLine();
	try {
	int n = Integer.parseInt(s);
	if (n%2==0) 
		System.out.println("Numarul este par.");
	else if(n%2!=0) System.out.println("Numarul este impar.");
	}catch(NumberFormatException e) {System.out.println("Valoarea introdusa nu este un numar valid.");
}
}
}

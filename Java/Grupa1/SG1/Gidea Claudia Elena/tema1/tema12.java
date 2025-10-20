package tema1;
import java.io.*;
import java.util.Scanner;
public class temab {
public static void main (String args[]) throws IOException
{
	InputStreamReader isr = new InputStreamReader(System.in);
	BufferedReader br=new BufferedReader(isr);
	System.out.println("Introdu un numar intreg: ");
	String s = br.readLine();
	int a=Integer.parseInt(s);
	System.out.println("Introdu alt numar intreg: ");
	s = br.readLine();
	int b=Integer.parseInt(s);
	System.out.println("Introdu alt numar intreg: ");
	s = br.readLine();
	int c=Integer.parseInt(s);
	
	int n=a+b+c;
	System.out.println("Suma celor trei numere este: "+ n);
	float m=(a+b+c)/3.0f;
	System.out.println("Media aritmetica este: "+m);
	
	int max= Math.max(a, Math.max(b, c));
	int min=Math.min(a, Math.min(b, c));
	
	System.out.println("Cel mai mare numar dintre cele trei este: "+max+", iar cel mai mic este: "+min);
}
}

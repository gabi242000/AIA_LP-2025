package temalab1;
import java.io.*;

//tema 1

public class aplicatia2 {

	public static void main(String[] args)throws IOException {
		int a, b, c, suma;
		double media;
		
		InputStreamReader isr= new InputStreamReader(System.in);
		BufferedReader br= new BufferedReader(isr);
		
		System.out.print("Introduceti primul numar intreg: ");
		a= Integer.parseInt(br.readLine());
		
		System.out.print("Introduceti al doilea numar intreg: ");
		b= Integer.parseInt(br.readLine());
		
		System.out.print("Introduceti al treilea numar intreg: ");
		c= Integer.parseInt(br.readLine());
		
		suma= a+b+c;
		
		media=suma/3.0;
		
		int maxim= a;
		if(b>maxim)
			maxim=b;
		if(c>maxim)
			maxim=c;
		
		int minim= a;
		if(b<minim)
			minim=b;
		if(c<minim)
			minim=c;
		
		System.out.println("Suma celor trei numere este: " + suma);
		System.out.println("Media aritmetica a celor trei numere este: " + media);
		System.out.println("Cel mai mare numar este: "+ maxim);
		System.out.println("Cel mai mic numar este: " + minim);
	}

}


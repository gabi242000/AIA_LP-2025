package lab1;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class lab1_tema2 {
	public static void main(String[] args) throws IOException
	{
		InputStreamReader isr = new InputStreamReader(System.in);
		
		BufferedReader br = new BufferedReader(isr);
		System.out.println("Introduceti 3 numere intregi: ");
		
		String s = br.readLine();
		String p = br.readLine();
		String r = br.readLine();
		
		int a = Integer.parseInt(s);
		int b = Integer.parseInt(p);
		int c = Integer.parseInt(r);
		
		System.out.println("Suma celor 3 numere este: " + Suma(a, b, c));
		System.out.println("Media aritmetica pentru cele 3 numere este: " + media(a, b, c));
		System.out.println("Cel mai mare numar este: " + Mare(a, b, c));
		System.out.println("Cel mai mic numar este: " + Mic(a, b, c));
		
	}
	
	public static int Suma(int a, int b, int c)
	{
		return a + b + c;
	}

	public static int media(int a, int b, int c)
	{
		int medie = 0;
		medie = (a + b + c) / 3;
		return medie;
	}
	
	public static int Mare(int a, int b, int c)
	{
		int max = 0;
		if(a > max)
		{
			max = a;
			if(b > max)
			{
				max = b;
			}
			if(c > max)
			{
				max = c;
			}
		}
		
		return max;
	}
	
	public static int Mic(int a, int b, int c)
	{
		int min = 999999999;
		if(a < min)
		{
			min = a;
			if(b < min)
			{
				min = b;
			}
			if(c < min)
			{
				min = c;
			}
		}
		
		return min;
	}
}











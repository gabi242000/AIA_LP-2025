package lab2_tema;
import java.io.*;

public class Lab2_tema2 {
	public static void main(String[] args) throws IOException
	{
		System.out.println("Introduceti un numar: ");
		int b = citesteNr();
		
		int min = 999999999, max = 0;
		int n = b;
		while(n != 0)
		{
			int x = n % 10;
			
			if(x < min)
			{
				min = x;
			}
			
			if(x > max)
			{
				max = x;
			}
			
			n /= 10;
		}
		
		System.out.println("Cea mai mare cifra din " + b + " este " + max);
		System.out.println("Cea mai mica cifra din " + b + " este " + min);
	}

	public static int citesteNr() throws IOException
	{
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		String s = br.readLine();
		
		return Integer.parseInt(s);	
	}
}

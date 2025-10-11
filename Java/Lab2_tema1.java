package lab2_tema;
import java.io.*;

public class Lab2_tema1 {
	public static void main(String[] args) throws IOException
	{
		System.out.println("Scrie un vector!");
		
		int n = citesteNr();
		int[] v = new int[n];
		
		int l = v.length;
		
		for(int i = 0; i < l; i++)
		{
			v[i] = citesteNr();
		}	
		
		System.out.println("Elementele pare sunt: ");
		afisareVector(v);
		
		System.out.println("Suma lor este: " + sumaPare(v));
		
	}
	 
	public static int citesteNr() throws IOException
	{
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		String s = br.readLine();
		
		return Integer.parseInt(s);	
	}
	
	public static void afisareVector(int[] v)
	{
		for(int i = 0; i < v.length; i++)
		{
			if(v[i] % 2 == 0)
			{
				System.out.println(v[i]);
			}
		}
	}
	
	public static int sumaPare(int[] v) throws IOException
	{
		int s = 0;
		for(int i = 0; i < v.length; i++)
		{
			if(v[i] % 2 == 0)
			{
				s += v[i];
			}
		}
		
		return s;	
	}

}

























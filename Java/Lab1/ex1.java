package prob1;
import java.io.*;
public class ex1 {
	public static void main(String[] args) throws IOException
	{
		InputStreamReader isr= new InputStreamReader(System.in);
		BufferedReader br= new BufferedReader(isr);
		System.out.println("introduceti un nr natural:");
		String s=br.readLine();
		try
		{
			int n=Integer.parseInt(s);
			System.out.println(n);
			if(n%2==0)
				System.out.println("numarul e par");
			if(n%2==1)
				System.out.println("numarul e impar");
		}
		catch(NumberFormatException e)
		{
			System.out.println("numar invalid");
		}
	}	
}

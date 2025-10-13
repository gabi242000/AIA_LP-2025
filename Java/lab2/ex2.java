package lab2;
import java.io.*;
import java.util.Scanner;

public class ex2 {
	public static void main(String args[]) throws IOException
	{
		System.out.println("Introdu un numar");
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		System.out.println("Cea mai mare cifra:"+maxim(n));
		System.out.println("Cea mai mica cifra:"+minim(n));
	}
	public static int maxim(int n) throws IOException
	{
		int mx=-1;
		while(n>0)
		{
			if(n%10>mx)
				mx=n%10;
			n/=10;
		}
		return mx;
	}
	public static int minim(int n) throws IOException
	{
		int mn=10;
		while(n>0)
		{
			if(n%10<mn)
				mn=n%10;
			n/=10;
		}
		return mn;
	}
}

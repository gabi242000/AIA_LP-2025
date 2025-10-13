package lab2;
import java.io.*;
import java.util.*;
public class ex1 {
	public static void main(String args[]) throws IOException
	{
		System.out.println("Introdu dimensiunea vectorului:");
		Scanner sc=new Scanner(System.in);
		int x=sc.nextInt();
		System.out.println("Introdu elementele vectorului");
		int v[]=new int[x];
		for(int i=0;i<v.length;i++)
		{
			v[i]=citire();
		}
		for(int i=0;i<v.length;i++)
		{
			if(v[i]%2==0)
			{
				System.out.println(v[i]);
			}
		}
		System.out.println("Suma elementelor pare:"+suma(v));
		}
	public static int citire() throws IOException
	{
		Scanner s2=new Scanner(System.in);
		return s2.nextInt();
	}
	public static int suma(int v[]) throws IOException
	{
		int s=0,i;
		for(i=0;i<v.length;i++)
		{
			if(v[i]%2==0)
			{
				s+=v[i];
			}
		}
		return s;
	}
}

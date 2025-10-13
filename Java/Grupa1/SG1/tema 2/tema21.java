package tema2;
import java.io.*;
import java.util.Scanner;
public class tema21 {
public static void main(String args []) throws IOException
{
	Scanner scanner = new Scanner(System.in);
	System.out.print("Introdu dimensiunea vectorului:");
	int n =scanner.nextInt();
	System.out.print("Introdu elementele vectorului: ");
	int v[]=new int[n];
	int i;
	for (i=0;i<n;i++)
	{
		v[i]=scanner.nextInt();
	}
	int suma=0;
	System.out.print("Elementele pare din vector sunt: ");
	for(i=0;i<n;i++)
	{
		if (v[i]%2==0)
		{
			suma+=v[i];
			System.out.print(v[i] + " ");
		}
	}
	System.out.println("");
	System.out.print("Suma elementelor pare este: "+suma);
}
}

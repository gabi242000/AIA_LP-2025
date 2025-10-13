package tema2;
import java.io.*;
import java.util.Scanner;
public class tema22 {
public static void main(String args[]) throws IOException
{
	Scanner scanner = new Scanner(System.in);
	int n, max=0, min=10;
	System.out.print("Introdu un numar: ");
	n= scanner.nextInt();
	while(n>0)
	{
		if(n%10>max) max=n%10;
		if(n%10<min) min=n%10;
		n/=10;
	}
	System.out.print("Cifra cea mai mare este "+max+" si cifra cea mai mica este "+min);
}
}

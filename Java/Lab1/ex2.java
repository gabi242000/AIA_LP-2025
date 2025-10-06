package prob1;
import java.io.*;

public class ex2 {
	public static void main(String[] args) throws IOException
	{
		InputStreamReader isr= new InputStreamReader(System.in);
		BufferedReader br= new BufferedReader(isr);
		System.out.println("introduceti 3 numere naturale:");
		String s=br.readLine();
		BufferedReader br2=new BufferedReader(isr);
		String s2=br2.readLine();
		BufferedReader br3=new BufferedReader(isr);
		String s3=br3.readLine();
		int a=Integer.parseInt(s);
		int b=Integer.parseInt(s2);
		int c=Integer.parseInt(s3);
		int sum,m;
		sum=a+b+c;
		System.out.println("suma numerelor este:"+sum);
		m=sum/3;
		System.out.println("media numerelor este:"+m);
		if(a>b)
		{
			if(a>c)
			{
				System.out.println("cel mai mare numar este:"+a);
			}
			else
			{
				System.out.println("cel mai mare numar este:"+c);
			}
		}
		else
		{
			if(b>c)
			{
				System.out.println("cel mai mare numar este:"+b);
			}
			else
			{
				System.out.println("cel mai mare numar este:"+c);
			}
		}
	}
}

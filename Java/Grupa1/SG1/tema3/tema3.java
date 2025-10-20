package tema3;
import java.io.*;
import java.util.Scanner;
public class tema3 {
public static int sume(int a[][],int n)
	{
	//in cerinta este scris ca suma tuturor liniilor sa fie egala cu suma tuturor coloanelor,
	//care oricum este aceeasi 
	//asa ca am facut suma primei si ultimei linii si suma primei si ultimei coloane
		int i,j, min, max, ok=0,s1=0,s2=0, s3=0,s4=0;
		if (n%2!=0)
			{
				min=1;
				max=n-1;
			}
		else 
			{
				min=0;
				max=n-1;
			}
		
		for(i=min;i<max;i++)
			for(j=min;j<max;j++)
			{
				if(i==min||i==max-1)
					s1+=a[i][j];
				if(j==min||j==max-1)
					s2+=a[i][j];
				if(i==j)
					s3+=a[i][j];
				if(min==0)
				 {
					if(i+j==max-1)
					s4+=a[i][j];
				 }
				else 
				{
					if(i+j==max)
					s4+=a[i][j];
				 }
			}
		System.out.println(s1+" "+s2+" "+s3+" "+s4);
		if(((s1==s2)&&(s3==s4)&&(s2==s3))) ok=1;
		if(ok==0) return -1;
		else return s1;
	}
public static void main(String args[]) throws IOException
{
	Scanner scanner = new Scanner(System.in);
	System.out.print("Introdu dimensiunea vectorului:");
	int n =scanner.nextInt();
	System.out.print("Introdu elementele vectorului: ");
	int a[][]=new int[n][n];
	int i,j;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			a[i][j]=scanner.nextInt();
	
	if (sume(a, n)==-1) System.out.print("Matrice nemagica");
	else System.out.print("Suma comuna este: "+ sume(a, n)+" si este o matrice magica partial.");
}
}

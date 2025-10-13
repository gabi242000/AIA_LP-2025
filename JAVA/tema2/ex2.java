package teme;
import java.util.Scanner;
public class ex2 {
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		System.out.println(" introduy un nr nat: ");
		int nr= sc.nextInt();
		int max=0;
		int min=9;
		int copie= nr;
				while (copie>0) {
					int cifra= copie%10;
					if(cifra>max)max=cifra;
					if(cifra<min)min=cifra;
					copie/= 10;
				}
		System.out.println("Cif max e: "+ max);
		System.out.println("Cif min e: " +min);
	}
}

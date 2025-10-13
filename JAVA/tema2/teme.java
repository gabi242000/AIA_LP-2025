package teme;
import java.util.Scanner;
public class teme {
		public static int[] citesteVector(int n, Scanner sc) {
			int[] v=new int [n];
			System.out.println("introdu elem. vectorului: ");
			for (int i = 0; i<n; i++) {
				System.out.println("v["+i + "]=");
				v[i]=sc.nextInt();
			}
			return v;
		}
		public static int cf(int[]v) {
			int suma=0;
			System.out.println("elem pare sunt: ");
			for (int x : v) {
				if (x % 2==0) {	
					System.out.println(x + " ");
					suma += x;
				}
			}
			return suma;
		}
		public static void main(String[] args) {
			Scanner sc= new Scanner(System.in);
			System.out.println("introdu dim vec: ");
			int n= sc.nextInt();
			int[] vector= citesteVector(n,sc);
			int sumpare=cf(vector);
			System.out.println("suma elem pare este: "+ sumpare);
		}
}

package Problema_2;
import java.io.*;
import java.util.Scanner;

public class problema2 {
	public static void main (String[] args) throws IOException {
		int n, max = -1, min = 999999, x;
		
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		
		while (n != 0) {
			x = n % 10;
			if (x > max) {
				max = x;
			}
			if (x < min) {
				min = x;
			}
			n = n/10;
		}
		
		System.out.println("Cifra cea mai mare este " + max);
		System.out.println("Cifra cea mai mica este " + min);
		
		sc.close();
	}
}
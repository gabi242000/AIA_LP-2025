package Tema_Lab;
import java.io.*;
import java.util.Scanner;
public class tema_lab2_2 {
	public static int citesteNumar(String mesaj) {
        Scanner scanner = new Scanner(System.in);
        System.out.print(mesaj);
        return scanner.nextInt();
    }
	public static void main(String[] args) throws IOException{
		int n=citesteNumar("introdu numarul: ");
		int maxim=0,minim=9;
		while (n!=0) {
			if (n%10>maxim)
				maxim=n%10;
			if (n%10<minim)
				minim=n%10;
			n /= 10;
		}
		System.out.println("max: " + maxim);
		System.out.println("min: "+ minim);
	}
}

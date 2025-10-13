package lab_2_java;
import java.io.*;
import java.util.Scanner;
public class Tema_lab_2_ex1 {
	
	public static int[] citireVector(int n, Scanner sc) {
        int[] v = new int[n];
        System.out.println("Introduceți elementele vectorului:");
        for (int i = 0; i < n; i++) {
            v[i] = sc.nextInt();
        }
        return v;
    }

    public static int sumaPare(int[] v) {
        int suma = 0;
        System.out.print("Elementele pare sunt: ");
        for (int x : v) {
            if (x % 2 == 0) {
                System.out.print(x + " ");
                suma += x;
            }
        }
        System.out.println();
        return suma;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Introduceți dimensiunea vectorului: ");
        int n = sc.nextInt();

        int[] vector = citireVector(n, sc);
        int suma = sumaPare(vector);

        System.out.println("Suma elementelor pare este: " + suma);
        sc.close();
    }
	
}

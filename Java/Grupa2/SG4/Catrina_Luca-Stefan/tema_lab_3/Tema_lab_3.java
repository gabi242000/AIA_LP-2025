package lab_3_java;

import java.util.Scanner;

public class Tema_lab_3 {
	
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Introduceti dimensiunea matricei: ");
        int n = sc.nextInt();

        int[][] A = new int[n][n];
        System.out.println("Introduceti elementele matricei:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                A[i][j] = sc.nextInt();
        }

        int m;
        if (n % 2 == 1) {
            m = n;
        } else {
            m = n - 1;
        }

        int[] sumaLinii = new int[m];
        int[] sumaColoane = new int[m];
        int diag1 = 0, diag2 = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                sumaLinii[i] += A[i][j];
                sumaColoane[j] += A[i][j];
                if (i == j) diag1 += A[i][j];
                if (i + j == m - 1) diag2 += A[i][j];
            }
        }

        int sumaComuna = sumaLinii[0];
        boolean magica = true;

        for (int i = 0; i < m; i++) {
            if (sumaLinii[i] != sumaComuna || sumaColoane[i] != sumaComuna) {
                magica = false;
                break;
            }
        }

        if (diag1 != sumaComuna || diag2 != sumaComuna) magica = false;

        if (magica) {
            System.out.println("Suma comuna este: " + sumaComuna);
            System.out.println("Matrice magica partial");
        } else {
            System.out.println("Matrice nemagica");
        }

        sc.close();
    }

}

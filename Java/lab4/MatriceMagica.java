package javalab3;
import java.util.Scanner;

public class MatriceMagica {


    public static boolean esteMagica(int[][] matrice, int start, int dimensiune) {
        int suma = 0;

        for (int j = start; j < start + dimensiune; j++) {
            suma += matrice[start][j];
        }

        for (int i = start; i < start + dimensiune; i++) {
            int sumaLinie = 0;
            for (int j = start; j < start + dimensiune; j++) {
                sumaLinie += matrice[i][j];
            }
            if (sumaLinie != suma) {
                return false;
            }
        }

        for (int j = start; j < start + dimensiune; j++) {
            int sumaColoana = 0;
            for (int i = start; i < start + dimensiune; i++) {
                sumaColoana += matrice[i][j];
            }
            if (sumaColoana != suma) {
                return false;
            }
        }

        int sumaDiag1 = 0;
        for (int i = 0; i < dimensiune; i++) {
            sumaDiag1 += matrice[start + i][start + i];
        }
        if (sumaDiag1 != suma) return false;

        int sumaDiag2 = 0;
        for (int i = 0; i < dimensiune; i++) {
            sumaDiag2 += matrice[start + i][start + dimensiune - 1 - i];
        }
        if (sumaDiag2 != suma) return false;

        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Introdu dimensiunea matricei n: ");
        int n = sc.nextInt();
        int[][] A = new int[n][n];

        System.out.println("Introdu elementele matricei:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = sc.nextInt();
            }
        }

        boolean gasit = false;
        int sumaComuna = 0;

        for (int dim = n; dim >= 1; dim--) {
            if (dim % 2 == 1) { 
                int start = (n - dim) / 2; 
                if (esteMagica(A, start, dim)) {
                    gasit = true;
                    sumaComuna = 0;
                    for (int j = start; j < start + dim; j++) {
                        sumaComuna += A[start][j];
                    }
                    break;
                }
            }
        }

        if (gasit) {
            System.out.println("Matrice magica partial");
            System.out.println("Suma comuna: " + sumaComuna);
        } else {
            System.out.println("Matrice nemagica");
        }

        sc.close();
    }
}

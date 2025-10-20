package Tema3;

import java.io.*;

public class ExercitiuMatrice {
	public static int[][] citireMatrice(BufferedReader br, int n) throws IOException {
		int[][] A = new int[n][n];
		System.out.println("Introduceti elementele matricei (" + n + "x" + n + "):");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				System.out.print("A[" + i + "][" + j + "] = ");
				A[i][j] = Integer.parseInt(br.readLine());
			}
		}
		return A;
	}

	public static boolean esteMagica(int[][] M) {
		int n = M.length;
		int suma = 0;

		for (int j = 0; j < n; j++)
			suma += M[0][j];

		for (int i = 1; i < n; i++) {
			int s = 0;
			for (int j = 0; j < n; j++)
				s += M[i][j];
			if (s != suma)
				return false;
		}

		for (int j = 0; j < n; j++) {
			int s = 0;
			for (int i = 0; i < n; i++)
				s += M[i][j];
			if (s != suma)
				return false;
		}

		int s1 = 0, s2 = 0;
		for (int i = 0; i < n; i++) {
			s1 += M[i][i];
			s2 += M[i][n - 1 - i];
		}
		if (s1 != suma || s2 != suma)
			return false;

		System.out.println("Suma comuna: " + suma);
		return true;
	}

	public static int[][] submatriceCentrala(int[][] A) {
		int n = A.length;
		int dim;
		if (n % 2 == 1)
			dim = n;
		else
			dim = n - 1;
		int start = (n - dim) / 2;

		int[][] B = new int[dim][dim];
		for (int i = 0; i < dim; i++)
			for (int j = 0; j < dim; j++)
				B[i][j] = A[start + i][start + j];
		return B;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		System.out.print("Introduceți dimensiunea n: ");
		int n = Integer.parseInt(br.readLine());

		int[][] A = citireMatrice(br, n);

		int[][] B = submatriceCentrala(A);

		if (esteMagica(B))
			System.out.println("Matrice magica partial!");
		else
			System.out.println("Matrice nemagica!");
	}
}
//Nu vreau sa mai vad in viata mea matrice PARTIAL magica. Isi pierde magia cand incerc sa inteleg cerinta.


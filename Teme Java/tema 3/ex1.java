package tema3;
import java.io.*;
import java.util.*;

public class ex1 {
	public static void main(String[] args) {
		var sc = new Scanner(System.in);
		System.out.print("Introduceti dimensiunea matricei : ");
		int n = sc.nextInt();
		int[][] v = new int[n][n];
		int i, j;

		System.out.print("Introduceti elementele matricei : ");
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				v[i][j] = sc.nextInt();

		System.out.println("\nMatricea introdusa este:");
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				System.out.print(v[i][j] + " ");
			}
			System.out.println();
		}

		if (n % 2 == 0) {
			int sl = SumaLinii(v, n, 1, n);
			int sC = SumaColoane(v, n, 1, n);
			int sdp = SumaDiagP(v, n, 1, n);
			int sds = SumaDiagS(v, n, 1, n);

			if (sl == sC && sC == sdp && sdp == sds)
				System.out.print("\nMatrice magica partial ! Suma este : " + sl);
			else
				System.out.print("\nMatrice nemagica!");

		} else {
			int sl = SumaLinii(v, n, 0, n);
			int sC = SumaColoane(v, n, 0, n);
			int sdp = SumaDiagP(v, n, 0, n);
			int sds = SumaDiagS(v, n, 0, n);

			if (sl == sC && sC == sdp && sdp == sds)
				System.out.print("\nMatrice magica partial ! Suma este : " + sl);
			else
				System.out.print("\nMatrice nemagica!");

		}

	}

	static int SumaLinii(int v[][], int n, int c, int f) {
		int s1, k = 0;
		int[] a = new int[n];

		for (int i = c; i < f; i++) {
			s1 = 0;
			for (int j = c; j < f; j++)
				s1 = s1 + v[i][j];
			a[k] = s1;
			k++;
		}

		for (int i = 1; i < k; i++)
			if (a[i] != a[0])
				return 0;

		return a[0];
	}

	static int SumaColoane(int v[][], int n, int c, int f) {
		int s2, k = 0;
		int[] a = new int[n];

		for (int j = c; j < f; j++) {
			s2 = 0;
			for (int i = c; i < f; i++)
				s2 = s2 + v[i][j];
			a[k] = s2;
			k++;
		}

		for (int j = 1; j < k; j++)
			if (a[j] != a[0])
				return 0;

		return a[0];
	}

	static int SumaDiagP(int v[][], int n, int c, int f) {
		int s3 = 0;
		for (int i = c; i < f; i++)
			for (int j = c; j < f; j++)
				if (i == j)
					s3 = s3 + v[i][j];

		return s3;
	}

	static int SumaDiagS(int v[][], int n, int c, int f) {
		int s4 = 0;
		for (int i = c; i <= f; i++)
			for (int j = c; j < f; j++)
				if (i + j == f + c - 1)
					s4 = s4 + v[i][j];

		return s4;
	}
}

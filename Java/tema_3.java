
import java.util.*;

public class tema_3 {
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Introdu dimensiunea  matricei:");
        int n = sc.nextInt();
		if (n<3) {
			System.out.println("Nu pot fi formate submatrici cu aceasta dimensiune!");
			return;
		}
        int[][] A = new int[n][n];

        System.out.println("Introdu elementele matricei:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = sc.nextInt();
            }
        }
        int m;
        if (n % 2 == 1) {
            m = n;
        } else {
            m = n - 1;
        }

        int inceput = (n - m) / 2;
        int[][] M = new int[m][m];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                M[i][j] = A[inceput + i][inceput + j];
            }
        }
        System.out.println("Submatricea centrala este:");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(M[i][j] + " ");
            }
            System.out.println();
        }

        int suma = 0;
        for (int j = 0; j < m; j++) suma=suma+ M[0][j];
        boolean magica = true;

        for (int i = 1; i < m; i++) {
            int s = 0;
            for (int j = 0; j < m; j++) s= s+ M[i][j];
            if (s != suma) magica = false;
        }

        for (int j = 0; j < m; j++) {
            int s = 0;
            for (int i = 0; i < m; i++) s=s+ M[i][j];
            if (s != suma) magica = false;
        }

        int sdp = 0, sds = 0;
        for (int i = 0; i < m; i++) {
            sdp=sdp+ M[i][i];
            sds=sds+ M[i][m - 1 - i];
        }
        if (sdp != suma || sds != suma) magica = false;

        if (magica) {
            System.out.println("Matrice magica partiala! Suma comuna este = " + suma);
        } else {
            System.out.println("Matrice nemagica!");
        }

        sc.close();
    }

}

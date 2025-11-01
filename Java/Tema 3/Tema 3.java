import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class tema3 {
    public static void main(String[] args) {
        var fis = new File("tema3.txt");
        try (var sc = new Scanner(fis)) {
            while (sc.hasNextInt()) {
                int dim = sc.nextInt();
                if (dim % 2 == 0) {
                    System.out.println("Marimea matricii trebuie sa fie impara");
                    return;
                }

                int[][] mat = new int[dim][dim];
                for (int i = 0; i < dim; i++)
                    for (int j = 0; j < dim; j++)
                        mat[i][j] = sc.nextInt();

                int sum = 0;
                for (int j = 0; j < dim; j++)
                    sum += mat[0][j];

                // verificare randuri
                for (int i = 1; i < dim; i++) {
                    int s = 0;
                    for (int j = 0; j < dim; j++)
                        s += mat[i][j];
                    if (s != sum) {
                        System.out.println("Matricea nemagica");
                        return;
                    }
                }

                // verificare coloane
                for (int j = 0; j < dim; j++) {
                    int s = 0;
                    for (int i = 0; i < dim; i++)
                        s += mat[i][j];
                    if (s != sum) {
                        System.out.println("Matricea nemagica");
                        return;
                    }
                }

                // verificare diagonale
                int diag1 = 0, diag2 = 0;
                for (int i = 0; i < dim; i++) {
                    diag1 += mat[i][i];
                    diag2 += mat[i][dim - 1 - i];
                }
                if (diag1 != sum || diag2 != sum) {
                    System.out.println("Matricea nemagica");
                    return;
                }

                System.out.println("Matrice magica");
            }
        } catch (FileNotFoundException e) {
            System.out.println("Fisierul nu exista");
        }
    }
}

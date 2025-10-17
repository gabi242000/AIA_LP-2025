import java.util.Scanner;
public class ex1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Va rog introduceti marimea matricii: ");
        int n = in.nextInt();
        if  (n % 2 == 0) {
            System.out.println("Va rog introduceti o valoare impara: ");
            n = in.nextInt();
        }
        int [][] matrice = new int [n][n];
        for(int i=0 ; i < n ; i++)
            for(int j=0 ; j < n ; j++)
                matrice[i][j] = in.nextInt();
        int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
        for (int i = 1 ; i < n - 1; i++)
            sum1 += matrice[i][1];
        for(int i = 2; i < n - 1; i++) {
            sum2 = 0;
            for (int j = 1; j < n - 1; j++)
                sum2  += matrice[j][i];
            if(sum1 != sum2){
                System.out.println("Matrice nemagica");
                return;
            }
        }
        for (int j = 1 ; j < n - 1; j++)
            sum3 += matrice[1][j];
        for(int i = 2 ; i < n - 1; i++) {
            sum4 = 0;
            for (int j = 1; j < n - 1; j++)
                sum4 += matrice[i][j];
            if(sum3 != sum4) {
                System.out.println("Matrice nemagica");
                return;
            }
        }
        if(sum1 != sum3){
            System.out.println("Matrice nemagica");
            return;
        }
        int sum5 = 0;
        for(int i = 1; i < n - 1; i++)
            for(int j = 1; j < n - 1; j++)
                if(i == j)
                    sum5 += matrice[i][j];
        if(sum5 != sum1){
            System.out.println("Matrice nemagica");
            return;
        }
        int sum6 = 0;
        for(int i = 1; i < n - 1; i++){
            for(int  j = 1; j < n - 1; j++){
                if(i + j == n - 1){
                    sum6 += matrice[i][j];
                }
            }
        }
        if(sum6 != sum1){
            System.out.println("Matrice nemagica");
            return;
        }
        System.out.println("Matrice partial magica");
        System.out.print("Suma este: " + sum1);
    }
}

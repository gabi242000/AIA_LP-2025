package tema3;
import java.util.Scanner;
public class Ex1 {
	 public static void main(String[] args) {
		 Scanner in=new Scanner(System.in);
		 System.out.print("Introduceti dimensiunea n:");
		 int n=in.nextInt();
	     int[][] a=new int[n][n];

	     System.out.println("Introduceti elementele matricei:");
	        for (int i=0;i<n;i++)
	            for (int j=0;j<n;j++)
	                a[i][j]=in.nextInt();

	     int suma=0;
	        for (int j=0;j<n;j++)
	            suma += a[0][j];

	     boolean magica=true;

	        for (int i=0; i<n && magica;i++) {
	            int s=0;
	            for (int j=0;j<n;j++)
	                s += a[i][j];
	            if (s!=suma)
	                magica=false;
	        }

	        for (int j=0;j<n && magica;j++) {
	            int s=0;
	            for (int i=0;i<n;i++)
	                s += a[i][j];
	            if (s!=suma)
	                magica=false;
	        }

	     int diag1=0, diag2=0;
	        for (int i=0;i<n;i++) {
	            diag1 += a[i][i];
	            diag2 += a[i][n-1-i];
	        }
	        if (diag1!=suma || diag2!=suma)
	            magica=false;

	        if (magica)
	            System.out.println("Suma comuna: " + suma + "\nMatrice magica partial");
	        else
	            System.out.println("Matrice nemagica");

	        in.close();
	    }
}

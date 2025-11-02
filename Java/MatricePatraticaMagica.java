package temalaborator3;
import java.util.Scanner;

public class MatricePatraticaMagica {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		 Scanner in= new Scanner(System.in);
		 
		 System.out.print("Introduceti dimensiunea matricei (n): ");
		 int n= in.nextInt();
		 int[][] a= new int[n][n];
		 
		 System.out.println("Introduceti elementele matricei: ");
		 for (int i= 0; i< n; i++)
			 for(int j=0; j<n; j++)
				 a[i][j]= in.nextInt();
		 
		 //det dim submat impare centrale
		 int dim= (n %2 == 1) ? n : n- 1;
		 int start= ( n- dim)/2;
		 //daca n este impar, matricea ramane neschimbata, iar daca n este par se elimina prima linie si prima coloana
		 
		 //extragere submat centrala
		 int[][] sub= new int[dim][dim];
		 for (int i= 0; i< dim; i++)
			 for( int j=0; j< dim; j++)
				 sub[i][j]= a[start+ i][start+ j];
		 
		 int suma= -1;
		 boolean magica= true;
		 
		 //sume pe coloane
		 for(int j= 0; j< dim; j++) {
			 int s=0;
			 for(int i= 0; i< dim; i++)
				 s += sub[i][j];
			 if ( s != suma)
				 magica= false;
		 }
		 
		 //sume pe linii
		 for (int i= 0; i< dim; i++) {
			 int s= 0;
			 for (int j= 0; j< dim; j++)
				 s += sub[i][j];
			 if ( s != suma)
				 magica= false;
		 }
		 
		 //diag principala
		 int diagprincipala= 0;
		 for (int i= 0; i< dim; i++)
			 diagprincipala += sub[i][i];
		 if ( diagprincipala != suma)
			 magica= false;
		 
		 System.out.println("\nCea mai mare submatrice centrala cu dimensiune impara (" + dim + "x" + dim + "):");
	     for (int i = 0; i < dim; i++) {
	    	 for (int j = 0; j < dim; j++) {
	    		 System.out.print(sub[i][j] + " ");
	    		 }
	    	 System.out.println();
	    	 }
	     
	     System.out.println();
	     if (magica)
	    	 System.out.println("Matrice magica partial, suma comuna = " + suma);
	     else
	    	 System.out.println("Matrice nemagica");
	}

}

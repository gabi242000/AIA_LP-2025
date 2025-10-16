package Grupa1.Java.Tema3;

import java.util.Scanner;

//Pentru ca dimensiunea celei mai mari submatrice centrale sa fie impara , n trebuie sa fie impar


public class Ex1 {

    public static int[][] citireMatrice(int n,Scanner scanner,int [][] matrice){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                matrice[i][j] = scanner.nextInt();
        }

        return matrice;
    }

    public static void afisareMatrice(int n,int [][] matrice){

        System.out.println("Matricea este :");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                System.out.print(matrice[i][j] + " ");
            System.out.println();
        }
    }   


    public static boolean PM(int n,int [][] matrice){
       boolean ok = true;

       int sumalinie=0;
       int sumacoloana=0;
       int sumadiagPrincipala=0;
       int sumadiagSecundara=0;

       for(int j=1;j<n-1;j++)
           sumalinie += matrice[1][j];
       

       for(int i=1;i<n-1;i++)
        sumacoloana += matrice[i][1];

        for(int i=1;i<n-1;i++){
            int sumatemp=0;
            for(int j=1;j<n-1;j++)
                sumatemp += matrice[i][j];
            if(sumatemp != sumacoloana){ ok= false; break;}
        }

        for(int j=1;j<n-1;j++){
            int sumatemp=0;
            for(int i=1;i<n-1;i++)
                sumatemp += matrice[i][j];
            if(sumatemp != sumalinie){ ok= false; break;}
        }   


        for(int i=1;i<n-1;i++){
            for(int j=1;j<n-1;j++)
                if(i==j) sumadiagPrincipala += matrice[i][j];
        }

        for(int i=1;i<n-1;i++){
            for(int j=1;j<n-1;j++)
                if(i+j == n-1) sumadiagSecundara += matrice[i][j];
        }

        if(sumadiagPrincipala!=sumacoloana) ok =false;



        if(sumadiagSecundara!=sumadiagPrincipala) ok =false;
   




       return ok;
    }

     
    public static void main(String[] args) {

        boolean magic=true;
        int n=0;
       
        Scanner scanner = new Scanner(System.in);

        System.out.println("Introduceti numarul de linii si de coloane a matricei :");

       while(n%2==0) { 
             if(n%2==0)   System.out.println("Trebuie introdusa o valoare para!");
                n = scanner.nextInt();
       }
       
        System.out.println("Introduceti elementele matricei :");
        int [][] matrice = new int[n][n];
        
            matrice = citireMatrice(n, scanner, matrice);
            
        
        

        afisareMatrice(n, matrice);

         magic = PM(n, matrice);
        
        
        if(magic) System.out.println("Matricea este partial magica");
        else System.out.println("Matricea este nemagica");



        




        
    }
}

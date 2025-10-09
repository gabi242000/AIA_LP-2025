package Grupa1.Java.Tema2;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Ex2 {
    public static void main(String[] args){
            Scanner scanner = new Scanner(System.in);
            int n,min=9999,max=-9999;

            try{
                System.out.println("Introduceti numarul de la tastatura:");
                n = scanner.nextInt();
            } catch (InputMismatchException e){
                System.out.println("Nu ati introdus un numar intreg");
                return;
            }

            while(n!=0){
                int x=n%10;
                if(x<min) min=x;
                if(x>max) max=x;
                n=n/10;
            }

            System.out.println("Cifra minima este: " + min);
            System.out.println("Cifra maxima este: " + max); 
            
            scanner.close();
        }


       
}

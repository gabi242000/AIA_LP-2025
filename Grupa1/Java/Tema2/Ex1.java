package Grupa1.Java.Tema2;

import java.util.Scanner;

public class Ex1 {

    public static int[] citireVector(int n, Scanner scanner){
        int[] v = new int[n];
        for(int i=0;i<n;i++){
            v[i] = scanner.nextInt();
        }
        return v;
    }

    public static int sumaPare(int[] v){
        int suma =0;
        for(int i=0;i<v.length;i++){
            if(v[i]%2==0)
                suma += v[i];
        }

        return suma;
    }
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Introduceti numarul de elemente al vectorului:");

        int n = scanner.nextInt();
        int[] v = new int[n];

        System.out.println("Introduceti elementele vectorului:");

        
        v = citireVector(n, scanner);

        System.out.println("Elementele pare ale vectorului sunt:");
        for(int i=0;i<n;i++){
            if(v[i]%2==0)
                System.out.print(v[i]+ " ");
            
        
        }
        System.out.println();

        System.out.println("Suma elementelor pare este: " + sumaPare(v));
        



    }

}

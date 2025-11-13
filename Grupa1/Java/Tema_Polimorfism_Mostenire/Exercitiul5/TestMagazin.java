package Grupa1.Java.Tema_Polimorfism_Mostenire.Exercitiul5;

import java.util.*;
public class TestMagazin {

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int n;
        System.out.println("Introduceti numarul de produse din magazin:");
        n = scanner.nextInt();
        scanner.nextLine();

        List<Produs> produse = new ArrayList<>();

        for(int i=0;i<n;i++){
            System.out.println("Produsul numarul "+ (i+1));
            System.out.println("Introduceti tipul produsului: 1-Aliment, 2-Electronic, 3-Haina");
            int tip = scanner.nextInt();
            scanner.nextLine();

            switch (tip) {
                case 1 ->                     {
                        Produs aliment = new Alimente(null,0,false);
                        System.out.println("Introduceti denumirea produsului alimentar:");
                        String denumire = scanner.nextLine();
                        aliment.denumire = denumire;
                        System.out.println("Introduceti pretul produsului alimentar:");
                        double pret = scanner.nextDouble();
                        scanner.nextLine();
                        aliment.pret = pret;
                        System.out.println("Produsul este aproape de expirare? (true/false)");
                        boolean aproapeExpirare = scanner.nextBoolean();
                        scanner.nextLine();
                        ((Alimente) aliment).aproapeExpirare = aproapeExpirare;
                        produse.add(aliment);
                    }
                case 2 ->                     {
                        Produs electronic = new Electronice(null,0);
                        System.out.println("Introduceti denumirea produsului electronic:");
                        String denumire = scanner.nextLine();
                        electronic.denumire = denumire;
                        System.out.println("Introduceti pretul produsului electronic:");
                        double pret = scanner.nextDouble();
                        scanner.nextLine();
                        electronic.pret = pret;
                        produse.add(electronic);
                    }
                case 3 ->                     {
                        Produs haina = new Haine(null,0);
                        System.out.println("Introduceti denumirea hainei:");
                        String denumire = scanner.nextLine();
                        haina.denumire = denumire;
                        System.out.println("Introduceti pretul hainei:");
                        double pret = scanner.nextDouble();
                        scanner.nextLine();
                        haina.pret = pret;
                        produse.add(haina);
                    }
                default -> {
                }
            }
        }

        double total = 0;
        for(Produs produs : produse){
            produs.PretFinal();
            total += produs.pret;
            System.out.println("Produsul 1: " + produs.denumire + ", Pret: "+ produs.pret);;
        }  

        System.out.println("Total de plata: "+ total);

    }
}
    

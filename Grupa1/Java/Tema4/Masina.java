package Grupa1.Java.Tema4;
import java.util.Scanner;
public class Masina {
    private String marca;
    private String model;
    private int an_fabricare;
    private String culoare;
    private  double pret;

    public Masina(String marca,String model,int an_fabricare, String culoare, double pret){
        
    }

    public void setMarca(String marca){
        this.marca = marca;
    }

    public void setModel(String model){
        this.model = model;
    }
    public void setAnFabricare(int  an_fabricare){
        this.an_fabricare = an_fabricare;
    }
    public void setCuloare(String culoare){
        this.culoare = culoare;
    }
    public void setPret(double pret){
        this.pret= pret;
    }

    public String getMarca(){
        return marca;
    }
    public String getModel(){
        return model;
    }
    public int getAnFabricare(){
        return an_fabricare;
    }
    public String getCuloare(){
        return culoare;
    }
    public double getPret(){
        return pret;
    }


    public void afisareMasina(){
        System.out.println("Datele masinii sunt:");
        System.out.println("Marca: "+ marca);
        System.out.println("Model: "+ model);
        System.out.println("An fabricare: "+ an_fabricare);
        System.out.println("Culoare: "+ culoare);
        System.out.println("Pret : "+ pret);
    
    }


    public static void main(String[]args){
        Masina masina = new Masina(null, null, 0, null, 0);
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.println("Introdu datele masinii:");
            System.out.println("Marca: ");
            masina.setMarca(scanner.nextLine());
            System.out.println("Model: ");
            masina.setModel(scanner.nextLine());
            System.out.println("An de fabricare: ");
            masina.setAnFabricare(scanner.nextInt());
            scanner.nextLine();
            System.out.println("Culoare: ");
            masina.setCuloare(scanner.nextLine());
            System.out.println("Pret: ");
            masina.setPret(scanner.nextDouble());
            scanner.nextLine();
        }
        catch (Exception e) {
            System.out.println("A aparut o eroare: " + e.getMessage());
        }

        System.out.println("\n\n\n");
        masina.afisareMasina();

    }
   




   
}

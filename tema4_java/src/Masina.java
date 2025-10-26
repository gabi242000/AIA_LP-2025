import java.util.Scanner;
public class Masina {
    private String marca;
    private String model;
    private int an_fabricare;
    private String culoare;
    private double pret;
    public Masina(String marca, String model, int an_fabricare, String culoare, double pret) {
        this.marca = marca;
        this.model = model;
        this.an_fabricare = an_fabricare;
        this.culoare = culoare;
        this.pret = pret;
    }
    public void afisareMasina() {
        System.out.println("Marca: " + marca);
        System.out.println("Model: " + model);
        System.out.println("An Fabricare: " + an_fabricare);
        System.out.println("Culoare: " + culoare);
        System.out.println("Pret: " + pret);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Introduceti datele masinii: ");
        System.out.println("Marca: ");
        String marca = sc.nextLine();
        System.out.println("Model: ");
        String model = sc.nextLine();
        System.out.println("An Fabricare: ");
        int an_fabricare = sc.nextInt();
        sc.nextLine();
        System.out.println("Culoare: ");
        String culoare = sc.nextLine();
        System.out.println("Pret: ");
        double pret = sc.nextDouble();
        Masina masina = new Masina(marca, model, an_fabricare, culoare, pret);
        masina.afisareMasina();
    }
}

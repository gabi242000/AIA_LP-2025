import java.util.Scanner;

public class Masina{
    
    private String marca;
    private String model;
    private int an_fabricare;
    private String culoare;
    private double pret;

    public Masina(String marca,String model,int an_fabricare,String culoare,double pret)
    {
        this.marca=marca;
        this.model=model;
        this.an_fabricare=an_fabricare;
        this.culoare=culoare;
        this.pret=pret;
    }
    
    public void afisareMasina()
    {
        System.out.println("Marca masinii este: "+marca);
        System.out.println("Modelul masinii este: "+model);
        System.out.println("Anul de fabricare al masinii este: "+an_fabricare);
        System.out.println("Culoarea masinii este: "+culoare);
        System.out.println("Pretul masinii este: "+pret);
    }
    
    public static void main(String [] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Introduceti detaliile masinii: ");
        
        System.out.println("Introduceti marca masinii: ");
        String marca=sc.nextLine();
        
        System.out.println("Introduceti modelul masinii: ");
        String model=sc.nextLine();
        
        System.out.println("Introduceti anul de fabricare al masinii: ");
        int an_fabricare=sc.nextInt();
        sc.nextLine();
        
        System.out.println("Introduceti culoarea masinii: ");
        String culoare=sc.nextLine();
        
        System.out.println("Introduceti pretul masinii: ");
        Double pret=sc.nextDouble();
        
        System.out.println("Detaliile masinii sunt: ");
        Masina m=new Masina(marca,model,an_fabricare,culoare,pret);
        m.afisareMasina();
        
    }
}
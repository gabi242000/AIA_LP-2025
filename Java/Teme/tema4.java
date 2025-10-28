import java.util.Scanner;

class Animal{
    String nume , specie;
    int varsta;
    Animal(){
        nume = "Necunoscut";
        specie = "Necunoscuta";
        varsta = 0;
    }
    public void afisareAnimal()
    {
        System.out.println("Nume :" + nume);
        System.out.println("Specie :" + specie);
        System.out.println("Varsta :" + varsta);
    }
}

class Masina{
    String marca , model , culoare;
    int an_fabricare , pret;
    public Masina(String marca , String model , String culoare , int an_fabricare , int pret){
        marca = this.marca;
        model = this.model;
        culoare = this.culoare;
        an_fabricare = this.an_fabricare;
        pret = this.pret;
    }
    public void afisareMasina(){
        System.out.println("Marca :" + marca);
        System.out.println("Model :" + model);
        System.out.println("An de fabricatie :" + an_fabricare);
        System.out.println("Culoare :" + culoare);
        System.out.println("Pret :" + pret);
    }
}

class FacturaServiciu{
    String denumireServiciu;
    int tarifOra , numarOre , valoareTotala;
    public void valTotala(){
        valoareTotala = tarifOra * numarOre;
    }
    FacturaServiciu(String denumireServiciu , int tarifOra , int numarOre){
        denumireServiciu = this.denumireServiciu;
        tarifOra = this.tarifOra;
        numarOre = this.numarOre;
    }
    public void afisareFactura(){
        System.out.println("Denumire serviciu :" + denumireServiciu);
        System.out.println("Tarif per ora :" + tarifOra);
        System.out.println("Numar ore :" + numarOre);
        valTotala();
        System.out.println("Valoare totala :" + valoareTotala);
    }
}
public class tema4{
    public static void main(String[] args)
    {
        var sc = new Scanner(System.in);
        while(true)
        {
            int x = sc.nextInt();
            switch(x)
            {
                case 1:
                {
                    var animal = new Animal();
                    animal.afisareAnimal();
                    System.out.println();
                    break;
                }
                case 2:
                {
                    var masina = new Masina(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextInt() , sc.nextInt());
                    masina.afisareMasina();
                }
                case 3:
                {
                    var fact = new FacturaServiciu(sc.nextLine() , sc.nextInt() , sc.nextInt());
                    fact.afisareFactura();
                }
            }
        }
    }
}
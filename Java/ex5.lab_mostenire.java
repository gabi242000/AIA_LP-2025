
import java.util.*;

abstract class Produs{
	protected String denumire;
	protected double pret;
	public Produs(String denumire, double pret){
		this.denumire=denumire;
		this.pret=pret;
	}
	public double calculeazaPretFinal() {
		return pret;
	}
	public String toString() {
		return denumire + "(pret de baza: " + pret + ")";
	}
}

 class Electronice extends Produs{
	 public Electronice(String denumire, double pret) {
		 super(denumire, pret);
	 }
	 public double calculeazaPretFinal() {
		 return pret - 0.1*pret;
	 }
 }
 
 class Haine extends Produs{
	 public Haine(String denumire, double pret) {
		 super(denumire, pret);
	 }
	 public double calculeazaPretFinal() {
		 return pret - 0.2*pret;
	 }
 }
 
 class Alimente extends Produs{
	 private boolean aproapeExpirare;
	 public Alimente(String denumire, double pret, boolean aproapeExpirare) {
		 super(denumire,pret);
		 this.aproapeExpirare=aproapeExpirare;
	 }
	 public double calculeazaPretFinal() {
		 if (aproapeExpirare==true) return pret - 0.3*pret;
		 else return pret;
	 }
	 public String toString() {
			return denumire + "(pret de baza: " + pret + ", aproape de expirare" + aproapeExpirare + ")";
		}
 }
public class TestMagazin {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
        System.out.print("Introdu numar de produse: ");
        int n = sc.nextInt();
        Produs produse[] = new Produs[n];
        for(int i=0; i<n; i++) {
        	System.out.println("Produs "+ (i+1));
        	System.out.println("Alege tipul produsului( 1-electronice, 2-haine, 3-alimente): ");
        	int tip= sc.nextInt();
        	sc.nextLine();
        	System.out.println("introdu denumire produs: ");
        	String denumire=sc.nextLine();
        	System.out.println("introdu pretul de baza: ");
        	double pret=sc.nextDouble();
        	if (tip==1) produse[i]= new Electronice(denumire,pret);
        	else if (tip==2) produse[i]= new Haine(denumire,pret);
        	else if (tip==3) {
        		System.out.print("Produsul e aproape de expirare? (true / false):");
        		boolean aproapeExpirare = sc.nextBoolean();
        		produse[i]= new Electronice(denumire,pret);
        	}
        }
        double total = 0;
        System.out.println("Lista produse: ");
        for (int i=0; i<produse.length; i++) {
        	double pretFinal= produse[i].calculeazaPretFinal();
        	System.out.println(produse[i].toString()+" - pret final: "+pretFinal);
        	total = total + pretFinal;
        }
        System.out.println("Total de plata: "+total);
        sc.close();
	}

}
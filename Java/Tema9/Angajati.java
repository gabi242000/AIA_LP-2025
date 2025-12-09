package temalab9;

import java.io.*;
import java.util.Scanner;
class Angajat{
	
	String nume, prenume;
	double salariu;
	public Angajat(String nume, String prenume, double salariu) {
		this.nume=nume;
		this.prenume=prenume;
		this.salariu=salariu;
	}
	
	public double getSalariu() {
		return salariu;
	}
}

public class Angajati {
	private Angajat[] angajati;
	private int numaraAngajati() {
        int contor = 0;
        try (Scanner scanner = new Scanner(new File("angajati.txt"))) {
            while (scanner.hasNextLine()) {
            	String linie = scanner.nextLine();
                contor++;
            }
        } catch (FileNotFoundException e) {
            System.err.println("Eroare: Fisierul 'angajati.txt' nu a fost gasit");
            return 0;
        }
        return contor;
    }
	int nrAngajati;
	public void citireAngajati() {
		this.nrAngajati=numaraAngajati();
		int i=0;
		this.angajati = new Angajat[nrAngajati];
		try (Scanner scanner = new Scanner (new File("angajati.txt"))){
			while (scanner.hasNextLine()) {
				String linie = scanner.nextLine();
				String[] parti = linie.split("\\s+");
				angajati[i] = new Angajat(parti[0],parti[1],Double.parseDouble(parti[2]));
				i++;
			}
		} catch (FileNotFoundException e) {
			System.err.println("Fisierul nu a fost gasit.");
		}
	}
	
	public double salariuMediu() {
		double ss=0;
		for (int i=0;i<angajati.length;i++) {
			ss += angajati[i].salariu;
		}
		return ss/angajati.length;
	}
	
	public String angajatSalarMaxim() {
		double sm=0;
		String numeAng="";
		for (int i=0;i<angajati.length;i++) {
			if (angajati[i].salariu > sm) {
				sm=angajati[i].salariu;
				numeAng = angajati[i].nume + " " + angajati[i].prenume;
			}
		}
		
		return numeAng;
	}
	
	public void scrieAngPesteMedie() {
		try (PrintWriter writer = new PrintWriter("venit_peste_medie.txt")){
			for (int i=0;i<angajati.length;i++) {
				if (angajati[i].salariu> salariuMediu())
					writer.println(angajati[i].nume +" "+ angajati[i].prenume +" " + angajati[i].salariu);
			}
		}catch (IOException e) {
			System.err.println("eroare in venit peste medie");
		}
	}
	
	public void scrieRaport() {
		try (PrintWriter writer = new PrintWriter("raport_angajati.txt")){
			writer.println("nr angajati: " + angajati.length);
			writer.println("salariu mediu: " + salariuMediu());
			writer.println("angajat cu salariul maxim : " + angajatSalarMaxim());
		}catch (IOException e) {
			System.err.println("eroare raport");
		}
	}
	
	public static void main(String[] args) {
		Angajati a = new Angajati();
		a.citireAngajati();
		a.scrieAngPesteMedie();
		a.scrieRaport();
	}
}

package temalab9ex1;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Angajati {

	public static void main(String[] args) throws IOException{
		File fisier = new File("angajati.txt");
		if(!fisier.exists()) {
			System.out.println("Fisierul nu exista");
			return;
		}
		int nr_angajati=0;
		double valTotala =0;
		double media = 0;
		double salariuMax=0;
		String angajatMax="";
		BufferedReader br = new BufferedReader(new FileReader(fisier));
		BufferedWriter bw = new BufferedWriter(new FileWriter("venit_peste_medie.txt"));
		String linie;
		while((linie = br.readLine()) !=null) {
			nr_angajati ++;
			String[] a = linie.split(" ");
			String nume =a[0];
			String prenume = a[1];
			double salariu = Double.parseDouble(a[2]);
			valTotala= valTotala + salariu;
			if (salariu > salariuMax) {
				salariuMax = salariu;
				angajatMax= nume + " " + prenume;
			}
			media = valTotala/nr_angajati;
			if (salariu > media) {
				bw.write(linie);
				bw.newLine();
			}	
		}
		br.close();
		bw.close();
		BufferedWriter bww = new BufferedWriter(new FileWriter("raport_angajati.txt"));
		bww.write("Numar total de angajati: "+nr_angajati);
		bww.newLine();
		bww.write("Salariu mediu: "+ media);
		bww.newLine();
		bww.write("Angajat cu salariu maxim: "+angajatMax+ " "+ salariuMax);
		System.out.println("Raport generat cu succes");
        bww.close();
	}

}

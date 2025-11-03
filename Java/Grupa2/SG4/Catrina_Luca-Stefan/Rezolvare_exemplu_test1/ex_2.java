package exemplu_test;

import java.util.Scanner;

class Student{
	private String nume;
	private int varsta;
	private double[] note;
	
	public Student(String nume, int varsta, double[] note) {
		this.nume = nume;
		this.varsta = varsta;
		this.note = note;
	}
	
	public double media() {
		
		double media = 0;
		for(int i = 0; i < note.length; i++)
			media += note[i];
		return media/note.length;
	}
	
	public void afisare() {
		System.out.println("Numele studentului este: " + nume);
		System.out.println("Studentul " + nume + " are " + varsta + " ani.");
		System.out.println("Notele studentului sunt: ");
		for(int i = 0; i < note.length; i++)
			System.out.print(note[i] + "\t");
		System.out.println();
		System.out.println("Media studentului este: " + media());
		System.out.println();
	}
}

public class ex_2 {
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Introduceti numarul studentilor: ");
		int nrStudenti = sc.nextInt();
		sc.nextLine();
		
		Student[] studenti = new Student[nrStudenti];
		
		for(int i = 0; i < nrStudenti; i++) {
			
			System.out.println("\n--- Studentul " + (i + 1) + " ---");
		
			System.out.println("Introduceti numele studentului: ");
			String nume = sc.nextLine();
			System.out.println("Introduceti varsta studentului: ");
			int varsta = sc.nextInt();
			System.out.println("Introduceti numarul de note ale studentului:");
			int nrNote = sc.nextInt();
			System.out.println("Introduceti notele: ");
			double[] note = new double[nrNote];
			for(int j = 0; j < nrNote; j++)
				note[j] = sc.nextDouble();
			sc.nextLine();
			
			studenti[i] = new Student(nume, varsta, note);
		}
		
		for(int i = 0; i < nrStudenti; i++) {
			
			studenti[i].media();
			studenti[i].afisare();
		}
		
		double topMedie = studenti[0].media();
		int studentTop = 0;
		
		for(int i = 0; i < nrStudenti; i++) 
			if(studenti[i].media() > topMedie){
				topMedie = studenti[i].media();
				studentTop = i;
			}
		
		System.out.println("Studentul cu cea mai mare medie este: ");
		studenti[studentTop].afisare();
		
		sc.close();
	}

}

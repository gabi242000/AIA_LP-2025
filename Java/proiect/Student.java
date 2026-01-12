package proiect;
import java.util.*;



public class Student {
	private String nume;
	private String prenume;
	private int varsta;
	private ArrayList<Integer> note;

	Student(String nume, String prenume, int varsta) {
		this.nume = nume;
		this.prenume = prenume;
		this.varsta = varsta;
		this.note = new ArrayList<>();
	}
	public String getNume() {
		return nume;
	}
	
	public String getPrenume() {
		return prenume;
	}
	
	public int getVarsta() {
		return varsta;
	}
	public void addNota(int nota) {
		note.add(nota);
	}
	
	public  ArrayList<Integer> getNote() {
		return note;
	}
	
	public String afiseazaNote() {
	    String rezultat = "Notele sunt: ";
	    for (int nota : note) {
	        rezultat += nota + " ";
	    }
	    return rezultat;
	}
	
	
	public double calculeazaMedie() {
		int suma = 0;
		double medie = 0;
		for(int nota : note) {
			suma += nota;
			
			
		}
		return suma / note.size();
	}
	
	public String prezentare() {
		
		return "Numele complet al studentului este "  + getNume() + " " + getPrenume() + " si are varsta de " + getVarsta() + " ani.";
	}
}

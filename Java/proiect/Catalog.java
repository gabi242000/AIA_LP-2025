package proiect;

import java.util.*;
public class Catalog {
	Scanner sc = new Scanner(System.in);
    private ArrayList<Student> studenti;

    public Catalog() {
        studenti = new ArrayList<>();
    }

    public void adaugaStudent(Student s) {
        studenti.add(s);
    }

    public void afiseazaStudentiCuIndex() {
        if (studenti.isEmpty()) {
            System.out.println("Nu exista studenti in catalog.");
            return;
        }

        for (int i = 0; i < studenti.size(); i++) {
            Student s = studenti.get(i);
            System.out.println(i + " -- " + s.getNume() + " " + s.getPrenume() + " (" + s.getVarsta() + " ani)");
        }
    }

    public void stergeStudent(int index) {
        if (studenti.isEmpty()) {
            System.out.println("Nu exista studenti in catalog.");
            return;
        }

        if (index < 0 || index >= studenti.size()) {
            System.out.println("Index invalid!");
            return;
        }

        studenti.remove(index);
        System.out.println("Student sters!");
        
    
    } 
    public Student getStudent(int index) {
    	if(index < 0 || index >= studenti.size()) {
    		return null;
    	}
    	return studenti.get(index);
    	
    }
    
    public void listaBursieri() {
		System.out.println("--LISTA STUDENTI BURSIERI--");
    	for(Student s : studenti) {
    		if(s.calculeazaMedie() > 9) {
    			System.out.println(s.getNume() + " " +s.getPrenume());
    			
    		}
    		
    	}
    }
		
    public void statisticiCatalog() {
        if (studenti.isEmpty()) {
            System.out.println("Catalog gol.");
            return;
        }

        double sumaMedii = 0;
        Student max = null;
        Student min = null;

        for (Student s : studenti) {
            if (s.getNote().isEmpty()) continue;

            double medie = s.calculeazaMedie();
            sumaMedii += medie;

            if (max == null || medie > max.calculeazaMedie()) {
                max = s;
            }
            if (min == null || medie < min.calculeazaMedie()) {
                min = s;
            }
        }

        System.out.println("Media generala: " + sumaMedii / studenti.size());
        System.out.println("Cea mai mare medie: " + max.getNume() + " " + max.getPrenume());
        System.out.println("Cea mai mica medie: " + min.getNume() + " " + min.getPrenume());
    }

    
    }



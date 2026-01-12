package proiect;
import java.util.*;



public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        Catalog catalog = new Catalog();

        Student student = null; 

        int meniu;
        do {
            System.out.println("Introdu alegerea pe care vrei sa o faci: ");
            System.out.println("\n      --CATALOG--");
            System.out.println(" 1 -- Adauga student");
            System.out.println(" 2 -- Sterge student");
            System.out.println(" 3 -- Adauga nota student");
            System.out.println(" 4 -- Lista studenti");
            System.out.println(" 5 -- Calculeaza medie student");
            System.out.println(" 6 -- Verifica student");
            System.out.println(" 7 -- Lista bursieri");
            System.out.println(" 8 -- Statistici Catalog");
            System.out.println(" 0 -- Iesire ");

            meniu = sc.nextInt();
            sc.nextLine(); 

            switch (meniu) {
                case 1:
                    System.out.println("Introdu numele studentului: ");
                    String nume = sc.nextLine();

                    System.out.println("Introdu prenumele studentului: ");
                    String prenume = sc.nextLine();

                    System.out.println("Introdu varsta studentului: ");
                    int varsta = sc.nextInt();
                    sc.nextLine();

                    student = new Student(nume, prenume, varsta);
                    System.out.println(student.prezentare());
                    catalog.adaugaStudent(student);
                    break;

                case 2:
                    catalog.afiseazaStudentiCuIndex();
                    System.out.print("Alege indexul studentului pe care doresti sa il stergi: ");
                    int n = sc.nextInt();
                    sc.nextLine();
                    catalog.stergeStudent(n);
                    break;

                case 3:
                	System.out.println("Alege index-ul studentului caruia doresti sa ii adaugi  nota/notele");
                	catalog.afiseazaStudentiCuIndex();
                	int index = sc.nextInt();
                	sc.nextLine();
                	Student ales = catalog.getStudent(index);
                	if(ales == null) {
                		System.out.println("Index Invalid");
                		break;
                	}
                	System.out.println("Cate note doresti sa adaugi?: ");
                	int contor = sc.nextInt();
                	sc.nextLine();
                	for(int i = 0; i < contor; i++) {
         
                		System.out.println("Nota " + (i+1) + ": ");
                		int nota = sc.nextInt();
                		if (nota >= 1 && nota <= 10) {
                		    ales.addNota(nota);
                		} else {
                		    System.out.println("Nota invalida (1–10)");
                		    i--;
                		}

                	
                	}
                		
                    break;
                   
                case 4:
                	catalog.afiseazaStudentiCuIndex();
                	break;

                case 5:
                    System.out.println("Alege index-ul studentului pentru calculul mediei:");
                    catalog.afiseazaStudentiCuIndex();

                    int idxMedie = sc.nextInt();
                    sc.nextLine();

                    Student stMedie = catalog.getStudent(idxMedie);
                    if (stMedie == null) {
                        System.out.println("Index invalid");
                        break;
                    }

                    System.out.println("Media studentului este: " + stMedie.calculeazaMedie());
                    break;
                
                case 6:
                	System.out.println("Alege index-ul studentului pe care doresti sa il verifici: ");
                	catalog.afiseazaStudentiCuIndex();
                	int idx = sc.nextInt();
                	sc.nextLine();
                	Student als = catalog.getStudent(idx);
                	if(als == null ) {
                		System.out.println("index invalid");
                		break;
                	}
                	
                	System.out.println(als.prezentare());
                	System.out.println(als.afiseazaNote());

                	break;
                	
                case 7:
                	catalog.listaBursieri();
                	
                	break;
                	
                case 8:
                	catalog.statisticiCatalog();
                	break;
                	
                case 0:
                    System.out.println("Iesire...");
                    break;

                default:
                    System.out.println("Optiune invalida!");
            }

        } while (meniu != 0);

        sc.close();
    }
}

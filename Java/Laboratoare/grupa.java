package lab5;
import java.util.*;
class Student {
    private String nume;
    private int varsta;
    private double[] note;
    public Student(String nume, int varsta, double[] note) {
        this.nume = nume;
        this.varsta = varsta;
        this.note = note;
    }
    public double medie() {
        if (note.length == 0) return 0;
        double s = 0;
        for (int i = 0; i < note.length; i++) s += note[i];
        return s / note.length;
    }

    public void afisare() {
        System.out.print("Student: " + nume + ", " + varsta + " ani, note = ");
        for (int i = 0; i < note.length; i++) {
            System.out.print(note[i]);
            if (i < note.length - 1) System.out.print(", ");
        }
        System.out.printf(" | medie = %.2f%n", medie());
    }

    public String getNume() {
        return nume;
    }
}

class Grupa {
    private Student[] studenti;
    public void citireGrupa(Scanner sc) {
        System.out.print("Număr studenți: ");
        int n = sc.nextInt();
        studenti = new Student[n];
        for (int i = 0; i < n; i++) {
            System.out.println("\n--- Student " + (i + 1) + " ---");
            System.out.print("Nume: ");
            String nume = sc.next();
            System.out.print("Vârsta: ");
            int varsta = sc.nextInt();
            System.out.print("Număr note: ");
            int k = sc.nextInt();
            double[] note = new double[k];
            System.out.println("Introduceți cele " + k + " note:");
            for (int j = 0; j < k; j++) note[j] = sc.nextDouble();
            studenti[i] = new Student(nume, varsta, note);
        }
    }

    public void afisareGrupa() {
        System.out.println("\n--- Lista Studenților ---");
        for (int i = 0; i < studenti.length; i++) {
            studenti[i].afisare();
        }
    }

    public Student studentMaxMedie() {
        if (studenti.length == 0) return null;
        Student best = studenti[0];
        for (int i = 1; i < studenti.length; i++) {
            if (studenti[i].medie() > best.medie()) best = studenti[i];
        }
        return best;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Grupa g = new Grupa();
        g.citireGrupa(sc);
        g.afisareGrupa();

        Student top = g.studentMaxMedie();
        if (top != null)
            System.out.println("\nStudentul cu media cea mai mare este: " + top.getNume());
        else
            System.out.println("\nNu există studenți în grupă.");
    }
}

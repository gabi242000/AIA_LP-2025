package tema9;
import java.io.*;
import java.util.*;
public class Angajati {
	 public static void main(String[] args)
	 {
		 File fisier=new File("angajati.txt");
		 if(!fisier.exists())
		 {
			 System.out.println("Fisierul nu exista!");
			 return;
		 }
		 String[] nume=new String[20];
		 double[] salarii=new double[20];
		 double medie=0;
		 double salmax=0;
		 int nrangajati=0;
		 String numemax="";
		 double sumasalarii=0;
		 try(Scanner s=new Scanner(new File("angajati.txt")); BufferedWriter bw=new BufferedWriter(new FileWriter("venit_peste_medie.txt")))
		 {
			 String linie;
			 while(s.hasNextLine())
			 {
				 linie=s.nextLine();
				 String[] p=linie.split(";");
				 String angajat=p[0];
				 double sal=Double.parseDouble(p[1]);
				 nume[nrangajati]=angajat;
				 salarii[nrangajati]=sal;
				 nrangajati++;
				 sumasalarii+=sal;
				 if(sal>salmax)
				 {
					 salmax=sal;
					 numemax=angajat;
				 }
			 }
			 medie=sumasalarii/nrangajati;
			 for(int i=0;i<nrangajati;i++)
			 {
				 if(salarii[i]>medie)
				 {
					 bw.write(nume[i]+";"+salarii[i]);
					 bw.newLine();
				 }
			 }
		 }catch(IOException e)
		 {
			 System.out.println("Eroare la citirea/scrierea fisierului!");
			 return;
		 }
		 try(BufferedWriter bw2=new BufferedWriter(new FileWriter("raport_angajati.txt")))
		 {
			 bw2.write("Numar total angajati: "+nrangajati);
			 bw2.newLine();
			 bw2.write("Salariu mediu: "+medie);
			 bw2.newLine();
			 bw2.write("Angajatul cu salariu maxim: "+numemax+";"+salmax);
			 bw2.newLine();
		 }catch(IOException e)
		 {
			 System.out.println("Eroare la generarea raportului!");
			 return;
		 }
		 System.out.println("Raport generat cu succes!");
	 }
}

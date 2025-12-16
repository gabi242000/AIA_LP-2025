package Tema9;

import java.io.*;
import java.util.Scanner;

public class Temperaturi {
		private double[] temperaturi;
		
		private int numaraTemperaturi(){
			int contor=0;
			try (Scanner sc = new Scanner(new File("temperaturi.txt"))){
				while (sc.hasNextDouble()) {
	            	double nr = sc.nextDouble();
	                contor++;
				}
			}catch (FileNotFoundException e) {
				System.err.println("Eroare: Fisierul 'temperaturi.txt' nu a fost gasit");
				return 0;
			}
			return contor;
		}
		
		public void citireTemp() {
			this.temperaturi = new double[numaraTemperaturi()];
			int i=0;
			try (Scanner sc = new Scanner(new File("temperaturi.txt"))){
				while(sc.hasNextDouble()) {
					temperaturi[i]=sc.nextDouble();
					i++;
				}
			}catch(FileNotFoundException e) {
				System.err.println("Fisierul nu a fost gasit.");
			}
		}
		
		public double tempMedie() {
			double st=0;
			for (int i=0;i<temperaturi.length;i++)
				st += temperaturi[i];
			return st/temperaturi.length;
		}
		
		public double tempMin() {
			double tmin=temperaturi[0];
			for (int i=1;i<temperaturi.length;i++)
				if (tmin>temperaturi[i])
					tmin=temperaturi[i];
			return tmin;
		}
		
		public double tempMax() {
			double tmax=temperaturi[0];
			for (int i=1;i<temperaturi.length;i++)
				if (tmax<temperaturi[i])
					tmax=temperaturi[i];
			return tmax;
		}
		
		public int nrSubZero() {
			int nr=0;
			for (int i=0;i<temperaturi.length;i++)
				if (temperaturi[i]<0)
					nr++;
			return nr;
		}
		
		public void scrieRaport() {
			try (PrintWriter writer = new PrintWriter(new File("raport_temperaturi.txt"))){
				writer.println("temp medie: " + tempMedie());
				writer.println("temp minima: " + tempMin());
				writer.println("temp maxima: " + tempMax());
				writer.println("nr temp sub zero: " + nrSubZero());
			}catch(IOException e) {
				System.err.println("eroare la scrierea raportului");
			}
		}
		
		public void scrieTempNegative() {
			try (PrintWriter writer = new PrintWriter(new File("temp_sub_zero.txt"))){
				for (int i=0;i<temperaturi.length;i++)
					if (temperaturi[i]<0)
						writer.println(temperaturi[i]);
			}catch(IOException e) {
				System.err.println("eroare la scrierea temperaturilor negative");
			}
		}
		
		public static void main(String[] args) {
			Temperaturi t = new Temperaturi();
			t.citireTemp();
			t.scrieRaport();
			t.scrieTempNegative();
		}
}
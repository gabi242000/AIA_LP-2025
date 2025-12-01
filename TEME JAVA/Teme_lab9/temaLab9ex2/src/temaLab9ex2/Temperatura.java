package temaLab9ex2;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Temperatura {

	public static void main(String[] args) {
		File fisier = new File("temperaturi.txt");
		if(!fisier.exists()) {
			System.out.println("Fisierul nu exista");
			return;
		}
		double tempMin =Double.MAX_VALUE;;
		double tempMax=Double.MIN_VALUE;
		double tempTotala=0;
		double tempMedie=0;
		int nr_valNeg = 0;
		try(
		BufferedReader br = new BufferedReader(new FileReader(fisier));
		BufferedWriter bw = new BufferedWriter(new FileWriter("temp_sub_zero.txt"))
			){
			String linie;
			while ((linie = br.readLine()) !=null) {
				double temp = Double.parseDouble(linie);
				tempTotala += temp;
				if(temp < tempMin) tempMin = temp;
				if(temp > tempMax) tempMax =temp;
				
					if(temp <0) {
						nr_valNeg++;
					     bw.write(temp + " ");      
					}
			}
			tempMedie= tempTotala/24;
			
		} catch (IOException e ) {
			System.out.println("Eroare la citirea/scrierea fisierelor");
			return;
		}
		try(BufferedWriter bww = new BufferedWriter(new FileWriter("raport_temperaturi.txt"))){
			bww.write("Temperatura medie: "+ tempMedie);
			bww.newLine();
			bww.write("Temperatura minima: "+ tempMin);
			bww.newLine();
			bww.write("Temperatura maxima: "+ tempMax);
			bww.newLine();
			bww.write("Numar valori negative: "+ nr_valNeg);
			bww.newLine();
			System.out.println("Raport generat cu succes");
		}catch (IOException e) {
			System.out.println("eroare la generarea raportului");
		}
	}
}

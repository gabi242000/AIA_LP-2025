package tema9;
import java.io.*;
import java.util.*;
public class ex2 {
	public static void main(String[] args)
	{
		File fisier=new File("temperaturi.txt");
		if(!fisier.exists())
		{
			System.out.println("Fisierul nu exista");
			return;
		}
		double medie=0;
		double maxim=-1000;
		double minim=1000;
		double suma=0;
		int nrtemp=0;
		int nrsz=0;
		try(Scanner s=new Scanner(new File("temperaturi.txt")); BufferedWriter bw=new BufferedWriter(new FileWriter("temp_sub_zero.txt")))
		{
			String linie;

			while(s.hasNextLine())
			{
				linie=s.nextLine();
				double temperatura=Double.parseDouble(linie);
				suma+=temperatura;
				nrtemp++;
				if(temperatura<minim)
				{
					minim=temperatura;
				}
				if(temperatura>maxim)
				{
					maxim=temperatura;
				}
				if(temperatura<0)
				{
					nrsz++;
					bw.write(""+temperatura);
					bw.newLine();
				}
			}
			medie=suma/nrtemp;
		}catch(IOException e)
		{
			System.out.println("Eroare la citirea/scrierea fisierului!");
			return;
		}
		try(BufferedWriter bw2=new BufferedWriter(new FileWriter("raport_temperaturi.txt")))
		{
			bw2.write("Temperatura medie: "+medie);
			bw2.newLine();
			bw2.write("Temperatura maxima: "+maxim);
			bw2.newLine();
			bw2.write("Temperatura minima: "+minim);
			bw2.newLine();
			bw2.write("Numar temperaturi sub 0: "+nrsz);
		}catch(IOException e)
		{
			System.out.println("Eroare la generarea raportului!");
			return;
		}
		System.out.println("Raport generat cu succes!");
	}
}

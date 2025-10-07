package tema_lab;
import java.io.*;

public class temalab2 {
	public static void main(String[] args) throws IOException{
		InputStreamReader isr= new InputStreamReader (System.in);
		BufferedReader br = new BufferedReader(isr);
		System.out.println("Introduceti 3 numere naturale:");
		String s = br.readLine();
		int x = Integer.parseInt(s);
		String t = br.readLine();
		int y = Integer.parseInt(t);
		String u = br.readLine();
		int z = Integer.parseInt(u);
		int suma = x + y + z;
		System.out.println("Suma lor este:" + suma);
		double ma = suma/3.0;
		System.out.println("Media aritmetica: " + ma);
		int maxim=x;
		if (maxim<y)
			maxim=y;
		if (maxim<z)
			maxim=z;
		System.out.println("Cel mai mare numar este: " + maxim);
	}
}

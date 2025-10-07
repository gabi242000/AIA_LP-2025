package tema_lab;
import java.io.*;
public class tema_lab_1_ex2 {
	public static void main(String[] args) throws IOException{
		InputStreamReader isr=new InputStreamReader(System.in);
		BufferedReader br=new BufferedReader(isr);
		System.out.println("introdu un sir de caractere: ");
		String t = br.readLine();
		int n = Integer.parseInt(t);
		String a = br.readLine();
		int o = Integer.parseInt(a);
		String z = br.readLine();
		int g = Integer.parseInt(z);
		int suma=n + o + g; 
		System.out.println("suma lor este " + suma);
		double ma= suma/3;
		System.out.println("media lor aritmetica este "+ ma);
		int maxim=n;
		if (maxim<o)
			maxim=o;
		if (maxim<g)
			maxim=g;
		System.out.println("cel mai mare este " + maxim);
	}
}

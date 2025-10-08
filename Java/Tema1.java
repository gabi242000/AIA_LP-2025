package tema1;
import java.io.*;
public class Tema1 {
/*
	//Ex1
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		String s = br.readLine();
		try {
			int n = Integer.parseInt(s);
			if(n%2==0)
				System.out.println("Par");
			else
				System.out.println("Impar");
		}catch (NumberFormatException e) {
			System.out.println("Not integer: " + e);
		}
		br.close();
		isr.close();
	}
	*/
	//Ex2
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		System.out.print("Introdu primul numar:");
		int a = Integer.parseInt(br.readLine());
		System.out.print("Introdu al doilea numar:");
		int b = Integer.parseInt(br.readLine());
		System.out.print("Introdu al treilea numar:");
		int c = Integer.parseInt(br.readLine());
		
		int suma = a + b + c;
		float media= suma/2;
		System.out.println("Suma: " + suma);
		System.out.println("Media: " + media);

		int max = Math.max(a, Math.max(b, c));
		int min = Math.min(a, Math.min(b, c));
		System.out.println("Max:"+max + "\nMin:" + min);
		br.close();
		isr.close();
	}
}

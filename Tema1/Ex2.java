package tema1;
import java.io.*;
public class Ex2 {
	
	public static void main(String[] args) throws IOException {
		int x, y, z;
		String s;
		System.out.println("Introduceti primul numar: ");
		InputStreamReader isrx = new InputStreamReader(System.in);
		BufferedReader brx = new BufferedReader(isrx); 
		s = brx.readLine(); 
		x = Integer.parseInt(s);
		
		System.out.println("Introduceti al doilea numar: ");
		InputStreamReader isry = new InputStreamReader(System.in);
		BufferedReader bry = new BufferedReader(isry); 
		s = bry.readLine(); 
		y = Integer.parseInt(s);
		
		System.out.println("Introduceti al treilea numar: ");
		InputStreamReader isrz = new InputStreamReader(System.in);
		BufferedReader brz = new BufferedReader(isrz); 
		s = brz.readLine(); 
		z = Integer.parseInt(s);
		
		int Suma= x + y + z;
		System.out.println("Suma numerelor este: " + Suma);
		
		float mA =(float) (x + y + z)/3;
		System.out.println("Media artimetica este: " + mA);
		
		int max = x;
		if (y > max ) max = y;
		if (z > max ) max = z;
		
		int min = x;
		if (y < min ) min = y;
		if (z < min ) min = z;
		
		System.out.println("Cel mai mare numar este: " + max);
		System.out.println("Cel mai mic numar este: " + min);
		}
}


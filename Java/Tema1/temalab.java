package tema_lab;
import java.io. *;

public class temalab {
	public static void main(String[] args) throws IOException{
	InputStreamReader isr= new InputStreamReader (System.in);
	BufferedReader br = new BufferedReader(isr);
	System.out.println("Introduceti un numar natural:");
	String s = br.readLine();
	try {
	int n = Integer.parseInt(s);
	if (n!=0) {
		System.out.println("Numar valid: " + n);
		if (n%2==1)
			System.out.println("Numar impar");
		else
			System.out.println("Numar par");
		
	}
	
	} catch (NumberFormatException e) {
		System.out.println("Numar invalid");
	}
	}
}
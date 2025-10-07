package tema1;
import java.io.*;
public class ex2 {
	public static void main(String []args )	throws IOException {
		int x,n=3,i,suma=0,maxim=-9999, minim=9999;
		String s;
		for(i=1;i<=n;i++) {System.out.println("introduceti numarul de pe pozitia " +i +": ");
							InputStreamReader isrx = new InputStreamReader(System.in);
							BufferedReader brx=new BufferedReader(isrx);
							s= brx.readLine();
							x=Integer.parseInt(s);
							suma+=x;
							if(x>=maxim)maxim=x;
							if(x<=minim)minim=x;}
		System.out.println("Suma numerelor este :" +suma);
		float ma;
		ma=(float)suma/n;
		System.out.println("Media naritmetica a numerelor este :" +ma);
		System.out.println("Maximul dintre numere este :" +maxim);
		System.out.println("Minimul dintre numere este :" +minim);
		
	}
}

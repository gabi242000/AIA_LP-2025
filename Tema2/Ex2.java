package tema2;
import java.io.*;
public class Ex2 {
	public static void main(String[] args) throws IOException {
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

  System.out.print("Introduceti un numar natural: ");
  int nr = Integer.parseInt(br.readLine());
  int copie = nr;
  int cifre = 0;
    if (copie == 0) {
  System.out.println("Cea mai mare cifra este 0, iar cea mai mica este 0");
   return;}

  while (copie != 0) {
    cifre++;
    copie/=10;}
  int[] v = new int[cifre];

  for (int i=0; i<cifre; i++) {
    v[i] = nr%10;
     nr/=10;
        }

   int max = v[0], min = v[0];
    for (int i = 1; i < cifre; i++) {
    	if (v[i]>max) max = v[i];
    	if (v[i]<min) min = v[i];}

  System.out.println("Cea mai mare cifra este " + max + ", iar cea mai mica este " + min);
    }
}

package tema2;
import java.io.*;
public class Ex1 {
	public static void main(String[] args) throws IOException {
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  System.out.print("Introduceti dimensiunea vectorului: ");
  int n = Integer.parseInt(br.readLine());
  int[] v = citireVector(br, n);
  System.out.println("Numerele pare sunt: ");
  afisarePare(v);
  int suma = sumaPare(v);
  System.out.println("\nSuma elementelor pare din vector este: " + suma);
   }

  static int[] citireVector(BufferedReader br, int n) throws IOException {
  int[] v = new int[n];
  System.out.println("Introduceti elementele vectorului:");
  for (int i=0; i<n; i++) 
       v[i] = Integer.parseInt(br.readLine()); 
  return v;
    }

   static int sumaPare(int[] v) {
   int suma = 0;
   	for (int x : v) 
      if (x%2 == 0) 
        suma += x;
        
  return suma; }
   static void afisarePare(int[] v) {
     for (int x:v) 
       if (x%2 == 0) 
  System.out.print(x + " ");
            
        }
    }


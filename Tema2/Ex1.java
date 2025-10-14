package tema2;
import java.util.*;
public class Ex1 {
	public static void main (String[] args) {
  var sc =new Scanner(System.in);
  System.out.println("Introduceti dimensiunea vectorului: ");
  int n=sc.nextInt();
  int i;
    	
   int[] v= new int[n+1];
   System.out.println("Introduceti elementele vectorului: ");
   for(i=1;i<=n;i++)v[i]=sc.nextInt();
   int suma=SumaPare(v,n);
   System.out.println("Suma elementelor pare din vector este: "+ suma);
   System.out.println("Numerele pare sunt: ");
   NrPare(v,n,i=1);
    }
  
   static int SumaPare(int []v,int n){int suma=0;
   for(int i=1;i<=n;i++)if(v[i]%2==0)suma+=v[i];
   return suma;}
   
   static void  NrPare(int[]v,int n,int i) {
	   if(i==n) return;
	   else if(v[i]%2==0)System.out.print(v[i] + " ");
	   NrPare(v,n,i+1);}
    
}

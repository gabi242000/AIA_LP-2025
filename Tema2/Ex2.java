package tema2;
import java.util.Scanner;
public class Ex2 {
	public static void main (String[] args) {
  var sc =new Scanner(System.in);
  System.out.print("Introduceti numarul: ");
  int nr=sc.nextInt();
  int d=0;
  int cop=nr;
  while(cop!=0) {cop=cop/10;
			d=d+1;}
  int[] v=new int[d+1];
  int i=1;
	while(nr!=0) {v[i]=nr%10;
		nr=nr/10;
		i=i+1;}
  int max1=v[1],min1=v[1];
	for(i=2;i<=d;i++)if(v[i]>max1)max1=v[i];
		else if(v[i]<min1)min1=v[i]; 
  System.out.println("Cea mai mare cifra este " + max1 + ",iar cea mai mica este "+ min1);
	}
}

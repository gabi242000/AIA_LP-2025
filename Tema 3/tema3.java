package tema3;
import java.util.*;
public class tema3 {
	public static void main(String[] args) {
        var sc = new Scanner(System.in);
        System.out.print("Introduceti dimensiunea matricei: ");
        int n = sc.nextInt();
        int[][] a = new int[n+1][n+1];
        int i,j;
        int magic=0;

        System.out.println("Introduceti elementele matricei: ");
        for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)a[i][j]=sc.nextInt();
 
 magic=magica(a,n);
 
 if(magic==0)magic=submagic(a,n);
  if(magic==0)System.out.println("Matricea nu este magica");
 		else if(magic==1)System.out.println("Matrice este magica");
 				else if(magic==2)System.out.println("Matricea etse partial magica");
 
 
        
 }
 static int magica(int[][] a,int n) {int magic=0;
 
 //verificam daca este magica toata
 //calculam suma dupa care verificam in toata matricea
 int sum=0;
 for(int j=1;j<=n;j++)sum+=a[1][j];
 int ok1=0,ok2=0,ok3=0,ok4=0;
 
 for(int i=1;i<=n;i++) {int suma1=0;
	 for(int j=1;j<=n;j++)suma1+=a[i][j];
	 if(suma1!=sum)break;
	 else ok1=1;}
 
 for(int j=1;j<=n;j++) {int suma2=0;
	 for(int i=1;i<=n;i++)suma2+=a[i][j];
	 if(suma2!=sum)break;
	 else ok2=1;}
 
 int suma3=0;
 for(int i=1;i<=n;i++)suma3+=a[i][i];
 if(suma3==sum)ok3=1;
 
 int suma4=0;
 for(int i=1;i<=n;i++)suma4+=a[i][n-i+1];
 if(suma4==sum)ok4=1;
 
 if(ok1==1 && ok2==1 && ok3==1 && ok4==1)magic=1;
 
 return magic;}
 
 static int submagic(int[][] a,int n) {int submagic=0;
 if(n%2==0)n=n-1;
while(n>=3) {	 
 int sum=0;
 for(int j=1;j<=n;j++)sum+=a[1][j];
 int ok1=0,ok2=0,ok3=0,ok4=0;
 
 for(int i=1;i<=n;i++) {int suma1=0;
	 for(int j=1;j<=n;j++)suma1+=a[i][j];
	 if(suma1!=sum)break;
	 else ok1=1;}
 
 for(int j=1;j<=n;j++) {int suma2=0;
	 for(int i=1;i<=n;i++)suma2+=a[i][j];
	 if(suma2!=sum)break;
	 else ok2=1;}
 
 int suma3=0;
 for(int i=1;i<=n;i++)suma3+=a[i][i];
 if(suma3==sum)ok3=1;
 
 int suma4=0;
 for(int i=1;i<=n;i++)suma4+=a[i][n-i+1];
 if(suma4==sum)ok4=1;
 
 if(ok1==1 && ok2==1 && ok3==1 && ok4==1) {submagic=2;break;}
 else {for(int i=1;i<=n;i++) {for(int j=1;j<n;j++)a[i][j]=a[i][j+1];}
       for(int j=1;j<=n;j++) {for(int i=1;i<n;i++)a[i][j]=a[i+1][j];}
       	 n=n-1;}
 
}
 return submagic;}
}


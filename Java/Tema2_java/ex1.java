import java.io.*;

public class ex1
{
    public static void main(String[] args) throws IOException{
        int v[]=citesteVector();
        afiseaza(v);
    }
    
    public static int citeste() throws IOException{
        InputStreamReader isr=new InputStreamReader(System.in);
        BufferedReader br=new BufferedReader(isr);
        String s=br.readLine();
        return Integer.parseInt(s);
    }
    
    public static int[] citesteVector() throws IOException{
        System.out.println("Introduceti dimensiunea vectorului:");
        int n=citeste();
        System.out.println("Introduceti elementele vectorului:");
        int v[]=new int[n];
        for(int i=0;i<v.length;i++)
        {
            v[i]=citeste();
        }
        return v;
    }
    
    public static void afiseaza(int [] v)
    {
        int suma=0;
        System.out.print("Elementele pare din vector sunt:  ");
        for(int i=0;i<v.length;i++)
        {
            if(v[i]%2==0)
            {
                System.out.print(v[i]+" ");
                suma+=v[i];
            }
        }
        System.out.println();
        System.out.println("Suma elementelor pare este: "+suma);
    }
    
}
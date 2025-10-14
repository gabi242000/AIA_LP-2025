import java.util.Scanner;

public class ex2{
    public static void main(String[] args)
    {
        Scanner scanner=new Scanner(System.in);
        
        System.out.print("Introduceti un numar natural:");
        int n=scanner.nextInt();
        
        if(n<0)
        {
            System.out.println("Numarul introdus nu este natural!");
            return;
        }
        
        int minn=9;
        int maxx=0;
        
        int aux=n;
        while(aux>0)
        {
            int c=aux%10;
            aux=aux/10;
            
            if(c<minn) minn=c;
            if(c>maxx) maxx=c;
        }
        System.out.println("Cel mai mic digit este: "+minn);
        System.out.println("Cel mai mare digit este: "+maxx);
    
}
}
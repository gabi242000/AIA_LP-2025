package lab1;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class lab1_tema1 {
	
	public static void main(String[] args) throws IOException
	{
		InputStreamReader isr = new InputStreamReader(System.in);
		
		BufferedReader br = new BufferedReader(isr);
		System.out.println("INtrouduceti un nr natural: ");
		
		String s = br.readLine();
		
		try 
		{
            int n = Integer.parseInt(s); 
            
            if(n >= 0) 
            {
                System.out.println(n);
                if(n % 2 == 0) 
                {
                    System.out.println("Numarul " + n + " este par");
                } 
                else 
                {
                    System.out.println("Numarul " + n + " este impar");
                }
            }  
        } 
		catch (NumberFormatException e) 
		{
            System.out.println("Valoarea introdusa nu este un numar natural valid!");
        }
    }
}
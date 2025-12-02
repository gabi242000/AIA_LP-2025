import java.util.Scanner;

public class tema2 {
    public static Scanner sc = new Scanner(System.in);
    public static void ex1()
    {
        int sum_par = 0 , dim = sc.nextInt();
        int[] v = new int[dim];
        for(int i = 0 ; i < dim ; i++)
            v[i] = sc.nextInt();

        for(int i = 0 ; i < dim ; i++)
        {
            if(v[i] % 2 == 0)
            {
                sum_par+=v[i];
                System.out.println(v[i] + " ");
            }
        }
        System.out.println(sum_par);
    }

    public static void ex2()
    {
        int max=-1 , min=10 , nr = sc.nextInt();
        while(nr !=0)
        {
            if(nr%10 > max)
                max = nr%10;
            if(nr%10 < min)
                min = nr%10;
            
            nr/=10;
        }
        System.out.println("Cif max este " + max + " si cif min este " + min);
    }

    public static void main(String[] args){
        while(true)
        {
            System.out.println("Alege exercitiul (1 sau 2 , 0 pentru iesire): ");
            int x = sc.nextInt();

            switch (x) {
                case 1:
                    ex1();
                    break;
                case 2:
                    ex2();
                    break;
                case 0:
                    System.out.println("Iesire...");
                    sc.close();
                    return;
                default:
                    System.out.println("Optiune invalida. Te rog alege 1 sau 2.");
                    continue;
            }
        }
    }   
}


import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;


public class tema3{
    public static void main(String[] args)
    {
        System.out.println();
        var fis = new File("tema3.txt");
        try(var sc = new Scanner(fis)){
            while(sc.hasNextInt())
            {
                ///problema asta are sens decat daca n de dimensiune e impar
                int dim = sc.nextInt();
                if (dim % 2 == 0){
                    System.out.println("Marimea matricii nu poate sa se imparta la nr 2");
                    return;
                }
                int[][] mat = new int[dim][dim];
                for(int i = 0 ; i < dim ; i++)
                    for(int j = 0 ; j < dim ; j++)
                        mat[i][j] = sc.nextInt();

                dim-=2;
                int sum = 0 , sum2 = 0 ;
                for(int i = 1; i < dim ; i++)
                    sum+=mat[1][i];

                for(int i = 2 ; i < dim; i++){
                    for(int j = 1 ; j < dim; i++)
                        sum2+=mat[i][j];
                    
                    if(sum != sum2)
                    {
                        System.out.println("Matricea nemagica");
                        return;
                    }
                    sum2 = 0;
                }

                for(int i = 1; i < dim ; i++){
                    for(int j = 1 ; j < dim ; j++)
                        sum2+= mat[j][i];
                    
                    if(sum != sum2)
                    {
                        System.out.println("Matricea nemagica");
                        return;
                    }
                }
                int sum3 = 0;
                for(int i = 1 , j = 1; i < dim; i++ , j++)
                {
                    sum2+=mat[i][j];
                    sum3+=mat[dim-i][dim-j];
                }
                if(sum2 != sum3)
                {
                    System.out.println("Matricea nemagica");
                    return;
                }
                System.out.println("Matrice magica partial");
                return;
            }
        }
        catch(FileNotFoundException e)
        {
            System.out.println("Fisierul nu exista");
            e.printStackTrace();
        }
    }
}
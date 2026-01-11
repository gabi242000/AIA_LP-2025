import java.sql.*;
import java.util.Scanner;


public class ServiciuAuth {
    
    private final Scanner scanner = new Scanner(System.in);

    private String nume;
    private String prenume;
    private String numeutilizator;
    private String parola;
    private String email;
    private String tara;
    private String oras;
    private String telefon;
    private double balanta = 0;


   
    
    String url = "jdbc:sqlite:realestate.db";
    public void Inregistrare(){
        try(Connection conn = DriverManager.getConnection(url)){

        System.out.println("=====================Inregistrare===================");
        System.out.println("Nume:");
        nume = scanner.nextLine();
        System.out.println("Prenume:");
        prenume = scanner.nextLine();
        System.out.print("Nume utilizator: ");
        numeutilizator =scanner.nextLine();
        System.out.print("Parola: ");
        parola= scanner.nextLine();
        System.out.print("Email: ");
        email = scanner.nextLine();  
        System.out.print("Tara:");
        tara = scanner.nextLine();
        System.out.print("Oras:");
        oras = scanner.nextLine();
        System.out.print("Numar de telefon:");
        telefon = scanner.nextLine();




        String sql = "INSERT INTO Utilizatori(Nume, Prenume,NumeUtilizator,Parola, Email, Tara, Oras, Telefon,Balanta) VALUES(?,?,?,?,?,?,?,?,?)";


        PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1,nume);
            pstmt.setString(2,prenume);
            pstmt.setString(3, numeutilizator);
            pstmt.setString(4,parola);
            pstmt.setString(5,email);
            pstmt.setString(6,tara);
            pstmt.setString(7,oras);
            pstmt.setString(8,telefon);
            pstmt.setDouble(9,balanta);
            

            pstmt.executeUpdate();
            System.out.println(" Inregistrare reusita!");
        
            conn.close();


        }catch (SQLException e) {
            System.out.println(" Eroare la conectare: " + e.getMessage());
        }

        
    }


    public void Autentificare(){
        System.out.println("=====================Autentificare===================");
        System.out.print("Nume utilizator: ");
        numeutilizator =scanner.nextLine();
        System.out.print("Parola: ");
        parola= scanner.nextLine();

        String sql = "SELECT * FROM Utilizatori WHERE NumeUtilizator = ? AND Parola = ?";

       try(Connection conn = DriverManager.getConnection(url);
            PreparedStatement pstmt = conn.prepareStatement(sql)){

                pstmt.setString(1, numeutilizator);
                pstmt.setString(2, parola);

                ResultSet rs = pstmt.executeQuery();
                if(rs.next()){
                    System.out.println("Autentificare reusita!");
                    Utilizator utilizator = new Utilizator(rs.getString("Nume"),
                    rs.getString("Prenume"),
                    rs.getString("NumeUtilizator"),
                    rs.getString("Email"),
                    rs.getString("Parola"),
                    rs.getString("Tara"),
                    rs.getString("Oras"),
                    rs.getString("Telefon"),
                    rs.getDouble("Balanta"));
                    
                    Autentificat au = new Autentificat(utilizator);
                    au.meniu();

                
                    
                }else{
                    System.out.println(" Nume utilizator sau parola incorecta.");
                }


                conn.close();



            }catch (SQLException e) {
            System.out.println(" Eroare la conectare: " + e.getMessage());
            }


        

        
    }

}

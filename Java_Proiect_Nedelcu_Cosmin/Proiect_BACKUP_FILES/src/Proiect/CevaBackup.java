package Proiect;
import java.io.*;

public class CevaBackup {
	public static void main(String[] args) throws IOException {
	    
	    File sursa = new File("ceva.txt");
	    File destinatie = new File("ceva_copie.txt");

	    if (sursa.exists()) {
	        System.out.println("Am găsit fișierul sursă: " + sursa.getAbsolutePath());
	        
	        copiazaFisier(sursa, destinatie);
	        
	        System.out.println("GATA! Am copiat totul din 'ceva.txt' în 'ceva_copie.txt'.");
	    } else {
	        System.err.println("EROARE: Nu găsesc 'ceva.txt'.");
	        System.err.println("Sfat: Asigură-te că fișierul nu e în 'src', ci direct în folderul proiectului!");
	    }
	}
	
	public static void copiazaFisier(File sursa, File destinatie) throws IOException {
	    try (FileInputStream intrare = new FileInputStream(sursa);
	         FileOutputStream iesire = new FileOutputStream(destinatie)) {

	        byte[] buffer = new byte[1024];
	        int lungimeCitita;

	        while ((lungimeCitita = intrare.read(buffer)) > 0) {
	            iesire.write(buffer, 0, lungimeCitita);
	        }
	    }
	}
}

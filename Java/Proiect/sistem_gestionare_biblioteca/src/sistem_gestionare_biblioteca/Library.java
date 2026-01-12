package sistem_gestionare_biblioteca;

import java.io.*;
import java.util.*;


class IncorrectNrofDetailsException extends Exception {
	public IncorrectNrofDetailsException(String msg) {
		super(msg);
	}
}

class LibraryFullException extends Exception {
	public LibraryFullException(String msg) {
		super(msg);
	}
}
		

class Book {

	private String title;
	private String author;
	private String category;
	private String format;
	private String status;
	private int nr_pages;
	private int publication_year;
	private int rating;
	
	public Book() {
		this.title = "";
		this.author = "";
		this.category = "";
		this.format = "";
		this.status = "";
		this.nr_pages = 0;
		this.publication_year = 0;
		this.rating = -1;
	}

	
	public String getTitle() {
		return title;
	}

	public String getAuthor() {
		return author;
	}

	public String getCategory() {
		return category;
	}

	public String getFormat() {
		return format;
	}

	public String getStatus() {
		return status;
	}

	public int getNr_pages() {
		return nr_pages;
	}

	public int getPublication_year() {
		return publication_year;
	}

	public int getRating() {
		return rating;
	}
	
	

	public void setTitle(String title) {
		this.title = title;
	}

	public void setAuthor(String author) {
		this.author = author;
	}

	public void setCategory(String category) {
		this.category = category;
	}

	public void setFormat(String format) {
		this.format = format;
	}

	public void setStatus(String status) {
		this.status = status;
	}

	public void setNr_pages(int nr_pages) {
		this.nr_pages = nr_pages;
	}

	public void setPublication_year(int publication_year) {
		this.publication_year = publication_year;
	}

	public void setRating(int rating) {
		this.rating = rating;
	}
	
	

	public String toFileFormat() {
		if(rating  == -1) {
			return title + ";" +
			           author + ";" +
					   category + ";" +
			           format + ";" +
					   status + ";" + 
			           nr_pages + ";" + 
					   publication_year;
		} else {
			return title + ";" +
			           author + ";" +
					   category + ";" +
			           format + ";" +
					   status + ";" + 
			           nr_pages + ";" + 
					   publication_year + ";" +
			           rating;
		}    
	}
}


public class Library {
	public static final int MAX_BOOKS = 10000;
	
	private Book[] library = new Book[MAX_BOOKS];
	private int nr_books = 0;
	
	File file = new File("carti.txt");
	
	Scanner sc = new Scanner(System.in);
	
	private String decor = "⁛⁙";
	
	public void load_books() throws IncorrectNrofDetailsException, IOException{
		nr_books = 0;
		
		if(!file.exists()) {
			System.out.println("fisierul carti.txt nu exista!!");
			return;
		}
		
		
		try(BufferedReader br = new BufferedReader(new FileReader(file))) {
			String line;
			while((line = br.readLine()) != null) {
				String[] details = line.split(";");
				
				if(details.length >= 7) {
					Book b = new Book();
					
					b.setTitle(details[0].trim());
					b.setAuthor(details[1].trim());
					b.setCategory(details[2].trim());
					b.setFormat(details[3].trim());
					b.setStatus(details[4].trim());
					b.setNr_pages(Integer.parseInt(details[5].trim()));
					b.setPublication_year(Integer.parseInt(details[6].trim()));
					
					if(b.getStatus().equalsIgnoreCase("citita") && details.length >= 8) {
						b.setRating(Integer.parseInt(details[7].trim()));
						
					}
					library[nr_books++] = b;
				} else {
					throw new IncorrectNrofDetailsException("Numarul de detalii este incorect!");
				}
				
			}
	
		}
	}
	
	public void save_books() {
		if(!file.exists()) {
			System.out.println("fisierul carti.txt nu exista!!");
			return;
		}
		
		try(BufferedWriter bw = new BufferedWriter(new FileWriter(file))) {
			for(int i = 0; i < nr_books; i++) {
				bw.write(library[i].toFileFormat());
				bw.newLine();
			}
			System.out.println("Biblioteca actualizata!");
		}catch(IOException e) {
			System.out.println("Eroare la salvarea cartilor!");
		}
	}
	
	public void add_books() throws LibraryFullException {
		if(nr_books >= MAX_BOOKS) {
			throw new LibraryFullException("Nu mai poti adauga carti. Capacitatea maxima atinsa: " + MAX_BOOKS);
		}
		
		Book new_book = new Book();
		
		System.out.println(decor.repeat(30));
		System.out.println(" ".repeat(20) + "INTRODU:" + " ".repeat(20));
		
		System.out.print("⁘Titlu: ");
		new_book.setTitle(sc.nextLine());
		
		System.out.print("⁘Autor: ");
		new_book.setAuthor(sc.nextLine());
		
		System.out.print("⁘Categorie: ");
		new_book.setCategory(sc.nextLine());
		
		String format;
		while(true) {
			System.out.print("⁘Format (fizic / ebook / audiobook): ");
			format = sc.nextLine();
			
			if(format.equalsIgnoreCase("fizic") || format.equalsIgnoreCase("ebook") || format.equalsIgnoreCase("audiobook"))
				break;
			System.out.println("Optiune invalida! Alege din cele trei variante.");
			System.out.println();
		}
		new_book.setFormat(format);
		
		String status;
		while(true) {
			System.out.print("⁘Status (citita / wishlist): ");
			status = sc.nextLine();
			
			if(status.equalsIgnoreCase("citita") || status.equalsIgnoreCase("wishlist"))
				break;
			System.out.println("Optiune invalida! Alege din cele doua variante.");
			System.out.println();
		}
		new_book.setStatus(status);
		
		int nr_pages;
		while(true) {
			System.out.print("⁘Numar de pagini: ");
			if(sc.hasNextInt()) {
				nr_pages = sc.nextInt();
				sc.nextLine();
			
			if(nr_pages > 0)
				break;
			}
			System.out.println("Numar invalid! Trebuie sa fie pozitiv.");
			System.out.println();
		}
		new_book.setNr_pages(nr_pages);

		int publication_year;
		while(true) {
			System.out.print("⁘Anul publicarii: ");
			if(sc.hasNextInt()) {
				publication_year = sc.nextInt();
				sc.nextLine();
			
			if(publication_year >= 1800 && publication_year <= 2026)
				break;
			}
			System.out.println("An inalid! Trebuie sa fie intre 1800 si 2026.");
			System.out.println();
		}
		new_book.setPublication_year(publication_year);
		
		int rating;
		if(new_book.getStatus().equalsIgnoreCase("citita")) {
			String yes = "da";
			System.out.print("Doresti sa oferi un rating? (da / nu): ");
			yes = sc.nextLine();
			if (yes.equalsIgnoreCase("da")) {
					while(true) {
						System.out.print("⁘Rating: ");
						if(sc.hasNextInt()) {
							rating = sc.nextInt();
							sc.nextLine();
							
							if(rating >= 0 && rating <= 10) 
								break;
						}
						System.out.println("Numar invalid! Alege un numar intre 0 si 10.");
						System.out.println();
					}
					new_book.setRating(rating);
				}
				
		}
		
		library[nr_books++] = new_book;
		System.out.println("Carte adaugata cu succes!");
		System.out.println(decor.repeat(30));
		
	}
	
	public void show_details_book(String title) {
		boolean book_found = false;
		
		for(int i = 0; i < nr_books; i++) {
			if(library[i].getTitle().equalsIgnoreCase(title)) {
				book_found = true;
				System.out.println(decor.repeat(15) + " Detalii carte " + decor.repeat(15));
				System.out.println();
				System.out.println("⁘TITLU:"  + " ".repeat(14) + library[i].getTitle());
				System.out.println("⁘AUTOR: " + " ".repeat(13) + library[i].getAuthor());
				System.out.println("⁘CATEGORIE: " + " ".repeat(9) + library[i].getCategory());
				System.out.println("⁘FORMAT: " + " ".repeat(12) + library[i].getFormat());
				System.out.println("⁘STATUS: " + " ".repeat(12) + library[i].getStatus());
				System.out.println("⁘NUMAR DE PAGINI: " + " ".repeat(3) + library[i].getNr_pages());
				System.out.println("⁘AN PUBLICATIE: " + " ".repeat(5) + library[i].getPublication_year());
				
				if(library[i].getRating() != -1)
					System.out.println("⁘RATING: " + " ".repeat(12) + library[i].getRating());
				
				System.out.println(decor.repeat(30));
			}	
		}
		
		if(!book_found) 
			System.out.println("Ne pare rau! Nu am gasit acest titlu.");
	}
	
	
	public void show_sorted_books(int filter) {
		int [] index = new int[MAX_BOOKS];
		int aux;
		
		for(int i = 0; i < nr_books; i++) {
			index[i] = i;
		}
		
		switch(filter) {
		case 1:
			System.out.println(decor.repeat(20) + " Carti sortate alfabetic dupa autor " + decor.repeat(20));
			
			for(int i = 0; i < nr_books - 1; i++) {
				for(int j =  i + 1; j < nr_books; j++) {
					if(library[index[i]].getAuthor().compareToIgnoreCase(library[index[j]].getAuthor()) > 0) {
						aux = index[i];
						index[i] = index[j];
						index[j] = aux;
					}
				}
			}
			
			for(int i = 0; i < nr_books; i++) 
				System.out.println(library[index[i]].getAuthor() + " ‖ " + "\"" + library[index[i]].getTitle() + "\"");
	
			System.out.println(decor.repeat(30));
			break;
			
		case 2:
			System.out.println(decor.repeat(20) + " Carti sortate alfabetic dupa titlu " + decor.repeat(20));
			
			for(int i = 0; i < nr_books - 1; i++) {
				for(int j = i + 1; j < nr_books; j++) {
					if(library[index[i]].getTitle().compareToIgnoreCase(library[index[j]].getTitle()) > 0) {
						aux = index[i];
						index[i] = index[j];
						index[j] = aux;
					}
				}
			}
			
			for(int i = 0; i < nr_books; i++) 
				System.out.println("\"" + library[index[i]].getTitle() + "\"" + " ‖ " + library[index[i]].getAuthor());
	
			System.out.println(decor.repeat(30));
			break;
			
		case 3:
			System.out.println(decor.repeat(20) + " Carti sortate dupa format " + decor.repeat(20));
			
			System.out.println(decor.repeat(4) + " Format fizic " + decor.repeat(4));
			for(int i = 0; i < nr_books; i++) {
				if(library[i].getFormat().equalsIgnoreCase("fizic")) 
					System.out.println("\"" + library[index[i]].getTitle() + "\"" + " ‖ " + library[index[i]].getAuthor());	
			}
			
			System.out.println(decor.repeat(25));
			System.out.println(decor.repeat(4) + " Format ebook " + decor.repeat(4));
			for(int i = 0; i < nr_books; i++) {
				if(library[i].getFormat().equalsIgnoreCase("ebook")) 
					System.out.println("\"" + library[index[i]].getTitle() + "\"" + " ‖ " + library[index[i]].getAuthor());	
			}
			
			System.out.println(decor.repeat(25));
			System.out.println(decor.repeat(4) + " Format audiobook " + decor.repeat(4));
			for(int i = 0; i < nr_books; i++) {
				if(library[i].getFormat().equalsIgnoreCase("audiobook")) 
					System.out.println("\"" + library[index[i]].getTitle() + "\"" + " ‖ " + library[index[i]].getAuthor());	
			}
			
			System.out.println(decor.repeat(30));
			break;
			
		case 4:
			System.out.println(decor.repeat(20) + " Carti sortate crescator dupa numarul de pagini " + decor.repeat(20));
			for(int i = 0; i < nr_books - 1; i++) {
				for(int j = i + 1; j < nr_books; j++) {
					if(library[index[i]].getNr_pages() > library[index[j]].getNr_pages()) {
						aux = index[i];
						index[i] = index[j];
						index[j] = aux;
					}
				}
			}
			
			for(int i = 0; i < nr_books; i++) 
				System.out.println(library[index[i]].getNr_pages() + " pagini " + " ‖ " + "\"" + library[index[i]].getTitle() + "\"" + " ‖ " + library[index[i]].getAuthor());
			
			System.out.println(decor.repeat(30));
			break;
			
		case 5:
			System.out.println(decor.repeat(20) + " Carti sortate crescator dupa rating " + decor.repeat(20));
			for(int i = 0; i < nr_books - 1; i++) {
				for(int j = i + 1; j < nr_books; j++) {
					if(library[index[i]].getRating() > library[index[j]].getRating()) {
						aux = index[i];
						index[i] = index[j];
						index[j] = aux;
					}
				}
			}
			
			boolean existsRating = false;
			for(int i = 0; i < nr_books; i++) 
				if(library[index[i]].getRating() != -1) {
					   System.out.println(library[index[i]].getRating() + " / 10 ☆ " + " ‖ " + "\"" + library[index[i]].getTitle() + "\"" + " ‖ " + library[index[i]].getAuthor());
					   existsRating = true;
				}
			
			if(!existsRating) 
				System.out.println("Momentan nu exista rating pentru nicio carte.");

			System.out.println(decor.repeat(30));
			break;
			
		case 6:
			System.out.println(decor.repeat(20) + " Wishlist " + decor.repeat(20));
			
			for(int i = 0; i < nr_books; i++) {
				if(library[i].getStatus().equalsIgnoreCase("wishlist")) 
					System.out.println("\"" + library[index[i]].getTitle() + "\"" + " ‖ " + library[index[i]].getAuthor());	
			}
			
			System.out.println(decor.repeat(30));
			break;
			
		case 7:
			System.out.println(decor.repeat(20) + " Cartile in ordinea adaugarii " + decor.repeat(20));
			
			for(int i = 0; i < nr_books; i++) {
				System.out.println("\"" + library[index[i]].getTitle() + "\"" + " ‖ " + library[index[i]].getAuthor());	
			}
			
			System.out.println(decor.repeat(30));
			break;
		}
	}
	
	public void edit_book(String title) {
		boolean found = false;
		int option;
		
		for(int i = 0; i < nr_books; i++) {
			if(library[i].getTitle().equalsIgnoreCase(title)) {
				found = true;
				
				while(true) {
					System.out.println(decor.repeat(30));
					System.out.println("""
							Ce doresti sa modifici?
							   1. Titlu
							   2. Autor
							   3. Categorie
							   4. Format
							   5. Status
							   6. Numar pagini
							   7. Anul publicarii
							   8. Rating
							""");
					if(sc.hasNextInt()) {
						option = sc.nextInt();
						sc.nextLine();
					
					if(option >= 1 && option <= 8)
						break;
					}
					System.out.println("Varianta invalida. Alege un numar de la 1 la 8.");
					System.out.println();
				}
				
				switch(option) {
				case 1:
					System.out.println(decor.repeat(1) + "Titlu nou: ");
					library[i].setTitle(sc.nextLine());
					break;
					
				case 2:
					System.out.println(decor.repeat(1) + "Autor nou: ");
					library[i].setAuthor(sc.nextLine());
					break;
					
				case 3:
					System.out.println(decor.repeat(1) + "Categorie noua: ");
					library[i].setCategory(sc.nextLine());
					break;
					
				case 4:
					String format;
					while(true) {
						System.out.print(decor.repeat(1) + "Format nou (fizic / ebook / audiobook): ");
						format = sc.nextLine();
						
						if(format.equalsIgnoreCase("fizic") || format.equalsIgnoreCase("ebook") || format.equalsIgnoreCase("audiobook"))
							break;
						System.out.println("Optiune invalida! Alege din cele trei variante.");
						System.out.println();
					}
					library[i].setFormat(format);
					break;
					
				case 5:
					String status;
					while(true) {
						System.out.print(decor.repeat(1) + "Status nou (citita / wishlist): ");
						status = sc.nextLine();
						
						if(status.equalsIgnoreCase("citita") || status.equalsIgnoreCase("wishlist"))
							break;
						System.out.println("Optiune invalida! Alege din cele doua variante.");
						System.out.println();
					}
					library[i].setStatus(status);
					break;
					
				case 6:
					int nr_pages;
					while(true) {
						System.out.print(decor.repeat(1) + "Numar nou de pagini: ");
						if(sc.hasNextInt()) {
							nr_pages = sc.nextInt();
							sc.nextLine();
						
						if(nr_pages > 0)
							break;
						}
						System.out.println("Numar invalid! Trebuie sa fie pozitiv.");
						System.out.println();
					}
					library[i].setNr_pages(nr_pages);
					break;
					
				case 7:
					int publication_year;
					while(true) {
						System.out.print(decor.repeat(1) + "Anul nou al publicarii: ");
						if(sc.hasNextInt()) {
							publication_year = sc.nextInt();
							sc.nextLine();
						
						if(publication_year >= 1800 && publication_year <= 2026)
							break;
						}
						System.out.println("An inalid! Trebuie sa fie intre 1800 si 2026.");
						System.out.println();
					}
					library[i].setPublication_year(publication_year);
					break;
					
				case 8:
					int rating;
					if(library[i].getStatus().equalsIgnoreCase("citita")) {
						while(true) {
							System.out.print(decor.repeat(1) + "Rating nou: ");
							if(sc.hasNextInt()) {
								rating = sc.nextInt();
								sc.nextLine();
								
								if(rating >= 0 && rating <= 10) 
									break;
							}
							System.out.println("Numar invalid! Alege un numar intre 0 si 10.");
							System.out.println();
						}
						library[i].setRating(rating);
						break;
					}	
				}
				break;
			}
				
		}
		
		if(!found) {
			System.out.println("Cartea nu a fost gasita!");
			return;
		}
		
		save_books();
		System.out.println(decor.repeat(30));
	}
	
	public void delete_books() {
		int delete;
		System.out.println(decor.repeat(20) + " Carti sortate alfabetic dupa autor " + decor.repeat(20));
		
		for(int i = 0; i < nr_books; i++) {
			System.out.println((i + 1) + ". " + "\"" + library[i].getTitle() + "\"");
		}
		while(true) {
			System.out.print("Alege numarul cartii pe care doresti sa o stergi: ");
			if(sc.hasNextInt()) {
				delete = sc.nextInt();
				sc.nextLine();
			
			if(delete >= 1 && delete <= nr_books)
				break;
			}
			System.out.println("Varianta invalida. Incearca din nou!.");
			System.out.println();
		}
		
		for(int i = delete - 1; i < nr_books; i++)
			library[i] = library[i + 1];
		
		nr_books--;
		System.out.println("Cartea a fost stearsa cu succes!");
		System.out.println(decor.repeat(30));
		save_books();
	}
	
	
	public static void main(String[] args) {
		Library lib = new Library();
		
		try {
			lib.load_books();
			
			System.out.println("Bun venit la The Book Nook, biblioteca ta digitala!");
			System.out.println(lib.decor.repeat(30));
			
			boolean run = true;
			int option_menu;
			String y_n;
			
			while(run) {
				System.out.println(lib.decor.repeat(30));
				System.out.println("""
						Cu ce te pot ajuta azi?
						   1. Adauga o carte
						   2. Sorteaza cartile
						   3. Cauta o carte
						   4. Editeaza detaliile unei carti
						   5. Sterge o carte
						   6. Iesire
						""");
				
				while(true) {
					System.out.print("Raspuns:  ");
					if(lib.sc.hasNextInt()) {
						option_menu = lib.sc.nextInt();
						lib.sc.nextLine();
					
					if(option_menu >= 1 && option_menu <= 6)
						break;
					}
					System.out.println("Varianta invalida. Incearca din nou!.");
					System.out.println();
				}
				
				switch(option_menu) {
				case 1:
					String op1 = "da";
					while(op1.equalsIgnoreCase("da")) {
						try {
							lib.add_books();
						}catch (LibraryFullException e) {
							System.out.println(e.getMessage());
							break;
						}
						System.out.print("Doresti sa mai adaugi o carte? (da / nu) : ");
						op1 = lib.sc.nextLine();
					}	
					lib.save_books();
					break;
					
				case 2:
					System.out.println(lib.decor.repeat(30));
					System.out.println("""
							Alege cum doresti sa sortezi cartile:
							  1. Alfabetic dupa autor
							  2. Alfabetic dupa titlu
							  3. Format
							  4. Crescator dupa numarul de pagini
							  5. Crescator dupa rating
							  6. Wishlist
							  7. Ordinea adaugarii
							""");
					
					int op2;
					while(true) {
						System.out.print("Raspuns:  ");
						if(lib.sc.hasNextInt()) {
							op2 = lib.sc.nextInt();
							lib.sc.nextLine();
						
						if(op2 >= 1 && op2 <= 7)
							break;
						}
						System.out.println("Varianta invalida. Alege un numar de la 1 la 7.");
						System.out.println();
					}	
					lib.show_sorted_books(op2);
					break;
					
				case 3:
					String op3 = "da";
					while(op3.equalsIgnoreCase("da")) {
						System.out.print("Introdu titlul cartii cautate: ");
						String title_found = lib.sc.nextLine();
						lib.show_details_book(title_found);
						
						System.out.print("Mai cauti alta carte? (da / nu) : ");
						op3 = lib.sc.nextLine();
					}			
					break;
					
				case 4:
					String op4 = "da";
					while(op4.equalsIgnoreCase("da")) {
						System.out.print("Introdu titlul cartii pe care vrei sa o editezi: ");
						String title_edit = lib.sc.nextLine();
						lib.edit_book(title_edit);
						
						System.out.print("Doresti sa mai editezi si alta carte? (da / nu) : ");
						op4 = lib.sc.nextLine();
					}
					break;
						
				case 5:
					String op5 = "da";
					while(op5.equalsIgnoreCase("da")) {
						lib.delete_books();
						
						System.out.print("Doresti sa mai stergi o carte? (da / nu) : ");
						op5 = lib.sc.nextLine();
					}
					break;
					
				case 6:
					run = false;
					System.out.println("Spor la citit! Ne vedem data viitoare!!");
					break;
				}
				
				if(run) {
					System.out.println(lib.decor.repeat(30));
					System.out.println("Doresti sa alegi altceva din meniul principal? (da / nu) : ");
					y_n = lib.sc.nextLine();
					if(!y_n.equalsIgnoreCase("da")) {
						run = false;
						System.out.println("Spor la citit! Ne vedem data viitoare!!");
					}
				}
			}
		}catch(IncorrectNrofDetailsException e) {
			System.out.println(e.getMessage());
		}catch(IOException e) {
			System.out.println("Eroare la citirea fisierului!");
		}catch(Exception e) {
			System.out.println("A aparut o eroare neasteptata: " +  e.getMessage());
		}
		
		
	}
	
}




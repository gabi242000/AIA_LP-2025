import java.util.*;
import java.util.stream.Collectors;

public class file{
  private static final List<Produs> inventory = new ArrayList<>();
  private static final Scanner scanner = new Scanner(System.in);

  public static void main(String[] args){
    initializareDate();
    boolean running = true;

    while (running){
      afisareAntet();
      System.out.println(" [1] Vizualizare Inventar Complet");
      System.out.println(" [2] Adaugare Produs Nou");
      System.out.println(" [3] Actualizare Nivel Stoc");
      System.out.println(" [4] Cautare si Filtrare");
      System.out.println(" [5] Panou Statistici");
      System.out.println(" [6] Iesire Sistem");
      System.out.print("\nSelectati o optiune: ");

      String input = scanner.nextLine();
      switch (input) {
        case "1" -> afisareInventar(inventory);
        case "2" -> adaugareProdus();
        case "3" -> actualizareStoc();
        case "4" -> meniuCautare();
        case "5" -> afisareStatistici();
        case "6" -> {
          System.out.println("Inchidere sistem... La revedere.");
          running = false;
        }
        default -> System.out.println("Optiune invalida. Va rugam sa incercati din nou.");
      }
    }
  }

  private static void initializareDate(){
    inventory.add(new Produs(101, "MacBook Pro", 15, 2399.99, "Electronice"));
    inventory.add(new Produs(102, "Scaun Ergonomic", 45, 299.50, "Mobilier"));
    inventory.add(new Produs(103, "Boabe de Cafea", 120, 18.25, "Alimente"));
    inventory.add(new Produs(104, "Cablu USB-C", 8, 12.99, "Electronice"));
  }

  private static void afisareAntet() {
    System.out.println("\n" + "=".repeat(50));
    System.out.println("       SISTEM GESTIONARE STOCURI ");
    System.out.println("=".repeat(50));
  }

  private static void afisareInventar(List<Produs> list) {
    if (list.isEmpty()) {
      System.out.println("\nNu au fost gasite produse care sa corespunda criteriilor.");
      return;
    }
    System.out.printf("\n%-5s | %-20s | %-12s | %-12s | %-10s\n", "ID", "Nume", "Categorie", "Cantitate", "Pret");
    System.out.println("-".repeat(70));
 
    for (Produs p : list) {
      String alertaStoc = p.cantitate < 10 ? "(!)" : "";
      System.out.printf("%-5d | %-20s | %-12s | %-8d %3s | %.2f RON\n",p.id, p.nume, p.categorie, p.cantitate, alertaStoc, p.pret);
    }
  }

  private static void adaugareProdus() {
    try{
      System.out.print("Introduceti numele produsului: ");
      String nume = scanner.nextLine();
      System.out.print("Introduceti categoria: ");
      String categorie = scanner.nextLine();
      System.out.print("Introduceti cantitatea initiala: ");
 
      int qty = Integer.parseInt(scanner.nextLine());
      System.out.print("Introduceti pretul unitar: ");
      double pret = Double.parseDouble(scanner.nextLine());

      int newId = inventory.stream().mapToInt(p -> p.id).max().orElse(100) + 1;
      inventory.add(new Produs(newId, nume, qty, pret, categorie));
      System.out.println("Produs adaugat cu succes cu ID-ul: " + newId);
    }catch (Exception e) {
      System.out.println("Eroare: Introducere numerica invalida. Tranzactie abandonata.");
    }
  }

  private static void actualizareStoc(){
    System.out.print("Introduceti ID-ul produsului pentru actualizare: ");
    try{
      int id = Integer.parseInt(scanner.nextLine());
      Optional<Produs> prod = inventory.stream().filter(p -> p.id == id).findFirst();
      if (prod.isPresent()) {
        System.out.print("Introduceti modificarea (ex: 10 pentru adaugare, -5 pentru eliminare): ");
        int change = Integer.parseInt(scanner.nextLine());
        int newQty = prod.get().cantitate + change;
        if (newQty < 0) {
          System.out.println("Eroare: Nu puteti avea stoc negativ.");
        }else{
          prod.get().cantitate = newQty;
          System.out.println("Actualizare reusita. Noua cantitate: " + newQty);
        }
      }else{
        System.out.println("ID-ul produsului nu a fost gasit.");
      }
    }catch(Exception e) {
      System.out.println("Input invalid.");
    }
  }

  private static void meniuCautare() {
    System.out.print("Cautare dupa (1) Nume sau (2) Categorie: ");
    String choice = scanner.nextLine();
    System.out.print("Introduceti cuvantul cheie: ");
    String keyword = scanner.nextLine().toLowerCase();
    List<Produs> rezultate = inventory.stream().filter(p -> choice.equals("1") ? p.nume.toLowerCase().contains(keyword) : p.categorie.toLowerCase().contains(keyword)).collect(Collectors.toList());
    afisareInventar(rezultate);
  }

  private static void afisareStatistici() {
    double totalValue = inventory.stream().mapToDouble(p -> p.pret * p.cantitate).sum();
    long lowStock = inventory.stream().filter(p -> p.cantitate < 10).count();
    System.out.printf("Numar total de produse (SKU): %d\n", inventory.size());
    System.out.printf("Valoarea totala a inventarului: %.2f RON\n", totalValue);
    System.out.printf("Alerte stoc critic (<10):      %d produse\n", lowStock);
    System.out.println("-------------------------");
  }

  static class Produs{
    int id;
    String nume;
    int cantitate;
    double pret;
    String categorie;

    public Produs(int id, String nume, int cantitate, double pret, String categorie){
      this.id = id;
      this.nume = nume;
      this.cantitate = cantitate;
      this.pret = pret;
      this.categorie = categorie;
    }
  }
}

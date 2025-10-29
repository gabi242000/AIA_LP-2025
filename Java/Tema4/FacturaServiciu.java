package lab4;

public class FacturaServiciu {
		private String denumireServiciu;
		private double tarifOra;
		private int numarOre;
		
		public double valoareTotala(){
			return tarifOra*numarOre;
		}
		
		public void afisareFactura() {
			System.out.println("serviciu: " + denumireServiciu);
			System.out.println("tarif / ora: " + tarifOra);
			System.out.println("numar ore: " + numarOre);
			System.out.println("valoarea totala: " + valoareTotala());
		}
		
		public FacturaServiciu() {
			this.denumireServiciu="reparatie";
			this.numarOre=2;
			this.tarifOra=120.5;
		}
		
		public static void main (String[] args) {
			FacturaServiciu factura = new FacturaServiciu();
			factura.afisareFactura();
		}
}

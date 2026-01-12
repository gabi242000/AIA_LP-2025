package ConfiguratorAuto;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage; 

public class ConfiguratorAuto extends JFrame implements ActionListener {
    private Configuratie configuratie = new Configuratie();
    private JRadioButton optiuneGri, optiuneNegru, optiuneVerde, optiuneAlb;
    private JCheckBox checkJante, checkTrapa, checkScauneIncalzite, checkNavigatie;
    private JLabel labelPretTotal, labelImagineMasina;
    private JButton butonNext;


    public ConfiguratorAuto() {
        super("Configurator Auto");

        setLayout(new BorderLayout(10, 10));
        getContentPane().setBackground(Color.WHITE);

        JPanel panouOptiuni = crearePanouOptiuni();
        JPanel panouRezultat = crearePanouRezultat();
        JPanel panouMasina = crearePanouMasina();

        add(panouOptiuni, BorderLayout.WEST); 
        add(panouRezultat, BorderLayout.SOUTH);
        add(panouMasina, BorderLayout.CENTER);

        actualizeazaPret(); 
        actualizeazaImagine(); 

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(1200, 700);
        setLocationRelativeTo(null);
        setVisible(true);
    }

 
    private JPanel crearePanouOptiuni() {
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(0, 1, 5, 5)); 
        panel.setBackground(Color.WHITE);
        panel.setBorder(BorderFactory.createTitledBorder("Alege Opțiunile"));

        // Culoare
        panel.add(new JLabel("Culoare:"));
        optiuneAlb = new JRadioButton("Alb (Standard)", true);
        optiuneNegru = new JRadioButton("Negru Metalizat (+" + Configuratie.PRET_VOPSEA_METALIZATA + " EUR)");
        optiuneVerde = new JRadioButton("Verde Metalizat (+" + Configuratie.PRET_VOPSEA_METALIZATA + " EUR)");
        optiuneGri = new JRadioButton("Gri Metalizat (+" + Configuratie.PRET_VOPSEA_METALIZATA + " EUR)");

        ButtonGroup grupCulori = new ButtonGroup();
        grupCulori.add(optiuneNegru); 
        grupCulori.add(optiuneAlb); 
        grupCulori.add(optiuneVerde); 
        grupCulori.add(optiuneGri);

        optiuneGri.addActionListener(this); 
        optiuneAlb.addActionListener(this);
        optiuneNegru.addActionListener(this); 
        optiuneVerde.addActionListener(this);

        panel.add(optiuneAlb); 
        panel.add(optiuneNegru); 
        panel.add(optiuneVerde); 
        panel.add(optiuneGri);
        panel.add(new JSeparator());

        // Dotări
        panel.add(new JLabel("Dotări Extra:"));
        checkJante = new JCheckBox("Jante Aliaj (+" + Configuratie.PRET_JANTE_ALIAJ + " EUR)");
        checkTrapa = new JCheckBox("Trapă Panoramică (+" + Configuratie.PRET_TRAPA + " EUR)");
        checkScauneIncalzite = new JCheckBox("Scaune Incalzite (+" + Configuratie.PRET_SCAUNE_INCALZITE + " EUR)");
        checkNavigatie = new JCheckBox("Navigatie (+" + Configuratie.PRET_NAVIGATIE + " EUR)");

        checkJante.addActionListener(this);
        checkTrapa.addActionListener(this);
        checkScauneIncalzite.addActionListener(this);
        checkNavigatie.addActionListener(this);

        panel.add(checkJante);
        panel.add(checkTrapa);
        panel.add(checkScauneIncalzite);
        panel.add(checkNavigatie);
        panel.add(new JSeparator());
        butonNext  = new JButton("Finalizare Configuratie");
        butonNext.addActionListener(this);
        panel.add(butonNext);

        return panel;
    }

    private JPanel crearePanouRezultat() {
    JPanel panel = new JPanel();
    panel.setLayout(new FlowLayout(FlowLayout.CENTER));
    panel.setBackground(Color.WHITE);

    JLabel labelPretStatic = new JLabel("Preț Total:");
    labelPretStatic.setFont(new Font("Arial", Font.BOLD, 16));

    labelPretTotal = new JLabel();
    labelPretTotal.setFont(new Font("Arial", Font.BOLD, 16));
    labelPretTotal.setForeground(Color.BLUE); 

    panel.add(labelPretStatic);
    panel.add(labelPretTotal);

    return panel;
}

  
    private JPanel crearePanouMasina() {
        JPanel panel = new JPanel();
        panel.setBackground(Color.WHITE);
       
        panel.setLayout(new BorderLayout()); 
        panel.setBorder(BorderFactory.createTitledBorder("Vizualizare Model"));

        JLabel labelModelMasina = new JLabel("DACIA LOGAN", SwingConstants.CENTER);
        labelModelMasina.setFont(new Font("Arial", Font.BOLD, 16));
    
        labelImagineMasina = new JLabel(); 
        labelImagineMasina.setHorizontalAlignment(SwingConstants.CENTER);
        labelImagineMasina.setVerticalAlignment(SwingConstants.CENTER);

        panel.add(labelModelMasina, BorderLayout.NORTH);
        panel.add(labelImagineMasina, BorderLayout.CENTER); 

        return panel;
    }
    
    public void actionPerformed(ActionEvent e) {
    if (e.getSource() == butonNext) { 
        afiseazaRezumat(); 
        return;
    }

    configuratie.setAreJanteAliaj(checkJante.isSelected());
    configuratie.setAreTrapa(checkTrapa.isSelected());
    configuratie.setAreScauneIncalzite(checkScauneIncalzite.isSelected());
    configuratie.setAreNavigatie(checkNavigatie.isSelected());

    actualizeazaPret(); 
    actualizeazaImagine();
    }
    
    private void actualizeazaPret() {
    double pretCurent = configuratie.calculeazaPretTotal();
    labelPretTotal.setText(String.format("%.2f EUR", pretCurent));
    }   

    private void actualizeazaImagine() {
        String numeFisier = "";
        if (optiuneAlb.isSelected() && checkJante.isSelected()) {
            numeFisier = "ALB_JANTEALIAJ_resized550.jpeg"; 
        }else if (optiuneAlb.isSelected() && !(checkJante.isSelected())) {
            numeFisier = "ALB_JANTEOTEL_resized550.jpeg"; 
        }else if (optiuneNegru.isSelected() && checkJante.isSelected()) {
            numeFisier = "NEGRU_JANTEALIAJ_resized550.jpeg"; 
        }else if (optiuneNegru.isSelected() && !(checkJante.isSelected())) {
            numeFisier = "NEGRU_JANTEOTEL_resized550.jpeg"; 
        }else if (optiuneGri.isSelected() && checkJante.isSelected()) {
            numeFisier = "GRI_JANTEALIAJ_resized550.jpeg"; 
        }else if (optiuneGri.isSelected() && !(checkJante.isSelected())) {
            numeFisier = "GRI_JANTEOTEL_resized550.jpeg"; 
        }else if (optiuneVerde.isSelected() && checkJante.isSelected()) {
            numeFisier = "VERDE_JANTEALIAJ_resized550.jpeg"; 
        }else if (optiuneVerde.isSelected() && !(checkJante.isSelected())) {
            numeFisier = "VERDE_JANTEOTEL_resized550.jpeg"; 
        }

        String caleFisier = "D:\\Code\\Java\\ConfiguratorAuto\\src\\ConfiguratorAuto\\" + numeFisier;
        ImageIcon imaginemasina = new ImageIcon(caleFisier);
        labelImagineMasina.setIcon(imaginemasina);
    }

  private void afiseazaRezumat() {

    RezumatConfiguratie rezumat = new RezumatConfiguratie(this, configuratie); 
    rezumat.setVisible(true); 
}
    public static void main(String[] args) {
        SwingUtilities.invokeLater(ConfiguratorAuto::new);
    }
}
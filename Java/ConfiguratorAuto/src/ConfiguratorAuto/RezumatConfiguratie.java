package ConfiguratorAuto;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileWriter;
import java.io.IOException;

public class RezumatConfiguratie extends JDialog implements ActionListener {

    private Configuratie configuratie;
    private JLabel labelImagineFinala;
    private JButton butonSalvare;

    public RezumatConfiguratie(JFrame parinte, Configuratie config) {
        super(parinte, "Rezumat Final Configurație", true); 
        this.configuratie = config;

        setLayout(new BorderLayout(15, 15));
        setSize(1200, 850);
        getContentPane().setBackground(Color.WHITE);
        setLocationRelativeTo(parinte);

        JPanel panouSus = new JPanel(new BorderLayout());
        panouSus.setBackground(Color.WHITE);
        labelImagineFinala = new JLabel("Încărcare imagine...", SwingConstants.CENTER);
        panouSus.add(labelImagineFinala, BorderLayout.CENTER);
        
        JPanel panouDetaliiText = new JPanel(); 
        panouDetaliiText.setLayout(new GridLayout(0, 1, 0, 5)); 
        panouDetaliiText.setBackground(Color.WHITE); 
        populeazaDetalii(panouDetaliiText); 

        JPanel panouCentru = new JPanel(new GridBagLayout());
        panouCentru.setBackground(Color.WHITE);
        panouCentru.add(panouDetaliiText); 
        
        JPanel panouJos = new JPanel(new FlowLayout(FlowLayout.CENTER));
        panouJos.setBackground(Color.WHITE);
        butonSalvare = new JButton("Salvare Configurație (.txt)");
        butonSalvare.addActionListener(this);
        panouJos.add(butonSalvare);
        
        add(panouSus, BorderLayout.NORTH);
        add(panouCentru, BorderLayout.CENTER);
        add(panouJos, BorderLayout.SOUTH);
        
        actualizeazaImagineFinala(); 
    }
    
    
    private JLabel creeazaEtichetaDetaliu(String text, Font font) {
        JLabel label = new JLabel(text, SwingConstants.CENTER);
        label.setFont(font);
        return label;
    }


    private void populeazaDetalii(JPanel panel) {
        Font fontTitlu = new Font("Arial", Font.BOLD, 18);
        Font fontDetalii = new Font("Arial", Font.PLAIN, 14);
        Font fontTotal = new Font("Arial", Font.BOLD, 16);

      
        JLabel titlu = new JLabel("REZUMAT CONFIGURAȚIE AUTO", SwingConstants.CENTER);
        titlu.setFont(fontTitlu);
        panel.add(titlu);
        
        panel.add(new JLabel(" "));
        
        JLabel model = new JLabel(String.format("Model: DACIA LOGAN - Culoare: %s", configuratie.getCuloareSelectata()), SwingConstants.CENTER);
        model.setFont(fontDetalii);
        panel.add(model);
        
        panel.add(new JLabel(" ")); 

        JLabel subtitlu = new JLabel("--- DOTĂRI ALESE ---", SwingConstants.CENTER);
        subtitlu.setFont(fontTotal);
        panel.add(subtitlu);
        
        boolean dotariSuplimentare = false;

        if (!configuratie.getCuloareSelectata().equals("Alb")) {
             panel.add(creeazaEtichetaDetaliu(configuratie.getCuloareSelectata() + " (Metalizat) + " + 
                 String.format("%.2f EUR", Configuratie.PRET_VOPSEA_METALIZATA), fontDetalii));
             dotariSuplimentare = true;
        }

        if (configuratie.areJanteAliaj()) {
            panel.add(creeazaEtichetaDetaliu("Jante Aliaj + " + 
                String.format("%.2f EUR", Configuratie.PRET_JANTE_ALIAJ), fontDetalii));
            dotariSuplimentare = true;
        }
        
        if (configuratie.areTrapa()) {
            panel.add(creeazaEtichetaDetaliu("Trapă Panoramică + " + 
                String.format("%.2f EUR", Configuratie.PRET_TRAPA), fontDetalii));
            dotariSuplimentare = true;
        }
        
        if (configuratie.areScauneIncalzite()) {
            panel.add(creeazaEtichetaDetaliu("Scaune Încălzite + " + 
                String.format("%.2f EUR", Configuratie.PRET_SCAUNE_INCALZITE), fontDetalii));
            dotariSuplimentare = true;
        }
        
      
        if (configuratie.areNavigatie()) {
            panel.add(creeazaEtichetaDetaliu("Sistem Navigație + " + 
                String.format("%.2f EUR", Configuratie.PRET_NAVIGATIE), fontDetalii));
            dotariSuplimentare = true;
        }

        if (!dotariSuplimentare) {
             panel.add(creeazaEtichetaDetaliu("Nu au fost selectate dotări suplimentare.", fontDetalii));
        }
        
        panel.add(new JLabel(" ")); 
        JLabel pretBaza = new JLabel(String.format("PRET DE BAZĂ: %.2f EUR", Configuratie.PRET_DE_BAZA), SwingConstants.CENTER);
        pretBaza.setFont(fontTotal);
        panel.add(pretBaza);

        JLabel pretTotal = new JLabel(String.format("PRET FINAL: %.2f EUR", configuratie.calculeazaPretTotal()), SwingConstants.CENTER);
        pretTotal.setFont(new Font("Arial", Font.BOLD, 18));
        pretTotal.setForeground(Color.BLUE);
        panel.add(pretTotal);
    }
    
  
    private void actualizeazaImagineFinala() {
        String culoare = configuratie.getCuloareSelectata();
        boolean janteAliaj = configuratie.areJanteAliaj();

        String numeFisier = "";
        
        if (culoare.equals("Alb")) {
            numeFisier = janteAliaj ? "ALB_JANTEALIAJ_resized400.jpeg" : "ALB_JANTEOTEL_resized400.jpeg";
        } 
        else if (culoare.equals("Negru")) {
            numeFisier = janteAliaj ? "NEGRU_JANTEALIAJ_resized400.jpeg" : "NEGRU_JANTEOTEL_resized400.jpeg";
        }
        else if (culoare.equals("Verde")) {
            numeFisier = janteAliaj ? "VERDE_JANTEALIAJ_resized400.jpeg" : "VERDE_JANTEOTEL_resized400.jpeg";
        } 
        else if (culoare.equals("Gri")) {
            numeFisier = janteAliaj ? "GRI_JANTEALIAJ_resized400.jpeg" : "GRI_JANTEOTEL_resized400.jpeg";
        }
        
        String caleFisier = Configuratie.CALE_BAZA_IMAGINI + numeFisier;
        ImageIcon masinaDorita = new ImageIcon(caleFisier);
        labelImagineFinala.setIcon(masinaDorita);
        labelImagineFinala.setText(null);
    }


    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == butonSalvare) {
            salveazaConfiguratieInFisier();
        }
    }

    private void salveazaConfiguratieInFisier() {
        JFileChooser fileChooser = new JFileChooser();
        fileChooser.setDialogTitle("Salvare Configurație");
        fileChooser.setSelectedFile(new java.io.File("Configuratie_Dacia_Logan.txt")); 

        int userSelection = fileChooser.showSaveDialog(this);

        if (userSelection == JFileChooser.APPROVE_OPTION) {
            java.io.File fileToSave = fileChooser.getSelectedFile();
            
            if (!fileToSave.getAbsolutePath().endsWith(".txt")) {
                fileToSave = new java.io.File(fileToSave.getAbsolutePath() + ".txt");
            }
            
            try (FileWriter fileWriter = new FileWriter(fileToSave)) {
                fileWriter.write(generareTextRezumat());
                JOptionPane.showMessageDialog(this, 
                    "Configurația a fost salvată cu succes în:\n" + fileToSave.getAbsolutePath(), 
                    "Salvare Reușită", JOptionPane.INFORMATION_MESSAGE);
            } catch (IOException ex) {
                JOptionPane.showMessageDialog(this, 
                    "Eroare la salvarea fișierului: " + ex.getMessage(), 
                    "Eroare", JOptionPane.ERROR_MESSAGE);
            }
        }
    }
    
    
    private String generareTextRezumat() {
        StringBuilder sb = new StringBuilder();
        
        sb.append("=========================================\n");
        sb.append("        REZUMAT CONFIGURATIE AUTO        \n");
        sb.append("=========================================\n");
        sb.append(String.format("Model: DACIA LOGAN\n"));
        sb.append(String.format("Culoare: %s\n\n", configuratie.getCuloareSelectata()));

        sb.append("--- DOTARI ALESE ---\n");
        
        boolean dotariSuplimentare = false;

        if (!configuratie.getCuloareSelectata().equals("Alb")) {
             sb.append(String.format("%-25s : %.2f EUR\n", configuratie.getCuloareSelectata() + " (Metalizat)", Configuratie.PRET_VOPSEA_METALIZATA));
             dotariSuplimentare = true;
        }

        if (configuratie.areJanteAliaj()) {
            sb.append(String.format("%-25s : %.2f EUR\n", "Jante Aliaj", Configuratie.PRET_JANTE_ALIAJ));
            dotariSuplimentare = true;
        }
        
        if (configuratie.areTrapa()) {
            sb.append(String.format("%-25s : %.2f EUR\n", "Trapa Panoramica", Configuratie.PRET_TRAPA));
            dotariSuplimentare = true;
        }
        
        if (configuratie.areScauneIncalzite()) {
            sb.append(String.format("%-25s : %.2f EUR\n", "Scaune Incalzite", Configuratie.PRET_SCAUNE_INCALZITE));
            dotariSuplimentare = true;
        }
        
        if (configuratie.areNavigatie()) {
            sb.append(String.format("%-25s : %.2f EUR\n", "Sistem Navigatie", Configuratie.PRET_NAVIGATIE));
            dotariSuplimentare = true;
        }

        if (!dotariSuplimentare) {
             sb.append("Nu au fost selectate dotari suplimentare (doar Alb Standard).\n");
        }

        sb.append("\n=========================================\n");
        sb.append(String.format("PRET DE BAZA: %.2f EUR\n", Configuratie.PRET_DE_BAZA));
        sb.append(String.format("PRET TOTAL: %.2f EUR\n", configuratie.calculeazaPretTotal()));
        sb.append("=========================================\n");
        
        return sb.toString();
    }
}
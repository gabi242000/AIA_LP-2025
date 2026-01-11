import java.util.List;

public class ServiciuChirii {
    private UtilizatorDAO udao;
    private TranzactiiDAO tdao;
    private ProprietateDAO dao;


    public ServiciuChirii(UtilizatorDAO udao, TranzactiiDAO tdao, ProprietateDAO dao){
        this.udao = udao;
        this.tdao = tdao;
        this.dao = dao;


    }


    public void proceseazaChirii(){

    try{
        List<ChirieInfo> chirii = dao.ChiriiActive();

        for(ChirieInfo chirie : chirii){
            

            Utilizator proprietar = udao.ReturneazaUtilizator(chirie.getVanzator());
            Utilizator chirias = udao.ReturneazaUtilizator(chirie.getChirias());
            
            tdao.InregistrareTranzactie(proprietar.getNumeUtilizator(), 
                                        chirias.getNumeUtilizator(), chirie.getTitlu(),
                                         chirie.getTipProprietate(), chirie.getPret(), false, true);
            
            udao.AdaugareBani(chirie.getPret(), proprietar.getNumeUtilizator());
            udao.RetragereBani(chirie.getPret(), chirias.getNumeUtilizator());
            chirie.setProfit(chirie.getPret());
            dao.ActualizareProfit(chirie.getProfit(), chirie.getID());

            
        }
        }catch(Exception e){
            System.out.println("Eroare la extragerea chiriilor"+ e.getMessage());
        }
    }

    public void IncetareChirie(model_proprietate prop_selectata,ProprietateDAO dao){
        UtilizatorDAO vanzatordao = new UtilizatorDAO();
        Utilizator vanzator = vanzatordao.ReturneazaUtilizator(prop_selectata.getNumeUtilizator());
        prop_selectata.setStatus("ACTIV");
        dao.AcualizareStatus(prop_selectata.getStatus(), prop_selectata.getID());
        dao.ActualizareCumparator("", prop_selectata.getID());

    }
}

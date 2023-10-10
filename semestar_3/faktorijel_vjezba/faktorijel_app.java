package faktorijel_vjezba;

public class faktorijel_app {
    
    public static void main(String[] args){
        int vrijednost=11;
        Broj broj= new Broj(vrijednost);
        System.out.println("\n\tfaktorijel broja:\t"+vrijednost+"\tje:\t"+broj.faktorijel());
        
    }
}

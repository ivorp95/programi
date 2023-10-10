package faktorijel_vjezba;

public class Broj {         //klasa tipa Broj
    private int vrijednost;


    public Broj(int vrijednost){
        this.vrijednost=vrijednost;
    }


    public int faktorijel(){
        int rezultat=1;
        for (int i=1;i<=this.vrijednost;i++)
        rezultat=rezultat*i;
        return rezultat;
    }
}

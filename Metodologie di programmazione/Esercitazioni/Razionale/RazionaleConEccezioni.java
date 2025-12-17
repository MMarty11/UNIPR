
import java.util.Scanner;
import java.io.*;

public class RazionaleConEccezioni {

	private int n = 0;    // Numeratore.
    private int d = 1;    // Denominatore.

    public RazionaleConEccezioni() {                  // Costruttore senza parametri 
       }
    
    public RazionaleConEccezioni(int num, int den)  
    {   // Costruttore con 2 parametri
       n = num;
       if (den == 0)
	       throw new DenominatoreNullo("ATTENZIONE!: denominatore nullo");
       else 
          d = den;
       }
    
    // Legge il numero razionale nella forma `n/d'.
    public void leggi(InputStream sIn)  {
       int num, den;
       Scanner sc = new Scanner(sIn);
       String frazione = sc.nextLine();
       int sepIndex = frazione.indexOf('/');
       num = Integer.parseInt(frazione.substring(0,sepIndex));
       den = Integer.parseInt(frazione.substring(sepIndex+1,frazione.length()));
       n = num;
       if (den == 0) 
	       throw new DenominatoreNullo("Errore nella frazione " + num + '/' + den);
       d = den;
       }

    // Stampa il numero razionale nella forma `n/d'.
    public void stampa(PrintStream sOut) {
       sOut.println(this);  // N.B. invoca (implicitamente) la toString
       return;
       }   
 
    // Esegue la somma tra `x' e l'oggetto di invocazione.
    RazionaleConEccezioni somma(RazionaleConEccezioni x) {
       RazionaleConEccezioni risultato = new RazionaleConEccezioni();
       risultato.d = d * x.d;
       risultato.n = n * x.d + x.n * d;
       return risultato;
       }
    
    // Converte il numero razionale nella stringa `n/d'.
    public String toString() {
       return "" + n + '/' + d;
       }   

    public boolean equals(Object o) {
        if(o instanceof RazionaleConEccezioni) {
   	        if (this.n == ((RazionaleConEccezioni)o).n && 
   	        	this.d == ((RazionaleConEccezioni)o).d)
    		    return true;
    	    else
    		    return false;
        }
        else return false;
    }

    public void setNum(int num) {
    	n = num;   	
    }
    
    public Object clone() {
    	return new RazionaleConEccezioni(this.n,this.d);
    }

    
}




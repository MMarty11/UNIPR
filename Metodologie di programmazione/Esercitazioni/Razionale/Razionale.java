
import java.util.Scanner;
import java.io.*;

public class Razionale {

	private int n = 0;    // Numeratore.
    private int d = 1;    // Denominatore.

    public Razionale() {                  // Costruttore senza parametri 
       }
    
    public Razionale(int num, int den) {   // Costruttore con 2 parametri
       n = num;
       if (den == 0)
          System.out.println("ATTENZIONE!: denominatore nullo");
       else 
          d = den;
       }
 
    public void setNum(int num) {
    	  n = num;   	
       }
   
    // Legge il numero razionale nella forma `n/d'.
    public void leggi(InputStream sIn) {
       int num, den;
       Scanner sc = new Scanner(sIn);
       String frazione = sc.nextLine();
       int sepIndex = frazione.indexOf('/');
       num = Integer.parseInt(frazione.substring(0,sepIndex));
       den = Integer.parseInt(frazione.substring(sepIndex+1,frazione.length()));
       n = num;
       if (den == 0) 
          System.out.println("ATTENZIONE!: denominatore nullo");
       else
          d = den;
       return;
       }

    // Stampa il numero razionale nella forma `n/d'.
    public void stampa(PrintStream sOut) {
       sOut.println("" + n + '/' + d);
       return;
       }   
 
    // Esegue la somma tra `x' e l'oggetto di invocazione.
    Razionale somma(Razionale x) {
       Razionale risultato = new Razionale();
       risultato.d = d * x.d;
       risultato.n = n * x.d + x.n * d;
       return risultato;
       }
    
    // Converte il numero razionale nella stringa `n/d'.
    public String toString() {
       return "" + n + '/' + d;
       }   

    public boolean equals(Object o) {
        if(o instanceof Razionale) {
   	        if (this.n == ((Razionale)o).n && 
   	        	this.d == ((Razionale)o).d)
    		    return true;
    	    else
    		    return false;
        }
        else return false;
    }
    
    public Object clone() {
    	return new Razionale(this.n,this.d);
    }

}

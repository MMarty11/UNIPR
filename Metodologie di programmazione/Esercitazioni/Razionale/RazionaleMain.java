import java.io.IOException;


public class RazionaleMain {
	
   public static void main (String[] args) throws IOException {
	    
	   Razionale a = new Razionale(2,3);
	   Razionale b = new Razionale(3,4);
	   Razionale c = new Razionale();
	    	    
	   c = a.somma(b);

       System.out.print("La somma e' ");
	   c.stampa(System.out);
	    
       System.out.println("Ripeto: la somma e' " + c.toString());
 
       System.out.print("e ancora: la somma e' " + c);
	          
       return;
    }   
}

/* Prova esecuzione:
 
La somma e' 17/12
Ripeto: la somma e' 17/12
e ancora: la somma e' 17/12

*/



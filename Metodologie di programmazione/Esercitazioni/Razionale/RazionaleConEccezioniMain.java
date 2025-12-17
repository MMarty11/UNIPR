
public class RazionaleConEccezioniMain {
	
	public static void main (String[] args) 
    {
	    RazionaleConEccezioni a = new RazionaleConEccezioni();
	    RazionaleConEccezioni b = new RazionaleConEccezioni();
	    RazionaleConEccezioni c = new RazionaleConEccezioni();
	    
        try{
          System.out.println("Dai la prima frazione (n/d): ");
	      a.leggi(System.in);
	    
          System.out.println("Dai la seconda frazione (n/d): ");
	      b.leggi(System.in);
	    
	      c = a.somma(b);
 
          System.out.print("La somma e' " + c);
        }
        catch (NumberFormatException e) {  
            // cattura l'eccezione NumberFormatException definita in
            // java.lang e generata da Integer.parseInt nel metodo leggi
            // della classe Razionale
        	System.out.println(e);
        }
        catch (DenominatoreNullo e) {  
        	System.out.println(e);
        }
        catch (Throwable e) {    // catch all
        	System.out.println("eccezione non prevista");
        }

    }   
}

/* Prove esecuzione
  
Dai la prima frazione (n/d): 
2/3
Dai la seconda frazione (n/d): 
3/4
La somma e' 17/12

---

Dai la prima frazione (n/d): 
2/a
java.lang.NumberFormatException: For input string: "a"

*/


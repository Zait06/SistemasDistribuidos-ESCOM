import java.util.Random;

public class Busqueda{
	public static void main(String[] arg){
        int n;
        String npalabras="",in;
        String alfabeto  ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        // System.out.println("Ingrese el número de palabras: ");
        // Scanner in = new Scanner(System.in);            
        n=Integer.parseInt(arg[0]);
      
        char letra;
        // // generar n “palabras” de tres
        // // letras cada una y de contenido aleatorio
        for (int i=0; i<n; i++){
             for(int j=0; j<3; j++){
                letra=alfabeto.charAt((int)Math.floor(Math.random()*25));
                npalabras+=letra;
             }
              npalabras+=" ";
        }
        
        int total=0;
        int pos=0;
        int i=0;
        //búsqueda de la subcadena “IPN”
        while(i<npalabras.length()){
            if(npalabras.indexOf("IPN", pos)!= -1){
                total++;
                pos=npalabras.indexOf("IPN", pos) + 2;
             }else{
                 break;
             }
        }
        System.out.println("Total="+ total);
	}
}
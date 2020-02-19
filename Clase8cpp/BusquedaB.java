import java.util.Random;
import java.util.Arrays;

public class BusquedaB{
	public static void main(String[] arg){
        int n=Integer.parseInt(arg[0]);
        byte[] npalabras=new byte[n*4];
        byte[]  alfabeto ={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};        
        byte[] espacio={' '};
        // // generar n “palabras” de tres
        // // letras cada una y de contenido aleatorio
        int pos=0;
        for (int i=0; i<n; i++){
            for(int j=0; j<3; j++){
                int nletra=(int)Math.floor(Math.random()*25);
                System.arraycopy(alfabeto, nletra, npalabras, pos, 1);
                pos++;
            }
           System.arraycopy(espacio, 0, npalabras, pos, 1);
           pos++;
        }
        //System.out.println(Arrays.toString(b2));

        int total=0;
        int i, j;
        // //búsqueda de la subcadena “IPN”}
        byte[] ipn = {'I', 'P', 'N'};
        for(i = 0; i <= npalabras.length-3; i++) {
            for(j = 0; j < 3; j++)
                if((char)npalabras[i + j] != ipn[j])
                    break;
            if(j == 3)
                total++;
        }

         System.out.println("Total="+ total);

	}
}
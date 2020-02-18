import java.util.Scanner;
public class calculos {
    public static void main(String[] args) {
        double i=0, seno,coseno,tangente,logaritmo=1,raiz=0;
        Scanner in = new Scanner(System.in);
        int n= in.nextInt();
        while (i<n)
        {
           seno= Math.sin(i);
           coseno=Math.cos(i);
           tangente=Math.tan(i);
           logaritmo=Math.log(i);
           raiz=Math.sqrt(i);
           i++;
        }
    }  
}

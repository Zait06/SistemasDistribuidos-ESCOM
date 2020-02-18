public class calculos {
    public static void main(String[] args) {
        double i=1,seno=0,coseno=0,tangente=0,logaritmo=0,raiz=0;
        // Scanner in = new Scanner(System.in);
        double n=Integer.parseInt(args[0]);
        while (i<n){
           seno+=Math.sin(i);
           coseno+=Math.cos(i);
           tangente+=Math.tan(i);
           logaritmo+=Math.log(i);
           raiz+=Math.sqrt(i);
           i++;
        }
    }  
}

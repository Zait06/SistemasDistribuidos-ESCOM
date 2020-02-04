 #include <stdio.h>
 #include <stdlib.h>

 int main( )
 {
    int n=2;
    int op=0;
    op= n+(++n);
    printf("%d\n", op);

    return 0;
}
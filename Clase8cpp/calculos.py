import sys
import math


if __name__== "__main__":
    i=1
    seno=0
    coseno=0
    tangente=0
    logaritmo=0
    raizCuad=0
    while i<float(sys.argv[1]):
        seno+=math.sin(i)
        coseno+=math.cos(i)
        tangente+=math.tan(i)
        logaritmo+=math.log10(i)
        raizCuad+=math.sqrt(i)
        i=i+i
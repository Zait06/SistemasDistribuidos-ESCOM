import sys
import random

def countWord(text):
    text=text.upper().split()
    s=0
    for word in text:
      if(word=="IPN"):
        s=s+1
    return s 

if __name__== "__main__":
    n=int(sys.argv[1])
    npalabras=""
    alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    palabra=""
    
    for i in range(n):
        for j in range(3):
            letra=alfabeto[1+random.randrange(25)]
            palabra=palabra+letra
        palabra=palabra+" "
        npalabras=npalabras+palabra
        palabra="";

    total=countWord(npalabras)

    print("Numero de ocurrencias {}".format(total))
import sys
from random import choice
from string import ascii_uppercase 

if __name__== "__main__":
    n=int(sys.argv[1])
    npalabras=""

    for j in range(n):
        npalabras+=(''.join(choice(ascii_uppercase) for i in range(3)))+" "

    total=npalabras.count("IPN")

    print("Numero de ocurrencias: {}".format(total))
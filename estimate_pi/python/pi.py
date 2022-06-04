import time as tm
import math as mt
import numpy as np
import random as rng
import matplotlib.pyplot as plt

from sys import argv
from doctest import testmod

time_NULL = tm.clock_gettime(tm.CLOCK_REALTIME)

def main():

    '''
    >>> pi(1e+7, 0)
    3.14
    >>> pi(1e0, 0)
    4.0
    '''

    seed = rng.seed(int(argv[2])) if len(argv) == 3 else rng.seed(time_NULL)    #   Python ternary operator
    n = float(argv[1])

    i, s = 0, 0
    x, y = 0.0, 0.0
    while i < n:
        x = rng.random()
        y = rng.random()
        plt.scatter(x, y, s= 0.24)  #   Plot the drawn points inside of the image
        if (mt.sqrt(x*x+y*y) < 1.0):
            s += 1
        i += 1

    p = 4.0*s/n
    txt = "With {:.0e} interations the approximation for Pi is {:.2f}." 
    print(txt.format(n, p))

#   Print a pdf with a image of a circle inside a square with the drawn points
    plt.xlim(-1, 1)
    plt.ylim(-1, 1)
    plt.xticks(np.arange(-1, 1.5, 0.5))
    plt.yticks(np.arange(-1, 1.5, 0.5))
    plt.gca().set_aspect('equal', adjustable= 'box')
    plt.gca().add_patch(plt.Circle((0, 0), radius= 1, fill= False, linewidth= 0.42))
    plt.text(-1, 1, 'The estimate valeu of pi is {}' .format(p), fontsize= 6.9, horizontalalignment= 'left', verticalalignment= 'bottom')
    plt.savefig("/mnt/c/Users/Gcmar/Onedrive/Área de Trabalho/pi.pdf", bbox_inches= "tight", transparent= True)

if __name__ == "__main__":
    main()

print(testmod())
import sys
import numpy as np
import random as rng
import matplotlib.pyplot as plt

def main():
    n= int(sys.argv[1])
    pi= estimate_pi(n)
    print("The estimate value of pi is {}" .format(pi))

def plot(pi):
    plt.xlim(-1, 1)
    plt.ylim(-1, 1)
    plt.xticks(np.arange(-1, 1.5, 0.5))
    plt.yticks(np.arange(-1, 1.5, 0.5))
    plt.gca().set_aspect('equal', adjustable= 'box')
    plt.gca().add_patch(plt.Circle((0, 0), radius= 1, fill= False, linewidth= 0.42))
    plt.text(-1, 1, 'The estimate valeu of pi is {}' .format(pi), fontsize= 6.9, horizontalalignment= 'left', verticalalignment= 'bottom')
    plt.savefig("/mnt/c/Users/Gcmar/Onedrive/Área de Trabalho/programming/piton/estimate_pi/pi.pdf", bbox_inches= "tight", transparent= True)

def estimate_pi(n):
    total_pt= 0
    circle_pt= 0
    for _ in range(n):
        x= rng.uniform(-1, 1)
        y= rng.uniform(-1, 1)
        d= (x*x+y*y)**(1/2)
        plt.scatter(x, y, s= 0.24)
        total_pt+= 1
        if d<= 1:
            circle_pt+= 1
        if _%(n/100) == 0:
            print("{}%" .format(_/(n/100)))
    pi= 4*(circle_pt/total_pt)
    plot(pi)
    print("{}%" .format(n/(n/100)))
    return pi

if __name__ == '__main__':
	main()
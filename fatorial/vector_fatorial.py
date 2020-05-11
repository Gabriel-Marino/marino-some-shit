import sys
import numpy as np
import matplotlib.pyplot as plt

def main():
	n= int(sys.argv[1])
	fat= fatorial(n)
	print("O fatorial de {} é {}." .format(n, fat))

# def plot(xlim, ylim):
    # plt.xlim(0, xlim)
    # plt.ylim(0, ylim)
    # plt.xticks(np.arange(0, xlim, xlim/10))
    # plt.yticks(np.arange(0, ylim, 1))
    # plt.gca().set_aspect('equal', adjustable= 'box')
    # plt.savefig("/mnt/c/Users/Gcmar/Onedrive/Área de Trabalho/programming/piton/fatorial/fat.pdf", bbox_inches= "tight", transparent= True)

def fatorial(n):
    i= 1
    f= 1
    fat= [1]
    while i<= n:
        f= i*fat[i-1]
        fat.append(f)
        i+= 1
        # plt.scatter(f, i, s= 0.5)
        # if i%(n/100)==0:
            # print("{}%" .format(i/(n/100)))
    # plot(fat[n], n+1)
    # print("{}%" .format(100))
    return fat[n]

if __name__ == "__main__":
	main()
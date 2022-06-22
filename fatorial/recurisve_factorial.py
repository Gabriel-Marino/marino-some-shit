import sys

def main():
#    if len(sys.argv) == 0:
#        print('Para executar o programa:\n python3 fatorial.py "número"')
#        exit(1)
    n= int(sys.argv[1])
    fact= factorial(n)
    print('the factorial of {} is {}'.format(n, fact))

def factorial(n):
    fat= 0
    if n == 0:
        fat= 1
    else:
        fat= n*factorial(n-1)
    return fat
    
if __name__ == "__main__":
    main()

#print('O fatorial de {} é {}'.format(, fatorial()))
#print('O fatorial de {} é {}'.format(0, fatorial(0)))
#print('O fatorial de {} é {}'.format(1, fatorial(1)))
#print('O fatorial de {} é {}'.format(5, fatorial(5)))
#print('O fatorial de {} é {}'.format(10, fatorial(10)))
#print('O fatorial de {} é {}'.format(100, fatorial(100)))
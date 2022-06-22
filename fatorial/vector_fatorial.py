import sys

def main():
	n= int(sys.argv[1])
	fat= factorial(n)
	print("The factorial of {} is {}." .format(n, fat))

def factorial(n):
    i= 1
    f= 1
    fat= [1]
    while i<= n:
        f= i*fat[i-1]
        fat.append(f)
        i+= 1
    return fat[n]

if __name__ == "__main__":
	main()
import sys

def main():
	n= float(sys.argv[1])
	fat= fatorial(n)
	print("O Fatorial de {} é {}." .format(n, fat))

def fatorial(n):
	i= 1
	fat= 1
	while i<= n:
		fat*= i
		i+= 1
	return fat

if __name__ == '__main__':
	main()
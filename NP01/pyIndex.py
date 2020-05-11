from sys import argv

def helloworld():
    print("Hello World!")

def main():
    helloworld()
    f= []
    for i in argv:
        f.append(i)
    for i in f:
        print(i)

if __name__ == '__main__':
    main()
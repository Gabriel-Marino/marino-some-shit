def IsPrime2(n: int) -> bool:
    return len(list(filter(lambda div: n % div == 0, list(range(1, n+1))))) == 2

def IsPrime(n: int) -> bool:
    max_div = n     # want to optmize the max divisor to check, i was thinking in use like n/2 for even and (n-1)/2 for odd, but this way is not working properly
    div = []
    i = 1
    while i <= max_div:
        if n%i == 0:
            div.append(i)
        if len(div) > 2:
            break
        i += 1
    return len(div) == 2

def main():
    list(map(lambda i: print("%i is a Prime!" %i if IsPrime(i) else "Not a prime."), list(range(1,1000))))

if __name__ == "__main__":
    main()
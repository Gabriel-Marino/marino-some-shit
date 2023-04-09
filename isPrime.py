def IsPrime(number: int) -> bool:
    return False if number < 2 or number % 2 == 0 and number > 2 else len(list(filter(lambda denominator: number % denominator == 0, list(range(1, int(number/2)))))) < 2

def isPrime(number):
    if number < 2 or isinstance(number, float) :
        return False

    if number % 2 == 0:
        if number > 2:
            return False
        return True

    denominator = 1
    divisors = []
    while denominator < (number+1)/2:
        if number % denominator == 0:
            divisors.append(denominator)
        if len(divisors) == 2:
            return False
        denominator += 1

    return True


def main():
    #testing functions
    primes1 = list(filter(IsPrime, list(range(-10, 1000))))
    primes2 = list(filter(isPrime, list(range(-10, 1000))))
    print(primes1 == primes2, primes1, primes2)

if __name__ == "__main__":
    main()
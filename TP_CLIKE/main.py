def eh_primo(num):
    if num <= 1:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def main():
    n = int(input("Digite um numero inteiro: "))
    
    if eh_primo(n):
        print(f"{n} é um número primo.")
    else:
        print(f"{n} não é um número primo.")
    
    print(f"Números primos menores que {n}:")
    for i in range(2, n):
        if eh_primo(i):
            print(i, end=" ")
    print()

if __name__ == "__main__":
    main()

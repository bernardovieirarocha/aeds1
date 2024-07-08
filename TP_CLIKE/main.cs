using System;

class Program {
    static bool EhPrimo(int num) {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    static void Main() {
        Console.Write("Digite um numero inteiro: ");
        int n = int.Parse(Console.ReadLine());

        if (EhPrimo(n)) {
            Console.WriteLine($"{n} é um número primo.");
        } else {
            Console.WriteLine($"{n} não é um número primo.");
        }

        Console.WriteLine($"Números primos menores que {n}:");
        for (int i = 2; i < n; i++) {
            if (EhPrimo(i)) {
                Console.Write($"{i} ");
            }
        }
        Console.WriteLine();
    }
}

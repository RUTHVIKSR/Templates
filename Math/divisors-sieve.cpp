long long divisorCount(long long n) {
    if (n == 1) return 1;
    long long total = 1;

    for (long long p : primes) {
        if (p * p > n) break;

        int exponent = 0;
        while (n % p == 0) {
            n /= p;
            exponent++;
        }
        if (exponent > 0) {
            total *= (exponent + 1);
        }
    }

    // If remainder is a prime > sqrt(original n)
    if (n > 1) total *= 2;

    return total;
}

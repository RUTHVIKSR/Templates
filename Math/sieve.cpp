const int SIEVE_LIMIT = 1000000; 
vector<int> primes;
vector<bool> is_prime(SIEVE_LIMIT + 1, true);

// ------------------ SIEVE ------------------
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= SIEVE_LIMIT; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= SIEVE_LIMIT; i += p) {
                is_prime[i] = false;
            }
        }
    }
    for (int p = 2; p <= SIEVE_LIMIT; p++) {
        if (is_prime[p]) primes.push_back(p);
    }
}

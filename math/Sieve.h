// Worst case factorization O(log_2(x)) 
// 1e2 ~ 1 ms, 25 primes
// 1e3 ~ 1 ms, 168 primes
// 1e4 ~ 1 ms, 1229 primes 
// 1e5 ~ 1 ms, 9592 primes
// 1e6 ~ 2 ms, 78498 primes
// 1e7 ~ 20 ms, 664589 primes
// 1e8 ~ 220 ms, 5761455 primes 
  
const int MAX_PRIME = 1e6;

bitset<MAX_PRIME> prime;
vector<int> primeList;

void sieve() {
    prime.set();
    prime[0] = prime[1] = 0;
    primeList.push_back(2);
    for (int i=4; i<MAX_PRIME; i+=2)
        prime[i] = 0;
    for (int p=3; p<MAX_PRIME; p+=2)
        if (prime[p]) {
            primeList.push_back(p);
            for (int i=p; i<=(MAX_PRIME-1)/p; i+=2)
                prime[i*p] = 0;
        }
}  
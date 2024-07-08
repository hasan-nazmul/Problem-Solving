// Particular code prints all the prime factors of a number less then 1e14

// Time Complexity: O( (sqrt(n) / ln(sqrt(n))) + log2(n) )

// Almost 400 iterations for a 1e7 sized number

#include <bits/stdc++.h>

using namespace std;

const int mx_size = 1e7 + 100;

bitset <mx_size> isPrime;

vector <int> primes;

void sieve(int n)
{
    isPrime[2] = 1;

    for(int i = 3; i <= n; i += 2)  isPrime[i] = 1;

    for(int i = 3; i * i <= n; i += 2)
    {
        if(!isPrime[i]) continue;

        for(int j = i * i; j <= n; j += i)
            isPrime[j] = 0;
    }

    for(int i = 2; i <= n; i++) if(isPrime[i])  primes.push_back(i);
}

vector <long long> factorize(long long n)
{
    vector <long long> prime_factors;

    n = (long long) abs(n);

    if(n < 2)    return {-1};

    for(long long p : primes)
    {
        if(p * p > n)  break;

        while(!(n % p))
        {
            prime_factors.push_back(p);
            n /= p;
        }
    }

    if(n > 1)   prime_factors.push_back(n);

    return prime_factors;
}

int main()
{
    int lim = 1e7 + 10;

    sieve(lim);

    long long n, t;

    cin >> n;

    vector <long long> prime_factors = factorize(n);

    for(auto i : prime_factors) cout << i << endl;
}
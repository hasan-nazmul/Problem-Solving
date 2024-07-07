// Particular code prints all the prime factors of a number less then 1e14

// Time Complexity: O( (sqrt(n) / ln(sqrt(n))) + log2(n) )

// Almost 400 iterations for a 1e7 sized number

#include <bits/stdc++.h>

using namespace std;

const int mx_size = 1e5 + 100;

bitset <mx_size> isPrime;

vector <long long> primes;

void sieve(long long n)
{
    isPrime[2] = 1;

    for(long long i = 3; i <= n; i += 2)  isPrime[i] = 1;

    for(long long i = 3; i * i <= n; i += 2)
    {
        if(!isPrime[i]) continue;

        for(long long j = i * i; j <= n; j += i)
            isPrime[j] = 0;
    }

    for(long long i = 2; i <= n; i++) if(isPrime[i])  primes.push_back(i);
}

vector <long long> factorize(long long n)
{
    vector <long long> prime_factors;

    for(auto p : primes)
    {
        while(!(n % p))
        {
            prime_factors.push_back(p);
            n /= p;
        }

        if(p * p > n)  break;
    }

    if(n > 1)   prime_factors.push_back(n);

    return prime_factors;
}

int main()
{
    int lim = 1e5 + 10;

    sieve(lim);

    long long n;

    while(1)
    {
        cin >> n;

        if(!n)  break;

        if(n == 1 or !n or n == -1)
        {
            cout << n << " = " << n << "\n";
            continue;
        }

        vector <long long> prime_factors = factorize((long long) abs(n));

        if(n < 0)    cout << n << " = -1 x ";

        else    cout << n << " = ";

        for(int i = 0; i < (int) prime_factors.size(); i++)
        {
            cout << prime_factors[i];
            
            if(i < (int) prime_factors.size() - 1)  cout << " x ";
        }

        cout << "\n";
    }
}
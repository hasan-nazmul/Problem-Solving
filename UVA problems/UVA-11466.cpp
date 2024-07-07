#include <bits/stdc++.h>

using namespace std;

const int mx_size = 1e7 + 100;

bitset <mx_size> isPrime;

vector <long long> primes;

void sieve(int n)
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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int lim = 1e7 + 10;

    sieve(lim);

    while(1)
    {
        long long n;

        cin >> n;

        if(!n)  break;

        vector <long long> factors = factorize((long long) abs(n));

        if(!factors.empty() and factors.front() != factors.back())   cout << factors.back() << "\n";
        else    cout << -1 << "\n";
    }
}
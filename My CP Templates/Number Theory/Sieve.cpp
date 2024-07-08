// Particular code prints all the prime numbers from 1 to 1e7

// Time Complexity: Nearly O(n)

#include <bits/stdc++.h>

using namespace std;

const int mx_size = 1e8 + 100;

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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int lim = 1e7;

    sieve(lim);

    // for(auto i : primes)    cout << i << "\n";
}
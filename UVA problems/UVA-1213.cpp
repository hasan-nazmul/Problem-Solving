#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define nl '\n'

const int mx_size = 1150;

bitset <mx_size> isPrime;

vector <ll> primes;

void prime_gen(int n)
{
    isPrime[2] = 1;

    for(int i = 3; i <= n; i += 2)
        isPrime[i] = 1;
    
    for(int i = 3; i <= n; i += 2)
    {
        for(int j = i*i; j <= n; j += i)
            isPrime[j] = 0;
    }

    for(int i = 2; i <= n; i++)
        if(isPrime[i])
            primes.push_back(i);
}

ll n, k, c;
ll dp[200][1130][16];

ll f(int i, int sum, int j)
{
    if(sum == n and j == k) return 1;
    if(sum > n or primes[i] > n - sum or j > k) return 0;
    if(dp[i][sum][j] != -1) return dp[i][sum][j];

    int ret = f(i+1, sum+primes[i], j+1) + f(i+1, sum, j);

    return dp[i][sum][j] = ret;
}

int main()
{
    prime_gen(1130);

    while(1)
    {
        cin >> n >> k;

        memset(dp, -1, sizeof(dp));

        if(!n and !k)   return 0;

        cout << f(0, 0, 0) << nl;
    }
}

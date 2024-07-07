#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define nl '\n'

#define mod(a, b) (((a) % (b)) + (b)) % (b)

const int mx_size = 220;

ll n, m, d, q;

ll a[mx_size];
ll dp[mx_size][30][20];

ll f(int i, int sum, int j)
{
    sum = mod(sum, d);

    if(i > n or j >= m)   return !sum and (j==m);
    if(dp[i][sum][j] != -1) return dp[i][sum][j];

    return dp[i][sum][j] = f(i+1, mod(sum + mod(a[i], d), d), j+1) + f(i+1, sum, j);
}

int main()
{
    int t = 1;

    while(1)
    {
        cin >> n >> q;

        if(!n and !q)   break;

        for(int i = 1; i <= n; i++)
            cin >> a[i];

        cout << "SET " << t++ << ":" << nl;

        int p = 1;
        
        while(p <= q)
        {
            cin >> d >> m;

            memset(dp, -1, sizeof(dp));

            cout << "QUERY " << p++ << ": " << f(1, 0, 0) << nl;
        }
    }

    return 0;
}

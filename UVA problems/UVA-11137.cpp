#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mx = 1e4+100;

ll dp[30][mx];

ll ways(int i, ll amount)
{
    if(i == 1 or !amount)   return 1;
    
    if(dp[i][amount] != -1)   return dp[i][amount];

    ll count = 0, value = i*i*i;

    for(ll j = 0; j <= amount / value; j++)
    {
        if(amount >= value * j)
            count += ways(i-1, amount- value*j);
    }

    return dp[i][amount] = count;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;

    memset(dp, -1, sizeof(dp));

    while(cin >> n)
    {
        ll ans = ways(21, n);

        cout << ans << endl;
    }
}

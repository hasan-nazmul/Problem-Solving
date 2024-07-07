#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll coins[] = {0, 1, 5, 10, 25, 50};

ll dp[6][30010];

ll c = 0;

ll ways(int i, ll amount)
{
    c++;
    if(i == 5)   return !(amount%coins[i]);
    if(amount <= 0) return !amount;
    if(dp[i][amount] != -1)   return dp[i][amount];

    ll count = 0;

    for(ll j = 0; j <= amount; j++)
    {
        if(amount >= coins[i] * j)
            count += ways(i+1, amount-coins[i]*j);
        else    break;
    }

    return dp[i][amount] = count;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;

    memset(dp, -1, sizeof(dp));

    ways(1, 30000);

    while(cin >> n)
    {
        ll ans = ways(1, n);

        //cout << c << endl;

        if(ans == 1)
        {
            cout << "There is only 1 way to produce " << 
                n << " cents change." << endl;
        }
        
        else
        {
            cout << "There are " << ans << 
                " ways to produce " << n <<" cents change." << endl;
        }
    }
}

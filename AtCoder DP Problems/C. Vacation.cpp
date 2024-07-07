#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n;

ll w[100010][4];

ll dp[100010][4];

ll max_happiness(int i, int f)
{
    if(i == n+1)    return 0;
    if(dp[i][f] != -1)  return dp[i][f];
    
    ll mx = 0;
    
    for(int j = 1; j < 4; j++)
    {
        if(j == f)  continue;
        mx = max(mx, w[i][j] + max_happiness(i+1, j));
    }
    
    return dp[i][f] = mx;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 3; j++)
            cin >> w[i][j];
    }
    
    cout << max_happiness(0, 0) << endl;
}
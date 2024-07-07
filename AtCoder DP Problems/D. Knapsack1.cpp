#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, w;

ll a[2][100010];
ll dp[110][100010];

ll f(int i, int w)
{
    if(i >= n or !w)  return 0;
    if(dp[i][w] != -1)  return dp[i][w];

    ll u = INT_MIN, v = INT_MIN;

    if(w >= a[0][i])
        u = a[1][i] + f(i+1, w - a[0][i]);

    v = f(i+1, w);

    return dp[i][w] = max(u, v);
}

int main()
{
    cin >> n >> w;

    for(int i = 0; i < n; i++)
        cin >> a[0][i] >> a[1][i];

    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100005; j++)
            dp[i][j] = -1;

    cout << f(0, w) << endl;
}

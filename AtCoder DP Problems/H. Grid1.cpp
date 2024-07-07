#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, m;

string grid[1010];
ll dp[1010][1010];

ll ways(int i, int j)
{
    if(i == n and j == m)   return 1;
    if(dp[i][j] != -1)  return dp[i][j];

    ll u = 0, v = 0;

    if(i < n and grid[i+1][j] != '#')
        u = ways(i+1, j)%((ll)1e9+7);
    if(j < m and grid[i][j+1] != '#')
        v = ways(i, j+1)%((ll)1e9+7);

    return dp[i][j] = (u+v)%((ll)1e9+7);
}

int main()
{
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        cin >> grid[i];
        grid[i] = " " + grid[i];
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i][j] = -1;

    cout << ways(1, 1) << endl;
}

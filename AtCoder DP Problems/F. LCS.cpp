#include <bits/stdc++.h>

using namespace std;

#define ll long long

string a, b, ans;
int dp[3010][3010], dr[3010][3010], c = 0;

int f(int u, int v)
{
    c++;

    if(u == a.size() or v == b.size())  return 0;
    else if(dp[u][v] != -1) return dp[u][v];

    if(a[u] == b[v])
    {
        dr[u][v] = 1;
        return dp[u][v] = 1 + f(u+1, v+1);
    }
    else
    {
        int p = f(u, v+1);
        int q = f(u+1, v);

        if(p > q)
        {
            dr[u][v] = 3;
            dp[u][v] = p;
        }
        else
        {
            dr[u][v] = 2;
            dp[u][v] = q;
        }

        return dp[u][v];
    }
}

void g(int i, int j)
{
    if(i == a.size() or j == b.size())  return;
    if(dr[i][j] == 1)
    {
        ans.push_back(a[i]);
        g(i+1, j+1);
    }
    else if(dr[i][j] == 3)
        g(i, j+1);
    else    g(i+1, j);
}

int main()
{
    cin >> a >> b;

    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < b.size(); j++)
            dp[i][j] = -1;

    f(0, 0);

    g(0, 0);

    cout << ans << endl;
}

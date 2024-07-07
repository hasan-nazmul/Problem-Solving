#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, c = 0;

int a[100010], dp[100010];

int frog(int i)
{
    if(i == n-1)    return 0;

    else if(dp[i] != -1)    return dp[i];

    int u = 1e8, v = 1e8;

    if(i+1 < n)
        u = abs(a[i]-a[i+1]) + frog(i+1);

    if(i+2 < n)
        v = abs(a[i]-a[i+2]) + frog(i+2);

    return dp[i] = min(u, v);
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[i] = -1;
    }

    cout << frog(0) << endl;
}
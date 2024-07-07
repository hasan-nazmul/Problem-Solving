#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, c = 0, k;

int a[100010], dp[100010];

int frog(int i)
{
    if(i == n-1)    return 0;

    else if(dp[i] != -1)    return dp[i];

    int mn = INT_MAX;

    for(int j = 1; j <= k and i+j < n; j++)
        mn = min(mn, abs(a[i]-a[i+j]) + frog(i+j));

    return dp[i] = mn;
}

int main()
{
    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[i] = -1;
    }

    cout << frog(0) << endl;
}

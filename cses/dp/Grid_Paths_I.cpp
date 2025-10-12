/// Bismillahir Rahmanir Rahim
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define nl '\n'
#define pr pair <ll, ll>
#define sp ' '
#define mod(a, b) (((a) % (b)) + (b)) % (b)
#define sz(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YES cout << "YES" << nl
#define NO cout << "NO" << nl
#define Yes cout << "Yes" << nl
#define No cout << "No" << nl
#define yes cout << "yes" << nl
#define no cout << "no" << nl
#define neg cout << -1 << nl
#define OUT(v, n) for(auto x: v)    cout << x << n;
#define PAIR_OUT(v) for(auto x: v) \
        cout << x.first << " " << x.second << nl;
#define eps 1000000007
 
void solve()
{
    ll n;
 
    cin >> n;
 
    string grid[n+5];
 
    for(int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
 
    ll dp[n+5][n+5];
 
    memset(dp, 0, sizeof(dp));
 
    dp[n-1][n-1] = 1;
 
    for(int i = n-1; i >= 0; i--)
    {
        for(int j = n-1; j >= 0; j--)
        {
            if(grid[i][j] == '*')   dp[i][j] = 0;
            else {
                if(i+1 < n) dp[i][j] = mod(mod(dp[i][j], eps) + mod(dp[i+1][j], eps), eps);
                if(j+1 < n) dp[i][j] = mod(mod(dp[i][j], eps) + mod(dp[i][j+1], eps), eps);
            }
        }
    }
 
    cout << dp[0][0] << nl;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    solve();
 
    // ll M; cin >> M;
 
    // while(M--) {
    //    solve();
    // }
 
    return 0;
}

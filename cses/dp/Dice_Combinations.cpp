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
 
ll n;
 
ll dp[1000010];
 
ll calc(ll num)
{
    if(num == n)    return 1;
    else if(dp[num] != -1)  return dp[num];
 
    ll ways = 0;
 
    for(int i = 1; i <= 6 and num+i <= n; i++)
    {
        ways = mod(mod(ways, eps) + calc(num+i), eps);
    }
 
    return dp[num] = ways;
}
 
void solve()
{
    memset(dp, -1, sizeof(dp));
 
    cin >> n;
 
    cout << calc(0) << nl;
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
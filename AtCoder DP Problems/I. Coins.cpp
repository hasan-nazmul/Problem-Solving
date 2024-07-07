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

double p[3010];

double dp[3010][3010];

double func(int i, int c)
{
    if(i == n+1)
        return (2*c > n) ? 1 : 0;
    if(abs(-1 - dp[i][c]) <= 1e5)  return dp[i][c];
    
    double ret1 = 0, ret2 = 0;

    return dp[i][c] = (p[i] * func(i+1, c+1) + (1-p[i]) * func(i+1, c));
}

void solve()
{
    memset( dp, -1, sizeof(dp) );

    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> p[i];

    cout << setprecision(10) << fixed;
    
    cout << func(1, 0) << nl;
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
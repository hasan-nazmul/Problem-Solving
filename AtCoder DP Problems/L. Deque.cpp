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

const int mx_len = 3010;

ll dp[mx_len][mx_len][3];

ll a[mx_len];

ll fun(int l, int r, int i)
{
    if(l == r)  return (!i) ? a[l] : 0;
    if(l > r)  return 0;
    if(dp[l][r][i] != -1)   return dp[l][r][i];

    if(i)    return dp[l][r][i] = min(fun(l+1, r, i^1), fun(l, r-1, i^1));
    else    return dp[l][r][i] = max(a[l] + fun(l+1, r, i^1), a[r] + fun(l, r-1, i^1));
}

void solve()
{
    memset(dp, -1, sizeof(dp));

    cin >> n;

    ll sum = 0;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    cout << 2*fun(1, n, 0) - sum << nl;
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
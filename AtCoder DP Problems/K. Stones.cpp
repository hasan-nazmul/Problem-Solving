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

ll n, k;

ll a[110];
ll dp[100010];

bool calc(ll k)
{
    if(k < a[1])    return 0;
    else if(k == a[1])  return 1;
    else if(dp[k] != -1)    return dp[k];

    for(int i = 1; i <= n; i++)
    {
        if(a[i] <= k and !calc(k-a[i]))
        {
            return dp[k] = 1;
        }
    }

    return dp[k] = 0;
}

void solve()
{
    cin >> n >> k;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    memset( dp , -1 , sizeof(dp) );

    if(n == 1)
    {
        ll m = k / a[1];

        if(m%2) cout << "First" << nl;
        else    cout << "Second" << nl;

        return;
    }

    if(calc(k)) cout << "First" << nl;
    else        cout << "Second" << nl;
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
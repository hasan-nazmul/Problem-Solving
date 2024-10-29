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

ll v, e;

vector <ll> adj_list[100010];

ll dp[100010];

ll calc(ll i)
{
    if(!sz(adj_list[i]))    return 0;
    if(dp[i] != -1) return dp[i];

    ll mx = -1;

    for(auto p : adj_list[i])
    {
        mx = max(mx, 1 + calc(p));
    }

    return dp[i] = mx;
}

void solve()
{
    cin >> v >> e;

    for(int i = 0; i < e; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }

    memset(dp, -1, sizeof(dp));

    ll mx = -1;

    for(int i = 1; i <= v; i++)
        mx = max(mx, calc(i));

    cout << mx << nl;
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
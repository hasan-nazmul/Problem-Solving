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

ll n, w;

vector <pr> items(110);

ll dp[110][100010];

ll min_weight(int i, ll value)
{
    if(!value)  return 0;
    if(i == n+1)    return 1e12;
    if(dp[i][value] != -1)  return dp[i][value];

    ll ret1 = LLONG_MAX, ret2;

    if(value >= items[i].second)
        ret1 = items[i].first + 
                min_weight(i+1, value - items[i].second);
    
    ret2 = min_weight(i+1, value);

    return dp[i][value] = min(ret1, ret2);
}

void solve()
{
    memset(dp, -1, sizeof(dp)); 

    cin >> n >> w;

    for(int i = 1; i <= n; i++)
        cin >> items[i].first >> items[i].second;

    ll weight;
    
    for(int i = 100000; i; i--)
    {
        weight = min_weight(1, i);
        if(weight <= w) 
        {
            cout << i << nl;
            return;
        }
    }
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
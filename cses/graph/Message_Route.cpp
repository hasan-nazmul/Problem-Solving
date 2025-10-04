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
#define OUT(v, n) for(auto x: v) cout << x << n;
#define PAIR_OUT(v) for(auto x: v) \
        cout << x.first << " " << x.second << nl;
#define eps 1000000007

void solve()
{
    ll n, m;

    cin >> n >> m;

    vector <ll> adj[n+1];
    vector <ll> level(n+1, -1);
    vector <ll> prev(n+1, -1);

    for(int i=0; i<m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue <ll> bfs;

    bfs.push(1);

    level[1] = 0;

    bool found = 0;

    while(!bfs.empty())
    {
        int curr = bfs.front();
        bfs.pop();

        if(curr==n)
        {
            found = 1;
        }

        for(auto i : adj[curr])
        {
            if(level[i]==-1)
            {
                level[i] = level[curr]+1;
                prev[i] = curr;
                bfs.push(i);
            }
        }
    }

    if(!found)
    {
        cout << "IMPOSSIBLE" << nl;
        return;
    }

    vector <ll> ans;

    int idx = n;

    while(idx>=0)
    {
        ans.push_back(idx);
        idx = prev[idx];
    }

    cout << sz(ans) << nl;

    reverse(all(ans));

    for(auto i : ans)
        cout << i << sp;
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
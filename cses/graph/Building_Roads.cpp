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

    vector <bool> visited(n+1);

    for(int i=0; i<m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector <int> ans;

    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            ans.push_back(i);
            stack <int> dfs;
            dfs.push(i);

            while(!dfs.empty())
            {
                int curr = dfs.top();
                dfs.pop();

                if(visited[curr])   continue;

                visited[curr] = 1;

                for(auto i : adj[curr])
                    dfs.push(i);
            }
        }
    }

    cout << sz(ans)-1 << nl;

    for(int i=1; i<sz(ans); i++)
        cout << ans[i-1] << sp << ans[i] << nl;
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
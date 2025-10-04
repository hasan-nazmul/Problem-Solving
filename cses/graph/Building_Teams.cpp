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

    vector <int> friendship(n+1, -1);

    vector <int> adj[n+1];

    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
    {
        if(friendship[i]==-1)
        {
            queue <int> bfs;

            bfs.push(i);

            friendship[i] = 0;

            while(!bfs.empty())
            {
                auto curr = bfs.front();

                bfs.pop();

                for(auto j : adj[curr])
                {
                    if(friendship[j]==friendship[curr])
                    {
                        cout << "IMPOSSIBLE" << nl;
                        return;
                    }
                    if(friendship[j]==-1)
                    {
                        friendship[j] = friendship[curr] ^ 1;
                        bfs.push(j);
                    }
                }
            }
        }
    }

    for(int i=1; i<=n; i++)
        cout << friendship[i]+1 << sp;

    cout << nl;
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
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

const int mx_sz = 1e5+10;

int n, m;

vector <ll> adj[mx_sz], last(mx_sz, -1), ans;

int dfs(int source, int val)
{
    if(last[source]!=-1)    
    {
        if(val-last[source]>=3)
        {
            ans.push_back(source);
            return source;
        }
        
        return -1;
    }
    
    last[source] = val;
    
    for(auto i : adj[source])
    {
        int f = dfs(i, val+1);
        
        if(f!=-1)
        {
            ans.push_back(source);
            
            if(ans.back()==ans.front())
                return -1;
            else    return source;
        }
    }

    // last[source] = -1;

    return -1;
}

void solve()
{
    cin >> n >> m;

    for(int i=0; i<m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
    {
        if(last[i] != -1)   continue;
        ans.clear();
        dfs(i, 1);
        if(sz(ans)>3) 
        {
            int idx=-1;

            for(int i=1; i<sz(ans); i++)
            {
                if(ans[i]==ans[0])
                {
                    idx = i;
                    break;
                }
            }

            cout << idx+1 << nl;

            for(int i=0; i<=idx; i++)
                cout << ans[i] << sp;

            cout << nl;

            return;
        }
    }

    cout << "IMPOSSIBLE" << nl;

    return;
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
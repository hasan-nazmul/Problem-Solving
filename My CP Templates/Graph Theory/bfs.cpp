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

int main()
{
    int nodes, edges;

    cin >> nodes >> edges;

    vector <int> adj_list[nodes+1];

    for(int i=0; i<edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    vector <int> level(nodes+1, -1), bfs;

    int starting = 1;

    level[starting] = 0;

    queue <int> q;

    q.push(starting);

    while(!q.empty())
    {
        int curr = q.front();
        bfs.push_back(curr);
        q.pop();
        for(auto it=adj_list[curr].begin(); it!=adj_list[curr].end(); ++it)
        {
            if(level[*it]==-1)
            {
                q.push(*it);
                level[*it] = level[curr]+1;
            }
        }
    }

    for(auto i : bfs)
        cout << i << sp;

    cout << nl;

    for(int i=1; i<=nodes; i++)
    {
        cout << i << " : " << level[i] << nl;
    }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fr(i, n) for (ll i = 0; i < n; i++)

const int MAXN = 100005;
ll parent[MAXN];
ll color[MAXN];
vector<vector<ll>> adj(MAXN);
vector<ll> cycle;

bool dfs(ll node, ll par) {
    color[node] = 1; // Mark as visiting (gray)
    parent[node] = par;
    
    for (auto child : adj[node]) {
        if (child == par) continue; // Skip parent
        
        if (color[child] == 0) { // Unvisited node (white)
            if (dfs(child, node)) {
                return true;
            }
        } 
        else if (color[child] == 1) { // Back edge found - cycle detected
            // Reconstruct the cycle
            cycle.push_back(child);
            ll cur = node;
            while (cur != child) {
                cycle.push_back(cur);
                cur = parent[cur];
            }
            cycle.push_back(child); // Close the cycle
            return true;
        }
    }
    
    color[node] = 2; // Mark as fully processed (black)
    return false;
}

int main() {
    fastio;
    ll n, m;
    cin >> n >> m;
    
    // Initialize arrays
    memset(color, 0, sizeof(color));
    memset(parent, -1, sizeof(parent));
    
    // Build graph
    while (m--) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    // Perform DFS from each unvisited node
    for (ll i = 1; i <= n; i++) {
        if (color[i] == 0) {
            if (dfs(i, -1)) {
                // Cycle found - print it
                cout << cycle.size() << "\n";
                for (auto node : cycle) {
                    cout << node << " ";
                }
                cout << "\n";
                return 0;
            }
        }
    }
    
    // No cycle found
    cout << "IMPOSSIBLE\n";
    return 0;
}
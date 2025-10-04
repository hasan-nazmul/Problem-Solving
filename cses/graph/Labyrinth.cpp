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

    vector <string> grid(n), dir;

    for(auto &i : grid)
        cin >> i;

    dir = grid;

    queue <pair <int, int>> q;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            if(grid[i][j]=='A')
            {
                q.push({i,j});
                break;
            }
    }

    int dx[] = {0, 0, -1, +1};
    int dy[] = {-1, +1, 0, 0};
    string ds = "LRUD";

    bool found = 0;

    pair <int, int> finish;

    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();

        if(grid[curr.first][curr.second]=='B')
        {
            found = 1;
            finish = curr;
            break;
        }
        
        for(int i=0; i<4; i++)
        {
            int nx = curr.first+dx[i];
            int ny = curr.second+dy[i];
            
            if(nx<0 or nx>=n or ny<0 or ny>=m)
            continue;
            
            
            if(grid[nx][ny]=='.' or grid[nx][ny]=='B')
            {
                if(grid[nx][ny]=='.')
                    grid[nx][ny] = '$';
                dir[nx][ny] = ds[i];
                q.push({nx, ny});
            }
        }
    }

    if (!found)
    {
        NO;
        return;
    }

    YES;

    string path;

    while(dir[finish.first][finish.second]!='A')
    {
        path.push_back(dir[finish.first][finish.second]);
        switch (dir[finish.first][finish.second])
        {
            case 'U':
                finish.first++;
                break;
            case 'D':
                finish.first--;
                break;
            case 'L':
                finish.second++;
                break;
            case 'R':
                finish.second--;
                break;
            default:
                break;
        }
    }

    cout << sz(path) << nl;

    reverse(all(path));

    cout << path << nl;
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
/// Bismillahir Rahmanir Rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define pr pair <ll, ll>
#define sp ' '
#define mod(a, b) (((a) % (b)) + (b)) % (b)
#define sz(v) (int) v.size()

const int mx = 1e3+10;

int n, m;

string grid[mx];

int dist[mx][mx], path[mx][mx];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(dist, -1, sizeof(dist));
    memset(path, -1, sizeof(path));

    cin >> n >> m;

    for(int i=1; i<=n; i++)
    {
        string s;
        cin >> s;
        grid[i] = '#' + s;
    }

    auto valid_idx = [&](int x, int y)
    {
        return x > 0 and x <= n and y > 0 and y <= m;
    };

    queue <pair <int, int>> bfs;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(grid[i][j]=='M')
            {
                dist[i][j] = 0;
                bfs.push({i,j});
            }
        }
    }

    int dx[] = {0, 0, +1, -1};
    int dy[] = {+1, -1, 0, 0};

    while(!bfs.empty())
    {
        auto curr = bfs.front();
        bfs.pop();

        for(int i=0; i<4; i++)
        {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];

            if(!valid_idx(nx, ny) or dist[nx][ny]!=-1)  
                continue;

            else if(valid_idx(nx, ny) and grid[nx][ny]=='#')
                continue;

            bfs.push({nx,ny});
            dist[nx][ny] = dist[curr.first][curr.second] + 1;
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(grid[i][j]=='A')
            {
                bfs.push({i,j});
                path[i][j] = 0;
            }
        }
    }

    bool found = 0;

    pair <int, int> it;

    while(!bfs.empty())
    {
        auto curr = bfs.front();
        bfs.pop();

        if(!curr.first or !curr.second or curr.first==n or curr.second==m)
        {
            found = 1;
            it = curr;
            break;
        }

        for(int i=0; i<4; i++)
        {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];

            if(!valid_idx(nx, ny) or path[nx][ny]!=-1)
                continue;

            else if(valid_idx(nx, ny))
            {
                if(grid[nx][ny]!='.' or dist[nx][ny]<=path[curr.first][curr.second]+1)
                    continue;
            }

            bfs.push({nx,ny});
            path[nx][ny] = path[curr.first][curr.second] + 1;
        }
    }

    if(!found)
    {
        cout << "NO" << nl;
        return;
    }

    string ans;

    while(path[it.first][it.second])
    {

    }

    return 0;
}
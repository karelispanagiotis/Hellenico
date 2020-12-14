#include <bits/stdc++.h>
using namespace std;

int n, ans, idx[100005], counts[2][100005], board[3][100005];
bool deleted[100005];
vector<int> adj[100005];
queue<int> q;

void bfs(int col)
{
    q.push(col);
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        if(deleted[x]) continue;
        
        deleted[x] = true; 
        ans++;

        if(--counts[0][ board[1][x] ] == 0) 
            q.push(idx[ board[1][x] ]);
        if(--counts[1][ board[2][x] ] == 0) 
            q.push(idx[ board[2][x] ]);
        for(auto u : adj[ board[0][x] ])
            q.push(u);
    }
}

int main()
{
#ifdef CONTEST
    freopen("physics.in", "r", stdin);
    freopen("physics.out", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &board[0][i]);
        idx[board[0][i]] = i;
    }

    for(int i=1; i<3; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &board[i][j]);
            counts[i-1][board[i][j]]++;
            adj[board[i][j]].push_back(j);
        }
    }

    for(int i=1; i<=n; i++)
        if((counts[0][i]==0 || counts[1][i]==0) && !deleted[idx[i]])
            bfs(idx[i]);

    printf("%d\n", ans);
    return 0;
}
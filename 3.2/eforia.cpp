#include <bits/stdc++.h>
using namespace std;

int N, M, start, finish;
bool processed[1000005];
long long cost, dist[1000005];
vector<pair<int,int>> adj[1000005];

long long dijkstra()
{
    for(int i=1; i<=N; i++)
        dist[i] = 1e18;
    priority_queue<pair<int,int>> q;
    dist[start] = 0;
    q.push({0,start});
    while(!q.empty())
    {
        int v=q.top().second; q.pop();
        if(processed[v]) continue;
        processed[v] = true;

        for(auto e : adj[v])
        {
            int u=e.first, w=e.second;
            if(dist[v]+w < dist[u])
            {
                dist[u] = dist[v]+w;
                q.push({-dist[u], u});
            }
        }
    }
    return dist[finish];
}

int main()
{
#ifdef CONTEST
    freopen("eforia.in", "r", stdin);
    freopen("eforia.out", "w", stdout);
#endif
    scanf("%d%d", &N, &M);
    for(int a,b,w,i=0; i<M; i++)
    {
        scanf("%d%d%d", &a, &b, &w);
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
        cost += w;
    }

    for(int i=1; i<=N; i++)
        if(adj[i].size()%2)
            if(start==0) start =i;
            else finish = i;
    cost += dijkstra();
    printf("%lld\n", cost);
    return 0;
}
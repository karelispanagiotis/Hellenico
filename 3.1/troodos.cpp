#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int N, M, wait, counter, early[10005], late[10005], critical[10005];
vector<pii> adj[10005];

int main()
{
#ifdef CONTEST
    freopen("troodos.in", "r", stdin);
    freopen("troodos.out", "w", stdout);
#endif
    scanf("%d%d", &N, &M);
    for(int i=1; i<N; i++) early[i] = 1e9+5;
    for(int a,b,w,i=0; i<M; i++)
    {
        scanf("%d%d%d", &a, &b, &w);
        adj[a].push_back(make_pair(b,w));
    }

    // Vertexes are topologically sorted already (since A<B)
    for(int v=0; v<N; v++)
    {
        wait += late[v]-early[v];

        for(auto e : adj[v])
        {
            int u=e.first, w=e.second;
            late [u] = max(late [u], late[v] + w);
            early[u] = min(early[u], late[v] + w);
        }
    }

    critical[N-1] = true; 
    for(int v=N-2; v>=0; v--)
    {
        for(auto e : adj[v])
        {
            int u=e.first, w=e.second;
            if(critical[u] && late[v]+w==late[u])
                critical[v] = true;
        }
        if(!critical[v]) counter++;
    }    
    printf("%d %d %d\n", late[N-1], wait, counter);
    return 0;
}
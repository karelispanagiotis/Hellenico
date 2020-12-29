#include <bits/stdc++.h>  
using namespace std;  
  
typedef pair<int,int> pii;  
  
int N, M, rnk[50005], p[50005], used[100005];  
vector<pii> adj[50005];  
pair<int, pii> edges[100005];  
  
// Union-Find Data Structure  
int findSet(int v) { return p[v]==v ? v : p[v]=findSet(p[v]); }  
bool isSameSet(int v, int w) { return findSet(v) == findSet(w); }  
void unionSet(int v, int w)  
{  
    if(isSameSet(v,w)) return;  
  
    int x=findSet(v), y=findSet(w);  
    if(rnk[x]>rnk[y])  
        p[y] = x;  
    else  
    {  
        p[x] = y;  
        if(rnk[x]==rnk[y]) rnk[y]++;  
    }  
}  
  
//Lowest Common Ancestor with Binary Lifting  
int timer, tin[50005], tout[50005], up[50005][20], dp[500005][20];  
void dfs(int v, int p, int w)  
{  
    tin[v] = ++timer;  
    up[v][0] = p;  
    dp[v][0] = w;  
    for(int i=1; i<=ceil(log2(N)); i++)  
    {  
        up[v][i] = up[up[v][i-1]][i-1];  
        dp[v][i] = max(dp[v][i-1], dp[up[v][i-1]][i-1]);  
    }  
  
    for(auto u : adj[v])  
        if(u.first != p)  
            dfs(u.first, v, u.second);  
      
    tout[v] = ++timer;  
}  
  
bool is_ancestor(int u, int v) { return tin[u]<=tin[v] && tout[u]>=tout[v]; }  
  
int lca(int u, int v)  
{  
    if(is_ancestor(u,v)) return u;  
    if(is_ancestor(v,u)) return v;  
  
    for(int i=ceil(log2(N)); i>=0; i--)  
        if(!is_ancestor(up[u][i], v))  
            u = up[u][i];  
      
    return up[u][0];  
}  
  
int max_edge_parent(int u, int p)  
{  
    int maxW = 0;  
    for(int i=ceil(log2(N)); i>=0; i--)  
        if(!is_ancestor(up[u][i], p))  
        {  
            maxW = max(maxW, dp[u][i]);  
            u = up[u][i];  
        }  
    return max(maxW, dp[u][0]);  
}  
  
int max_edge(int u, int v)  
{  
    int LCA = lca(u, v);  
    if(LCA==u) return max_edge_parent(v, u);  
    if(LCA==v) return max_edge_parent(u, v);  
  
    return max(max_edge_parent(u,LCA), max_edge_parent(v,LCA));  
}  
  
long long min_spanning_tree()  
{  
    for(int i=1; i<=N; i++) p[i] = i;  
    sort(edges, edges+M);  
  
    long long cost=0;  
    for(int i=0; i<M; i++)  
    {  
        int a=edges[i].second.first, b=edges[i].second.second;  
        if(!isSameSet(a,b))  
        {  
            unionSet(a,b);  
            used[i] = true;  
            cost += edges[i].first;  
            adj[a].push_back(make_pair(b,edges[i].first));  
            adj[b].push_back(make_pair(a,edges[i].first));  
        }  
    }  
    return cost;  
}  
  
int main()  
{  
#ifdef CONTEST  
    freopen("christmas.in", "r", stdin);  
    freopen("christmas.out", "w", stdout);  
#endif  
    scanf("%d%d", &N, &M);  
    for(int a,b,w,i=0; i<M; i++)  
    {  
        scanf("%d%d%d", &a, &b, &w);  
        edges[i] = make_pair(w, make_pair(a,b));          
    }  
      
    long long best1 = min_spanning_tree();  
    dfs(1,1,0);  
  
    long long best2 = 1e18;  
    for(int i=0; i<M; i++)  
        if(!used[i])  
        {  
            int a=edges[i].second.first, b=edges[i].second.second;  
            long long diff = edges[i].first - max_edge(a,b);  
            best2 = min(best2, best1 + diff);  
        }  
    printf("%lld %lld \n", best1, best2);  
    return 0;  
} 
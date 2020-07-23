#include <bits/stdc++.h>
#define MAXN 55

using namespace std;

int N, val;
bool visited[MAXN];
set<int> targets;
vector<int> adj[MAXN], inevitable, divider;

bool search_targets(int v, int avoid)
{
    if(visited[v])  return false;
    if(targets.find(v) != targets.end()) return true;
    visited[v] = true;

    bool result = false;
    for(auto u : adj[v])
        if(u!=avoid) 
            result |= search_targets(u, avoid);
    return result;
}

void compose_first_half(int v, int stop)
{
    if(v==stop || visited[v]) return;

    visited[v] = true;
    targets.insert(v);
    for(auto u : adj[v])
        compose_first_half(u, stop);
}

int main()
{
#ifdef CONTEST
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
#endif
    for(N=0; scanf("%d", &val) && val!=-1; N++)
        for(; val!=-2; scanf("%d", &val)) 
            adj[N].push_back(val);
    N--;

    // if you can't reach N from node 0, trying to avoid a node,
    // then this node is inevitable.
    targets.insert(N);
    for(int avoid=1; avoid<N; avoid++)
    {
        memset(visited, false, N); 
        if(!search_targets(0, avoid))
            inevitable.push_back(avoid);
    }

    // For each inevitable node, seperate the circuit into two halves.
    // If you can reach the first half starting from an inevitable node,
    // then this node is not a divider.
    for(auto inev : inevitable)
    {
        targets.clear();
        memset(visited, false, N);
        compose_first_half(0, inev);

        memset(visited, false, N);
        if(!search_targets(inev, -1))
            divider.push_back(inev);
    }

    printf("%lu ", inevitable.size());
    for(auto u : inevitable) printf("%d ", u);
    printf("\n%lu ", divider.size());
    for(auto u : divider) printf("%d ", u);

    return 0;
}
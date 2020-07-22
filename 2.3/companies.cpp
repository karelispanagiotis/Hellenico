#include <bits/stdc++.h>
#define MAXN 105

using namespace std;

int n, a, b, w, adj[MAXN][MAXN], shares[MAXN][MAXN], visited[MAXN][MAXN];

void find_shares(int start, int current)
{
    if(visited[start][current]) return;
    visited[start][current] = true;

    for(int i=1; i<=100; i++) shares[start][i] += adj[current][i];
    for(int i=1; i<=100; i++) if(shares[start][i]>50 && i!=current) find_shares(start, i);
}

int main()
{
#ifdef CONTEST
    freopen("companies.in", "r", stdin);
    freopen("companies.out", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d %d", &a, &b, &w);
        adj[a][b] += w;
    }

    for(int i=1; i<=100; i++)
    {
        find_shares(i, i);
        for(int j=1; j<=100; j++)
            if(shares[i][j]>50 && j!=i)
                printf("%d %d\n", i, j);
    }

    return 0;
}
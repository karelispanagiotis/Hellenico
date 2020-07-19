#include <bits/stdc++.h>
#define MAXN 55

using namespace std;

vector<pair<int,int>> deltas = {{0,-1}, {-1,0}, {0,1}, {1,0}};
int n, m, rooms, max_sz, castle[MAXN][MAXN], cmp[MAXN][MAXN], cmp_sz[MAXN*MAXN];
bool added[MAXN][MAXN];

void dfs(int i, int j, int comp)
{
    if(added[i][j])    
        return;

    added[i][j]=true; cmp[i][j]=comp; cmp_sz[comp]++;

    for(int k=0; k<4; k++)
        if( 1<<k & ~castle[i][j])
            dfs(i + deltas[k].first, j + deltas[k].second, comp);
}

int main()
{
#ifdef CONTEST
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
#endif
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%d", &castle[i][j]);

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(added[i][j]) continue;
            
            rooms++;
            dfs(i, j, rooms);
            max_sz = max(max_sz, cmp_sz[rooms]);
        }
    }
    printf("%d\n%d\n", rooms, max_sz);

    int x=0, y=0; char orient;
    for(int j=1; j<=m; j++)
    {
        for(int i=n; i>=1; i--)
        {
            int comp=cmp[i][j], sz=cmp_sz[comp];
            if((2 & castle[i][j]) && comp!=cmp[i-1][j] && sz+cmp_sz[cmp[i-1][j]]>max_sz)
            {
                max_sz = sz + cmp_sz[cmp[i-1][j]];
                x=i; y=j; orient='N';
            }
            if((4 & castle[i][j]) && comp!=cmp[i][j+1] && sz+cmp_sz[cmp[i][j+1]]>max_sz)
            {
                max_sz = sz + cmp_sz[cmp[i][j+1]];
                x=i; y=j; orient='E';
            }
        }
    }
    printf("%d\n", max_sz);
    printf("%d %d %c\n", x, y, orient);

    return 0;
}
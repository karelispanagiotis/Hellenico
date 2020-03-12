#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> dims;
int n, m, surface[105][105];

int count_moves(int dim1, int dim2, int x, int y)
{
    if(x+dim1>n || y+dim2>n)
        return __INT_MAX__;

    int moves = 0;
    for(int i=x; i<x+dim1; i++)
        for(int j=y; j<y+dim2; j++)
            if(surface[i][j]==0)
                moves++;
    return moves;
}

int main()
{
    freopen("nered.in", "r", stdin);
    freopen("nered.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for(int i=1; i<=m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        surface[x-1][y-1]++;
        if(m%i==0) 
            dims.push_back( {i,m/i} );
    }
    
    int least = __INT_MAX__;
    for(auto i : dims)
        for(int x=0; x<n; x++)
            for(int y=0; y<n; y++)
                least = min(least, count_moves(i.first, i.second, x, y));

    printf("%d", least);
    return 0;
}

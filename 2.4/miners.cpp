#include <bits/stdc++.h>
using namespace std;

char ch;
int n, loads[100005], dp[100005][5][5][5][5];

int calc_coal(int food, int y, int yy)
{
    int ret = 0;
    for(int i=1; i<=3; i++)
        if(food==i || y==i || yy==i)
            ret++;
    return ret;
}

int main()
{
#ifdef CONTEST
    freopen("miners.in", "r", stdin);
    freopen("miners.out", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf(" %c", &ch);
        if(ch=='M') loads[i] = 1;
        if(ch=='B') loads[i] = 2;
        if(ch=='F') loads[i] = 3;
    }

    for(int i=n; i>=1; i--)
        for(int j=0; j<4; j++)
            for(int k=0; k<4; k++)
                for(int l=0; l<4; l++)
                    for(int m=0; m<4; m++)
                    {
                        int c1 = calc_coal(loads[i], j, k);
                        int c2 = calc_coal(loads[i], l, m);
                        dp[i][j][k][l][m] = max(
                            dp[i+1][loads[i]][j][l][m] + c1,
                            dp[i+1][j][k][loads[i]][l] + c2 );
                    }

    printf("%d\n", dp[1][0][0][0][0]);
    return 0;
}
#include <bits/stdc++.h>

int n, best, triangle[105][105], dp[105][105];

int main()
{
#ifdef CONTEST
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++)
            scanf("%d", &triangle[i][j]);

    dp[1][1] = triangle[1][1];
    for(int i=2; i<=n; i++)
        for(int j=1; j<=i; j++)
            dp[i][j] = triangle[i][j] + std::max(dp[i-1][j], dp[i-1][j-1]);

    for(int i=1; i<=n; i++) 
        best = std::max(best, dp[n][i]);

    printf("%d\n", best);
    return 0;
}
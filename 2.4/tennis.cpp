#include <bits/stdc++.h>
#define MAXN 100005

using namespace std;

long long t, n, sum, d[MAXN], pre_sum[MAXN];

int main()
{
#ifdef CONTEST
    freopen("tennis.in", "r", stdin);
    freopen("tennis.out", "w", stdout);
#endif
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        for(int i=1; i<=n; i++)
            scanf("%lld", &d[i]);
        
        // Erdos-Gallai Theorem
        sort(d+1, d+n+1, greater<int>());
        
        for(int i=1; i<=n; i++)
            pre_sum[i] = pre_sum[i-1] + d[i];

        bool possible = true;
        if(pre_sum[n]%2) 
            possible = false;
        for(long long k=1; k<=n && possible; k++)
        {
            auto i = lower_bound(d+k+1, d+n+1, k, greater<int>()) - d;
 
            sum = k*(i-k-1) + (pre_sum[n] - pre_sum[i-1]);

            if(pre_sum[k] > k*(k-1) + sum)
                possible = false;
        }

        printf("%s\n", possible ? "Possible" : "Not possible"); 
    }

    return 0;
}
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define YR_RNG 100000

int n, growth_rate[2*YR_RNG];

int main()
{
    freopen("crocodiles.in", "r", stdin);
    freopen("crocodiles.out", "w", stdout);
    
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int b, d;
        scanf("%d %d", &b, &d);
        growth_rate[b+YR_RNG]++;
        growth_rate[d+YR_RNG]--;
    }

    int best = 0, sum = 0;
    for(int k=0; k<2*YR_RNG; k++)
    {
        sum  = std::max(growth_rate[k], sum+growth_rate[k]);
        best = std::max(sum, best);
    }
    printf("%d", best);
    return 0;
}

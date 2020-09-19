#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define YR_RNG 100000

int n, b, d, best, sum, growth_rate[2*YR_RNG];

int main()
{
#ifdef CONTEST
    freopen("crocodiles.in", "r", stdin);
    freopen("crocodiles.out", "w", stdout);
#endif

    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d", &b, &d);
        growth_rate[b+YR_RNG]++;
        growth_rate[d+YR_RNG]--;
    }

    //Sum from 0 to k is the number of living crocodiles in year k.
    for(int k=0; k<2*YR_RNG; k++)
    {
        sum  += growth_rate[k]; 
        best = std::max(sum, best);
    }
    printf("%d\n", best);
    return 0;
}

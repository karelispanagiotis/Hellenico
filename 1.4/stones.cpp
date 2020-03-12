#include <cstdio>
#include <cstdlib>
#include <algorithm>

struct stone{
    double m, v, d;
    bool operator<(const stone &s) const {return d < s.d;}
};

stone stones[1000005];

int main()
{
    freopen("stones.in", "r", stdin);
    freopen("stones.out", "w", stdout);

    int n, i;
    double z;
    scanf("%d %lf", &n, &z);
    for(i=0; i<n; i++)
    {
        scanf("%lf %lf", &stones[i].v, &stones[i].m);
        stones[i].d = stones[i].m/stones[i].v;
    }

    std::sort(stones, stones+n);

    double mass = 0.0;
    for(i=n-1; z>0 && i>=0; i--)
    {
        mass += stones[i].m;
        z    -= stones[i].v;
    }
    if(z<0) mass += z*stones[++i].d;

    printf("%.3lf", mass);
    return 0;
}

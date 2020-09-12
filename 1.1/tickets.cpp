#include <cstdio>

int main()
{
#ifdef CONTEST
    freopen("tickets.in", "r", stdin);
    freopen("tickets.out", "w", stdout);
#endif

    int n, a, b, c, d, cost;
    scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
    
    if(n<a)              cost = 10*n;
    else if(a<=n && n<b) cost = 9*n;
    else if(b<=n && n<c) cost = 8*n;
    else if(c<=n && n<d) cost = 7*n;
    else                 cost = 5*n;

    if(n<a && 9*a<cost) cost = 9*a;
    if(n<b && 8*b<cost) cost = 8*b;
    if(n<c && 7*c<cost) cost = 7*c;
    if(n<d && 5*d<cost) cost = 5*d;

    printf("%d\n", cost);
    return 0;
}

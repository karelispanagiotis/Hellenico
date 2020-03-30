#include <bits/stdc++.h>
#define ll long long int

using namespace std;

long long int min_cubes(ll l, ll w, ll h)
{
    if(l==0 || w==0 || h==0)
        return 0;
    
    ll min_dim = min(min(l,w), min(w,h));
    ll max_sz = 1<<(31 - __builtin_clz(min_dim));
    ll count = (l/max_sz)*(w/max_sz)*(h/max_sz);
    return count + min_cubes(l%max_sz, w, h) 
                 + min_cubes(l-l%max_sz, w%max_sz, h) 
                 + min_cubes(l-l%max_sz, w-w%max_sz, h%max_sz);
}

int main()
{
    freopen("fillbox.in", "r", stdin);
    freopen("fillbox.out", "w", stdout);

    ll l, w, h;
    scanf("%lld %lld %lld", &l, &w, &h);
    printf("%lld", min_cubes(l, w, h));
    return 0;
}
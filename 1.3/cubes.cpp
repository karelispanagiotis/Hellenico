#include <cstdio>
#include <cstdlib>

int n, k;

int min_cubes(int h)
{
    int cubes = 0;
    for(int i=0; i<h/k; i++)
        cubes += h - i*k;
    cubes += h%k;
    return cubes;
}

int main()
{
    freopen("cubes.in", "r", stdin);
    freopen("cubes.out", "w", stdout);

    scanf("%d %d", &n, &k);
    int h = 0; 
    for(int b=2*n; b>=1; b/=2)
        while(min_cubes(h+b)<=n) 
            h += b;
    
    printf("%d", h);
    return 0;
}

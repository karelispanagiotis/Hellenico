#include <cstdio>
#include <cstdlib>
#include <algorithm>

int n, w[100005];

int main()
{
    freopen("elevator.in", "r", stdin);
    freopen("elevator.out", "w", stdout);

    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &w[i]);
    
    std::sort(w, w+n);

    int max = w[n-1], lifts = n/2;
    if(n%2)
    {
        lifts++;
        n--;
    }

    for(int i=0; i<n/2; i++)
        max = std::max(max, w[i]+w[n-1-i]);
    
    printf("%d %d", lifts, max);
    return 0;
}
 
#include <cstdio>
#include <cstdlib>
#include <algorithm>

bool ones[1005];
int w[1005];
int n;

int main()
{
    freopen("acropolis.in", "r", stdin);
    freopen("acropolis.out", "w", stdout);

    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &w[i]);
        ones[i] = w[i]==1 ? true : false;
    }

    std::sort(w, w + n);

    int j = std::upper_bound(w,w+n,1) - w;
    for(int i=0; i<n; i++)
    {
        if(ones[i]==false)
        {
            printf("%d\n", w[j]);
            j++;
        }
        else
            printf("1\n");
    }
    return 0;
}

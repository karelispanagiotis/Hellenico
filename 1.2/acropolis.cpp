#include <bits/stdc++.h>
using namespace std;

int n, ones[1005], w[1005];

int main()
{
    freopen("acropolis.in", "r", stdin);
    freopen("acropolis.out", "w", stdout);

    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &w[i]);
        if(w[i]==1) ones[i]=1, w[i]=9001;
    }

    sort(w, w + n);

    int j = 0;
    for(int i=0; i<n; i++)
        if(ones[i]==1) printf("1\n");
        else           printf("%d\n", w[j++]);

    return 0;
}

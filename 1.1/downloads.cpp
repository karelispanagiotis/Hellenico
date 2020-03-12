#include <cstdio>
#include <cmath>

int main()
{
    FILE *input  = freopen("downloads.in", "r", stdin);
    FILE *output = freopen("downloads.out", "w", stdout);

    int n;
    scanf("%d", &n);

    int size = 0, bandwidth = 0;
    int x, t;
    for(int i=0; i<n; i++)
    {
        scanf("%d %d", &x, &t);
        bandwidth += x;
        size += x*t;
    }

    printf("%d", (int) round( (double)size/bandwidth ));

    fclose(input);
    fclose(output); 
    return 0;
}

#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define CONTEST

int recs[1005], area_recs[4][4], count[4];

int greedy_swap(int areaA, int areaB)
{
    int swaps = std::min(area_recs[areaA][areaB], area_recs[areaB][areaA]);
    area_recs[areaA][areaB] -= swaps;
    area_recs[areaB][areaA] -= swaps;
    return swaps;
}

int main()
{
#ifdef CONTEST
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &recs[i]);
        count[ recs[i] ]++;
    }

    for(int i=0; i<n; i++)
    {
        int area;
        if(i<count[1]) area = 1;
        else if(i<count[1] + count[2]) area = 2;
        else area = 3;
        area_recs[area][ recs[i] ]++;
    }
    
    int swaps = greedy_swap(1, 2);
    swaps += greedy_swap(1, 3);
    swaps += greedy_swap(2, 3);
    swaps += 2*(area_recs[1][2] + area_recs[1][3]);

    printf("%d", swaps);

    return 0;
}

#include <cstdio>
#include <vector>
#include <bits/stdc++.h>

std::vector<std::pair<int,int>> intervals;

int main()
{
    freopen("rentacar.in", "r", stdin);
    freopen("rentacar.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int start, end;
        scanf("%*d %d %d", &start, &end);
        intervals.push_back(std::make_pair(end, start));
    }

    std::sort(intervals.begin(), intervals.end());

    int clients=1, k=0;
    for(int i=0; i<n; i++)
    {
        if(intervals[i].second > intervals[k].first)
        {
            clients++;
            k = i;
        }
    }

    printf("%d", clients);    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, sum, numbers[105], value[105][105];
bool ready[105][105];

int best(int i, int j)
{
    if(i>j) return 0;
    if(ready[i][j]) return value[i][j];

    ready[i][j] = true;
    value[i][j] = max(numbers[i] + min(best(i+2,j),best(i+1, j-1)), 
                      numbers[j] + min(best(i+1,j-1),best(i,j-2)));

    return value[i][j];
}

int main()
{    
    freopen("ngame.in", "r", stdin);
    freopen("ngame.out", "w", stdout);

    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    int score1 = best(0, n-1);
    int score2 = sum - score1;
    printf("%d %d", score1, score2);
    return 0;
}
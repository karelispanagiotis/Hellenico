#include <cstdio>
#include <cstdlib>
#include <map>

#define CONTEST

int n, k;
char sequence[1005];

int rep_count(int period)
{
    int reps = 0;
    for(int i=0; i<period; i++)
    {
        std::map<char, int> nuclei_count;
        for(int j=i; j<n; j+=period)
            nuclei_count[ sequence[j] ]++;

        int max = -1;
        for(auto j : nuclei_count)
            max = std::max(max, j.second);

        reps += n/period + ( i<n%period ? 1 : 0 ) - max;
    }

    return reps;
}

int main()
{
#ifdef CONTEST
    freopen("dna.in", "r", stdin);
    freopen("dna.out", "w", stdout);
#endif
    scanf("%d %d", &n , &k);
    scanf("%s", sequence);

    int min_reps = __INT_MAX__;
    for(int i=1; i<=k; i++)
        min_reps = std::min(min_reps, rep_count(i));

    printf("%d", min_reps);
    return 0;
}

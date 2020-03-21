#include <cstdio>
#include <bits/stdc++.h>

int n, m, k, ans, in_data[10][7], sequence[5];

bool isOk()
{
    int cpy_in[10][7], copy_seq[5];
    memcpy(cpy_in, in_data, 10*7*sizeof(int));

    for(int a=0; a<n; a++)
    {
        memcpy(copy_seq, sequence, 5*sizeof(int));
        int unmoved = 0;
        for(int i=0; i<k; i++)
        {
            if(cpy_in[a][i]==copy_seq[i])
            {
                copy_seq[i] = cpy_in[a][i] = 0;
                unmoved++;
            }
        }

        int permutated = 0;
        for(int i=0; i<k; i++)
        {
            for(int j=0; j<k; j++)  //Search copy_seq
            {
                if(copy_seq[j]==cpy_in[a][i] && copy_seq[j]!=0)
                {
                    copy_seq[j] = cpy_in[a][i] = 0;
                    permutated++;
                }
            }
        }
        if(unmoved!=cpy_in[a][k] || permutated!=cpy_in[a][k+1])
            return false;
    }
    return true;
}

void search(int pos)
{
    if(pos==k)
    {
        if(isOk()) ans++;
        return;
    }
    for(int i=1; i<=m; i++)
    {
        sequence[pos] = i;
        search(pos+1);
    }
}

int main()
{
    freopen("mastermind.in", "r", stdin);
    freopen("mastermind.out", "w", stdout);

    scanf("%d %d %d", &n, &m, &k);
    for(int i=0; i<n; i++)
        for(int j=0; j<k+2; j++)
            scanf("%d", &in_data[i][j]);

    search(0);

    printf("%d", ans);
    return 0;
}
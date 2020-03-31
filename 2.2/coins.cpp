#include <bits/stdc++.h>

bool state[1000005];

int main()
{
    freopen("coins.in", "r", stdin);
    freopen("coins.out", "w", stdout);

    int k, l, m, n;
    scanf("%d %d %d", &k, &l, &m);

    state[1] = state[k] = state[l] = true;
    for(int i=2; i<1000001; i++)
    {
        if(i==k || i==l) continue;

        bool next = state[i-1];
        if(i>k) next &= state[i-k];
        if(i>l) next &= state[i-l];

        state[i] = (next==true) ? false : true;
    }

    while(m--)
    {
        scanf("%d", &n);
        if(state[n]) printf("A");
        else         printf("B");
    }
    
    return 0;   
}
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int N, W, p[205], rnk[205], forgotten[6005];  
pair<int, pii> edges[6005], temp;

int findSet(int v) { return (p[v]==v) ? v : p[v]=findSet(p[v]); }  
bool isSameSet(int v, int w) { return findSet(v)==findSet(w); }  
void unionSet(int v, int w)  
{  
    if(isSameSet(v,w)) return;  
        
    int x=findSet(v), y=findSet(w);  
    if(rnk[x]>rnk[y])   
        p[y] = x;  
    else  
    {  
        p[x] = y;  
        if(rnk[x]==rnk[y])  
            rnk[y]++;  
    }  
}  

ll mst(int M)
{
    for(int i=0; i<=N; i++) 
        p[i]=i, rnk[i]=0;
    
    ll min_w=0, numCC=N;
    for(int i=0; i<M; i++)
    {
        int a=edges[i].second.first, b=edges[i].second.second;
        if(!isSameSet(a,b) && !forgotten[i])
        {
            unionSet(a,b);
            numCC--;
            min_w += edges[i].first;
        }
        else
            forgotten[i] = true;
    }

    if(numCC!=1)
    {
        memset(forgotten, false, sizeof(forgotten));
        return -1;
    }
    else return min_w;
}

int main()
{
#ifdef CONTEST
    freopen("maintain.in", "r", stdin);
    freopen("maintain.out", "w", stdout);
#endif 
    scanf("%d%d", &N, &W);
    for(int a,b,w,i=0; i<W; i++)
    {
        scanf("%d%d%d", &a, &b, &w);
        temp = make_pair(w, make_pair(a,b));
        
        int j=i-1;
        while(j>=0 && edges[j]>temp)
        {
            edges[j+1]=edges[j], forgotten[j+1]=forgotten[j];
            j--;
        }
        edges[j+1]=temp, forgotten[j+1]=false;

        ll weight = mst(i+1); 
        printf("%lld\n", weight);
    }
    return 0;
}
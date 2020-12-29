#include <bits/stdc++.h>  
typedef std::pair<int, int> pii;  
    
int n, m, B, p[20005], rank[20005];  
std::pair<long long, pii> bridge[1000005];  
    
int findSet(int v) { return (p[v]==v) ? v : p[v]=findSet(p[v]); }  
bool isSameSet(int v, int w) { return findSet(v)==findSet(w); }  
void unionSet(int v, int w)  
{  
    if(isSameSet(v,w)) return;  
        
    int x=findSet(v), y=findSet(w);  
    if(rank[x]>rank[y])   
        p[y] = x;  
    else  
    {  
        p[x] = y;  
        if(rank[x]==rank[y])  
            rank[y]++;  
    }  
}  
    
int main()  
{  
#ifdef CONTEST  
    freopen("resistance.in","r",stdin);  
    freopen("resistance.out","w",stdout);  
#endif  
    scanf("%d%d%d",&n,&m,&B);  
    for (int i=1; i<=n; i++)  
        p[i]=i, rank[i]=1;  
    for (int a,b,w,i=0; i<m; i++)  
    {  
        scanf("%d%d%d", &a, &b, &w);  
        bridge[i] = std::make_pair(w, std::make_pair(a,b));  
    }  
    
    std::sort(bridge,bridge+m); 

    //Maximum Spanning Tree
    for (int i=m-1; i>=0; i--)  
    {  
        int v=bridge[i].second.first, w=bridge[i].second.second;  
        if (!isSameSet(v,w))    
        {    
            unionSet(v,w);    
            bridge[i].first=-1;    
        }    
    }  

    int ans=0;      
    for (int i=0; i<m; i++)      
        if (bridge[i].first != -1)      
            if (bridge[i].first > B) break;      
            else B -= bridge[i].first, ans++; 
                
    printf("%d\n", ans);  
    return 0;  
}  

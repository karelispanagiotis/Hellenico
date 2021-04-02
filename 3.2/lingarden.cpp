    #include <bits/stdc++.h>  
    using namespace std;  
      
    int N, M, dp[1000005][5][5][5];  
    bool processed[1000005][5][5][5];  
    char str[1000005];  
      
    int lingarden(int pos, int low, int high, int diff)  
    {  
        if(high-low>2) return 0;  
        if(pos==N) return 1;  
        if(processed[pos][low][high][diff])  
            return dp[pos][low][high][diff];  
      
        int ret = 0;  
        ret = (ret + lingarden(pos+1,low,max(high,diff+1),diff+1))%M; //Put L
        ret = (ret + lingarden(pos+1,min(low,diff-1),high,diff-1))%M; //Put P 
    
        processed[pos][low][high][diff] = true;  
        return dp[pos][low][high][diff] = ret;  
    }  
      
    int main()  
    {  
    #ifdef CONTEST  
        freopen("lingarden.in", "r", stdin);  
        freopen("lingarden.out", "w", stdout);  
    #endif  
        scanf("%d%d%s", &N, &M, str);       

        int ans=0, diff=2, hi=2, lo=2;
        for(int i=0; i<N; i++)
        {
            if(str[i]=='L')
                diff=diff+1, hi=max(hi,diff);
            else
            {
                ans = (ans + lingarden(i+1,lo,max(hi,diff+1),diff+1))%M;
                diff=diff-1;
                lo = min(lo,diff);
            }
        }  

        printf("%d\n", ans+1);
        return 0;  
    }  
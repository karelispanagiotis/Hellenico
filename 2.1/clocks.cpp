#include <cstdio>  
#include <bits/stdc++.h>  
#include <vector>  
    
using namespace std;  

vector<int> init_clocks(9), final_clocks(9), moveset;  
vector<vector<int>> moves = { {0,1,3,4},{0,1,2},{1,2,4,5},{0,3,6},{1,3,4,5,7},{2,5,8},{3,4,6,7},{6,7,8},{4,5,7,8} } ;  
    
void make_moves()  
{  
    for(auto i : moveset)  
        for(auto j : moves[i])  
            ++final_clocks[j] %= 4;   
}           
    
bool check_answer()  
{  
    for(auto i : final_clocks)  
        if(i!=0) return false;  
    return true;  
}                       
    
bool search(int k)  
{  
    if(k==9)  
    {  
        final_clocks = init_clocks;  
        make_moves();  
        if(check_answer()==true)  
            return true;
    }  
    else  
    {   
        for(int i=0; i<4; i++)  
        {  
            if(search(k+1)) return true;
            moveset.push_back(k);  
        }  
        for(int i=0; i<4; i++)   
            moveset.pop_back();  
    }  
    return false;
}  
    
int main()  
{  
    freopen("clocks.in", "r", stdin);  
    freopen("clocks.out", "w", stdout);  

    for(int i=0; i<9; i++)  
        scanf("%d", &init_clocks[i]);  
    
    search(0);  
    
    for(auto i : moveset)  
        printf("%d ", i+1);  
        
    return 0;  
}  
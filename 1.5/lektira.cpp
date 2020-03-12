#include <bits/stdc++.h>
#include <string>

using namespace std;

string str;

string play(int i, int j)
{
    string ret = str;
    reverse(ret.begin(), ret.begin()+i);
    reverse(ret.begin()+i, ret.begin()+j);
    reverse(ret.begin()+j, ret.end());
    return ret;
}

int main()
{
    freopen("lektira.in", "r", stdin);
    freopen("lektira.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> str;
    string best = str;
    for(int i=1; i<str.length()-1; i++)
        for(int j=i+1; j<str.length(); j++)
            best = min(best, play(i, j));
    
    cout << best;
    return 0;
}

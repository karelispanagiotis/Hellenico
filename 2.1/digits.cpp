#include <cstdio>
#include <bits/stdc++.h>

int m, m1;
bool validM = true;
std::bitset<10> mDigits, allDigits;

bool check(int num)
{
    for(int tmp=num; tmp>0; tmp/=10)
        if(allDigits[tmp%10]==true)
            return false;
        else
            allDigits[tmp%10] = true;
    return true;
}

int main()
{
    freopen("digits.in", "r", stdin);
    freopen("digits.out", "w", stdout);

    scanf("%d", &m);
    allDigits[0] = true;
    validM = check(m);

    mDigits = allDigits;
    for(m1=1; m1<9876543 && validM; m1++)
    {
        allDigits = mDigits;
        if(check(m1) && check(m1*m) && allDigits.all())
            break;
    }

    if(m1<9876543 && validM) 
        printf("%d %d", m1, m1*m);
    else      
        printf("0");
    return 0;
}

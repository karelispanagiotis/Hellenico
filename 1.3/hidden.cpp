#include "hiddenlib.h"

int main()
{
    int n = getN();
    int start = 1, end = n;
    while(true)
    {
        int mid = (start+end)/2;
        if(ishidden(mid))
            break;
        
        int comp = compare(start, end);
        if(comp==1) 
            end = mid - 1;
        else if(comp==-1)       
            start = mid + 1;
    }

    return 0;
}

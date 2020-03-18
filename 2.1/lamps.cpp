#include <cstdio>
#include <vector>

bool show_comb[8];
bool combination[8][4] = {  0, 0, 0, 0,     0, 1, 1, 0,     1, 1, 0, 0,
                            1, 0, 1, 0,     0, 1, 0, 1,     0, 0, 1, 1,
                            1, 0, 0, 1,     1, 1, 1, 1  };   

/* ----- LAMP TYPES -----
 *  0: even and not multiple of 3
 *  1: even and multiple of 3
 *  2: odd and not multiple of 3
 *  3: odd and multiple of 3
 */
int lamp_type(int num)
{
    if(num%2)
        if(num%3==1) return 3;
        else         return 2;
    else
        if(num%3==1) return 1;
        else         return 0;
}

/* Reduces combinations to show
 *  \param n : The number of lamp
 *  \param state: Lamp should be ON(1)/OFF(0)  
 */
void reduce(int n, bool state)
{
    if(n==-1)
        return;
    
    for(int i=0; i<8; i++)
        if(combination[i][lamp_type(n)] != state) 
            show_comb[i] = false;
}

int main()
{
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);

    int n_lamp, n_ops, on1, on2=-1, off1, off2=-1;
    scanf("%d %d", &n_lamp, &n_ops);

    scanf("%d", &on1);
    if(on1!=-1) scanf("%d -1", &on2);
    scanf("%d", &off1);
    if(off1!=-1) scanf("%d -1", &off2);

    for(int i=0; i<8; i++) show_comb[i] = true;

    if(n_ops==1)
        show_comb[1] = show_comb[4] = show_comb[6] = show_comb[7] = false;
    else if(n_ops==2)
        show_comb[3] = false;

    reduce(on1, true); reduce(on2, true);
    reduce(off1, false); reduce(off2, false);

    for(int i=0; i<8; i++)
    {
        if(show_comb[i]==false)
            continue;
        for(int j=1; j<=n_lamp; j++)
            printf("%d", combination[i][lamp_type(j)]);
        printf("\n");
    }

    return 0;
}
#include <cstdio>

int ticketPrice[5] = {10, 9, 8, 7, 5};
int numOfPeople[5];

int main()
{
    FILE *input  = freopen("tickets.in", "r", stdin);
    FILE *output = freopen("tickets.out", "w", stdout);

    int n, i;
    scanf("%d", &n);
    for(i=1; i<=4; i++)
        scanf("%d", &numOfPeople[i]);

    for(i=0; i<5 && numOfPeople[i]<n; i++);

    int min = ticketPrice[i-1]*n;

    for(; i<5; i++)
        if(min > ticketPrice[i]*numOfPeople[i]) 
            min = ticketPrice[i]*numOfPeople[i];
    
    printf("%d", min);

    fclose(input);
    fclose(output);
    return 0;
}

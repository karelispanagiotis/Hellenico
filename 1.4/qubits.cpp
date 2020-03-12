#include <cstdio>
#include <cstdlib>

#define CONTEST

void move(int h, char source, char dest, char spare)
{
    if(h==0) 
        return;
    move(h-1, source, spare, dest);
    printf("%c %c\n", source, dest);
    move(h-1, spare, dest, source);
}

int main()
{
#ifdef CONTEST
    freopen("qubits.in", "r", stdin);
    freopen("qubits.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    move(n, 'A', 'C', 'B');
    return 0;
}

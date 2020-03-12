#include <cstdio>
#include <cmath>

bool sieve[1000005];

int main()
{
    FILE *input  = freopen("goldbach.in", "r", stdin);
    FILE *output = freopen("goldbach.out", "w", stdout);

    int n;
    scanf("%d", &n);

    // Sieve of Eratoshenes - calculate all primes < n
    for(int i=2; i<sqrt(n); i++)
    {
        if(sieve[i]==true)
            continue;
        
        for(int j=i*i; j<n; j+=i)
            sieve[j] = true;
    }

    for (int i=2; i<n; i++)
    {
        if(sieve[i]==false && sieve[n-i]==false)
        {
            printf("%d %d", i, n-i);
            break;
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}
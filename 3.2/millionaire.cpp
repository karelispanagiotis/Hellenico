#include <bits/stdc++.h>
using namespace std;

int T, N, M;
long double dist[1005]; // use long double !!!
struct edge{
	int a, b;
	long double cost;
} e[1000005];

bool bellman_ford()
{
	memset(dist, 0, sizeof(dist));
	bool change = true;
	for(int i=1; i<=N; i++)
	{
		change = false;
		for(int j=1; j<=M; j++)
		{
			if(dist[e[j].a] + e[j].cost < dist[e[j].b])
			{
				dist[e[j].b] = dist[e[j].a] + e[j].cost;
				change = true;
			}
		}
	}
	return change;
}

int main()
{
#ifdef CONTEST
	freopen("millionaire.in", "r", stdin);
	freopen("millionaire.out", "w", stdout);
#endif
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &N, &M);
		for(int a,b,p_e,i=1; i<=M; i++)
		{
			scanf("%d%d%d", &a, &b, &p_e);
			e[i] = {a,b,-log(0.5+0.015*p_e)};
		}
		printf("%s\n", bellman_ford() ? "Possible" : "Not possible");
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int N, M, K, ans, restrictions[15][12], sequence[10];

bool isOk()
{
	for(int i=0; i<N; i++)
	{
		int correct=0, permuted=0;
		vector<int> emf(15);
		for(int j=0; j<K; j++)
			if(sequence[j] == restrictions[i][j]) correct++;
			else emf[restrictions[i][j]]++;
		for(int j=0; j<K; j++)
		{
			if(sequence[j] == restrictions[i][j]) continue;
			if(emf[sequence[j]] > 0)
				permuted++, emf[sequence[j]]--;
		}
		if(correct!=restrictions[i][K] || permuted!=restrictions[i][K+1])
			return false;
	}
	return true;
}

void search(int pos)
{
	if(pos==K)
	{
		if(isOk()) ans++;
		return;
	}

	for(int i=1; i<=M; i++)
	{
		sequence[pos] = i;
		search(pos+1);
	}

}

int main()
{
	freopen("mastermind.in", "r", stdin);
	freopen("mastermind.out", "w", stdout);
	scanf("%d%d%d", &N, &M, &K);
	for(int i=0; i<N; i++)
		for(int j=0; j<K+2; j++)
			scanf("%d", &restrictions[i][j]);
	search(0);
	printf("%d\n", ans);

	return 0;
}

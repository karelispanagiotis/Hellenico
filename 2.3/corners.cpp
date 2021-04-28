#include <bits/stdc++.h>
using namespace std;

int di[4]={-1,0,+1,0}, dj[4]={0,+1,0,-1};
vector<pair<int,int>> start={{5,5},{5,6},{6,5},{6,6}}, win={{1,1},{1,2},{2,1},{2,2}};
map<vector<pair<int,int>>, int> dist, used;
char board[10][10];

void bfs()
{
	queue<vector<pair<int,int>>> q;
	dist[start] = 0;
	used[start] = true;
	q.push(start);

	while(!q.empty())
	{
		auto v = q.front(); q.pop();
		for(auto checker : v) //draw on the board
			board[checker.first][checker.second] = 'c'; 
		for(int i=0; i<4; i++) // for every checker
		{
			for(int k=0; k<4; k++) // for every direction
			{
				auto u = v;
				char adj1 = board[u[i].first + di[k]][u[i].second + dj[k]];
				char adj2 = board[u[i].first + 2*di[k]][u[i].second + 2*dj[k]]; 
				if(adj1 == '.')
					u[i] = {u[i].first + di[k], u[i].second + dj[k]};
				else if((adj1=='c' || adj1=='s') && adj2=='.')
					u[i] = {u[i].first + 2*di[k], u[i].second + 2*dj[k]};
				sort(u.begin(), u.end());

				if(!used[u])
				{
					dist[u] = dist[v] + 1;
					used[u] = true;
					q.push(u);
				}
			}
		}
		for(auto checker : v) //undo drawing
			board[checker.first][checker.second] = '.';
	}
}

int main()
{
#ifdef CONTEST
	freopen("corners.in", "r", stdin);
	freopen("corners.out", "w", stdout);
#endif
	for(int i=1; i<=6; i++)
		for(int j=1; j<=6; j++)
			scanf(" %c", &board[i][j]);
	bfs();
	printf("%d\n", dist[win]==0 ? -1 : dist[win]);
	return 0;
}
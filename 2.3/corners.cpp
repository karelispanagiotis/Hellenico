#include <bits/stdc++.h>
using namespace std;

char ch;
queue<long long> q;
unordered_map<long long, int> used, dist;
long long stones, flags, tiles, d[4] = {-8 /*Up*/, +1 /*Right*/, +8 /*Down*/, -1 /*Left*/} ;
long long beg = (1LL<<53) | (1LL<<54) | (1LL<<45) | (1LL<<46);
long long fin = (1LL<< 9) | (1LL<<10) | (1LL<<17) | (1LL<<18);

void bfs(){
	used[beg] = true;
	dist[beg] = 0;
	q.push(beg);

	while(!q.empty()){
		long long pawns = q.front(); q.pop();	

		for(int pos=0; pos<64; pos++){
			if( !(pawns>>pos & 1) ) continue;

			for(int k=0; k<4; k++){
				int new_pos = pos + d[k];
				if( (stones>>new_pos & 1) || (pawns>>new_pos & 1) ) new_pos += d[k];
				
				long long new_pawns = pawns & ~(1LL<<pos) | (1LL<<new_pos);
				if( (tiles>>new_pos & 1) && !(pawns>>new_pos & 1) && !used[new_pawns]){
					used[new_pawns] = true;
					dist[new_pawns] = dist[pawns] + 1; 
					q.push(new_pawns);
				}
			}
		}
	}
}

int main(){
#ifdef CONTEST
	freopen("corners.in", "r", stdin);
	freopen("corners.out", "w", stdout);
#endif
	for(int i=1; i<=6; i++){
		for(int j=1; j<=6; j++){
			scanf(" %c", &ch);
			if(ch=='.') tiles  |= (1LL<<(i*8+j));
			if(ch=='r') flags  |= (1LL<<(i*8+j));
			if(ch=='s') stones |= (1LL<<(i*8+j));
		}
	}
	bfs();
	printf("%d\n", used[fin] ? dist[fin] : -1);
	return 0;
}

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

int N;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> s;

int main(){
#ifdef CONTEST
	freopen("luckynum.in", "r", stdin);
	freopen("luckynum.out", "w", stdout);
#endif
	scanf("%d", &N);
	for(int i=1; i<=N; i+=2)
		s.insert(i);

	for(int i=1; i<s.size(); i++){
		int step = *s.find_by_order(i);
		for(int pos=step-1; pos<s.size(); pos+=step-1)
			s.erase(s.find_by_order(pos));
	}
	
	int i=0, j=s.size()-1, x, y;
	while(i<j){
		int l = *s.find_by_order(i), r = *s.find_by_order(j);
		if(l+r == N){
			x = l, y = r;
			i++, j--;
		}
		else if(l+r < N)
			i++;
		else 
			j--;
	}

	printf("%d %d\n", x, y);
	return 0;
}

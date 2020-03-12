#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    int shells;
    vector<int> children;
};

node tree[1005];

int max_shells(const node &x)
{
    if(x.children.size() == 0)
        return x.shells;
    
    int m = -1;
    for(auto i : x.children)
        m = max(max_shells(tree[i]), m);
    
    return m + x.shells;
}

int main()
{
    freopen("contest.in", "r", stdin);
    freopen("contest.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for(int i=0; i<n-1; i++)
    {
        int node, child, shells;
        scanf("%d %d %d", &node, &child, &shells);
        tree[node].children.push_back(child);
        tree[child].shells = shells;
    }

    printf("%d", max_shells(tree[1]));
    return 0;
}

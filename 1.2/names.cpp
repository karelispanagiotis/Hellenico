#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

string best_name[1005];
char names[1005][128];

string best(char *name)
{
    string ret = name, lex = name;
    for(int i=0; i<lex.length(); i++)
    {
        lex.push_back(lex.at(0));
        lex.erase(lex.begin());
        ret = min(ret, lex);
    }
    return ret;
}

int main()
{
    freopen("names.in", "r", stdin);
    freopen("names.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%s", names[i]);
        best_name[i] = best(names[i]);
    }

    int idx = min_element(best_name, best_name + n) - best_name;
    printf("%s", names[idx]);

    return 0;
}

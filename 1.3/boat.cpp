#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <array>

using namespace std;

int n;
vector<string> boat;

int main()
{
    freopen("boat.in", "r", stdin);
    freopen("boat.out", "w", stdout);

    cin >> n;
    for(int i=0; i<n; i++)
    {
        int x, y;
        string model;
        cin >> x >> y;
        for(int j=0; j<x; j++)
            boat.pop_back();
        for(int j=0; j<y; j++)
        {
            cin >> model;
            boat.push_back(model);
        }
    }

    sort(boat.begin(), boat.end());

    for(int i=0; i<boat.size(); i++)
        cout << boat[i] << '\n';

    return 0;
}

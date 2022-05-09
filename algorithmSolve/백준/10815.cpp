#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<int, int> mapList;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        mapList.insert(make_pair(x, 1));
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int x;
        cin >> x;
        if (mapList.find(x) != mapList.end())
            cout << "1" << " ";
        else
            cout << "0" << " ";
    }
    cout << '\n';
    return 0;
}
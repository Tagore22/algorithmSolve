#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    set<int> setList;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        setList.insert(x);
    }
    int answer = 0;
    for (int i = 0; i < m; ++i)
    {
        int x;
        cin >> x;
        if (setList.find(x) != setList.end())
            ++answer;

    }
    cout << n + m - (answer * 2) << '\n';
    return 0;
}
#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    set<string> setList;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        setList.insert(str);
    }
    int answer = 0;
    for (int i = 0; i < m; ++i)
    {
        string str;
        cin >> str;
        if (setList.find(str) != setList.end())
            ++answer;
    }
    cout << answer << '\n';
    return 0;
}
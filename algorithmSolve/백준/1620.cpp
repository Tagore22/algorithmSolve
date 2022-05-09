#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<string, int> mapSI;
    map<string, string> mapSS;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        mapSI.insert(make_pair(str, i + 1));
        mapSS.insert(make_pair(to_string(i + 1), str));
    }
    for (int i = 0; i < m; ++i)
    {
        string str;
        cin >> str;
        if (str[0] >= '0' && str[0] <= '9')
            cout << mapSS[str] << '\n';
        else
            cout << mapSI[str] << '\n';
    }
    return 0;
}
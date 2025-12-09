#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    str.erase(unique(str.begin(), str.end()), str.end());
    cout << str << '\n';
    return 0;
}
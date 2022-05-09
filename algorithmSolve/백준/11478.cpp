#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    set<string> setList;
    string str;
    cin >> str;
    int strSize = str.size();
    for (int i = 1; i <= strSize; ++i)
        for (int j = 0; j <= strSize - i; ++j)
            setList.insert(str.substr(j, i));
    cout << setList.size() << '\n';
    return 0;
}
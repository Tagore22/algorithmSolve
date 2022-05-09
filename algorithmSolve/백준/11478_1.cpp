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
    for (int i = 0; i < strSize; ++i)
    {
        string answer = "";
        for (int j = i; j < strSize; ++j)
        {
            answer += str[j];
            setList.insert(answer);
        }
    }
    cout << setList.size() << '\n';
    return 0;
}
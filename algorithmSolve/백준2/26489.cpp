#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    int answer = 0;
    while (getline(cin, str))
    {
        ++answer;
    }
    cout << answer << '\n';
    return 0;
}
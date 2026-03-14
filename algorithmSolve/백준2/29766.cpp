#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    int answer = 0;
    size_t pos = 0;
    while (true)
    {
        pos = str.find("DKSH", pos);
        if (pos == string::npos)
            break;
        ++answer;
        pos += 4;
    }
    cout << answer << '\n';
    return 0;
}
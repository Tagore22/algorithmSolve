#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int from = 0, answer = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] != ',')
            continue;
        answer += stoi(str.substr(from, i - from));
        from = i + 1;
    }
    answer += stoi(str.substr(from, str.size() - from));
    cout << answer << '\n';
    return 0;
}
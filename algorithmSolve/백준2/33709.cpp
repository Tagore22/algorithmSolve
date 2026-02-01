#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    string str;

    cin >> N >> str;
    int answer = 0, from = 0, num = 0;
    for (int i = 0; i < N; ++i)
    {
        if (str[i] == '.' || str[i] == '|' || str[i] == ':' || str[i] == '#')
        {
            answer += stoi(str.substr(from, num));
            from = i + 1;
            num = -1;
        }
        ++num;
    }
    answer += stoi(str.substr(from));
    cout << answer << '\n';
    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int answer = 1;
    for (int i = 1; i < str.size(); ++i)
    {
        if (str[i] == str[i - 1])
            ++answer;
        else
            break;
    }
    cout << answer << '\n';
    return 0;
}
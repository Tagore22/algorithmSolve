#include <iostream>

using namespace std;

int main()
{
    string str;
    for (int i = 0; i < 3; ++i)
    {
        cin >> str;
        int answer = 1, cur = 1;
        for (int j = 1; j < 8; ++j)
        {
            if (str[j] == str[j - 1])
            {
                ++cur;
            }
            else
            {
                answer = max(answer, cur);
                cur = 1;
            }
        }
        answer = max(answer, cur);
        cout << answer << '\n';
    }
    return 0;
}
#include <iostream>

using namespace std;

char board[5] = { 'a', 'e', 'i', 'o', 'u' };

int main()
{
    string str;
    cin >> str;
    int answer = 0;
    for (int iter = 0; iter < str.size(); ++iter)
        for (int i = 0; i < 5; ++i)
            if (str[iter] == board[i])
            {
                ++answer;
                break;
            }
    cout << answer << '\n';
    return 0;
}
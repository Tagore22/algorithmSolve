#include <iostream>

using namespace std;

int main()
{
    int board[4] = { 56, 24, 14, 6 };
    int answer = 0, cur;
    for (int i = 0; i < 4; ++i)
    {
        cin >> cur;
        answer += cur * board[i];
    }
    cout << answer << '\n';
    return 0;
}
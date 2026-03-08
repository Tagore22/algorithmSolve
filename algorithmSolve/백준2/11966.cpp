#include <iostream>

using namespace std;

int main()
{
    int board[31] = { 1, };
    for (int i = 1; i <= 30; ++i)
        board[i] = board[i - 1] * 2;
    int N;
    cin >> N;
    for (int i = 0; i <= 30; ++i)
    {
        if (N == board[i])
        {
            cout << 1 << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
    return 0;
}
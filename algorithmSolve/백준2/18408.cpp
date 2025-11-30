#include <iostream>

using namespace std;

int main()
{
    int board[3] = { 0, };
    for (int i = 0; i < 3; ++i)
    {
        int num;
        cin >> num;
        ++board[num];
    }
    cout << (board[1] > board[2] ? 1 : 2) << '\n';
    return 0;
}
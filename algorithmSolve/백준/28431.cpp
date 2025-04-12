#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int board[10];
    memset(board, 0, sizeof(board));
    for (int i = 0; i < 5; ++i)
    {
        int num;
        cin >> num;
        ++board[num];
    }
    for (int i = 0; i < 10; ++i)
    {
        if (board[i] % 2 == 1)
        {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}
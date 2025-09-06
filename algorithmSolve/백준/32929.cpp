#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    char board[3] = { 'U', 'O', 'S' };

    int num;
    cin >> num;
    --num;

    cout << board[num % 3] << '\n';
    return 0;
}
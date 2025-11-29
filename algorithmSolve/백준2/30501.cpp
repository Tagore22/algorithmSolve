#include <iostream>

using namespace std;

int main()
{
    string board[1000];
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)
        {
            if (board[i][j] == 'S')
            {
                cout << board[i] << '\n';
                exit(0);
            }
        }
    }
    return 0;
}
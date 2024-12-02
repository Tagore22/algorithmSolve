#include <iostream>

using namespace std;

int main()
{
    int N, Q, idx = 0, here;
    int board[10000];
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i)
    {
        cin >> here;
        for (int j = 0; j < here; ++j)
            board[idx++] = i;
    }
    for (int i = 0; i < Q; ++i)
    {
        cin >> here;
        cout << board[here] << '\n';
    }
    return 0;
}
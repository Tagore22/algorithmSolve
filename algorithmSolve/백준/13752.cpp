#include <iostream>

using namespace std;

// Ǯ��.
// �� �־��� ���Ұ���ŭ = ���.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int board[100];
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < board[i]; ++j)
            cout << '=';
        cout << '\n';
    }
    return 0;
}
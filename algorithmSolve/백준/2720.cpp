#include <iostream>

using namespace std;

// Ǯ��.
// �ּ����� �������� ������� �ϱ� ������ ū������ ���ʴ�� ������.

int board[4] = { 25, 10, 5, 1 };
int T, C;

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> C;
        for (int i = 0; i < 4; ++i)
        {
            cout << C / board[i] << ' ';
            C %= board[i];
        }
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
#include <iostream>

using namespace std;

// Ǯ��.
// ù��° ���忡 ��� ���� ���� �� ����� �ش� ������� ����� �ش��ϴ� ���� ����
// ���ų� �ݴ´�. ��� ���� ���� �����ִ� ���� ������ ����.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    bool board[101];
    int T, N;
    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N;
        for (int i = 1; i <= N; ++i)
            board[i] = true;
        for (int i = 2; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                if (j % i == 0)
                    board[j] ^= 1;
        int answer = 0;
        for (int i = 1; i <= N; ++i)
            if (board[i])
                ++answer;
        cout << answer << '\n';
    }
    return 0;
}
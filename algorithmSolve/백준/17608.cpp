#include <iostream>

using namespace std;

// Ǯ��.
// �����ʿ��� ���δٴ� ���� �� ������ ���뺸�� ũ�ٴ� ���� �ǹ��Ѵ�. �� ���� ���� �� Ŀ���� ���̱� ������
// ������, �� �� �ں��� ��ȸ�ϸ� ���� ������ ū ������ ���� ã���� �ȴ�.

int board[100000];
int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    int answer = 1, h = board[N - 1];
    for (int i = N - 2; i >= 0; --i)
        if (board[i] > h)
        {
            ++answer;
            h = board[i];
        }
    cout << answer << '\n';
    return 0;
}
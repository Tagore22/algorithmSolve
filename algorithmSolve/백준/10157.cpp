#include <iostream>

using namespace std;

// Ǯ��.
// ó������ �߸� ����ؼ� ���Ʈ�����δ� �ð��ʰ��� ������ ������ �˾ұ⿡ �ٸ� ����� �����س����� �ð��� ��
// ���. �׷��� �̸� ������ ���� ������ ����̱⿡ �ᱹ ���Ʈ������ �̿��ϱ�� �ߴ�. ���� ���ΰ� �ִ� 1000�̱⿡
// ��� ĭ�� �ٵ��ƺ��ٰ� �ص� ���귮�� 100���� ���� �ʱ⿡ �ð����� ����� Ǯ�� �ִ�. �� �ķδ� �׳� �ָԱ���������
// 4���� ��� ���� ����Ͽ���.

int main()
{
    int C, R, K;
    cin >> C >> R >> K;
    bool board[1001][1001] = { false, };
    if (C * R < K)
    {
        cout << 0 << '\n';
        return 0;
    }
    pair<int, int> pos = make_pair(1, 0);
    while (true)
    {
        for (int i = 0; i <= R; ++i)
        {
            if (K == 0)
            {
                cout << pos.first << ' ' << pos.second << '\n';
                return 0;
            }
            if (pos.second + 1 > R || board[pos.first][pos.second + 1])
                break;
            ++pos.second;
            board[pos.first][pos.second] = true;
            --K;
        }
        for (int i = 0; i <= C; ++i)
        {
            if (K == 0)
            {
                cout << pos.first << ' ' << pos.second << '\n';
                return 0;
            }
            if (pos.first + 1 > C || board[pos.first + 1][pos.second])
                break;
            ++pos.first;
            board[pos.first][pos.second] = true;
            --K;
        }
        for (int i = 0; i <= R; ++i)
        {
            if (K == 0)
            {
                cout << pos.first << ' ' << pos.second << '\n';
                return 0;
            }
            if (pos.second - 1 < 1 || board[pos.first][pos.second - 1])
                break;
            --pos.second;
            board[pos.first][pos.second] = true;
            --K;
        }
        for (int i = 0; i <= C; ++i)
        {
            if (K == 0)
            {
                cout << pos.first << ' ' << pos.second << '\n';
                return 0;
            }
            if (pos.first - 1 < 1 || board[pos.first - 1][pos.second])
                break;
            --pos.first;
            board[pos.first][pos.second] = true;
            --K;
        }
    }
    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// ��2�ε� ���� ������ �׷��� �������� ������ ��������. �� �ֱ⸶�� ������ ������ �ð���
// ����ϵ�, ������ ������ �����¶��� �ϳ��� ����� ����̴�. ó������ �ּҰ������ ����������
// N�� �ִ� 100�̱� ������ ����������. ���� �׳� �ܼ��� ��� ��츦 ����ϵ�, ù �ֱⰡ
// �̹� �湮�� ���¶�� �׺��� ���� ���� �̹� �ѹ� ��ȸ�� �� �����̱� ������ ��ȸ�� �� �ʿ䰡 �������ٴ�
// ���� �̿��ؾ��߰� �翬�� ������ ����Ǿ�� �ߴ�.

int main()
{
    int N, C;
    int board[100];
    bool visit[2000001] = { false, };
    cin >> N >> C;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    sort(board, board + N);
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        if (visit[board[i]])
            continue;
        for (int j = board[i]; j <= C; j += board[i])
        {
            if (visit[j])
                continue;
            ++answer;
            visit[j] = true;
        }
    }
    cout << answer << '\n';
    return 0;
}
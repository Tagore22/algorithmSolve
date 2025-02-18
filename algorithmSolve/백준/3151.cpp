#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// �������� �����ֵ� ����� ��������. ó������ 2���� ���ؼ� 2���� �迭�� ������
// �������͸� �̿��ؼ� Ǯ���� �ߴµ� ���� ������ �ߺ��� ���°��� �Ұ����ߴ�.
// ��������� 2���� ���� ���س��� ���¿��� �ι�° ������ ���ҵ��� ���� Ž������ ��ȸ�Ͽ� ������
// 3��° ���Ҹ� ã�ƾ��ߴ�.

// �ڼ��� ������ �ּ����� �����.

int board[10000];
int N;

void MakeAnswer()
{
    // ���� Ž���� ���� ����.
    sort(board, board + N);
    long long answer = 0;
    // 2��° ���ұ��� 10000 * 10000 ������ ��ȸ�ϸ� ã�´�.
    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            // 2��° ���� ������ ���ҵ��� ���� Ž������ ��ȸ�ϸ� ������ 3��° ���Ҹ� ã�´�.
            // �̶� ���ؼ� 0�� �Ǵ� ���� ã�ƾ� �ϱ⿡ �� ������ �� sum�� ���̳ʽ����� �̿��ؾ����� �����ؾ��Ѵ�.
            int sum = board[i] + board[j];
            int from = lower_bound(board + j + 1, board + N, -sum) - board;
            int to = upper_bound(board + j + 1, board + N, -sum) - board;
            answer += to - from;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
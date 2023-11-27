#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// N���� �ٱ��ϰ� ������ M�� �־����� ������ �������� �� �������� �ٱ��� ���¸� ����ϴ� �Լ���.
// reverse()�� M�� ������ ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

vector<int> board;
int N, M;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    // �ٱ����� �ʱⰪ�� 1, 2, 3, 4 ~
    for (int i = 1; i <= N; ++i)
        board.push_back(i);

    int from, to;
    // M�� �ݺ��Ѵ�.
    for (int i = 0; i < M; ++i)
    {
        // ������ �Է¹޾� �� ������ŭ reverse()�� �ٱ����� ��ȣ�� ������Ų��.
        cin >> from >> to;
        reverse(board.begin() + from - 1, board.begin() + to);
    }

    // M���� ���� ���� �ٱ����� ��ȣ���� ����Ѵ�.
    for (int i = 0; i < N; ++i)
        cout << board[i] << ' ';
    cout << '\n';
    return 0;
}
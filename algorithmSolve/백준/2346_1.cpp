#include <iostream>
#include <deque>

using namespace std;

// 2346���� ������ Ǭ Ǯ��.
// �� ����ϰ� ���� Ǯ���ΰ� ����.
// ó���� ������ ��� Ǯ�� ���� ����ߴµ� �׳� ���׸��� ���鼭 ���� �� �����̾���.

// �ڼ��� ������ �ּ����� �����.

deque<pair<int, int>> board;
int N;

void MakeAnswer()
{
    while (!board.empty())
    {
        // �̵����� �������� ���� ��ȣ�� ����Ѵ�. �׸��� �����Ѵ�.
        cout << board.front().first << ' ';
        int cost = board.front().second;
        board.pop_front();

        if (board.empty())
            break;

        // �̵����� ������ ������ �����ϸ鼭 �ѹ� �̵��߱⿡ cost - 1��ŭ�� �� �հ���
        // �� �ڷ� �ű��.
        if (cost > 0)
        {
            for (int i = 0; i < cost - 1; ++i)
            {
                pair<int, int> cur = board.front();
                board.push_back(cur);
                board.pop_front();
            }
        }
        // �̵����� ������� cost��ŭ �� �ް��� �� ������ �ű��.
        else
        {
            for (int i = 0; i < -1 * cost; ++i)
            {
                pair<int, int> cur = board.back();
                board.push_front(cur);
                board.pop_back();
            }
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int num;
    for (int i = 1; i <= N; ++i)
    {
        cin >> num;
        board.push_back(make_pair(i, num));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
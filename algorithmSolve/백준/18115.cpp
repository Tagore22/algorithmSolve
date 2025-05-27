#include <iostream>
#include <deque>

using namespace std;

// Ǯ��.
// ������ �����ϸ� ���� ������. ������ 1������ ī��� �������ְ�, ������ �Էµ� �ݴ� ������
// ī�带 �������� ������ ������� ����ϴ� ���̴�. �ٸ� ��, ��, �տ��� 2��°�� �迭���� 
// ��� ��������� ����ߴµ� ó������ �迭�� �ذ��ϰ� �;����� deque�� �� ����ϰ�
// Ǯ���� �� ���Ұ� Ǯ���� ��Ʈ�� ���� ������ ���� �̵� ���� �����ϰ� ���� ��������.

int N;
const int MAX = 1000000;
int board[MAX];
deque<int> answer;

void Solve()
{
    for (int i = N - 1; i >= 0; --i)
    {
        if (board[i] == 1)
        {
            answer.push_front(N - i);
        }
        else if (board[i] == 2)
        {
            int first = answer.front();
            answer.pop_front();
            answer.push_front(N - i);
            answer.push_front(first);
        }
        else
        {
            answer.push_back(N - i);
        }
    }
    for (auto& ans : answer)
        cout << ans << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    Solve();
    return 0;
}
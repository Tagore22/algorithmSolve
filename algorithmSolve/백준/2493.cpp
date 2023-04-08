#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

// Ǯ��.
// ������ ����ϴ� ������. �ڿ������� ���̿� ���� ��ȣ�� �����Ͽ�
// ���ÿ� ����� ���̺��� ũ�ٸ� �� ��ȣ�� �ٷ� ���Ź޴� ��ȣ���� �̿��ϸ� �ȴ�.

int board[500000], answer[500000];
int N;

void MakeAnswer()
{
    stack<pair<int, int>> sta; // ����, ��ȣ.
    for (int i = N - 1; i >= 0; --i)
    {
        while (!sta.empty() && board[i] > sta.top().first)
        {
            answer[sta.top().second] = i + 1;
            sta.pop();
        }
        sta.push(make_pair(board[i], i));
    }

    for (int i = 0; i < N; ++i)
        cout << answer[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(answer, 0, sizeof(answer));

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
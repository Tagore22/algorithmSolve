#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// �Է½� �̸� ��� ���Ұ����� �湮 ���θ� üũ�س��� ���� �迭�� �ѹ��� ��ȸ�ϸ�
// ���� ���Ұ� * 2�� ���� ������ �湮�Ͽ�����(�迭�� �����ϴ���)�� Ȯ���Ͽ� ������ answer�� �������ѳ�����.

int board[15];
bool visit[200];

void MakeAnswer()
{
    while (true)
    {
        int idx = 0;
        memset(visit, false, sizeof(visit));
        while (true)
        {
            cin >> board[idx];
            if (board[idx] == 0)
                break;
            else if (board[idx] == -1)
                return;
            visit[board[idx]] = true;
            ++idx;
        }
        int answer = 0;
        for (int i = 0; i < idx; ++i)
        {
            if (visit[board[i] * 2])
                ++answer;
        }
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
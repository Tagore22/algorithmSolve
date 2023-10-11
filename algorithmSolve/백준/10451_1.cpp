#include <iostream>
#include <cstring>

using namespace std;

// 10451�� �ٸ� Ǯ��.
// ��� ������ ������ ������ ������ �������� ���� ����Ǿ� �ִ�.
// �׷��⿡ �� ������Ʈ�� ������ ���ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[1001];
bool visit[1001];
int T, N, answer;

void DFS(int here)
{
    visit[here] = true;
    int next = board[here];

    // �̹� �湮�� ���� �����Ѵ�.
    if (!visit[next])
        DFS(next);
}

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        answer = 0;
        memset(visit, false, sizeof(visit));
        cin >> N;
        for (int i = 1; i <= N; ++i)
            cin >> board[i];

        // �̹� �湮�� ������ �����ϰ�
        // �Ź� DFS�� ȣ��ɶ����� ���ο� ������Ʈ�� ã�� �ȴ�.
        for (int i = 1; i <= N; ++i)
        {
            if (visit[i])
                continue;

            ++answer;
            DFS(i);
        }
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
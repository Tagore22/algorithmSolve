#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// �׷������߿��� ��ȯ�� ������ ���ϴ� ������.
// ���� ���� �����ϰ� Ǯ���µ� �����ϰ� DFS�� �̿��� ������Ʈ�� ������ ���ϴ� ������� Ǯ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[1001];
bool visit[1001], isCircle[1001];
int T, N, answer;

// ��� ��ȯ�� ã�� �Լ�.
void DFS(int here)
{
    visit[here] = true;
    int next = board[here];

    // �̹� �湮�Ѱ��� �ٽ� �����Ͽ��ٸ� ����Ŭ�� �̷��.
    if (visit[next])
    {
        // ���� �׷����̱� ������ ������ ã�ƺ� �ʿ䰡 ����.
        if (!isCircle[next])
        {
            isCircle[next] = true;
            int there = next;
            while (board[there] != next)
            {
                isCircle[board[there]] = true;
                there = board[there];
            }
            isCircle[board[there]] = true;
            ++answer;
        }
        return;
    }
    DFS(next);
}

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        answer = 0;
        memset(visit, false, sizeof(visit));
        memset(isCircle, false, sizeof(isCircle));
        cin >> N;
        for (int i = 1; i <= N; ++i)
            cin >> board[i];

        for (int i = 1; i <= N; ++i)
        {
            if (visit[i])
                continue;

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
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// 15663���� ����� �� Ǯ��.
// ���� ���ǹ��� ���� �ʿ���� �����ϳ��� �߰��ϸ� �Ǵ� ��������.
// ������ ������ �� prev_num ������ �߰��Ͽ� �̹��� ������ ���� ���ٸ�
// �����Ѵ�.

// �ڼ��� ������ �ּ����� �����.

int board[8], answer[8];
bool visit[8];
int N, M;

void BackTrack(int num)
{
    // M���� ���Ҹ� ������� ����ϰ� Ż���Ѵ�.
    if (num == M)
    {
        for (int i = 0; i < M; ++i)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }

    // ������ ������ ���� �����ϴ� prev_num.
    int prev_num = 0;
    for (int i = 0; i < N; ++i)
    {
        // �̹� ����� ���Ұų� ������ ���ݰ� ���� ���� ����ٸ� �����Ѵ�.
        if (!visit[i] && prev_num != board[i])
        {
            visit[i] = true;
            answer[num] = board[i];
            prev_num = board[i];
            BackTrack(num + 1);
            visit[i] = false;
        }
    }
}

void MakeAnswer()
{
    sort(board, board + N);
    memset(visit, false, sizeof(visit));
    BackTrack(0);
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
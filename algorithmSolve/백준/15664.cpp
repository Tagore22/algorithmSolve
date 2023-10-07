#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// N���� ������ M���� ����ϴ� ������ ����� �����̴�. �ٸ� ������ ���� ������ �ִ�.

// 1. �ߺ��� ������ �ʴ´�.
// 2. ���ڸ��� ���ڸ����� �۾Ƽ��� �ȵȴ�.

// ���� ������ �������� �����ؾ� �Ѵ�.

// 1. ��Ʈ��ŷ���� ��� ��츦 ��ȸ�ϵ�, for���� ���۵Ǵ� �������� ������ idx���� 1�� ũ�� �ȴ�.
// 2. �ٸ� �ߺ��� ������ �ʱ⿡ ������ �����ߴ� ���� üũ�Ͽ� ���ٸ� �����Ѵ�.

// �ڼ��� ������ �ּ����� �����.

int board[8], answer[8];
int N, M;

// ��� ��츦 ��ȸ�ϴ� ��Ʈ��ŷ �Լ�.
void BackTrack(int cur, int num)
{
    // M���� ��� ����� ��� ����ϰ� Ż���Ѵ�.
    if (num == M)
    {
        for (int i = 0; i < M; ++i)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }

    // ����� �����ؾ����� 2���� �ߺ��� �����ϱ� ���� ����� ������.
    int prev = -1;
    // 1���� �������� ���ڸ��� �� Ŀ�������� ������������ ���ĵ� �迭�� idx + 1���� �����Ѵ�.
    for (int i = cur + 1; i < N; ++i)
    {
        if (board[i] == prev)
            continue;

        answer[num] = board[i];
        BackTrack(i, num + 1);
        // �ߺ��� ���ϱ� ���� �������� �����Ѵ�.
        prev = board[i];
    }
}

void MakeAnswer()
{
    // �� ū ���� ����ϱ� ���� ����.
    sort(board, board + N);
    BackTrack(-1, 0);
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
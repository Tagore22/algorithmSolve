#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// �� �ٷ� Ǯ��ô� ������ ����� ��������. ���ҿ� ������ ���̸��� �����ߴ�.
// �׸���� Ǯ�� ������ó�� ���̳�, ���� ���� ��Ģ�� ���⿡ dp�� �̿��� ����Ž������
// Ǯ��� �Ѵ�.

// �ڼ��� ������ �ּ����� �����.

int board[1000], dp[1000];
int N;

// idx���� �����ϴ� ���ҵ��� ���� �� �����ϴ� �κ� ������ ã�� �Լ�.
int BackTrack(int idx)
{
    int& ans = dp[idx];
    if (ans != -1)
        return ans;

    ans = 1;
    // idx���� ������ ���ҵ��� board[idx]���� board[i]�� ũ�ٸ� ���Խ�Ų�� �״������� ���ư�����.
    for (int i = idx + 1; i < N; ++i)
    {
        if (board[idx] > board[i])
            ans = max(ans, BackTrack(i) + 1);
    }
    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));
    int answer = 0;
    // 0 ~ N - 1���� �����ϴ� ���� �� �����ϴ� �κ� ������ ã�´�.
    for (int i = 0; i < N; ++i)
        answer = max(answer, BackTrack(i));

    cout << answer << '\n';
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
    MakeAnswer();
    return 0;
}
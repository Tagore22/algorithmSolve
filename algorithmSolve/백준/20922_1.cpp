#include <iostream>
#include <cstring>

using namespace std;

// 20922���� queue�� �ƴ� ���״�� �������͸� �̿��Ͽ� Ǭ Ǯ��.
// ������ ū Ʋ�� ������ que�� �ƴ� from�� to�� ���Ǿ���.

// �ڼ��� ������ �ּ����� �����.

int board[200000];
int visit[100001];
int N, K, from;

// from�� ��ĭ�� �ű�鼭 ������ ���� erase�� ��� Ż���Ѵ�.
void RenewQueue(int erase)
{
    while (true)
    {
        int here = board[from];
        --visit[here];
        ++from;
        if (here == erase)
            break;
    }
}

void MakeAnswer()
{
    memset(visit, 0, sizeof(visit));
    int answer = 0;
    from = 0;

    for (int to = 0; to < N; ++to)
    {
        // 0 ~ N - 1���� ��ȸ�ϸ� ����� here�� K���� �� ���� �����Ͽ��ٸ�
        // to - from(������� ����)�� ������ answer�� ���Ͽ� answer�� ������
        // from�� ��ġ�� ���� here�� �ٷ� �������� �ű��.
        int here = board[to];
        ++visit[here];
        if (visit[here] > K)
        {
            answer = max(answer, to - from);
            RenewQueue(here);
        }
    }
    answer = max(answer, N - 1 - from + 1);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
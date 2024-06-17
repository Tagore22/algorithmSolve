#include <iostream>

using namespace std;

// 15658���� �� ���� Ǯ��.
// ����Ͽ��� set�� �ֽô��� �ʿ������ ��Ʈ��ŷ�� ���ȣ���Ҷ����� ��������
// string�� ����Ͽ� ���߿� ���� ����Ͽ��µ� ���� �׷� �ʿ���� �Ź� ���ȣ���Ҷ�����
// �Ű����� ��ü�� ��갪���� ������ �ȴ�.

int board[11], oper[4];
int N, min_ans = 1000000001, max_ans = -1000000001;

void BackTrack(int num, int cur)
{
    if (num == N - 1)
    {
        max_ans = max(max_ans, cur);
        min_ans = min(min_ans, cur);
        return;
    }

    if (oper[0] > 0)
    {
        --oper[0];
        BackTrack(num + 1, cur + board[num + 1]);
        ++oper[0];
    }
    if (oper[1] > 0)
    {
        --oper[1];
        BackTrack(num + 1, cur - board[num + 1]);
        ++oper[1];
    }
    if (oper[2] > 0)
    {
        --oper[2];
        BackTrack(num + 1, cur * board[num + 1]);
        ++oper[2];
    }
    if (oper[3] > 0)
    {
        --oper[3];
        BackTrack(num + 1, cur / board[num + 1]);
        ++oper[3];
    }
}

void MakeAnswer()
{
    BackTrack(0, board[0]);
    cout << max_ans << '\n';
    cout << min_ans << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    for (int i = 0; i < 4; ++i)
        cin >> oper[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 15665���� �Ǵٸ� Ǯ��.
// �ᱹ ������ ������ ����� int �迭�� �ƴ� string ������� ����ϴ� ���̾���.
// �������� �������δ� int �迭�� ��¿�� ���� for���� �̿��Ͽ� ��� ���Ҹ� ���ƾ�������
// string�� �̹� ��� ���ڰ� �پ��ִٴ� ���� ������� �����̱� ������ �������� ���� Ȥ�� ������
// ��¿��� ���ݴ� �����Ѱ� �ƴѰ� ������ ���.

int board[7];
int N, M;

void BackTrack(int idx, string str)
{
    if (idx == M)
    {
        // int �迭�� ��ȸ�ϸ� ����ϴ� ���� �ƴ� string ���ڿ� �ϳ��� ����Ѵ�.
        cout << str << '\n';
        return;
    }

    int prev = -1;
    for (int i = 0; i < N; ++i)
    {
        if (board[i] == prev)
            continue;

        BackTrack(idx + 1, str + to_string(board[i]) + " ");
        prev = board[i];
    }
}

void MakeAnswer()
{
    sort(board, board + N);
    BackTrack(0, "");
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
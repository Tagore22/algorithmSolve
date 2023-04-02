#include <iostream>
#include <cmath>
#include <cstring>

using namespace std; // ��Ϲ����� �� ���� ����Ұ�. 2�� ������ 6�� ����

// Ǯ��.
// ����� �ùķ��̼� ���� ������.
// �� ��Ϲ����� ȸ���Ҷ��� ������ ���ϸ� �ȴ�.

string board[4];
bool check[4];
int K;

// ��Ϲ����� ȸ���� �����ϴ� �Լ�. 
// ���ѹݺ��� �Ͼ�� �ʰԲ� ���� ��Ϲ����� �湮�� ǥ���ϴ� bool Ÿ�Թ迭
// check���� �������ְ� ��, �� ��Ϲ����� ȸ�� ���� ���θ� �ľ�����
// ���ȣ���� �Ѵ�.
void RotateCog(int idx, int dir)
{
    check[idx] = true;

    if (idx - 1 >= 0 && board[idx][6] != board[idx - 1][2] && !check[idx - 1])
        RotateCog(idx - 1, dir * -1);

    if (idx + 1 < 4 && board[idx][2] != board[idx + 1][6] && !check[idx + 1])
        RotateCog(idx + 1, dir * -1);

    if (dir == 1) // �ð������ ��� �ǵڰ� �Ǿ��� �ȴ�.
    {
        char to = board[idx][7];
        board[idx].erase(7);
        board[idx] = to + board[idx];
    }

    else
    {
        char to = board[idx][0];
        board[idx].erase(0, 1);
        board[idx] += to;
    }
}

void MakeAnswer()
{
    for (int i = 0; i < K; ++i)
    {
        memset(check, false, sizeof(check));
        int idx, dir;
        cin >> idx >> dir;
        RotateCog(idx - 1, dir);
    }

    int answer = 0;
    for (int i = 0; i < 4; ++i)
        if (board[i][0] == '1')
            answer += pow(2, i);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 4; ++i)
        cin >> board[i];

    cin >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
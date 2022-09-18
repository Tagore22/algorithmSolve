#include <iostream>
#include <map>

using namespace std;

//2���� �迭�� ��ȸ�ϸ�, ���� �л��� ���� ���̾��� �ο����� ��� �ľ��Ѵ�. ��, ���� ���̾��� �л��� �ߺ��� �ɼ��� �ֱ⿡
//(1�г�,2�г⶧ ��� �������� ��� ��) �ߺ��� ���ϱ� ���� map�� �̿��Ѵ�.

int board[1001][5];
int N;
pair<int, int> cheif = make_pair(0, -1); //�л���ȣ, ���� ���̾��� �ο��� ��

void CalNum(int idx)
{
    map<int, int> with_list;
    for (int i = 0; i < 5; ++i)
        for (int j = 1; j <= N; ++j)
            if (j != idx && board[j][i] == board[idx][i])
                with_list[j] = 1;
    int now = with_list.size();
    if (now > cheif.second)
        cheif = make_pair(idx, now);
    else if (now == cheif.second)
        cheif = make_pair(min(idx, cheif.first), now);
}

void MakeAnswer()
{
    for (int i = 1; i <= N; ++i)
        CalNum(i);
    cout << cheif.first << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j < 5; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
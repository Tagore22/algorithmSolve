#include <iostream>
#include <algorithm>

using namespace std;

//������ �Ÿ��� ���� ������. ���� ������ �� Ǭ�ٰų� 1�� ������ Ʋ���� 2�� ������ �ٷ� �°� �ϴµ��� �������� ����� ���� ����.
//������ �߸����� �˰� ���� ����ߴµ� �������� �������Ѱ��� �־���. �����ϰ� �ڵ带 ����...

struct team
{
    int sum_time = 0;
    int sum_solve = 0;
    int num;
    int solve[15] = { 0 };
    int time[15] = { 0 };
};

const int MAX_NUM = 100;
team board[MAX_NUM];
int n, m, q;

bool CompareTeams(team t1, team t2)
{
    if (t1.sum_solve != t2.sum_solve)
        return t1.sum_solve > t2.sum_solve;
    else if (t1.sum_time != t2.sum_time)
        return t1.sum_time < t2.sum_time;
    else
        return t1.num < t2.num;
}

void MakeAnswer()
{
    for (int i = 0; i < n; ++i)
        board[i].num = i + 1;

    for (int i = 0; i < q; ++i)
    {
        int a, b, c;
        string d;
        cin >> a >> b >> c >> d;
        if (board[b - 1].solve[c - 1] == 0)
        {
            if (d == "AC")
            {
                board[b - 1].sum_time += a + board[b - 1].time[c - 1];
                board[b - 1].solve[c - 1] = 1;
                ++board[b - 1].sum_solve;
            }
            else
            {
                board[b - 1].time[c - 1] += 20;
            }
        }
    }

    sort(board, board + n, CompareTeams);
    for (int i = 0; i < n; ++i)
        cout << board[i].num << ' ' << board[i].sum_solve << ' ' << board[i].sum_time << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
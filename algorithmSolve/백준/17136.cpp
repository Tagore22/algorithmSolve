#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// ����ġ�Ⱑ �߿��ߴ� �����̴�.
// 10X10 �迭�� �����̸� �ּ������� �ٿ� ��� �迭�� 0���� ����� �����ε�, �׸���δ� Ǯ���� ������.
// �׷��� ��Ʈ��ŷ�� ���� ����Ž���� �����ߴµ� ��ħ �迭�� 10X10���� ���� �������� �����Ǿ� �־���.
// �迭�� ��ȸ�ϸ� 1�� ���� �߰��Ͽ����� 5������ ����Ҽ� �ִ� ��� �����̸� ����Ͽ� ���� ��ȸ�� �Ѿ��
// (9,9)���� �����Ͽ����� ����� �ּ����� ������ ���� ����ϸ� �ȴ�.

vector<vector<int>> board;
vector<int> paper;
const int MAX_NUM = 987654321;
int answer = MAX_NUM;

// ����Ҽ� �ִ� �������� �ִ� ũ�⸦ ���ϴ� �Լ�.
int CalRange(int y, int x, vector<vector<int>>& cur_board)
{
    // ���� 0 ~ 9���� ����� ���� �����ϱ� ���� ���� �ִ����� ũ�⸦ ���Ѵ�.
    int dis_y = 10 - y;
    int dis_x = 10 - x;
    int total_dis = min(dis_y, dis_x);

    bool isfind;
    // ��ǥ������ ���� �ִ밪���� �ּ����� 1���� ��ȸ�ϸ� ������ �ִ� ũ���� �����̸� ���Ѵ�.
    for (int range = total_dis >= 5 ? 5 : total_dis; range > 0; --range)
    {
        isfind = true;
        for (int i = y; i < y + range; ++i)
        {
            for (int j = x; j < x + range; ++j)
                if (cur_board[i][j] != 1)
                {
                    isfind = false;
                    break;
                }
            if (!isfind)
                break;
        }
        if (isfind)
            return range;
    }
}

// �����̸� �ٿ� ��ǥ���� 0���� �����Ѵ�.
vector<vector<int>> OneToZero(int y, int x, int range, vector<vector<int>> cur_board)
{
    for (int i = y; i < y + range; ++i)
        for (int j = x; j < x + range; ++j)
            cur_board[i][j] = 0;

    return cur_board;
}

// �迭�� ��ȸ�ϴ� ��Ʈ��ŷ �Լ�. �̹� ���� �ּҰ����� ���� sum���� �� ũ�ٸ� �����ϰ�,
// �迭�� ��ȸ�ϸ� 1�� �߰��ҽ� �����Ҽ� �ִ� ���� ū �����̺��� �ϳ��� �����ذ��� ���� ��ȸ�� �Ѿ��.
// �ٸ� ��� �����̴� 5���� ������, 5�� �̻��� ����Ҽ� ���⿡ �������� ���� ���ذ��� ���ǹ��� �����Ѵ�.
// ������ ��ǥ(9,9)���� �����Ͽ� ���̻��� 1���� ���ٸ� ���� ����� �����̼��� answer�� ���Ͽ� ������
// answer�� �����Ѵ�.
void BackTrack(vector<vector<int>> cur_board, vector<int> paper, int y, int x, int sum)
{
    if (sum >= answer) // ����ġ��.
        return;

    int range;
    vector<vector<int>> temp = cur_board;
    for (int i = y; i < 10; ++i)
        for (int j = x; j < 10; ++j)
        {
            if (cur_board[i][j] == 1)
            {
                range = CalRange(i, j, cur_board);
                for (int k = range; k >= 1; --k)
                {
                    if (paper[k - 1] == 0)
                        continue;
                    --paper[k - 1];
                    temp = OneToZero(i, j, k, cur_board);
                    BackTrack(temp, paper, y, x, sum + 1);
                    ++paper[k - 1];
                }
                return;
            }
        }
    answer = min(answer, sum);
}

void MakeAnswer()
{
    BackTrack(board, paper, 0, 0, 0);

    cout << (answer == MAX_NUM ? -1 : answer) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    board.resize(10, vector<int>(10, 0));
    paper.resize(5, 5);
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
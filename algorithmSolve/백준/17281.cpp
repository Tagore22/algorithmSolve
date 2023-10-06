#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// ������ �������Ƽ� ã�ƺ��� �Ｚ ��������.
// ��û ������� ������. ūƲ�� ���ڸ� ó���� ��ó���� 4������ �������� �̸� ���س���
// �� ������� 4������ ��� ��츦 ���ȣ��� �����ذ��� �ִ� ������ ���� ����س´�.
// �ٸ� �ӵ��� �ʹ� ���ȴ�. �뷫 ����� 3������ ���ȴ�.
// ���߿� �ٽ� ã�ƺ���.

// �ڼ��� ������ �ּ����� �����.

int point[51][10];
vector<vector<int>> board;
vector<bool> visit;
int N, answer, ans, board_num;

// ������ ���ϴ� �Լ�. ��Ʈ����ũ�� �̿��Ͽ���.
int AddPoint(int mask, int point)
{
    // ��Ʈ����ũ�� �������� �о�� �縦 �����Ͽ���.
    // �� �Լ��� ȣ��Ǿ��ٴ� ���� ������ ��Ÿ�̻� �ƴٴ� ���̱⿡
    // �ݵ�� ���ڰ� �����ϰ� �ȴ�. ���� mask�� ������ 1�� �ٲ۴�.
    mask |= 1;
    // 3 ~ 4 - Ÿ������ ��ȸ�ϸ� �� �翡 ���ڰ� �����ϴ��� Ȯ���Ѵ�.
    // ���� �����Ѵٸ� �̹� ��Ÿ�� ���� ������ �����̴�.
    for (int i = 3; i >= 4 - point; --i)
        if (mask & (1 << i))
            ++ans;

    // ���ڰ� �̵��Ѵ�.
    mask <<= point;
    // mask�� ��� Ŀ���ٵ� int���� ������� ������ ���⿡ ���ο� mask�� �ִ� 3������� �����Ͽ�
    // ��ȯ���ش�.
    int temp = 0, mul = 0;
    for (int i = 0; i <= 3; ++i)
    {
        if (mask & (1 << i))
            temp |= (1 << i);
    }
    return temp;
}

// ��� ��츦 ���غ��� �Լ�.
void BackTrack(int cur, int mask, int ining, int out) // ���° ��Ʈ��ŷ ����, ���� ����, �� �ƿ��ΰ�
{
    // ��� �̴��� ������ ��Ⱑ ������ ��� �� ������ ���� �ִ밪�� ���Ͽ� �����Ѵ�.
    if (ining == N + 1)
    {
        answer = max(answer, ans);
        return;
    }

    // ���� ������ ���Ѵ�.
    int plus = point[ining][board[board_num][cur]];

    // ������ 0�̶�� 1�ƿ��� �߰��ǰ� ���� 3�ƿ��� �Ǿ��ٸ�
    // �̴��� �ٲ��. �̶� ��� ��� �������.
    if (plus == 0)
    {
        ++out;
        if (out == 3)
        {
            ++ining;
            mask = 0;
            out = 0;
        }
    }
    // �׷��� �ʴٸ� �簡 ���ŵǰ� ������ ���ŵȴ�.
    else
    {
        mask = AddPoint(mask, plus);
    }

    cur = cur + 1 >= 9 ? 0 : cur + 1;
    BackTrack(cur, mask, ining, out);
}

// ��� ������ ����� �Լ�.
void MakeBoard(vector<int> vec)
{
    int v_size = vec.size();
    // 9���� ��������ٸ� �ٸ������ ����̹Ƿ� board�� �߰��ϰ� Ż����.
    if (v_size == 9)
    {
        board.push_back(vec);
        return;
    }

    // ���� 3���� ��������� 4��°��� ������ 1�� ������ �߰��Ѵ�.
    if (v_size == 3)
    {
        vec.push_back(1);
        MakeBoard(vec);
        return;
    }

    for (int i = 2; i <= 9; ++i)
    {
        if (visit[i])
            continue;

        vec.push_back(i);
        visit[i] = true;
        MakeBoard(vec);
        vec.pop_back();
        visit[i] = false;
    }
}

void MakeAnswer()
{
    visit.resize(10, false);
    // ��� ����� ���� ������. �ٸ� 1�� ������ ������ 4��Ÿ���̱⿡
    // ���ܵȴ�.
    for (int i = 2; i <= 9; ++i)
    {
        visit[i] = true;
        vector<int> vec(1, i);
        MakeBoard(vec);
        visit[i] = false;
    }

    answer = 0;
    // �̸� �������� ������� ������ ���غ��� ���� �ִ밪�� �����.
    for (int i = 0; i < board.size(); ++i)
    {
        ans = 0;
        board_num = i;
        BackTrack(0, 0, 1, 0);
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= 9; ++j)
            cin >> point[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
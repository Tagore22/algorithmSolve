#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// Ǯ��.
// �Ｚ ������µ� ���� ��鼭 ���� ���� �˰��� ������ �ƴϾ��� �ʹ�.
// �־��� ��θ� ���� ����ȭ�ؾ� �߰�, ����ȭ�� �ϸ鼭�� ��θ� ���� ©���� ������.
// ��Ʈ��ŷ ��ü�� ����� �ʾ�����, �������� �־��� ������ �ϳ��� 
// ���� �̵���Ű�� ��ġ�� �̹� �ٸ� ���� ������ �� ���� ���� �ʴ´ٴ� ����
// �̵��� �ٽô� �� ���� ���� ���ٴ� ���� �˾Ҵµ� �˰��� �׷��� �̵� ��ü��
// ��ȿȭ�Ѵٴ� ���̾���. �����Ƿ� ����� ��������.

// �ڼ��� ������ �ּ����� �����.

// P.S ��¥ �������;;

int board[33], point[33], turn[33], dice[10], pos[4];
bool visit[33];
int answer = 0;

// �� �������� ���� ����� �߻�ȭ �κ��̴�. ��θ� �ϳ��� �� �迭�� �����ϵ�,
// ��ġ ����Ʈ�� ¥���� ���� �迭�� ��ȣ�� �����Ͽ� �����Ѵ�.
// ����, �Ķ��� �κ��� ������ ���� turn �迭�� ������ �ߴ�.
// ���� ��ġ���� turn�κ��� -1�� �ƴ϶�� �̵����� �ϹǷ� �̵��Ѵ�.
// �̰��� �Ķ��� �̵��� �����̴�.
// ����, �� ���� ���� ��θ� ���� �������ش�.
void MakeBoard()
{
    for (int i = 0; i <= 20; ++i)
        board[i] = i + 1;
    board[21] = 21;
    for (int i = 22; i <= 26; ++i)
        board[i] = i + 1;
    board[27] = 20;
    board[28] = 29;
    board[29] = 25;
    for (int i = 30; i <= 31; ++i)
        board[i] = i + 1;
    board[32] = 25;

    for (int i = 0; i <= 20; ++i)
        point[i] = i * 2;
    point[21] = 0;
    point[22] = 13;
    point[23] = 16;
    point[24] = 19;
    point[25] = 25;
    point[26] = 30;
    point[27] = 35;
    point[28] = 22;
    point[29] = 24;
    point[30] = 28;
    point[31] = 27;
    point[32] = 26;

    memset(turn, -1, sizeof(turn));

    turn[5] = 22;
    turn[10] = 28;
    turn[15] = 30;
}

// ����� ��Ʈ��ŷ �����̴�. 
void BackTrack(int idx, int sum)
{
    if (idx == 10)
    {
        answer = max(answer, sum);
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int cur = pos[i];
        // ���� 21���̶�� ���������̴�. �������������� ���̻� �����ϼ� ���⿡
        // �������ش�.
        if (cur == 21)
            continue;

        // ���� ��ġ�� �����ص� �Ŀ� �̵��� �Ѵ�.
        int prev = cur;
        int move = dice[idx];
        // ���� ��ġ�� turn�� -1�� �ƴ϶��(�Ķ��� �̵��� ������ ��ġ���)
        // �Ķ��� �̵��� �Ѵ�.
        if (turn[cur] != -1)
        {
            cur = turn[cur];
            --move;
        }

        // �̵� ����.
        while (move > 0)
        {
            cur = board[cur];
            --move;
        }

        // �̵��� ��ġ�� ���������� �ƴѵ��� �ұ��ϰ�
        // �̹� �ٸ� ���� �����Ѵٸ� �̹� �̵� ��ü�� ��ȿȭ�Ѵ�.
        if (cur != 21 && visit[cur])
            continue;

        // �̵��� ���� �̵��� ���� ó��.
        visit[cur] = true;
        visit[prev] = false;
        pos[i] = cur;
        BackTrack(idx + 1, sum + point[cur]);
        // ���� �̵��� ���� ����.
        visit[cur] = false;
        visit[prev] = true;
        pos[i] = prev;
    }
}

void MakeAnswer()
{
    memset(pos, 0, sizeof(pos));
    memset(visit, false, sizeof(visit));
    MakeBoard();
    BackTrack(0, 0);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 10; ++i)
        cin >> dice[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
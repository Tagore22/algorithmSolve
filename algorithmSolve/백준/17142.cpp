#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Ǯ��.
// �Ｚ ������� ������� ������ �����ϰ� �������� ���� ����� �������.
// �����ϰ� �����ڸ� ��Ʈ��ŷ���� ���̷����� ������ǥ M���� ������ �� ��Ȳ���� �迭�� ��ĭ�� ���̷����� ���� �ּ����� �ð���
// ���ϴ� �����̴�. ��, ��Ʈ��ŷ���� ��ǥ������ ������ �� ��� ��Ȳ���� BFS�� �ּҰ��� ���ϸ� �ȴ�.
// �ٸ� �����ؾ��� �κ��� �ִµ�, ���� ��Ȱ��ȭ ���̷����� ��ġ�� ��ĭ�� �ƴϱ� ������ �̰��� ������ ��ġ��� ���� �ʰ�
// �� ������ ������ �ȴٴ� ���̴�. �� ���� �ϳ� �ָ��� �κ��ε� BFS�� �Ѵܰ� �����Ҷ����� ���� ��ĭ�� �ִ��� Ȯ���� �ؾ��Ѵٴ� ���̴�.
// ���п� Ǯ��������, �ð��� 200ms�� �Ѿ��. �ٸ� Ǯ�̸� �����ߴµ� �� Ǯ�̿��� �ƿ� ��ĭ�� ���� ���س���, BFS����� ��ĭ�� ���� ���
// �� �� ��ĭ�� ���� �ϳ��� �ٿ�����. while���� ���ǹ����� ��ĭ�� ���� 0���� ���� ���� �����ϰ� �Ͽ� �Ź� ��ĭ�� ���� ���ؾ��ϴ�
// �ð��� �Ƴ��� �־���.

vector<vector<int>> board, temp;
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // �� �� �� ��.
vector<pair<int, int>> virus, virus_from;
const int MAX_NUM = 987654321;
int N, M, answer = MAX_NUM, total_zero = 0; // ��ĭ�� ��. �̹� ����Ǯ���� �ӵ��� �ø��µ� �ٽ� �κ��̾���.

bool FuncRound()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (board[i][j] == 0)
                return false;
    return true;
}

int BFS()
{
    board = temp;
    queue<pair<int, int>> que;
    for (int i = 0; i < virus_from.size(); ++i)
    {
        que.push(virus_from[i]);
        board[virus_from[i].first][virus_from[i].second] = 3;
    }

    int dy, dx, y, x, ans = 0, Qsize, zero = total_zero;
    while (!que.empty() && zero > 0)
    {
        if (ans >= answer)
            break;
        ++ans;

        Qsize = que.size();
        for (int iter = 0; iter < Qsize; ++iter)
        {
            y = que.front().first;
            x = que.front().second;
            que.pop();

            for (int i = 0; i < 4; ++i)
            {
                dy = y + rot[i][0];
                dx = x + rot[i][1];

                if (dy < 0 || dy >= N || dx < 0 || dx >= N || board[dy][dx] == 1
                    || board[dy][dx] == 3 || board[dy][dx] == 4)
                    continue;

                if (board[dy][dx] == 0)
                    --zero;

                board[dy][dx] = 4;
                que.push(make_pair(dy, dx));
            }
        }
    }
    if (FuncRound())
        return ans;
    else
        return MAX_NUM;
}

void BackTrack(int idx, int num)
{
    if (num == M)
    {
        answer = min(answer, BFS());
        return;
    }

    for (int i = idx + 1; i < virus.size(); ++i)
    {
        virus_from.push_back(virus[i]);
        BackTrack(i, num + 1);
        virus_from.pop_back();
    }
}

void MakeAnswer()
{
    BackTrack(-1, 0);

    cout << (answer == MAX_NUM ? -1 : answer) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
                virus.push_back(make_pair(i, j));
            else if (board[i][j] == 0)
                ++total_zero;
        }
    temp = board;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
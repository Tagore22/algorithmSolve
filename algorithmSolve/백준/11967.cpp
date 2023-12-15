#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

// Ǯ��.
// �������� �����ϵ� ����� ��������. �����¿쿡 ���� ���� �����θ� �̵��� �����ϸ�
// �� �濡�� �ٸ� ���� ���� ų�� �ִ� ����ġ�� �����Ҽ��� �ִ�. �̶� ���� ų�� �ִ� �ִ� ������ ����ؾ��Ѵ�.
// ��������δ� ���� ���� ����� ����� deque�� �̿��Ͽ� �����ϰ� �����鼭 ������ ���� ���� ���� �߰��ϰ�
// deque�� ��ȸ�ϸ� ���� �������� ���� �湮���� ���� ����� ���Ӱ� �湮�� �������� ���� �����س�����
// BFS�� ��ȸ�ߴ�. ������ �̰ͺ��� �� ���� ����� �־���.

// �ڼ��� ������ �ּ����� �����.

vector<pair<int, int>> board[101][101];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // ����, ����, ������, �Ʒ���.
int N, M;

int BFS()
{
    queue<pair<int, int>> que;
    que.push(make_pair(1, 1));
    // �� ����� �湮�ߴ����� ���� �迭.
    vector<vector<bool>> visit(N + 1, vector<bool>(N + 1, false));
    // �� ����� ���� ���������� ���� �迭.
    vector<vector<bool>> isLight(N + 1, vector<bool>(N + 1, false));
    visit[1][1] = true;
    isLight[1][1] = true;
    int ans = 1;
    deque<pair<int, int>> deq;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        // ���� �濡�� ���� ų�� �ִ� ��� ����� ��ȸ�Ѵ�.
        for (auto next : board[y][x])
        {
            // ���� ���� ������ ���� ���̶��
            if (!isLight[next.first][next.second])
            {
                // ���� Ű�� ������ ans�� ������Ų��.
                isLight[next.first][next.second] = true;
                ++ans;
                // ���� ���� �������� ���� �湮���� ���� ��鿡 ��Ͽ� �߰��Ѵ�.
                deq.push_back(next);
            }
        }

        // deque�� ���Ұ� �߰��ǰų� �����ɽ� ������ �ݺ��ڵ��� ��� ��ȿȭ�Ǳ� ������
        // �ݺ��ڸ� �̿����� �ʰ� Ƚ���� �̿��Ͽ��� �ߴ�.
        int idx = deq.size();
        // ���� ��� ���ҵ��� ��ȸ�Ѵ�.
        for (int iter = 0; iter < idx; ++iter)
        {
            int i = deq.front().first;
            int j = deq.front().second;
            deq.pop_front();

            bool isFind = false;
            // ���� ��ġ���� 4������ ��ȸ�Ѵ�.
            for (int k = 0; k < 4; ++k)
            {
                int di = i + rot[k][0];
                int dj = j + rot[k][1];

                // �迭���� ����ų� �湮���� ���� ���̶�� �����Ѵ�.
                if (di <= 0 || di > N || dj <= 0 || dj > N || !visit[di][dj])
                    continue;

                // �湮�� ���� �Ѱ��̶� �ִٸ� �ٷ� ��ĭ�� ���� ��ġ�� �̵��� ����������.
                // �湮���� �����ϰ� queue�� �߰����ش�.
                visit[i][j] = true;
                que.push(make_pair(i, j));
                isFind = true;
                break;
            }

            // �湮���� ���Ѵٸ� �ٽ� deque�� �߰��Ѵ�.
            if (!isFind)
                deq.push_back(make_pair(i, j));
        }
    }
    return ans;
}

void MakeAnswer()
{
    int answer = BFS();
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    pair<int, int> from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from.first >> from.second >> to.first >> to.second;
        board[from.first][from.second].push_back(to);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
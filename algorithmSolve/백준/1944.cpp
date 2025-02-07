#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Ǯ��.
// �������� �����ֵ� ����� ��������. �켱 ������� �ܾ ���Դµ� ��� �̰� �ǹ̰� ������. ������ BFS �˰�����
// ���� ��ü�� 4�������� �̵����� ��츦 �����Ͽ� que�� ����ֱ� �����̴�. �������� ���ϴ� ���� S���� K������ 
// �Ÿ����� �����̴�. �ٸ� S���� K�� ���� �Ǵٸ� K�� �����Ҷ� S���� �ι�° K�� �Ÿ��� ��ǻ� ù��° K����
// �ι�° K�� �Ÿ����� ������ �ȵȴ�. ��������� �� ������ S �� K���� �������� �ξ����� BFS�� ���ؼ�
// �� �������� �Ÿ��� ������, MST�� �̿��Ͽ� �� �Ÿ����� �ּҰ��� ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

char board[50][50];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }, idx[50][50], dist[251][251];
int N, M;
pair<int, int> from;
vector<pair<int, int>> pos;

// y, x���� �ٸ� S Ȥ�� K������ ��� �Ÿ����� ���Ѵ�.
void BFS(int y, int x)
{
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    bool visit[50][50] = { false, };
    visit[y][x] = true;
    int answer = -1;

    while (!que.empty())
    {
        ++answer;
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int cy = que.front().first;
            int cx = que.front().second;
            que.pop();

            // �Ǵٸ� K Ȥ�� S�� �߰������� �Ÿ��� �����Ѵ�.
            if (board[cy][cx] == 'K' || board[cy][cx] == 'S')
            {
                int from = idx[y][x];
                int to = idx[cy][cx];
                dist[from][to] = min(dist[from][to], answer);
            }

            for (int i = 0; i < 4; ++i)
            {
                int ny = cy + rot[i][0];
                int nx = cx + rot[i][1];

                if (ny < 0 || ny >= N || nx < 0 || nx >= N || board[ny][nx] == '1' || visit[ny][nx])
                    continue;
                que.push(make_pair(ny, nx));
                visit[ny][nx] = true;
            }
        }
    }
}

// ��� �Ÿ� ������ �ּҰ��� ���Ѵ�.
void Prim()
{
    bool visit[251] = { false, };
    int mindist[251];
    for (int i = 0; i <= M; ++i)
        mindist[i] = 2501;
    // ��� �������� �����ϵ� ����� ���⿡ 0�� ��ġ���� �����Ѵ�.
    mindist[0] = 0;
    int answer = 0;

    // K�� �ִ� 250���� S���� ���ؾ������� M - 1������ �ƴ� M������ ��ȸ�ؾ��Ѵ�.
    for (int iter = 0; iter <= M; ++iter)
    {
        int u = -1;
        for (int i = 0; i <= M; ++i)
            if (!visit[i] && (u == -1 || mindist[i] < mindist[u]))
                u = i;

        answer += mindist[u];
        visit[u] = true;

        // �ٸ� �������� ��ȸ�ϸ� ���� �湮���� ���� �������� �ּҰ����� �����Ѵ�.
        for (int i = 0; i <= M; ++i)
            if (!visit[i] && mindist[i] > dist[u][i])
                mindist[i] = dist[u][i];
    }
    // answer�� 2501�� �Ѿ��ٴ� ���� � �� �����鳢�� �����Ҽ� ���ٴ� ���� �ǹ��ϱ⿡
    // -1�� ����Ѵ�.
    cout << (answer >= 2501 ? -1 : answer) << '\n';
}

void MakeAnswer()
{
    for (int i = 0; i <= M; ++i)
        for (int j = 0; j <= M; ++j)
            dist[i][j] = 2501;
    for (auto& here : pos)
    {
        int y = here.first;
        int x = here.second;
        BFS(y, x);
    }
    Prim();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int num = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'S' || board[i][j] == 'K')
            {
                pos.push_back(make_pair(i, j));
                idx[i][j] = num++;
            }
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
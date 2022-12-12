#include <iostream>
#include <deque>

using namespace std;

//��Ʈ�� �ִ� 0-1BFS�� ã�Ƽ� ������ Ǯ��.
//���� BFS�� ũ�� �ٸ����� ������, ������ ���� �����̳ʿ� �յڷ� ���Ҹ� �����ؾ��ϱ⿡ queue��� deque�� ���Ǿ���.

//Ǯ��
//���� Ǯ�̿� Ǯ�� ��ü�� ����. �ٸ� 0-1BFS�� deque�� Ư���� ���� ���� �������� ���ư��� �������� ����ġ�� �߰��ȴٸ� 
//�ּ� ����ġ���� �־����⿡ deque�� ���� �ƴ� �ڿ� �ξ� ��������� ���귮�� ���̱⿡ ����ȭ�Ǿ���.
//�׷��Ƿ� �ð����⵵�� ���ϱ� �������µ�, �յڷ� ���Ҹ� ������ ���п� ����ġ�� ���� ���Һ��� ��ȸ�� �����ϴ�.
//�̷� ���� ���� ��� �������� �� �ѹ��� ���� �ִ� ��� ������ ���� ������ �Ͼ�⿡ �ð����⵵�� BFS�� ������ O(V+E)�� �ȴ�.
//(��� �������� �̵� ������ ������ ���� �̵��� �õ��ϳ�, deque�� �յ� ����(����ġ�� ����)�� ���� �� ������ �����ϴ� ������ ���� �ϳ��� �ȴ�)
//�׷��Ƿ� ���� ������ ��� ������ �� V + ��� ������ �� �ѹ��� V

int board[100][100];
int walls[100][100];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };
int M, N;
const int MAX_NUM = 987654321;

void ZeroOne(int y, int x)
{
    deque<pair<int, int>> deq;
    deq.push_back(make_pair(y, x));

    while (!deq.empty())
    {
        int now_y = deq.front().first;
        int now_x = deq.front().second;
        deq.pop_front();

        for (int i = 0; i < 4; ++i)
        {
            int cy = now_y + dy[i];
            int cx = now_x + dx[i];

            if (cy < 0 || cy >= N || cx < 0 || cx >= M)
                continue;

            if (walls[now_y][now_x] + board[cy][cx] < walls[cy][cx])
            {
                walls[cy][cx] = walls[now_y][now_x] + board[cy][cx];

                if (board[cy][cx] == 1)
                    deq.push_back(make_pair(cy, cx));
                else
                    deq.push_front(make_pair(cy, cx));
            }
        }
    }
}

void MakeAnswer()
{
    ZeroOne(0, 0);
    cout << walls[N - 1][M - 1] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j)
            walls[i][j] = MAX_NUM;
    walls[0][0] = 0;

    cin >> M >> N;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < M; ++j)
            board[i][j] = str[j] - '0';
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

//�ϳ� ���� �ָԾ��� �����̴�. ����� �ܼ��� �Ź� �� ������ �ִ� �������� ���� ������, ���� ���� �»�ܿ� �ִ� ��ġ�� ����⸦
//�����Ѵ�. �׷��� ���̻� ������ �ִ� ����Ⱑ ������������ �̵��ϴ� ĭ���� ����ϸ� �ȴ�.
//ó������ �� �������� ��ǥ�� map�� ����ص״ٰ� �Ź� ��ȸ�ذ��� ���Ұ��� ������ �ִ� ������� �ּҰ��� ���ذ��� Ǯ�̸� �߾��µ�
//�׷��� �ϸ� DFS * map ��ȸ * �ִ� �������� ���� �Ǿ� �ð��� ������ �ʰ��ϰ� �ȴ�. ���� �׳� �����ϰ� �� ��� ��ġ���� ������ �ִ�
//���� ����� ����⸦ ã�Ƽ� �Ծ�鼭 �����̴� ĭ���� ���ϸ� �Ǿ���.
//�ð� ���⵵�� N�� �ִ� 20�̱⿡ 400ĭ�̹Ƿ� BFS���� O(V+E)(400 + (400 * 4))�� ���ĭ�� ����Ⱑ �ְ� ������ �ִٴ� �����Ͽ�
//400������ ����⸦ �����Ƿ� 2000 * 400���� 80���̵Ǹ�, ����δ� n�� 4������ �ȴ�.

using namespace std;

const int MAX_NUM = 20;
int board[MAX_NUM][MAX_NUM];
int N, shark_power = 2;
vector<pair<int, pair<int, int>>> point;
pair<int, int> shark;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { -1,0,1,0 };
bool check[MAX_NUM][MAX_NUM];

void BFS(int y, int x)
{
    queue<pair<int, pair<int, int>>> que;
    que.push(make_pair(0, make_pair(y, x)));
    check[y][x] = false;

    while (!que.empty())
    {
        int cost = que.front().first;
        int y = que.front().second.first;
        int x = que.front().second.second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int cy = y + dy[i];
            int cx = x + dx[i];

            if (cy < 0 || cy >= N || cx < 0 || cx >= N || !check[cy][cx] || board[cy][cx] > shark_power)
                continue;
            if (board[cy][cx] < shark_power && board[cy][cx] != 0)
                point.push_back(make_pair(cost + 1, make_pair(cy, cx)));
            que.push(make_pair(cost + 1, make_pair(cy, cx)));
            check[cy][cx] = false;
        }
    }
}

void MakeAnswer()
{
    int answer = 0, eaten = 0;
    while (true)
    {
        point.clear();
        memset(check, true, sizeof(check));
        BFS(shark.first, shark.second);
        if (point.size() == 0)
        {
            cout << answer << '\n';
            return;
        }
        sort(point.begin(), point.end());
        answer += point[0].first;
        board[point[0].second.first][point[0].second.second] = 0;
        shark = make_pair(point[0].second.first, point[0].second.second);
        ++eaten;
        if (eaten == shark_power)
        {
            ++shark_power;
            eaten = 0;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                shark = make_pair(i, j);
                board[i][j] = 0;
            }
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
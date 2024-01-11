#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

// Ǯ��.
// ���� ��ü�� ����� ������ �ƴϴ�. 5���� ���� �����ϰ� �װ� �� ���� �ð�������� ȸ���� �����Ҷ�
// {0, 0, 0}���� {4, 4, 4}�� ���ް����� �ּ����� �̵�Ƚ���� ����ϸ� �ȴ�.
// �ٸ� �����ϴ� ���� ������ �����ϴ�. 5���� ���� �����ϰ� �ױ�, �� ���� ȸ���ϴ� ���, �� ��쿡 BFS ��ȸ�� �ϴ� ��츦
// ��� �����ؾ��Ѵ�. ������� �׷��� ������ �ӵ��� �ʹ� ������ ã�ƺ��� 3������ ��������.

// 1. ����ġ��
// 2. �翬������ ���ͺ��� �Ϲ� �迭�� �� ����. �ٸ� ũ�� ���̴� ���� ������ �̹��� ��� ���ͳ� �迭�� �ſ� ����ϰ� ����ϹǷ� �� ���̰�
// �������� �ϴ�.
// 3. ť�� ���к��� �����. ��������� clear()�� ���°� �� ������.

// ���� ��ü�� ��ȣ�� ��������. �����ڰ� ���Ƿ� ������ �������� �������̷��µ� �׷� ���� �����ϰ� ���°� �ƴѰ�?
// ������ �����δ� 0, 0, 0�� 4, 4, 4�� �������� ������ �������־���. ���� ������ ������ �̵��� �����ϴٰ� �ؼ�
// ���� �밢������ �����ߴµ� ���󺸴� �밢���� ���ܿ���. �̰� �� 55�ۼ�Ʈ¥�� �����ΰ�?

// �ڼ��� ������ �ּ����� �����.

int board[5][5][5], cube[5][5][5];
vector<int> seq;
// ���� BFS ��ȸ�� ���� �ƴ� ť�� ������ ť�� ���к��� ������� �������� ���� ���.
// ť�� clear()�� ���� �����̴�.
deque<pair<int, pair<int, int>>> que;
// �˰��� �밢���� ���ܿ���.
int rot[6][3] = { {0, 0, -1}, {0, -1, 0}, {0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {-1, 0, 0} };
bool visit[5][5][5];
int answer = 987654321;

// BFS ��ȸ �Լ�.
void BFS()
{
    // ������ ���� ����.
    que.clear();
    que.push_back(make_pair(0, make_pair(0, 0)));
    // �湮 ������ ����.
    memset(visit, false, sizeof(visit));
    visit[0][0][0] = true;
    int cost = -1;

    while (!que.empty())
    {
        int qsize = que.size();
        ++cost;
        for (int iter = 0; iter < qsize; ++iter)
        {
            int z = que.front().first;
            int y = que.front().second.first;
            int x = que.front().second.second;
            que.pop_front();

            // ������ ���������� �̵�Ƚ���� �����غ���.
            if (z == 4 && y == 4 && x == 4)
            {
                answer = min(answer, cost);
                return;
            }

            for (int i = 0; i < 6; ++i)
            {
                int dz = z + rot[i][0];
                int dy = y + rot[i][1];
                int dx = x + rot[i][2];

                if (dz < 0 || dz >= 5 || dy < 0 || dy >= 5 || dx < 0 || dx >= 5 ||
                    visit[dz][dy][dx] || cube[dz][dy][dx] == 0)
                    continue;

                visit[dz][dy][dx] = true;
                que.push_back(make_pair(dz, make_pair(dy, dx)));
            }
        }
    }
}

// idx��° ���� �ð�������� ȸ���ϴ� �Լ�.
void RotationCube(int idx)
{
    int plus = 4;
    // ���ͺ��� �迭�� ������.
    int temp[5][5];
    for (int j = 0; j < 5; ++j)
    {
        for (int i = 0; i < 5; ++i)
            temp[i][j] = cube[idx][j + plus][i];
        plus -= 2;
    }
    // ȸ����Ų ��ü ���� ���� ������ ����.
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            cube[idx][i][j] = temp[i][j];
}

// ��� ���� ȸ���� �����ϴ� �Լ�.
void RotationCubeAll()
{
    for (int a = 0; a < 4; ++a)
    {
        RotationCube(0);
        // ȸ���������� �Ա��� �����ٸ� �����Ѵ�.
        if (cube[0][0][0] == 0)
            continue;
        for (int b = 0; b < 4; ++b)
        {
            RotationCube(1);
            for (int c = 0; c < 4; ++c)
            {
                RotationCube(2);
                for (int d = 0; d < 4; ++d)
                {
                    RotationCube(3);
                    for (int e = 0; e < 4; ++e)
                    {
                        RotationCube(4);
                        // ������ �������� �ʴٸ� BFS ��ȸ�� �غ���.
                        if (cube[4][4][4] == 1)
                            BFS();
                        // 5x5x5�� �ּҰ��� 12�̴�. �׷��⿡ ���簪�� 12�� �Ǿ��ٸ�
                        // ����ϰ� Ż���Ѵ�. ����� 3���� ������ 1��.
                        if (answer == 12)
                        {
                            cout << answer << '\n';
                            exit(0);
                        }
                    }
                }
            }
        }
    }
}

void MakeAnswer()
{
    for (int i = 0; i < 5; ++i)
        seq.push_back(i);
    while (true)
    {
        // ��� ���� ������� �״´�.
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 5; ++j)
                for (int k = 0; k < 5; ++k)
                    cube[i][j][k] = board[seq[i]][j][k];
        // ��� ���� ȸ�����Ѻ���.
        RotationCubeAll();
        // ���̻� ������� ������ ���ٸ� Ż���Ѵ�.
        if (!next_permutation(seq.begin(), seq.end()))
            break;
    }
    cout << (answer != 987654321 ? answer : -1) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            for (int k = 0; k < 5; ++k)
                cin >> board[i][j][k];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
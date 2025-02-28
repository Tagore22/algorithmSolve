#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// BFS�� �̿��� �����̴�. �� �׷��� �ߺ��� ���� bool �迭�� ������ �߿��ѵ� ó������ [y��ġ][x��ġ][����][�������� ����]��
// 4���� �迭�� ���������� ����� ���� �ʾҴ�. ���� 3���� ���� ó�� S���� �������� �̵��� C�� �ѹ� �鸮��, �ٽ� S�� �̵��Ŀ�
// ������ C�� �����ؾ������� C�� ���������� �������� ������ ��� �پ��� ������ bool �迭�� �ߺ� �湮�� �������� ������.
// ���� �������� ������ �ƴ� ��Ʈ����ũ�� ���ؼ� �� C�� �ٸ��� ǥ���ؾ��ߴ�. �ᱹ �Է¿��� C�� ��� A�� B�� ��ȯ�Ͽ� ����
// �ϰ� BFS���� ��Ʈ����ũ�� ó���ߴ�.

// �ڼ��� ������ �ּ����� �����.

struct pos
{
    int Y;
    int X;
    int Dir;
    int Mask;
};

char Board[50][50];
int Rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int N, M;
pair<int, int> From;

void BFS()
{
    queue<pos> Que;
    Que.push(pos{ From.first, From.second, 4, 0 });
    bool Visit[50][50][5][(1 << 2)] = { false, };
    Visit[From.first][From.second][4][0] = true;
    int Answer = -1;
    while (!Que.empty())
    {
        ++Answer;
        int Qsize = Que.size();
        for (int iter = 0; iter < Qsize; ++iter)
        {
            int Y = Que.front().Y;
            int X = Que.front().X;
            int Dir = Que.front().Dir;
            int Mask = Que.front().Mask;
            Que.pop();

            // 2���� ������ ��� ����� ���.
            if (Mask == 3)
            {
                cout << Answer << '\n';
                return;
            }

            for (int i = 0; i < 4; ++i)
            {
                if (Dir == i)
                    continue;

                int Ny = Y + Rot[i][0];
                int Nx = X + Rot[i][1];

                if (Ny < 0 || Ny >= N || Nx < 0 || Nx >= M || Board[Ny][Nx] == '#')
                    continue;

                int Nmask = Mask;
                // C�� �湮�� ��� ��Ʈ����ũ�� �� �������� ǥ�ø� �ٸ��� �Ѵ�.
                if (Board[Ny][Nx] == 'A' || Board[Ny][Nx] == 'B')
                    Nmask |= (1 << (Board[Ny][Nx] - 'A'));

                if (Visit[Ny][Nx][i][Nmask])
                    continue;

                Que.push(pos{ Ny, Nx, i, Nmask });
                Visit[Ny][Nx][i][Nmask] = true;
            }
        }
    }
    cout << -1 << '\n';
}

void MakeAnswer()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    int Num = 0;
    for (int i = 0; i < N; ++i)
    {
        string Str;
        cin >> Str;
        for (int j = 0; j < M; ++j)
        {
            Board[i][j] = Str[j];
            if (Board[i][j] == 'S')
                From = make_pair(i, j);
            else if (Board[i][j] == 'C')
                Board[i][j] = 'A' + Num++;
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// BFS를 이용한 문제이다. 늘 그렇듯 중복을 막는 bool 배열의 구현이 중요한데 처음에는 [y위치][x위치][방향][나누어준 개수]로
// 4차원 배열을 구상했으나 제대로 되질 않았다. 예제 3번을 보면 처음 S에서 왼쪽으로 이동해 C를 한번 들리고, 다시 S로 이동후에
// 왼쪽의 C를 무시해야하지만 C를 만날때마다 나누어준 개수가 계속 줄어들기 때문에 bool 배열로 중복 방문을 막을수가 없었다.
// 따라서 나누어준 개수가 아닌 비트마스크를 통해서 각 C를 다르게 표현해야했다. 결국 입력에서 C일 경우 A와 B로 변환하여 저장
// 하고 BFS에서 비트마스크로 처리했다.

// 자세한 설명은 주석으로 남긴다.

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

            // 2개의 선물을 모두 배분한 경우.
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
                // C를 방문한 경우 비트마스크로 각 선물마다 표시를 다르게 한다.
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
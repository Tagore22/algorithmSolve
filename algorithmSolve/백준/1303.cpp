#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

//풀이
//2차원 배열을 순회하며 DFS를 호출하되, 같은 문자끼리만 이동 가능하다는 점에 주의할것. 또한, 아군의 수를 모두 더해서 제곱하는게 아닌
//더할때마다 제곱해서 더해야 한다는 것도 잊으면 안된다.

char board[100][100];
int tran[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
bool check[100][100];
int N, M;

int DFS(int y, int x, char c)
{
    int num = 1;
    check[y][x] = true;
    for (int i = 0; i < 4; ++i)
    {
        int dy = y + tran[i][0];
        int dx = x + tran[i][1];

        if (dy < 0 || dy >= M || dx < 0 || dx >= N || check[dy][dx] || board[dy][dx] != c)
            continue;

        num += DFS(dy, dx, c);
    }

    return num;
}

void MakeAnswer()
{
    int our = 0, enemy = 0;
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            if (!check[i][j])
            {
                int cur = DFS(i, j, board[i][j]);
                if (board[i][j] == 'W')
                    our += pow(cur, 2);
                else
                    enemy += pow(cur, 2);
            }
    cout << our << ' ' << enemy << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(check, false, sizeof(check));

    cin >> N >> M;
    string str;
    for (int i = 0; i < M; ++i)
    {
        cin >> str;
        for (int j = 0; j < N; ++j)
            board[i][j] = str[j];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
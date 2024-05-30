#include <iostream>

using namespace std;

// 풀이.
// DFS 문제이다. 배열의 모든 맨위칸에서 시작해서 어느 한곳이든 맨 아래로 이동할수 있다면 YES를, 그렇지 않다면
// NO를 출력하면 된다. 

// 자세한 설명은 주석으로 남긴다.

bool check[1000][1000] = { false, }, board[1000][1000];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 왼쪽, 위쪽, 오른쪽, 아래쪽
int M, N;

// DFS 순회함수.
void DFS(int y, int x)
{
    // 만약 맨 아래쪽에 도달하였다면 YES를 출력하고 프로그램을 종료한다.
    if (y == M - 1)
    {
        cout << "YES" << '\n';
        exit(0);
    }

    // 4방향으로 이동해본다.
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + rot[i][0];
        int nx = x + rot[i][1];

        // 배열을 벗어났거나, 이미 방문한 곳이거나, 전류가 통하지 않는 곳이라면 무시한다.
        if (ny < 0 || ny >= M || nx < 0 || nx >= N || check[ny][nx] || board[ny][nx])
            continue;
        // 방문 여부를 수정하고 재귀호출한다.
        check[ny][nx] = true;
        DFS(ny, nx);
    }
}

void MakeAnswer()
{
    // 모든 맨 위칸을 순회한다.
    for (int i = 0; i < N; ++i)
    {
        // 아직 방문하지 않았으며, 전류가 흐르는 곳이라면 DFS순회를 해본다.
        if (!check[0][i] && !board[0][i])
        {
            check[0][i] = true;
            DFS(0, i);
        }
    }
    // 모든 순회에도 맨 아래까지 도달못했다면 NO를 출력한다.
    cout << "NO" << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N;
    string str;
    for (int i = 0; i < M; ++i)
    {
        cin >> str;
        for (int j = 0; j < N; ++j)
            board[i][j] = str[j] == '0' ? false : true;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
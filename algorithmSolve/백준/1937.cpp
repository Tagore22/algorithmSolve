#include <iostream>
#include <cstring>

using namespace std;

const int MAXNUM = 500;
int cashe[5][MAXNUM][MAXNUM];
int board[MAXNUM][MAXNUM];
int N;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };
int answer = 0;

//시작점조차 알수 없기에 모든 정점에서 DFS를 시작해야하는데 이러면 500을 4번곱해야 하기에 결코 시간내에 풀수없다.
//생각해보면 모든 정점은 상,하,좌,우 4곳으로밖에 못움직이는데 어떤 정점 A에 왼쪽에서 접근하는 방법은 시작점이 어디든
//모두 똑같이 왼쪽에서 한번 움직이므로 캐싱할수 있다. 움직이는 방법은 4군데이므로 4개의 배열이 필요하며
//시작점을 잡기가 애매했기에 아무것도 없는 0을 추가해 총 5개의 배열로 캐싱하면 된다.
//ex) 1,1에서 1,2로 이동하는건 한칸 이동하는 것이며 그 시작점이 2,0이든 3,0이든 어디든지 단 한번의 이동이다.

int DFS(int prev, int y, int x)
{
    int& ans = cashe[prev][y][x];
    if (ans != -1)
        return ans;
    ans = 1;
    for (int i = 0; i < 4; ++i)
    {
        int cy = y + dy[i];
        int cx = x + dx[i];

        if (cy >= N || cx >= N || cy < 0 || cx < 0 || board[cy][cx] <= board[y][x])
            continue;

        ans = max(ans, DFS(i + 1, cy, cx) + 1);
    }
    return ans;
}

void MakeAnswer()
{
    int answer = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            answer = max(answer, DFS(0, i, j));
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cashe, -1, sizeof(cashe));

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
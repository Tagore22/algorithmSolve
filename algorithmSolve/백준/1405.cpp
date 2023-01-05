#include <iostream>
#include <cstring>

using namespace std;

//문제가 아리송했던 문제. 모든 N번의 이동중에서 같은 곳을 방문하지 않는 확률인줄 알았는데, 그게 아니라 N번 움직이는 도중에 방문했던 곳을
//또다시 방문하지 않는 확률이었다.

//풀이
//이동 할수 있는 모든 경우를 백트래킹으로 이동하되, 이미 방문했던 곳을 또다시 방문하는 경우라면 함수를 종료하여 무시한다.
//중요한 점은, 한번 이동시 방문했던 곳은 다음 시작(N번의 이동을 마쳤거나 혹은, 이미 방문한곳을 방문하여 함수가 return된 상태)에서는
//무효하기에 백트래킹시 true와 false를 잊지 않고 매번 갱신해주어야 한다.

int per[4];
int trans[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} }; //동서남북 순
int N;
double answer = 0.0;
bool board[29][29]; //동서남북으로 최대 N번씩 움직일수 있어야하는 크기.

void BackTrack(int y, int x, int move, double plus) //y좌표, x좌표, 남은 이동수, 현재 좌표에 도달할수 있는 확률.
{
    if (board[y][x]) //이미 방문한 곳이라면 이번 이동은 무시한다.
        return;

    if (move == 0) //마지막 N번째 방문이면서 도달하지 않던 곳에 도달했다면 그 확률을 최종답에 더한후 이번 이동종료.
    {
        answer += plus;
        return;
    }

    board[y][x] = true; //이번 이동에서 현 좌표는 방문했음을 기록.
    for (int i = 0; i < 4; ++i) //동서남북으로 모두 이동해보되, 이동할 확률이 0이라면 무시.
    {
        if (per[i] == 0)
            continue;

        int dy = y + trans[i][0];
        int dx = x + trans[i][1];

        BackTrack(dy, dx, move - 1, plus * (per[i] / 100.0));
    }
    board[y][x] = false; //이번 이동은 종료되었으므로 방문했던 곳은 모두 무효화시킨다.
}

void MakeAnswer()
{
    BackTrack(N, N, N, 1.0);

    cout.precision(9);
    cout << fixed;
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(board, false, sizeof(board));

    cin >> N;
    for (int i = 0; i < 4; ++i)
        cin >> per[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
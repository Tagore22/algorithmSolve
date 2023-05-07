#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// 풀이.
// 삼성 문제라는데 세상 살면서 가장 빡쎈 알고리즘 문제가 아니었나 싶다.
// 주어진 경로를 직접 매핑화해야 했고, 매핑화를 하면서도 경로를 대충 짤수도 없었다.
// 백트래킹 자체는 어렵지 않았으나, 문제에서 주어진 조건중 하나인 
// 말을 이동시키는 위치에 이미 다른 말이 있으면 그 말은 고르지 않는다는 것이
// 이동후 다시는 그 말을 고를수 없다는 건줄 알았는데 알고보니 그러한 이동 자체를
// 무효화한다는 뜻이었다. 여러므로 어려운 문제였다.

// 자세한 설명은 주석으로 남긴다.

// P.S 진짜 어려웠다;;

int board[33], point[33], turn[33], dice[10], pos[4];
bool visit[33];
int answer = 0;

// 이 문제에서 제일 어려운 추상화 부분이다. 경로를 하나의 긴 배열로 매핑하되,
// 마치 리스트를 짜듯이 다음 배열의 번호를 대입하여 매핑한다.
// 또한, 파란색 부분의 구현을 위해 turn 배열을 만들어야 했다.
// 현재 위치에서 turn부분이 -1이 아니라면 이동가능 하므로 이동한다.
// 이것이 파란색 이동의 구현이다.
// 또한, 각 점수 역시 경로를 따라 매핑해준다.
void MakeBoard()
{
    for (int i = 0; i <= 20; ++i)
        board[i] = i + 1;
    board[21] = 21;
    for (int i = 22; i <= 26; ++i)
        board[i] = i + 1;
    board[27] = 20;
    board[28] = 29;
    board[29] = 25;
    for (int i = 30; i <= 31; ++i)
        board[i] = i + 1;
    board[32] = 25;

    for (int i = 0; i <= 20; ++i)
        point[i] = i * 2;
    point[21] = 0;
    point[22] = 13;
    point[23] = 16;
    point[24] = 19;
    point[25] = 25;
    point[26] = 30;
    point[27] = 35;
    point[28] = 22;
    point[29] = 24;
    point[30] = 28;
    point[31] = 27;
    point[32] = 26;

    memset(turn, -1, sizeof(turn));

    turn[5] = 22;
    turn[10] = 28;
    turn[15] = 30;
}

// 평범한 백트래킹 구현이다. 
void BackTrack(int idx, int sum)
{
    if (idx == 10)
    {
        answer = max(answer, sum);
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int cur = pos[i];
        // 현재 21번이라면 도착지점이다. 도착지점에서는 더이상 움직일수 없기에
        // 무시해준다.
        if (cur == 21)
            continue;

        // 현재 위치를 복사해둔 후에 이동을 한다.
        int prev = cur;
        int move = dice[idx];
        // 현재 위치의 turn이 -1이 아니라면(파란색 이동이 가능한 위치라면)
        // 파란색 이동을 한다.
        if (turn[cur] != -1)
        {
            cur = turn[cur];
            --move;
        }

        // 이동 실행.
        while (move > 0)
        {
            cur = board[cur];
            --move;
        }

        // 이동후 위치가 도착지점이 아닌데도 불구하고
        // 이미 다른 말이 존재한다면 이번 이동 자체를 무효화한다.
        if (cur != 21 && visit[cur])
            continue;

        // 이동후 다음 이동을 위한 처리.
        visit[cur] = true;
        visit[prev] = false;
        pos[i] = cur;
        BackTrack(idx + 1, sum + point[cur]);
        // 다음 이동을 위한 복구.
        visit[cur] = false;
        visit[prev] = true;
        pos[i] = prev;
    }
}

void MakeAnswer()
{
    memset(pos, 0, sizeof(pos));
    memset(visit, false, sizeof(visit));
    MakeBoard();
    BackTrack(0, 0);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 10; ++i)
        cin >> dice[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
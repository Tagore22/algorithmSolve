#include <iostream>
#include <cmath>
#include <cstring>

using namespace std; // 톱니바퀴의 총 합을 출력할것. 2가 오른쪽 6이 왼쪽

// 풀이.
// 평범한 시뮬레이션 구현 문제다.
// 각 톱니바퀴가 회전할때의 구현만 잘하면 된다.

string board[4];
bool check[4];
int K;

// 톱니바퀴의 회전을 구현하는 함수. 
// 무한반복이 일어나지 않게끔 현재 톱니바퀴의 방문을 표현하는 bool 타입배열
// check값을 갱신해주고 좌, 우 톱니바퀴의 회전 가능 여부를 파악한후
// 재귀호출을 한다.
void RotateCog(int idx, int dir)
{
    check[idx] = true;

    if (idx - 1 >= 0 && board[idx][6] != board[idx - 1][2] && !check[idx - 1])
        RotateCog(idx - 1, dir * -1);

    if (idx + 1 < 4 && board[idx][2] != board[idx + 1][6] && !check[idx + 1])
        RotateCog(idx + 1, dir * -1);

    if (dir == 1) // 시계방향일 경우 맨뒤가 맨앞이 된다.
    {
        char to = board[idx][7];
        board[idx].erase(7);
        board[idx] = to + board[idx];
    }

    else
    {
        char to = board[idx][0];
        board[idx].erase(0, 1);
        board[idx] += to;
    }
}

void MakeAnswer()
{
    for (int i = 0; i < K; ++i)
    {
        memset(check, false, sizeof(check));
        int idx, dir;
        cin >> idx >> dir;
        RotateCog(idx - 1, dir);
    }

    int answer = 0;
    for (int i = 0; i < 4; ++i)
        if (board[i][0] == '1')
            answer += pow(2, i);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 4; ++i)
        cin >> board[i];

    cin >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 입력시 미리 모든 원소값들의 방문 여부를 체크해놓고 이후 배열을 한번씩 순회하며
// 현재 원소값 * 2의 값이 이전의 방문하였는지(배열에 존재하는지)를 확인하여 최종값 answer를 증가시켜나간다.

int board[15];
bool visit[200];

void MakeAnswer()
{
    while (true)
    {
        int idx = 0;
        memset(visit, false, sizeof(visit));
        while (true)
        {
            cin >> board[idx];
            if (board[idx] == 0)
                break;
            else if (board[idx] == -1)
                return;
            visit[board[idx]] = true;
            ++idx;
        }
        int answer = 0;
        for (int i = 0; i < idx; ++i)
        {
            if (visit[board[i] * 2])
                ++answer;
        }
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
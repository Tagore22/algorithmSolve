#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 주어지는 점수가 중복될시 더해지지 않고 중복되지 않을시 더해지는 로직에서
// 각 플레이어의 최종 점수를 출력하는 문제다.
// N이 2번 반복되기에 좀 찝찝하지만 주어지는 방식이 한 플레이어의 모든 점수가 주어지는 방식이기에
// 이렇게 할수밖에 없었다.

// 자세한 설명은 주석으로 남긴다.

int board[200][3], visit[101], answer[200];
int N;

void MakeAnswer()
{
    // 모든 게임을 순회한다.
    for (int j = 0; j < 3; ++j)
    {
        // 각 수의 등장횟수를 0으로 초기화한다.
        memset(visit, 0, sizeof(visit));
        for (int i = 0; i < N; ++i)
        {
            // 각 수의 등장횟수를 증가시킨다.
            ++visit[board[i][j]];
        }
        for (int i = 0; i < N; ++i)
        {
            // 현재 수가 1번만 등장했다면 해당 플레이어의 점수를 증가시킨다.
            if (visit[board[i][j]] == 1)
            {
                answer[i] += board[i][j];
            }
        }
    }
    // 모든 플레이어의 최종 점수를 출력한다.
    for (int i = 0; i < N; ++i)
        cout << answer[i] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i][0] >> board[i][1] >> board[i][2];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
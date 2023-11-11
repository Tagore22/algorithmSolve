#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// 풀이.
// 주어진 원소들중 더해서 M이 되는 쌍의 수를 출력하는 문제다.
// 모든 원소값은 고유하기에 일단 하나의 쌍이 결정되면 그 쌍들은 더이상 선택할수 없다.
// 조금은 주먹구구식으로 풀어서 다시 풀었다.

// 자세한 설명은 주석으로 남긴다.

int board[15000];
bool visit[15000];
int N, M;

void MakeAnswer()
{
    // 쌍을 찾을수 없을 경우 연산을 최소화하기 위한 정렬.
    sort(board, board + N);
    // 처음엔 모두 선택되지 아니함.
    memset(visit, false, sizeof(visit));
    int answer = 0;
    // 모든 원소들을 순회하며 각 쌍을 찾아본다.
    for (int i = 0; i < N - 1; ++i)
    {
        // 자기자신 이후부터 찾아본다.
        for (int j = i + 1; j < N; ++j)
        {
            // 현재 원소가 이미 선택된 원소라면 무시한다.
            if (visit[j])
                continue;

            // 두 원소의 합이 M이라면 j번째 원소를 고르고 최종답 answer를 1 증가시킨후 탈출한다.
            if (board[i] + board[j] == M)
            {
                visit[j] = true;
                ++answer;
                break;
            }
            // 현재 합이 이미 M을 넘었다면 쌍을 찾을수 없기에 포기하고 탈출한다.
            else if (board[i] + board[j] > M)
            {
                break;
            }
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
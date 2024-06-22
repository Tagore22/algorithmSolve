#include <iostream>

using namespace std;

// 풀이.
// 평범한 백트래킹 문제이다. 사용하는 키트의 순서에 따라 답이 달라지므로 모든 경우의 수를 따져봐야 한다.

// 자세한 설명은 주석으로 남긴다.

int board[8];
bool check[8] = { false, };
int N, K, answer = 0;

// 모든 경우의 수를 순회하는 함수.
void BackTrack(int cur, int num)
{
    // 만약 현재 중량이 500이 안된다면 이 방법은 무시한다.
    if (cur < 500)
        return;

    // 500을 유지하며 N개를 모두 사용할 경우 최종답 answer를 1 증가시키고 탈출한다.
    if (num == N)
    {
        ++answer;
        return;
    }

    // 모든 키트를 순회하며, 사용 가능한 키트를 사용하고 재귀호출한다.
    for (int i = 0; i < N; ++i)
    {
        if (!check[i])
        {
            check[i] = true;
            BackTrack(cur + board[i] - K, num + 1); // 여기서 K가 아닌 예시에 주어진 K값 4를 넣어 한번 틀렸다.. T^T
            check[i] = false;
        }
    }
}

void MakeAnswer()
{
    BackTrack(500, 0);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
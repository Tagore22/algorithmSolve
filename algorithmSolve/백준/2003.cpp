#include <iostream>

using namespace std;

// 풀이.
// i번째 원소부터 시작해서 연속된 원소의 합이 M인 경우의 수를 출력하는 문제다.
// 원소의 개수가 최대 10000개라 2중 for문을 써도 1억밖에 되지 않아서
// 충분히 풀수는 있다.

// 자세한 설명은 주석으로 남긴다.

int board[10000];
int N, M;

void MakeAnswer()
{
    int answer = 0;
    int cur;
    // 모든 원소(시작 위치)를 순회한다.
    for (int i = 0; i < N; ++i)
    {
        cur = 0;
        // 시작 위치부터 모든 원소를 순회하며 그 원소들의 합이 M이거나 더 클때까지 순회한다.
        for (int j = i; j < N; ++j)
        {
            cur += board[j];
            // 더 크거나 같을시 두번째 for문을 탈출한다. 다만 m과 같을때에만 최종값 answer을 1 더해준다.
            if (cur >= M)
            {
                answer = cur == M ? answer + 1 : answer;
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
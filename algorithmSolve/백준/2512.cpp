#include <iostream>

using namespace std;

// 풀이.
// 문제 자체는 어렵지 않다. 2중 반복문으로 가장 큰 값부터 1씩 감소해가며
// 지정된 값 M안에서 모두에게 줄수 있는 가장 큰 기준값을 출력해내면 된다.
// 다만 이 풀이는 최대 10억의 연산량을 지니기 때문에 매우 느리다.

// 자세한 설명은 주석으로 남긴다.

int board[10000];
int N, M, cur;

void MakeAnswer()
{
    int answer;
    // 기준값 cur을 최대 원소값부터 시작해서 1씩 감소해가며 줄수 있는 최대값을 구한다.
    while (cur > 0)
    {
        answer = 0;
        for (int i = 0; i < N; ++i)
        {
            answer += board[i] > cur ? cur : board[i];
            if (answer > M)
            {
                answer = 0;
                --cur;
                break;
            }
        }
        if (answer != 0)
        {
            cout << cur << '\n';
            return;
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        cur = max(cur, board[i]);
    }
    cin >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
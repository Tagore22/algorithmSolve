#include <iostream>
#include <algorithm>

using namespace std;

// 14225번이 가장 최적화된 풀이.
// 0부터 시작하는건 비슷하지만 수학적 접근으로 푸는 방식이다.
// 예전에 이런 비슷한 풀이방식을 봤던 것 같은데 이번이 2번째 보는 것이라
// 기억이 나질 않았다. 굉장히 유용하기에 잘 기억해두어야겠다.

int board[20];
int N;

void MakeAnswer()
{
    sort(board, board + N);
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        // 이번 원소값이 현재 값보다 2이상 크다면 현재 값 + 1의 값을 구할수 없다.
        if (board[i] > answer + 1)
            break;
        // 현재값이 더해지면서 1 ~ 현재값까지의 모든 수를 부분수열로 구할수 있다.
        answer += board[i];
    }
    cout << answer + 1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
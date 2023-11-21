#include <iostream>

using namespace std;

// 11501번의 더 나은 풀이.
// 이 문제에서 결과적으로 가장 중요한건 현재 인덱스 idx에서부터 마지막 원소까지 가장 높은 가격을 구하는 것이다.
// 이전 풀이에서는 우선순위큐를 통해서 현재 가장 높은 가격의 일자와 현재 일자를 비교하는등 불필요한 연산이 많았다.
// 단순하게 뒤에서부터 가장 높은 가격들을 비교해나가면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[1000000];
int T, N;

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N;
        // 각 일자별 가격들을 입력받는다.
        for (int i = 0; i < N; ++i)
        {
            cin >> board[i];
        }

        long long answer = 0;
        int max_num = 0;
        // 맨뒤부터 가장 높은 가격들 갱신하고 현재 원소를 뺀 이익들을
        // 모두 더한다.
        for (int i = N - 1; i >= 0; --i)
        {
            max_num = max(max_num, board[i]);
            answer += max_num - board[i];
        }

        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

// 11652번의 다른 풀이.
// 사이값을 이용하지 아니하고 직접 하나씩 현재값과 이후값을 비교한다.
// 큰 문맥은 같으나 이것만 다르다. 메모리나 성능에서는 차이가 없었다.

// 자세한 설명은 주석으로 남긴다.

long long board[100000];
int N;

void MakeAnswer()
{
    sort(board, board + N);
    pair<int, long long> answer = make_pair(-1, -1); // 개수, 원소값.
    pair<int, long long> prev_num = make_pair(1, board[0]); // 원소의 위치값, 원소값.
    for (int i = 0; i < N - 1; ++i)
    {
        // 현재값과 이후값이 같다면 현재값의 등장횟수가 1 증가한다.
        if (board[i] == board[i + 1])
        {
            ++prev_num.first;
        }
        // 그렇지 않다면 현재값의 등장횟수를 최종값 answer와 비교하여 answer를 갱신하고
        // 이전값까지 갱신한다.
        else
        {
            answer = prev_num.first > answer.first ? prev_num : answer;
            prev_num = make_pair(1, board[i + 1]);
        }
    }
    // 마지막에 한번 더 갱신해야한다.
    answer = prev_num.first > answer.first ? prev_num : answer;
    cout << answer.second << '\n';
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
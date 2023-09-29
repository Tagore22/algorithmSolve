#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 가장 많이 등장한 수들중 가장 작은 수를 출력하는 문제다.
// 배열을 이용해서 각 수들의 등장수를 확인후 그들중 가장 작은수를 출력하면 되는 쉬운 패턴이지만
// 이 경우에는 조금 다르다. 주어지는 수의 범위가 long long범위이기 때문에 배열을 만들수 없기 때문이다.
// 따라서 주어지는 수들을 모두 정렬하여 그 수들을 하나씩 세는 수밖에 없다. 많은 이들이 이 접근법을 떠올리지 못해
// 이 문제의 정답률이 30퍼센트가 안되는것 같다. 나는 이전값들을 기록해놓은 상태로 0 ~ N - 1까지 순회하며 현재값이
// 이전값과 다를때 정답 answer을 갱신하는 방법으로 풀었다. 다른 방법도 있으나 메모리 및 성능에서 차이가 없었다.

// 자세한 설명은 주석으로 남긴다.

long long board[100000];
int N;

void MakeAnswer()
{
    // 정렬을 해야 같은 수들을 셀수 있다.
    sort(board, board + N);
    pair<int, long long> answer = make_pair(-1, -1); // 개수, 원소값.
    pair<int, long long> prev_num = make_pair(0, board[0]); // 원소의 위치값, 원소값.

    // 0 ~ N - 1까지 순회하며 등장한 수들의 개수를 확인한다.
    // 이전값을 미리 기록해놓고 현재값과 값이 다를때 그 사이들의 값이 이전값의 등장 횟수이므로
    // 그것을 구해 최종값 answer의 등장횟수와 비교한다.
    for (int i = 0; i < N; ++i)
    {
        if (prev_num.second != board[i])
        {
            // 이전값의 위치값과 현재값의 위치값을 비교하면 이전값의 등장횟수를 알수 있다.
            int cur = i - prev_num.first;
            // 이전값의 등장횟수와 최종값 answer의 등장횟수를 비교하여 answer를 갱신한다.
            answer = answer.first < cur ? make_pair(cur, prev_num.second) : answer;
            // 이제는 이전값이 된 현재값을 prev_num에 갱신한다.
            prev_num = make_pair(i, board[i]);
        }
    }
    // 맨 마지막으로 한번더 갱신해주어야 한다.
    int cur = N - prev_num.first;
    answer = answer.first < cur ? make_pair(cur, prev_num.second) : answer;
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
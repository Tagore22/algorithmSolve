#include <iostream>

using namespace std;

// 풀이.
// 문제를 만든게 애새끼인지 뭣도 없는 문제인데 드럽게 길고 가독성만 떨어진다.
// 요점을 말하자면 i번째 원소에서 시작했을때 자기자신보다 작은 연속된 수의 최대값을 출력하면 되는 것이다.
// 큰틀은 다음과 같다.

// 1. 0번째 원소부터 순회를 시작한다.
// 2. 현재값이 기준값보다 크다면 여태까지 추가된 수 ans를 answer와 갱신하고 ans를 다시 0으로 초기화후 기준값을 현재값을 변경한다.
// 3. 현재값이 더 작다면 ans를 1 추가시킨다.
// 4. 모두 순회했을때 마지막으로 answer를 갱신한다. ex) 5 4 3 2 1일때.

// 자세한 설명은 주석으로 남긴다.

int N;

void MakeAnswer()
{
    int answer = 0;  // 최종값.
    int ans = 0;     // 기준값이 처리할수 있는 수들.
    int cur;         // 현재값.
    int prev_num = -1; // 기준값.
    for (int i = 0; i < N; ++i)
    {
        cin >> cur;
        // 현재값이 더 크다면 위 상술한 2번대로 처리한다.
        if (cur > prev_num)
        {
            answer = max(answer, ans);
            ans = 0;
            prev_num = cur;
        }
        // 그렇지 않다면 위 상술한 3번대로 처리한다.
        else
        {
            ++ans;
        }
    }
    // 상술한 4번처리.
    answer = max(answer, ans);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
#include <iostream>

using namespace std;

// 풀이.
// 오름차순을 연속적으로 만나면 그 값들을 더하고 내림차순 혹은 평지를 만났을때에는
// 오르막길의 값을 0으로 초기화하며 순회해주면 된다.
// 다만, 최대 1000개의 배열을 쓰기 싫어서 다르게 해보았다.

// 자세한 설명은 주석으로 남긴다.

int N, prev_num, cur;

void MakeAnswer()
{
    prev_num = 1001;
    int answer = 0;
    int ans = 0;
    // 최대 1000개의 메모리를 써보지 않기 위해 변수값 2개를 이중 버퍼링을 사용하듯 값을 교체한다.
    // 매 입력마다 연속적으로 오름차순을 만났다면 그 값들을 더하고 그렇지 않다면
    // 오름차순을 0으로 초기화해준다.
    for (int i = 0; i < N; ++i)
    {
        cin >> cur;
        if (cur > prev_num)
        {
            ans += cur - prev_num;
        }
        else
        {
            answer = max(answer, ans);
            ans = 0;
        }
        prev_num = cur;
    }
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
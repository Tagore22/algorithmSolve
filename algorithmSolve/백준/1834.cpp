#include <iostream>

using namespace std;

//풀이
//문제에서 주어진 그대로 1부터 N-1까지 N * i + i를 구해서 그 누적합을 출력하면 된다.
//다만, 범위가 int를 훌쩍 넘어섬으로 long long을 사용하여야 한다.

int N;

void MakeAnswer()
{
    long long answer = 0;

    for (long long i = 1; i < N; ++i)
        answer += N * i + i;

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
#include <iostream>

using namespace std;

//아래 주석처럼 N-M이 순간적으로 int값의 최대값을 넘어설수도 있기에 캐스팅을 하던가 아니면 N과 M을 아예 long long으로 선언하면 된다.

long long N, M;

void MakeAnswer()
{
    long long answer = abs(N - M); //abs안에서 N-M이 int의 최대값을 넘어설수 있음.
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
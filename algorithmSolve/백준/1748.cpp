#include <iostream>

using namespace std;

int N;

//풀이
//자리수가 1인 9까지, 2인 99까지 등의 기준으로 주어진 수 N을 자리수마다 단계적으로 처리한다.
//다만 현재 자리수의 수를 알기 위해 이전 자리수의 최대값인 prev를 매번 갱신하며 기록해야한다.

void MakeAnswer()
{
    int answer = 0;
    int prev = 0, mul = 1; //초기 이전값과 초기 자리수값.
    for (int i = 9; i < N; i = (i + 1) * 10 - 1) //매 자리수의 최대값마다 비교한다. 자리수가 1개인 최대값 9, 자리수가 2개인 최대값 99등...
    {
        answer += mul * (i - prev); //현재 자리수의 최대값 - 이전 자리수의 최대값을 구해야 수가 중복되지 아니한다.
        prev = i;
        ++mul;
    }

    answer += (N - prev) * mul; //남은 값 (ex) 주어진 값 101, 이전 값 99일때 100 ~ 101) 의 처리.

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
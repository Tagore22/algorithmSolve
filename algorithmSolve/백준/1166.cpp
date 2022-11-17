#include <iostream>

using namespace std;

int N, L, W, H;

//풀이 자체는 어렵지 않으나, 생각해야할 조건이 많은 문제이다. 직육면체 박스 안에 정육면체를 N개를 넣을수 있는 가장 큰 길이를 구하는 것인데,
//길이자체는 각변의 길이를 나누어 구할수 있으나 이 과정에서 반드시 long long으로의 타입 변환이 있어야한다. 그 이유는 
//1. 각 변의 길이는 최대 10억이기에 변의 길이를 어떠한 값으로 나누었을때 최대값 역시 10억이 된다. 그랬을 경우 10억을 3번 곱하면
//int의 범위를 아득히 벗어난다.
//2. 각 변의 길이 / @의 결과는 int값과 double의 연산 및 승격으로 인해 double로 변환된다. 그러나, 각 변에 넣을수 있는 개수는 소수점이
//없어야 하기에 정수값으로의 재변환이 필요하다.

//11-17 추가
//1번 이유에 대해 조금 추가하자면, 10억을 세번 곱하는 일은 일어나지 않는다. 최대의 경우는 다름아닌 1000000000, 1, 1000000000, 1000000000의
//경우인데 이런 경우 각 변은 1보다 커질수 없기에 존재하는 답의 수는 1e18이 되어 int값을 벗어나나, long long의 범위로 담아낼수 있다.


void MakeAnswer()
{
    double lo = 0, hi = 1000000000;
    for (int i = 0; i < 100; ++i)
    {
        double mid = (lo + hi) / 2;
        if (static_cast<long long>(L / mid) * static_cast<long long>(W / mid) * static_cast<long long>(H / mid) >= N)
            lo = mid;
        else
            hi = mid;
    }
    cout << fixed;
    cout.precision(9);
    cout << lo << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L >> W >> H;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
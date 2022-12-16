#include <iostream>
#include <cmath>

using namespace std;

//풀이
//어떤 수들의 집합이 있을때 그 집합의 모든 곱이 가장 크기 위해서는 집합의 원소들이 균등하게 커야한다.
//즉, 이 문제에서 K개의 수들의 곱이 가장 크기 위해선 각자 수를 균등하게 맞춰야하는데 그 방법은 S를 K로 나누는 것이다.
//만약 나머지가 생긴다면 역시 균등하게 최대한 많은 수에게 1씩 나누어주면 된다. 또한 범위가 int가 아닌 long long의 범위이기에
//변수들의 타입을 잘 고려해야했다.

int S, K;

void MakeAnswer()
{
    long long mul_num = S / K;
    int div_num = S % K;

    long long answer = pow(mul_num, K - div_num) * pow(mul_num + 1, div_num);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> S >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
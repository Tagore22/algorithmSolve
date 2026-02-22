#include <iostream>

using namespace std;

// 처음엔 실제로 다 계산해봐야했는데 규칙이 있었다. 첫번째
// 위치부터 나 스스로를 제외하고 나머지 N - 1개와 자리를 바꿀 수 있고
// 다음 순서의 원소가 앞서 위치를 바꾼 2개와 나 스스로를 제외한
// N - 3개와 자리를 바꿀 수 있기에 결과적으로 N - 1개부터 1개까지
// 매번 2씩 줄여가며 정답을 곱해가면 된다.

const int DIV = 1000000007;

int main()
{
    int N;
    cin >> N;

    long long answer = 1;
    for (int i = N - 1; i > 0; i -= 2)
    {
        answer *= i;
        answer %= DIV;
    }
    cout << answer << '\n';
    return 0;
}
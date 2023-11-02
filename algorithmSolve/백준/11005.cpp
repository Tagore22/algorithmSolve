#include <iostream>

using namespace std;

// 풀이.
// 진법 변환 문제이다. 진법을 변환하려는 수 N가 0보다 큰동안 진법 B로 나누어 그 나머지를 앞에서부터 붙이면 된다.

// 자세한 설명은 주석으로 남긴다.

int N, B;

int main()
{
    cin >> N >> B;

    string answer;
    // N이 0보다 클동안 반복한다.
    while (N > 0)
    {
        // N을 B로 나누어 그 값이 10보다 같거나 작다면 숫자 그대로,
        // 그렇지 않다면 알파벳으로 변형시켜 앞부터 집어넣는다.
        int div = N % B;
        char plus = div >= 10 ? div + 55 : div + 48;
        answer = plus + answer;

        // N을 B로 나눈다.
        N /= B;
    }

    // 최종답 answer 출력.
    cout << answer << '\n';
    return 0;
}
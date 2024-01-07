#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 미리 최대 10000까지 제곱수들을 구해놓은후 범위를 입력받았을때
// 그 범위안에 제곱수들을 계산한다.

// 자세한 설명은 주석으로 남긴다.

bool isPrime[10000];
int M, N;

int main()
{
    // 미리 모든 범위내의 제곱수들을 계산한다.
    memset(isPrime, false, sizeof(isPrime));
    for (int i = 1; i <= 100; ++i)
        isPrime[i * i] = true;
    cin >> M >> N;
    int sum = 0, answer = 10000;
    // 주어진 범위내에 제곱수들을 계산한다.
    for (int i = M; i <= N; ++i)
    {
        if (isPrime[i])
        {
            sum += i;
            answer = min(answer, i);
        }
    }
    if (sum == 0)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << sum << '\n';
        cout << answer << '\n';
    }
    return 0;
}
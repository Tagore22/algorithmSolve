#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 문제 자체는 그리 어렵지 않았다. 최대 천만까지의 소수들을 구한후 각 소수들을 순회하며
// 소수들의 제곱이 A ~ B 범위내에 속하는 수들을 모두 더하여 출력하면 된다.
// 다만 처음에 vector를 이용한 풀이를 했는데 자꾸만 답이 틀렸다. 잠이 덜깼는지 한참을 헤맸는데
// 범위가 전혀 달랐다.

// 자세한 설명은 주석으로 남긴다.

long long A, B;
const int MAXNUM = 10000001;
// 왜인지는 모르겠으나 함수내에서 천만의 배열을 만들수가 없었다.
bool isprime[MAXNUM];

void Era()
{
    memset(isprime, true, sizeof(isprime));
    // 최대 천만까지의 소수를 구하려고 하기에 에라토스테네스의 체의 의해
    // 다시 제곱했을때 천만까지의 수까지만 순회하면 된다.
    for (int i = 2; i * i <= MAXNUM; ++i)
        if (isprime[i])
        {
            for (int j = i * i; j < MAXNUM; j += i)
                isprime[j] = false;
        }
}

void MakeAnswer()
{
    cin >> A >> B;
    Era();
    int answer = 0;
    for (int i = 2; i <= MAXNUM; ++i)
    {
        if (isprime[i])
        {
            long long here = i;
            // while문의 조건이 아주 중요한데 기존에는 here * i <= B였다.
            // 하지만 이것은 long long의 범위값을 넘어설수도 있으므로
            // 나눗셈값을 이용하여 그 값을 줄여야한다.
            while (here <= B / i)
            {
                here *= i;
                answer = here >= A ? answer + 1 : answer;
            }
        }
    }
    cout << answer << '\n';
}

int main()
{
    MakeAnswer();
    return 0;
}
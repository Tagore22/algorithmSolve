#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 풀이.
// 보통 에라토스테네스의 체를 이용한 소수 구하기 문제에서는 최대값을 주는 경우가 많으나, 이번에는 특이하게
// K번째를 주었다. 덕분에 따로 최대값을 구해야만 했다. 아래 풀이보다 더 최적화된 방법은 2보다 큰 짝수들은
// 아예 배제하는 것이다. 나중에 한번 해보자.

const int MAX = 8000000;
bool isprime[MAX];
vector<int> primes;

void CalPrimeNum()
{
    for (int i = 2; i < MAX; ++i)
        isprime[i] = true;
    int sqrtnum = sqrt(MAX);
    for (int i = 2; i <= sqrtnum; ++i)
    {
        if (isprime[i])
        {
            for (int j = i * i; j < MAX; j += i)
                isprime[j] = false;
        }
    }
    for (int i = 2; i <= MAX; ++i)
        if (isprime[i])
            primes.push_back(i);
}

int main()
{
    int K;
    cin >> K;

    CalPrimeNum();
    cout << primes[K - 1] << '\n';
    return 0;
}
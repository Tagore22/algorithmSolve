#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

// 풀이.
// 2보다 큰 짝수 N이 주어질때 더해서 N이 되는 두 소수들의 쌍을 구하는 문제다.
// 다만 두 소수의 순서만 뒤바뀐 경우는 무시한다. 이 문제를 풀기 위해선 에라토스테네스의 체를 사용해야한다.
// 최대값인 100만까지의 모든 소수를 구해서 N이 주어질때 N - 1까지의 소수들중 N을 제외하고 나머지 역시 소수가 된다면
// 두 소수는 더해서 N이 될수 있다.

// 자세한 설명은 주석으로 남긴다.

const int MAX_NUM = 1000000;
bool isPrime[MAX_NUM + 1];
vector<int> primes;
int T, N;

// 에라토스테네스의 체를 사용하여 최대값 100만까지의 모든 소수들을 구한다.
void Era()
{
    memset(isPrime, true, sizeof(isPrime));
    // 0과 1은 소수가 아님.
    isPrime[0] = isPrime[1] = false;
    int sqrt_num = sqrt(MAX_NUM);
    for (int i = 2; i <= sqrt_num; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= MAX_NUM; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    // 2부터 100만까지중 소수를 모두 벡터에 넣는다. 그렇지 않으면
    // 모든 테스트 케이스마다 2부터 최대 100만까지 순회를 해야한다.
    for (int i = 2; i <= MAX_NUM; ++i)
    {
        if (isPrime[i])
            primes.push_back(i);
    }
}

void MakeAnswer()
{
    Era();
    int answer;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N;
        answer = 0;
        // 현재 존재하는 소수들을 N으로부터 감소시켜 그 수가 소수인지 찾는다.
        for (int i = 0; i < primes.size(); ++i)
        {
            // 순서만 뒤바뀐 경우는 무시하여야 했기에 N / 2보다 같거나 큰 경우는 무시한다.
            // 에라토스테네스에서 sqrt_num까지만 소수들을 제거하는 것과 일맥상통한다.
            if (primes[i] > N / 2)
                break;
            // N에서 현재 소수만큼 감소시켰을때 남은 수가 소수라면 이 둘은 하나의 쌍을 이룬다.
            if (isPrime[N - primes[i]])
                ++answer;
        }
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
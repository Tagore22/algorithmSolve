#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

// 1456번의 다른 풀이.
// 1456.cpp에 기록했던 vector를 이용한 풀이이다. Era()안의 for문의 범위값이 잘못되었었다.
// 기존처럼 배열을 이용하면 그 제곱근까지만 순회를 돌아도 배열에 이미 소수들이 파악되지만
// vector를 이용하여 실제로 모든 소수를 집어넣으려면 제곱근이 아닌 MAXNUM까지 모두 순회를 해야한다.
// 이점을 잊고 있었다. 이 풀이는 조금 이상한데, 두번째 for문에서 굳이 순회하지 않아도 되는 부분까지
// 한번 더 순회하기 때문이다. 그로 인해 실제로 시간도 더 느리고, 필요없는 long long 타임의 vector까지
// 필요로 한다. 

long long A, B;
vector<long long> primes;
const int MAXNUM = 10000001;
bool isprime[MAXNUM];

void Era()
{
    memset(isprime, true, sizeof(isprime));
    for (long long i = 2; i <= MAXNUM; ++i)
        if (isprime[i])
        {
            primes.push_back(i);
            for (long long j = i * i; j <= MAXNUM; j += i)
                isprime[j] = false;
        }
}

void MakeAnswer()
{
    cin >> A >> B;
    Era();
    int answer = 0;
    for (long long cur : primes)
    {
        long long here = cur;
        while (here <= B / cur)
        {
            here *= cur;
            answer = here >= A ? answer + 1 : answer;
        }
    }
    cout << answer << '\n';
}

int main()
{
    MakeAnswer();
    return 0;
}
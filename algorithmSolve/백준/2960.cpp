#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 에라토스테네스의 체를 구현하는 어렵지 않은 문제다.
// 다만 한가지 주의해야할점이 있는데 기존에 에라토스테네스의 체를 구현할때는
// 그 연산량을 줄이기 위해 2 ~ sqrt(N)만큼만을 순회했다. 그러나 이 문제에서는
// 그렇지 않고 2 ~ N까지 모두 순회해야한다는 점이 문제에 제시되어 있기에 
// 첫번째 방식대로 구현하면 답이 나오지 않는다.

// 자세한 설명은 주석으로 남긴다.

bool isPrime[1001];
int N, K, answer = 0;

// 에라토스테네스의 체를 구현하는 함수. 상술한대로 한가지 다른 부분이 있음에 주의.
void Era()
{
    isPrime[0] = isPrime[1] = false;

    // 기존에는 이 for문을 순회하는 구간이 2 ~ sqrt(N)이다. 다만 이 문제에는 그렇지
    // 않음이 직접적으로 제시되어 있다.
    for (int i = 2; i <= N; ++i)
    {
        if (isPrime[i])
        {
            // i의 배수들을 모두다 지운다.
            for (int j = i; j <= N; j += i)
            {
                // 기존의 에라토스테네스의 체에서는 굳이 if문을 쓸필요가 없으나
                // 이 문제에서는 기존에 지워지지 않은 수들을 지울때에만 K의 수가 증가하므로
                // 반드시 if문으로 상황을 걸러내야한다.
                if (isPrime[j])
                {
                    isPrime[j] = false;
                    ++answer;
                }

                if (answer == K)
                {
                    cout << j << '\n';
                    return;
                }
            }
        }
    }
}

void MakeAnswer()
{
    memset(isPrime, true, sizeof(isPrime));
    cin >> N >> K;

    Era();
}

int main()
{
    MakeAnswer();
    return 0;
}
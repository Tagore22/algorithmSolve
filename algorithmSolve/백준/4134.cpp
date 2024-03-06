#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

// 풀이.
// 난이도는 실4지만 정답율이 25프로도 안되는 꽤나 어려운 문제였다.
// 주어지는 수의 최대값이 40억을 넘어가기 때문에 에라토스테네스의 체 자체를 사용할수는 없었으나
// 그 원리를 사용해야하는 문제였다. 에라토스테네스의 체에 의해서 모든 합성수는 소수로 나누어진다.
// 따라서 40억의 제곱근인 63245까지의 모든 소수들을 구한다. 왜 40억도 아닌 제곱근인 63245까지의 소수를
// 구해도 되냐면, 에라토스테네스의 체를 구할때 제곱근까지의 소수들만 사용하는 것과 일치한다. 제곱근까지의
// 소수들과 제곱근 이후의 값들이 연동되기 때문이다. 
// 결과적으로 num을 입력받아 1씩 증가시키며 소수들과 비교한다. 모든 소수들과 나누어지지 않는다면
// num보다 더 큰 소수인경우밖에 존재하지 않는다.

// 자세한 설명은 주석으로 남긴다.

// 미래에 혹여나 원리를 잊어버렸을 나를 위해 한번더 설명해보고자 한다.
// 모든 수는 자기자신보다 작거나 같은 소수와의 곱으로 나타낼수 있다. 소수조차도 1 X 자기자신으로 나타낼수 있기 때문이다.
// 따라서 확실하게 얻을수 있는 가장 큰 범위인 40억의 제곱근인 63245까지의 모든 소수들을 구해
// 주어진 수 num을 이 범위의 소수들로 나타낼수 있는지(나눌수 있는지) 확인하는 것이다. 만약 미리 구해놓았던
// 모든 소수들의 수로 나타낼수 없다면 기존의 구해놓은 수들보다 더 큰 소수(자기 자신)이 나타남을 의미한다.

const int MAX_NUM = 63245;
bool isPrime[MAX_NUM + 1];
vector<int> primes;
int T;

// 구할수 있는 가장 큰 범위인 0 ~ 63245까지의 모든 소수를 구하여 벡터에 넣는다.
// 벡터에 넣는 이유는 0 ~ 63245보다 순회하는 범위를 최대한 줄이기 위해서이다.
void FindPrime()
{
    memset(isPrime, true, sizeof(isPrime));
    int sqrt_num = sqrt(MAX_NUM);
    for (int i = 2; i <= sqrt_num; ++i)
        if (isPrime[i])
            for (int j = i * i; j <= MAX_NUM; j += i)
                isPrime[j] = false;
    for (int i = 2; i <= MAX_NUM; ++i)
        if (isPrime[i])
            primes.push_back(i);
}

// 주어진 수 num이 소수인지 확인하는 함수.
// 범위내의 수들과 비교한다.
bool CheckIsPrime(long long num)
{
    bool isFind = true;
    // 주어진 소수들을 모두 순회한다.
    for (int j = 0; j < primes.size(); ++j)
    {
        // num이 j번째 소수의 제곱보다 작다면 이 이상의 소수들로는 비교가 불가능하기에
        // 탈출한다.
        if (primes[j] * primes[j] > num)
            break;
        // num을 j번째 소수로 나타낼수 있다면(나눌수 있다면)
        // num는 합성수이다.
        if (num % primes[j] == 0)
        {
            isFind = false;
            break;
        }
    }
    return isFind;
}

void MakeAnswer()
{
    FindPrime();
    long long num;
    for (int i = 0; i < T; ++i)
    {
        cin >> num;
        if (num == 0 || num == 1)
        {
            cout << 2 << '\n';
            continue;
        }
        while (!CheckIsPrime(num))
        {
            ++num;
        }
        cout << num << '\n';
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
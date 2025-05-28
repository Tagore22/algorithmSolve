#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Ǯ��.
// ���� �����佺�׳׽��� ü�� �̿��� �Ҽ� ���ϱ� ���������� �ִ밪�� �ִ� ��찡 ������, �̹����� Ư���ϰ�
// K��°�� �־���. ���п� ���� �ִ밪�� ���ؾ߸� �ߴ�. �Ʒ� Ǯ�̺��� �� ����ȭ�� ����� 2���� ū ¦������
// �ƿ� �����ϴ� ���̴�. ���߿� �ѹ� �غ���.

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
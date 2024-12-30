#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

// 1456���� �ٸ� Ǯ��.
// 1456.cpp�� ����ߴ� vector�� �̿��� Ǯ���̴�. Era()���� for���� �������� �߸��Ǿ�����.
// ����ó�� �迭�� �̿��ϸ� �� �����ٱ����� ��ȸ�� ���Ƶ� �迭�� �̹� �Ҽ����� �ľǵ�����
// vector�� �̿��Ͽ� ������ ��� �Ҽ��� ����������� �������� �ƴ� MAXNUM���� ��� ��ȸ�� �ؾ��Ѵ�.
// ������ �ذ� �־���. �� Ǯ�̴� ���� �̻��ѵ�, �ι�° for������ ���� ��ȸ���� �ʾƵ� �Ǵ� �κб���
// �ѹ� �� ��ȸ�ϱ� �����̴�. �׷� ���� ������ �ð��� �� ������, �ʿ���� long long Ÿ���� vector����
// �ʿ�� �Ѵ�. 

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
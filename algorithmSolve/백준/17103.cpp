#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

// Ǯ��.
// 2���� ū ¦�� N�� �־����� ���ؼ� N�� �Ǵ� �� �Ҽ����� ���� ���ϴ� ������.
// �ٸ� �� �Ҽ��� ������ �ڹٲ� ���� �����Ѵ�. �� ������ Ǯ�� ���ؼ� �����佺�׳׽��� ü�� ����ؾ��Ѵ�.
// �ִ밪�� 100�������� ��� �Ҽ��� ���ؼ� N�� �־����� N - 1������ �Ҽ����� N�� �����ϰ� ������ ���� �Ҽ��� �ȴٸ�
// �� �Ҽ��� ���ؼ� N�� �ɼ� �ִ�.

// �ڼ��� ������ �ּ����� �����.

const int MAX_NUM = 1000000;
bool isPrime[MAX_NUM + 1];
vector<int> primes;
int T, N;

// �����佺�׳׽��� ü�� ����Ͽ� �ִ밪 100�������� ��� �Ҽ����� ���Ѵ�.
void Era()
{
    memset(isPrime, true, sizeof(isPrime));
    // 0�� 1�� �Ҽ��� �ƴ�.
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
    // 2���� 100�������� �Ҽ��� ��� ���Ϳ� �ִ´�. �׷��� ������
    // ��� �׽�Ʈ ���̽����� 2���� �ִ� 100������ ��ȸ�� �ؾ��Ѵ�.
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
        // ���� �����ϴ� �Ҽ����� N���κ��� ���ҽ��� �� ���� �Ҽ����� ã�´�.
        for (int i = 0; i < primes.size(); ++i)
        {
            // ������ �ڹٲ� ���� �����Ͽ��� �߱⿡ N / 2���� ���ų� ū ���� �����Ѵ�.
            // �����佺�׳׽����� sqrt_num������ �Ҽ����� �����ϴ� �Ͱ� �ϸƻ����Ѵ�.
            if (primes[i] > N / 2)
                break;
            // N���� ���� �Ҽ���ŭ ���ҽ������� ���� ���� �Ҽ���� �� ���� �ϳ��� ���� �̷��.
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
#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// �̸� �ִ� 10000���� ���������� ���س����� ������ �Է¹޾�����
// �� �����ȿ� ���������� ����Ѵ�.

// �ڼ��� ������ �ּ����� �����.

bool isPrime[10000];
int M, N;

int main()
{
    // �̸� ��� �������� ���������� ����Ѵ�.
    memset(isPrime, false, sizeof(isPrime));
    for (int i = 1; i <= 100; ++i)
        isPrime[i * i] = true;
    cin >> M >> N;
    int sum = 0, answer = 10000;
    // �־��� �������� ���������� ����Ѵ�.
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
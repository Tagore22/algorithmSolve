#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// ���� ��ü�� �׸� ����� �ʾҴ�. �ִ� õ�������� �Ҽ����� ������ �� �Ҽ����� ��ȸ�ϸ�
// �Ҽ����� ������ A ~ B �������� ���ϴ� ������ ��� ���Ͽ� ����ϸ� �ȴ�.
// �ٸ� ó���� vector�� �̿��� Ǯ�̸� �ߴµ� �ڲٸ� ���� Ʋ�ȴ�. ���� �������� ������ ��̴µ�
// ������ ���� �޶���.

// �ڼ��� ������ �ּ����� �����.

long long A, B;
const int MAXNUM = 10000001;
// �������� �𸣰����� �Լ������� õ���� �迭�� ������� ������.
bool isprime[MAXNUM];

void Era()
{
    memset(isprime, true, sizeof(isprime));
    // �ִ� õ�������� �Ҽ��� ���Ϸ��� �ϱ⿡ �����佺�׳׽��� ü�� ����
    // �ٽ� ���������� õ�������� �������� ��ȸ�ϸ� �ȴ�.
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
            // while���� ������ ���� �߿��ѵ� �������� here * i <= B����.
            // ������ �̰��� long long�� �������� �Ѿ���� �����Ƿ�
            // ���������� �̿��Ͽ� �� ���� �ٿ����Ѵ�.
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
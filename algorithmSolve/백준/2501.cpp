#include <iostream>

using namespace std;

//Ǯ��
//N�� K��° ����� ���ϴ� �����̱⿡ 1���� N���� ��� ���� �����ذ��� K�� ������� ���ϰ� ���Ѵٸ� idx�� �����Ͽ� ���° ��������� ����Ѵ�.
//�׸��� idx�� K��� ���� ã�����Ƿ� ����ϰ�, N���� ������������ K��° ����� ������ ���ߴٸ� �ݺ������� �������� 0�� ����Ѵ�.

int N, K;

void MakeAnswer()
{
    int idx = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (N % i == 0)
            ++idx;
        if (idx == K)
        {
            cout << i << '\n';
            return;
        }
    }
    cout << 0 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
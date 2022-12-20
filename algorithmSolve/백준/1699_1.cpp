#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//����� �Լ��� �ƴ� �ٸ� ����� DP. �� ������ �뷮�� �� �۰� �����Ѵ�.

//Ǯ��
//� �� N�� ���������� ������ ġȯ�ϴµ� ���� ū ���� ��� ���� 1�� ������ 1�� ������ ��� �̱⿡ �ڱ� �ڽ� N�� �ȴ�.
//�̻��¿��� ���� Ǯ�̿� ����ϰ� N���� �ڽź��� ���� ������ S�� �� cashe[N - S] + 1�� cashe[N]�� ���Ͽ� �ּҰ��� ���� �ִ�.

vector<int> board, cashe;
int N;


void MakeAnswer()
{
    for (int i = 1; i <= N; ++i)
    {
        cashe[i] = i;
        for (int j = 1; j * j <= i; ++j)
            cashe[i] = min(cashe[i], cashe[i - j * j] + 1);
    }

    cout << cashe[N] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cashe.resize(N + 1, 0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
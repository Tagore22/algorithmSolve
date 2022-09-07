#include <iostream>

using namespace std;

//9471�� �ǻ�� �ֱ�� ����Ǵ� �����̴�. �ǻ�� �ֱ⸦ ���ؼ� �Ǻ���ġ ������ �鸸���� ������ �ֱ�� 150������ �˼� �����Ƿ�
//�Ǻ���ġ �������� 100������ ���� 150������ �迭�� �̸� ����س���, �־��� n�� 150������ ������ �������� ���� �ε����� �Ͽ�
//�迭���� ����ϸ� �ȴ�.

int cashe[1500010];
long long N;
const int MODNUM = 1000000;

void CalculFibo()
{
    cashe[0] = 0;
    cashe[1] = 1;
    for (int i = 2; i < 1500005; ++i)
        cashe[i] = (cashe[i - 2] + cashe[i - 1]) % MODNUM;
}

void MakeAnswer()
{
    CalculFibo();
    cout << cashe[N % 1500000] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
#include <iostream>
#include <cstring>

//�־��� �� N�� ��������(4,9,16�� ��� ���� 2������ �Ǵ� ����)�� �����鼭 �ּ����� �������� N�� ǥ���Ҽ� �ִ����� ���ϴ� �����̴�.
//�ܼ��� �ִ��� �������� ����� ū ���� �������� �ɰŶ� ����������, �׷��� �׸����� ������ �Ұ����߰�, �ᱹ ����Ž���� �̿��Ͽ�
//1~�����ٱ����� ���� ��� �ѹ��� ������ �ּҰ��� ���ؾ��Ѵ�. �׷��� �Ʒ� Ǯ�̿� ���� ��Ϳ� DP�� �̿��Ͽ� Ǯ������, N�� �ִ밪�� 5���϶�
//1�� ��� �������� �ݽ����� 5���� ���̱⿡ ���߿� ���õǾ���. �뷫 2926���� ������ ���µ� ���±��� ������ Ǯ�鼭 �ʹ� ��Ϳ��� �����ؿ°�
//�ƴѰ� ������ �����.

using namespace std;

int cashe[50001];
int N;

int Cal(int num)
{
    if (num == 0)
        return 0;

    int& ans = cashe[num];
    if (ans != -1)
        return ans;

    ans = 987654321;
    for (int i = 1; i * i <= num; ++i)
        ans = min(ans, Cal(num - i * i) + 1);

    return ans;
}

void MakeAnswer()
{
    cout << Cal(N) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cashe, -1, sizeof(cashe));

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
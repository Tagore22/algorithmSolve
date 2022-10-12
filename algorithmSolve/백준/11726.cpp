#include <iostream>
#include <cstring>

using namespace std;

//�ٷ� ���� Ǯ���� 9095���� �ſ� ������ �����̴�. 2XN���� Ÿ���� 1X2, Ȥ�� 2X1 Ÿ�Ϸ� ä��� ���̸� ������ �ٸ��� �ٸ� ���� ģ��.
//�� ���� ��� �� N�� 1 Ȥ�� 2�� ���ذ��� �Ͱ� ������ ��, ��� �� N�� 1 Ȥ�� 2�� ������ 0�� ���ð�� �Ѱ��� ���� �ľ��ϸ� �ȴ�.
//���� Ǯ���� �Ǻ���ġ ������ ���Ҵ�.

const int DIV_NUM = 10007;
const int MAX_NUM = 1000 + 1;
int cashe[MAX_NUM];
int n;

int Cal(int num)
{
    if (num == 0)
        return 1;

    int& ans = cashe[num];
    if (ans != -1)
        return ans;

    ans = 0;
    for (int i = 1; i <= 2; ++i)
        if (num >= i)
            ans += Cal(num - i);

    return ans %= DIV_NUM;
}

void MakeAnswer()
{
    cout << Cal(n) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cashe, -1, sizeof(cashe));

    cin >> n;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
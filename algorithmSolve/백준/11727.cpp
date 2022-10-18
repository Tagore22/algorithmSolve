#include <iostream>
#include <cstring>

using namespace std;

//11726���� ����ȣȯ�����̴�. �ٸ����� 2x2Ÿ���� �߰��Ǿ��� �ǵ� 2x2Ÿ���� 1x2Ÿ���� 2���Ἥ nĭ�� ����°Ͱ� ������ �ٸ� ������� 
//�ľ��ϱ� ������ ��������� n-2�϶����� 2���� ����� �����Ѵ�. �̸� �ڵ忡 �ݿ��Ͽ� 2ĭ�� �����Ҷ����� �� ������� 2�� ���ϸ� �ȴ�.

const int DIV_NUM = 10007;
int cashe[1001];
int n;

//������ �޶��� ���� �� �ϳ��� ����Ͽ����� 2ĭ�� ���� �Ҷ����� �� ������� 2������ �ȴٴ°��� �ݿ��Ͽ� 2�� �����ش�.

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
            ans += Cal(num - i) * i; //2ĭ�� �����Ҷ��� ������� 2�� �����ش�.
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
#include <iostream>
#include <cstring>

using namespace std;

//17626���� �Ǵٸ� Ǯ���̴�. ��Ͱ� �ƴ� �ݺ��� ������ Ǯ�̷ν� 1���� �־��� N���� ��ȸ�ϸ� N���� ���� 2�������� DP��+1 ���� ���Ͽ�
//�ּҰ��� dp[N]�� �ȴ�. �տ� Ǯ�̴� ������ ��ȸ�� ������ 1�� ���̴� ��͸� �ִ� 5���� ���ƾ� �ϱ⿡ ��� ���� �˻� + 5���������� �ݽ���
//���� ���� �� Ǯ�̺��� �ξ� ������. �� Ǯ�̴� ������ �κи��� ������ �ܼ� �ݺ������� ��ȸ�ϱ⿡ �޸𸮵� �� �۰� �����Ѵ�.
//�ʹ� ��Ϳ��� ������������.

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
#include <iostream>
#include <cstring>

//�� ���� ��� ������ 1,2,3�� ������ ��Ÿ���� �ִ��� �� ���� ���ϴ� �����̴�. �����ؾ� ������ 1+2�� 2+1ó�� ������ �ٸ� ��쿡��
//���� �ٸ� ���� �����Ѵٴ� ���̴�. �׷��⿡ �־��� ������ ���� 1,2,3���� ū�� ���Ͽ� ũ�ٸ� ������ �ᱹ 0�� ������ ���
//1���� ������� ���Ͽ� 1�� �����ش�.

using namespace std;

int cashe[11];
int T;

int Cal(int num)
{
    if (num == 0)
        return 1;

    int& ans = cashe[num];
    if (ans != -1)
        return ans;

    ans = 0;
    for (int i = 1; i <= 3; ++i)
        if (num >= i)
            ans += Cal(num - i);

    return ans;
}

void MakeAnswer()
{
    int num;
    for (int i = 0; i < T; ++i)
    {
        cin >> num;
        cout << Cal(num) << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cashe, -1, sizeof(cashe));

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
#include <iostream>

using namespace std;

//11727���� �ٸ� Ǯ��. ��͸� ������� �ʰ� �ܼ� �ݺ������� Ǫ�� ���. ��ͷ� Ǭ�Ͱ� �޸𸮳� �ӵ��� ���̴� �̹��ϳ�, �ڵ尡 �� ª�⿡
//������ ������ ���⵵ ���ϴ�. ��Ϳ� �������� ���� �ٸ� ����� ã�ƺ���.

const int DIV_NUM = 10007;
int cashe[1001];
int n;

void MakeAnswer()
{
    cashe[1] = 1;
    cashe[2] = 3;
    for (int i = 3; i <= n; ++i)
        cashe[i] = (cashe[i - 1] + cashe[i - 2] * 2) % DIV_NUM;
    cout << cashe[n] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
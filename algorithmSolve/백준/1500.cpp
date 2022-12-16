#include <iostream>
#include <cmath>

using namespace std;

//Ǯ��
//� ������ ������ ������ �� ������ ��� ���� ���� ũ�� ���ؼ��� ������ ���ҵ��� �յ��ϰ� Ŀ���Ѵ�.
//��, �� �������� K���� ������ ���� ���� ũ�� ���ؼ� ���� ���� �յ��ϰ� ������ϴµ� �� ����� S�� K�� ������ ���̴�.
//���� �������� ����ٸ� ���� �յ��ϰ� �ִ��� ���� ������ 1�� �������ָ� �ȴ�. ���� ������ int�� �ƴ� long long�� �����̱⿡
//�������� Ÿ���� �� ����ؾ��ߴ�.

int S, K;

void MakeAnswer()
{
    long long mul_num = S / K;
    int div_num = S % K;

    long long answer = pow(mul_num, K - div_num) * pow(mul_num + 1, div_num);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> S >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
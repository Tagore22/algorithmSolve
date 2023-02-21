#include <iostream>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

// Ǯ�� 
// � �� N�� �־�����(1 ~ 1,000,000) N���� ���ų� �� ū �ּ����� �Ӹ�����̸鼭 �Ҽ��� ���� ���ϴ� �����̴�.
// �� 2���� ��� �ִ밪���� �Ҽ������� �̸� ����س���(�����佺�׳׽��� ü), ���߿� N�� ������Ű�� �Ӹ�����̸鼭 �Ҽ����� Ȯ���ؾ��Ѵ�.
// �� �ִ밪�� �������� ���ؾ� �ϴ��� ����ߴµ�, �׳� 9876543���� ���ݾ� �ٿ�����. �ᱹ�� 1003001�� ���� ��������.

const int MAXNUM = 1300000;
bool era[MAXNUM + 1];
int N;

// �Ҽ����� �̸� Ȯ���ϴ� �Լ�. 1300000�� �ִ밪���� ��Ƴ��� ����.
void MakeEra()
{
    era[0] = false;
    era[1] = false;
    int sqrt_num = sqrt(MAXNUM);
    for (int i = 2; i <= sqrt_num; ++i)
        if (era[i])
            for (int j = i * i; j <= MAXNUM; j += i)
                era[j] = false;
}


// �Ӹ�������� Ȯ���ϴ� �Լ�. string���� ��ȯ�� Ȯ���Ѵ�.
bool CheckPalin(int cur)
{
    string str = to_string(cur);
    for (int i = 0; i < str.size() / 2; ++i)
        if (str[i] != str[str.size() - 1 - i])
            return false;
    return true;
}

// N�� 1�� ������Ű�� �Ӹ�����̸鼭 �Ҽ��� �ּҰ��� ����Ѵ�.
void MakeAnswer()
{
    MakeEra();
    while (true)
    {
        if (era[N] && CheckPalin(N))
        {
            cout << N << '\n';
            return;
        }
        ++N;
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(era, true, sizeof(era));

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
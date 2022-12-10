#include <iostream>

//����� ���̵� �����ε� �����Ұ� ���� �ϳ� �ָԾ��� ����. �ϳ��ϳ� ������ Ǯ���.

//Ǯ��
//�־��� �ð� num�� �� �ð��� �� ������ ��ȯ�Ͽ� ������ �������ѳ�����. �ٸ� 23 59 59 1 ���� ���ó�� ���� ������ ���� �������� ���İ� ��ġ��
//��쵵 �����ؾ��ϰ�, �ܼ��� for������ �ñ��� ������ų�� �ƴ϶�, ���� �ð��뿡�� 1�� ���������� �ִ밪(ex 24, 60 ��)�� �ʰ��ؾ� ��������
//�Ѿ�� �ݺ����� �����ؾ��Ѵ�.

using namespace std;

int times[3];
int div_num[3] = { 24, 60, 60 };
int num;

void MakeAnswer()
{
    int idx = 60 * 60;
    for (int i = 0; i < 3; ++i)
    {
        int plus = num / idx;
        num %= idx;
        if (i > 0 && times[i] + plus >= div_num[i])
            for (int j = i - 1; j >= 0; --j)
            {
                ++times[j];
                if (times[j] >= div_num[j])
                    times[j] %= div_num[j];
                else
                    break;
            }
        times[i] = (times[i] + plus) % div_num[i];
        idx /= 60;
    }

    for (int i = 0; i < 3; ++i)
        cout << times[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 3; ++i)
        cin >> times[i];
    cin >> num;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
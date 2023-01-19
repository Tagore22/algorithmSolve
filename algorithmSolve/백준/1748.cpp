#include <iostream>

using namespace std;

int N;

//Ǯ��
//�ڸ����� 1�� 9����, 2�� 99���� ���� �������� �־��� �� N�� �ڸ������� �ܰ������� ó���Ѵ�.
//�ٸ� ���� �ڸ����� ���� �˱� ���� ���� �ڸ����� �ִ밪�� prev�� �Ź� �����ϸ� ����ؾ��Ѵ�.

void MakeAnswer()
{
    int answer = 0;
    int prev = 0, mul = 1; //�ʱ� �������� �ʱ� �ڸ�����.
    for (int i = 9; i < N; i = (i + 1) * 10 - 1) //�� �ڸ����� �ִ밪���� ���Ѵ�. �ڸ����� 1���� �ִ밪 9, �ڸ����� 2���� �ִ밪 99��...
    {
        answer += mul * (i - prev); //���� �ڸ����� �ִ밪 - ���� �ڸ����� �ִ밪�� ���ؾ� ���� �ߺ����� �ƴ��Ѵ�.
        prev = i;
        ++mul;
    }

    answer += (N - prev) * mul; //���� �� (ex) �־��� �� 101, ���� �� 99�϶� 100 ~ 101) �� ó��.

    cout << answer << '\n';
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
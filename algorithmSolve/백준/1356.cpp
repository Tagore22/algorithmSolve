#include <iostream>

using namespace std;

//�ִ� 10�ڸ��� �������� ��� �� ���� �����ʿ� �ִ� ���Ұ����� ���� ���Ͽ� ������ Ȯ���Ѵ�.
//�־����� �� N�� �ִ밪�� 10�ڸ��̹Ƿ� �������� �ִ� 9���� ������ �ְ�,
//�� ���������� �ִ� 10���� ������ �����Ƿ� �ִ� ������ 100���� ���� �ʴ´�.

string N;

void MakeAnswer()
{
    for (int i = 1; i < N.size(); ++i)
    {
        int left = 1;
        int right = 1;
        for (int idx = 0; idx < i; ++idx)
            left *= N[idx] - '0';
        for (int idx = i; idx < N.size(); ++idx)
            right *= N[idx] - '0';
        if (left == right)
        {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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
#include <iostream>

using namespace std;

// Ǯ��.
// ��Ģ�� �ľ��ϴ� ��������. �־����� �� num���� 5�� �����Ҷ����� 0�� ������ 1�� �����ߴµ�
// 24���� 25�� �ɶ� 1���� �ƴ� 2���� �þ��. ���������� 124���� 125�� �ɶ� 1���� �ƴ� 2����
// �þ��. ��������� num���� �۰ų� ���� ��� 5�� ����� ������ ���Ѱ��� �����̾���.

int T;

void MakeAnswer()
{
    int num;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> num;
        int piv = 5, answer = 0;
        while (piv <= num)
        {
            answer += num / piv;
            piv *= 5;
        }
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
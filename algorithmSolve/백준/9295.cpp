#include <iostream>

using namespace std;

// Ǯ��.
// �� �ֻ����� ���� �� ���̽� ��ȣ�� �Բ� ����ϴ� ����.
// Input()�� ȣ������ �ʾҴ��� 28ms���� �ӵ��� ��������. �ڵ�� ���̷��� �׷�������
// ���� ȣ���ؾ߰ڴ�.

int T, a, b;

void MakeAnswer()
{
    for (int iter = 1; iter <= T; ++iter)
    {
        cin >> a >> b;
        cout << "Case " << iter << ": " << a + b << '\n';
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
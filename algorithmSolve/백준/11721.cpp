#include <iostream>

using namespace std;

// Ǯ��.
// ���� ���ڿ��� ����� ���� iter�� ���ǹ��� �̿��� ���Ѵ�.
// �� ���� iter��ŭ ����� �ϰ� �ٽ� iter��ŭ �߶󳽴�.

// �� ��� ���� str�� �������� �ݺ��Ѵ�.

string str;

void MakeAnswer()
{
    while (!str.empty())
    {
        int ssize = str.size();
        int iter = ssize > 10 ? 10 : ssize;
        for (int i = 0; i < iter; ++i)
            cout << str[i];

        cout << '\n';
        str = str.substr(iter);
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
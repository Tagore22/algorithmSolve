#include <iostream>

using namespace std;

// Ǯ��.
// �־��� ���ڿ��� �Ӹ�������� Ȯ���ϴ� ������. �� ���ڿ��� ���� �߰��κб��� �� �հ� �� �ڸ� Ȯ��
// �ϸ� �Ǵµ� �� �߰��κ��� ���ڿ��� ���� / 2�� ���Ҽ� �ִ�.

// �ڼ��� ������ �ּ����� �����.

string str;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
    int sSize = str.size();
    bool isFind = true;
    // ���ڿ��� �߰��κ�(���ڿ��� ���� / 2)������ ��ȸ�ϸ� Ȯ���Ѵ�.
    for (int i = 0; i < sSize / 2; ++i)
    {
        // �߰��� �������� �յڸ� Ȯ���Ҷ� �ٸ� �κ��� �����Ѵٸ� �Ӹ������ �ƴϴ�.
        if (str[i] != str[sSize - 1 - i])
        {
            isFind = false;
            break;
        }
    }

    cout << isFind ? 1 : 0 << '\n';
    return 0;
}
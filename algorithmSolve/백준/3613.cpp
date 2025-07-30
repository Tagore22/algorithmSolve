#include <iostream>

using namespace std;

// Ǯ��.
// 20�ۿ� ���ϴ� ��������� ��3ġ��� ���̵��� �ִ� ������.
// �־����� ���ڿ��� cpp�̶�� java��, java��� cpp��, �Ѵ� �ش����� �ʴ´ٸ�
// "Error!"�� ����ϴ� �����ε� �Ѵ� �ش����� �ʴ� ������ �ϳ� �߻����̶� �ָԾ���.

// 1. �빮�� Ȥ�� '_'�� �����ϴ� ���.
// 2. '_'�� �ܾ�� �ܾ �����ϱ� ���� �����ϹǷ� �������� ���� ���.
// 3. '_'�� �� �������� ���ͼ� ���� �ܾ ���� ���.
// 4. ���ڿ��� �빮�ڿ� '_'�� ���ÿ� ������ ���.

// �� ��찡 ������ ����̰� �������� ġȯ�� �ϸ� �ȴ�. ����, ���ÿ� �־��� nameó��
// �빮�ڳ� '_'�� ������ ���� ��쵵 �����Կ� �����Ѵ�.

// �ڼ��� ������ �ּ����� �����.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    // 1��, 3�� ���.
    if (str[0] == '_' || ('A' <= str[0] && str[0] <= 'Z') || str[str.size() - 1] == '_')
    {
        cout << "Error!" << '\n';
        return 0;
    }
    bool isCpp = false, isJava = false;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '_')
        {
            isCpp = true;
            // 2�� ���.
            if (i != 0 && str[i - 1] == '_')
            {
                cout << "Error!" << '\n';;
                return 0;
            }
        }
        else if ('A' <= str[i] && str[i] <= 'Z')
            isJava = true;
    }
    // 4�� ���.
    if (isCpp && isJava)
    {
        cout << "Error!" << '\n';
        return 0;
    }
    // Java���� Cpp��.
    else if (isJava)
    {
        for (int i = 0; i < str.size(); ++i)
        {
            if ('A' <= str[i] && str[i] <= 'Z')
            {
                str[i] += 32;
                cout << '_';
            }
            cout << str[i];
        }
    }
    // Cpp���� Java��.
    else if (isCpp)
    {
        bool isupper = false;
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == '_')
            {
                isupper = true;
                continue;
            }
            else if (isupper)
            {
                str[i] -= 32;
                isupper = false;
            }
            cout << str[i];
        }
    }
    // �Ѵ� ���ϴ� �ҹ��ڸ� �����ϴ� ���.
    else
    {
        cout << str;
    }
    cout << '\n';
    return 0;
}
#include <iostream>

using namespace std;

// Ǯ��.
// ���ڿ��� �Է¹޾� �� ���ڸ� �빮�� Ȥ�� �ҹ��ڷ� ����Ī�ϴ� ����.

int main()
{
    string str, answer = "";
    cin >> str;
    for (int i = 0; i < str.size(); ++i)
    {
        if ('a' <= str[i] && str[i] <= 'z')
            answer += str[i] - 32;
        else
            answer += str[i] + 32;
    }
    cout << answer << '\n';
    return 0;
}
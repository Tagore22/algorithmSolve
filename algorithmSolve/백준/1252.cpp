#include <iostream>
#include <string>

using namespace std;

// Ǯ��.
// ó������ ������ -> ���������� ġȯ�Ͽ� ���� ���� ��, �ٽ� ���������� ġȯ�ϴ� �������� �����ߴµ�
// ������ �ڼ��� ���� �������� ���̰� �ִ� 80���� �־����⿡ ������������ ġȯ�� �Ұ����ߴ�.

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    while (str1.size() != str2.size())
    {
        if (str1.size() > str2.size())
            str2 = "0" + str2;
        else
            str1 = "0" + str1;
    }
    int plus = 0;
    string answer = "";
    for (int i = str1.size() - 1; i >= 0; --i)
    {
        int first = stoi(str1.substr(i, 1));
        int second = stoi(str2.substr(i, 1));
        int cur = first + second + plus;
        plus = cur >= 2 ? 1 : 0;
        answer = to_string(cur % 2) + answer;
    }
    answer = plus == 1 ? "1" + answer : answer;
    while (answer != "0" && answer[0] == '0')
        answer.erase(0, 1);
    cout << answer << '\n';
    return 0;
}
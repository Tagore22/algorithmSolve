#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// 1342���� �� ���� Ǯ��. next_permutation()�� �̿��Ͽ� ��� ���ڿ��� ������
// �� ������ ������ �� �ִ�.

string str;
int answer;

bool IsLuckyStr()
{
    for (int i = 0; i < str.size() - 1; ++i)
        if (str[i] == str[i + 1])
            return false;
    return true;
}

int main()
{
    cin >> str;
    sort(str.begin(), str.end());
    answer = IsLuckyStr() ? 1 : 0;
    while (next_permutation(str.begin(), str.end()))
    {
        if (IsLuckyStr())
            ++answer;
    }
    cout << answer << '\n';
    return 0;
}
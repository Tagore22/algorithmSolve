#include <iostream>
#include <algorithm>

//Ǯ��
//� ���ڿ��� �ִ� ������ �Ӹ������ �� ���ڿ��� ����� �ٿ������̴�. ��, abc�� �ִ� ���� �Ӹ������ abc + cba = abccba��.
//�̷��� ����� �ǵ��ڸ����� �κй��ڿ��� �ٿ����� ���ʷ� �Ӹ������ �߰��������� �ٷ� �ּ� ������ �Ӹ�����̴�.

using namespace std;

string str;

bool IsPal(const string& str)
{
    int len = str.size() - 1;
    for (int i = 0; i < str.size() / 2; ++i)
        if (str[i] != str[len - i])
            return false;
    return true;
}

void MakeAnswer()
{
    string rev = str;
    reverse(rev.begin(), rev.end());
    int answer = str.size();

    if (IsPal(str))
    {
        cout << answer << '\n';
        return;
    }

    for (int i = rev.size() - 1; i >= 0; --i)
    {
        ++answer;
        if (IsPal(str + rev.substr(i)))
        {
            cout << answer << '\n';
            return;
        }
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
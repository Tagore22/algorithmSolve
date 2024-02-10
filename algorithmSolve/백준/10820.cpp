#include <iostream>
#include <string>

using namespace std;

// Ǯ��.
// ���ڿ��� ������ �־����� �ʾұ⿡ while���� ����ؾ��߰�, ������ ������ ���ڿ��� �Է¹ޱ⿡
// getline()�� �̿��ؾ��ߴ�. ���ڿ��� �Է¹��� �Ŀ��� ���� �빮��, �ҹ���, ����, ������ ���� ���Ͽ�
// ����Ѵ�.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    while (getline(cin, str))
    {
        int upper = 0, lower = 0, dig = 0, space = 0;
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == ' ')
                ++space;
            else if ('0' <= str[i] && str[i] <= '9')
                ++dig;
            else if ('a' <= str[i] && str[i] <= 'z')
                ++lower;
            else if ('A' <= str[i] && str[i] <= 'Z')
                ++upper;
        }
        cout << lower << ' ' << upper << ' ' << dig << ' ' << space << '\n';
    }
    return 0;
}
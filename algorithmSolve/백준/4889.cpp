#include <iostream>

using namespace std;

// Ǯ��.
// �� ������ ���ǽ��� �߿��ϴ�. ���簪�� { �϶��� } �϶��� ���ǽ��̴�.
// ���ڿ� str�� ��ȸ�ϸ�, ���±��� }�� ���Դ� ���� end��� �Ҷ�

// 1. ���簪�� { �϶� end�� 1 ���ҽ�Ų��.
// 1-1. end�� �����϶� {�� }���� �� ���� ���� ����̹Ƿ�, ���簪�� }�� �ٲٰ� end�� 2 �������� }�� �Ѱ� ���»�Ȳ���� �ٲ۰� ��������
// 1 ������Ų��.
// 1-2. �׷��� ���� ��� �����Ѵ�.
// 2. ���簪�� } �϶� end�� 1 ������Ų��.
// 3. ��ȸ�� ������ end���� 0���� ũ�ٸ� }�� �� ���� ���� ����̹Ƿ� �̰͵��� ������ {�� �ٲپ� ¦�� �����־�� �ϱ⿡
// end���� 2�� ������ �� ���� �������� ���Ѵ�.

string str;

int Check()
{
    int end = 0, ans = 0;

    for (int i = str.size() - 1; i >= 0; --i)
    {
        if (str[i] == '{')
        {
            --end;
            if (end < 0)
            {
                ++ans;
                end += 2;
            }
        }
        else
        {
            ++end;
        }
    }

    if (end > 0)
        ans += end / 2;

    return ans;
}

void MakeAnswer()
{
    int idx = 0, answer;
    while (true)
    {
        ++idx;
        cin >> str;
        if (str[0] == '-')
            break;
        // ���⼭ �˻�.
        answer = Check();
        cout << idx << ". " << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
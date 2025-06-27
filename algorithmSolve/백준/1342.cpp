#include <iostream>

using namespace std;

// Ǯ��.
// 1342���� ù��° Ǯ��. ���� ��� ����� ���ڿ��� ����� �� ���� �ľ��Ѵ�.
// �ٸ� ���ڿ��� ����� ������ STL�� next_permutation()���� ��ȿ�����̱� ������
// ���������� ���� �ӵ��� ���� �� ���� �ڵ尡 �� ����.

string str, cur = "";
bool visit[10] = { false, };
int ssize, answer = 0;

bool IsLuckyStr(string cur)
{
    for (int i = 0; i < cur.size() - 1; ++i)
        if (cur[i] == cur[i + 1])
            return false;
    return true;
}

void MakeString(int idx)
{
    if (cur.size() == ssize && IsLuckyStr(cur))
    {
        ++answer;
        return;
    }

    bool isuse[26] = { false, };

    for (int i = 0; i < ssize; ++i)
    {
        if (!visit[i] && !isuse[str[i] - 'a'])
        {
            visit[i] = true;
            cur += str[i];
            isuse[str[i] - 'a'] = true;
            MakeString(idx + 1);
            cur.erase(cur.size() - 1, 1);
            visit[i] = false;
        }
    }
}


int main()
{
    cin >> str;
    ssize = str.size();
    MakeString(0);
    cout << answer << '\n';
    return 0;
}
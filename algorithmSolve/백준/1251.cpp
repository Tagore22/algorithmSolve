#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// MakeStr()�� �ι�° for���� �������ѿ��� �ϳ� �ָ� �Ծ���. �������� - from�� �����µ�
// �̷��� ��𿡼� �����ϵ� �ִ� ���̸� ��� ���ϰ� �Ǿ� ���� ���� ����� �Ǿ���.

string str;
vector<string> strs;

void MakeStr(int num, int from, string cur)
{
    if (num == 3)
    {
        string ans = str.substr(from);
        reverse(ans.begin(), ans.end());
        cur += ans;
        strs.push_back(cur);
        return;
    }

    for (int i = 1; i <= str.size() - 3 + num - from; ++i)
    {
        string ans = str.substr(from, i);
        reverse(ans.begin(), ans.end());
        ans = cur + ans;
        MakeStr(num + 1, from + i, ans);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> str;
    MakeStr(1, 0, "");
    sort(strs.begin(), strs.end());
    cout << strs[0] << '\n';
    return 0;
}
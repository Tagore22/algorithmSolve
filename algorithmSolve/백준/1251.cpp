#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// MakeStr()의 두번째 for문의 범위제한에서 꽤나 애를 먹었다. 기존에는 - from이 없었는데
// 이러니 어디에서 시작하든 최대 길이를 모두 더하게 되어 범위 값을 벗어나게 되었다.

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
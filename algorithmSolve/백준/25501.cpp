#include <iostream>

using namespace std;

// Ǯ��.
// ��͸� ���� ��ͷ� �������� �ʰ� for������ ��� �����Ҽ� �ִ�. �ٸ� ���ڿ��� ���̰� 3�� ���
// ��� 1��° �ε����� ���� ���� �ʿ䰡 ������ �� ���������� ���ؾ��Ѵٰ� �����ֱ⿡
// ���ڿ��� ���� / 2���� ��ȸ�� �ؾ��Կ� �־� �����ؾ� �Ѵ�.

string str;
int T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> str;
        int idx = str.size();
        int num = idx / 2;
        idx -= 1;
        int answer = 1, ans = 0;
        for (int i = 0; i <= num; ++i)
        {
            ++ans;
            if (str[i] != str[idx - i])
            {
                answer = 0;
                break;
            }
        }
        cout << answer << ' ' << ans << '\n';
    }
    return 0;
}
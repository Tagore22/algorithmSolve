#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str = "SciComLove";
    int N, Q;
    cin >> N >> Q;
    string cur = "";
    int idx = 0, answer = 0;
    for (int i = 0; i < N; ++i)
    {
        cur += str[idx];
        idx = (idx + 1) % 10;
        answer = cur.back() <= 'Z' ? ++answer : answer;
    }
    for (int i = 0; i < Q; ++i)
    {
        int num;
        cin >> num;
        if (cur[num - 1] >= 'a')
        {
            cur[num - 1] -= 32;
            ++answer;
        }
        else
        {
            cur[num - 1] += 32;
            --answer;
        }
        cout << answer << '\n';
    }
    return 0;
}
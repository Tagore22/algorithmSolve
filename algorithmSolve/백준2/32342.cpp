#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        string cur;
        cin >> cur;
        int answer = 0;
        auto idx = cur.find("WOW");
        while (idx != string::npos)
        {
            ++answer;
            if (cur.size() <= 3)
                break;
            cur = cur.substr(idx + 2);
            idx = cur.find("WOW");
        }
        cout << answer << '\n';
    }
    return 0;
}
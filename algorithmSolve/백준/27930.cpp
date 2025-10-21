#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    string y = "YONSEI", k = "KOREA";
    int yidx = 0, kidx = 0, yans = -1, kans = -1;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == y[yidx])
            ++yidx;
        if (yidx == (int)y.size())
        {
            yans = i;
            break;
        }
        if (str[i] == k[kidx])
            ++kidx;
        if (kidx == (int)k.size())
        {
            kans = i;
            break;
        }
    }
    cout << (yans != -1 ? "YONSEI" : "KOREA") << '\n';
    return 0;
}
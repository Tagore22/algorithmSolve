#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S, K;
    cin >> S >> K;
    string cur = "";
    for (int i = 0; i < S.size(); ++i)
    {
        if ('0' <= S[i] && S[i] <= '9')
            continue;
        cur += S[i];
    }
    cout << (cur.find(K) != string::npos ? 1 : 0) << '\n';
    return 0;
}
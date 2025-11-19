#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    char board[3] = { 'P', 'E', 'R' };
    int ans = 0;
    for (int i = 0; i < str.size(); ++i)
        if (str[i] != board[i % 3])
            ++ans;
    cout << ans << '\n';
    return 0;
}
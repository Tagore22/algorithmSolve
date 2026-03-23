#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> board = { 0 };

void CalBit(int num)
{
    vector<int> ans;
    while (num > 0)
    {
        ans.push_back(num % 2);
        num /= 2;
    }
    reverse(ans.begin(), ans.end());
    for (const auto& cur : ans)
        board.push_back(cur);
}

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= 100; ++i)
        CalBit(i);
    int num = 0;
    for (int i = k - 1; ; i += n)
    {
        cout << board[i] << ' ';
        ++num;
        if (num >= 5)
            break;
    }
    cout << '\n';
    return 0;
}
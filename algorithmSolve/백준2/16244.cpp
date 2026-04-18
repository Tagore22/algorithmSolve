#include <iostream>

using namespace std;

int n;
long long sum = 0;
int board[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> board[i];
        sum += board[i];
    }
    int idx = -1;
    for(int i = 0; i < n; ++i)
    {
        if (sum == board[i] * 2)
        {
            idx = i;
            break;
        }
    }
    for(int i = 0; i < n; ++i)
    {
        if (i == idx)
            continue;
        cout << board[i] << ' ';
    }
    cout << board[idx] << '\n';
    return 0;
}
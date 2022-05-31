#include <iostream>
#include <algorithm>

using namespace std;

const int MAXNUM = 100000;
int board[MAXNUM];
int n;

void Calcul()
{
    int left = 0;
    int right = n - 1;
    int Answer = 1000000000 * 2;
    pair<int, int> AnsPair;
    sort(board, board + n);
    while (left < right)
    {
        int sum = board[left] + board[right];
        if (abs(sum) < Answer)
        {
            Answer = abs(sum);
            AnsPair = make_pair(board[left], board[right]);

            if (sum == 0)
                break;
        }
        if (sum > 0)
            --right;
        else
            ++left;
    }
    cout << AnsPair.first << ' ' << AnsPair.second << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> board[i];
    Calcul();
    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int board[100000];
int n, x;

void Calcul()
{
    int left = 0;
    int right = n - 1;
    int answer = 0;

    while (left < right)
    {
        int sum = board[left] + board[right];
        if (sum == x)
        {
            ++left;
            --right;
            ++answer;
        }
        else if (sum < x)
            ++left;
        else
            --right;
    }
    cout << answer << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> board[i];
    cin >> x;
    sort(board, board + n);
    Calcul();
    return 0;
}
#include <iostream>

using namespace std;

const int MAXNUM = 987654321;
int n, s;
int board[1000000];

void Calcul()
{
    int left = 0;
    int right = 0;
    int sum = board[0];
    int answer = MAXNUM;
    while (left <= right && right < n)
    {
        if (sum >= s)
        {
            answer = min(answer, right - left + 1);
            sum -= board[left];
            ++left;
        }
        else
        {
            ++right;
            sum += board[right];
        }
    }
    if (answer != MAXNUM)
        cout << answer << '\n';
    else
        cout << 0 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; ++i)
        cin >> board[i];
    Calcul();
    return 0;
}
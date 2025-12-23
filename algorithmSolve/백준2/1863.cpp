#include <iostream>
#include <stack>

using namespace std;

int n;
stack<int> board;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int answer = 0;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        if (y == 0)
        {
            while (!board.empty())
                board.pop();
        }
        else if (board.empty() || board.top() < y)
        {
            ++answer;
            board.push(y);
        }
        else
        {
            while (!board.empty() && board.top() > y)
                board.pop();
            if (board.empty() || board.top() < y)
            {
                board.push(y);
                ++answer;
            }
        }
    }
    cout << answer << '\n';
    return 0;
}
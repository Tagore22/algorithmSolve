#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXNUM = 200000;
pair<int, int> board[MAXNUM];
int N;

void MakeAnswer()
{
    sort(board, board + N);
    priority_queue<int> que;
    for (int i = 0; i < N; ++i)
    {
        if (que.size() < board[i].first)
        {
            que.push(-board[i].second);
        }
        else
        {
            if (que.top() < board[i].second)
            {
                que.pop();
                que.push(-board[i].second);
            }
        }
    }
    int answer = 0;
    while (!que.empty())
    {
        answer += -que.top();
        que.pop();
    }
    cout << answer << '\n';
}
void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int deadline, cup;
        cin >> deadline >> cup;
        board[i] = make_pair(deadline, cup);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
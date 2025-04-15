#include <iostream>
#include <stack>

using namespace std;

stack<pair<int, int>> HomeWorks;
int N, answer = 0;

void Solve()
{
    for (int iter = 0; iter < N; ++iter)
    {
        int num;
        cin >> num;
        pair<int, int> now;
        if (num == 0 && !HomeWorks.empty())
        {
            now = HomeWorks.top();
            HomeWorks.pop();
            now.second -= 1;
        }
        else if (num == 1)
        {
            int score, time;
            cin >> score >> time;
            time -= 1;
            now = make_pair(score, time);
        }
        if (now.second == 0)
            answer += now.first;
        else
            HomeWorks.push(now);
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
}

int main()
{
    Input();
    Solve();
    return 0;
}
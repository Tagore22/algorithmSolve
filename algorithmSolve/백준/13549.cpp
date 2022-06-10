#include <iostream>
#include <queue>
#include <vector> 
using namespace std;

const int MAXNUM = 100000;
int n, k;

void DK()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push(make_pair(0, n));
    vector<int> answer(MAXNUM + 1, 987654321);
    answer[n] = 0;
    while (!que.empty())
    {
        int cost = que.top().first;
        int here = que.top().second;
        que.pop();

        if (cost > answer[here])
            continue;

        if (here - 1 >= 0)
        {
            int there = here - 1;
            int len = 1;
            if (answer[here] + len < answer[there])
            {
                answer[there] = answer[here] + len;
                que.push(make_pair(answer[there], there));
            }
        }
        if (here + 1 <= MAXNUM)
        {
            int there = here + 1;
            int len = 1;
            if (answer[here] + len < answer[there])
            {
                answer[there] = answer[here] + len;
                que.push(make_pair(answer[there], there));
            }
        }
        if (here * 2 <= MAXNUM)
        {
            int there = here * 2;
            int len = 0;
            if (answer[here] + len < answer[there])
            {
                answer[there] = answer[here] + len;
                que.push(make_pair(answer[there], there));
            }
        }
    }
    cout << answer[k] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    DK();
    return 0;
}
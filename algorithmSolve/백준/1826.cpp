#include <iostream>
#include <queue>

using namespace std;

int N, goal, fuel;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;

void MakeAnswer() //pair<int,int> = <거리,연료>
{
    int answer = 0;
    priority_queue<int> cango;
    while (fuel < goal)
    {
        while (!que.empty() && que.top().first <= fuel)
        {
            cango.push(que.top().second);
            que.pop();
        }
        if (cango.empty())
        {
            answer = -1;
            break;
        }
        fuel += cango.top();
        cango.pop();
        ++answer;
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
        int a, b;
        cin >> a >> b;
        que.push(make_pair(a, b));
    }
    cin >> goal >> fuel;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
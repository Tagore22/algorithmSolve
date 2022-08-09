#include <iostream>
#include <queue>

using namespace std;

int N, goal, fuel;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;

//현 연료로 도달할수 있는 모든 주유소를 파악후(우선순위 큐에 거리순으로 모아둠), 그 주유소중
//가장 많은 연료를 얻을수 있는 곳에 도달하여(우선순위 큐에서 제외됨) 연료를 추가한다.

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
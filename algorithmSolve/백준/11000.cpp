#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 풀이.
// 그리디, 정렬 등등의 문제다. 이런 문제는 어떻게 정렬하여 그 자료를 어떻게 쓸지를 생각해내야하는데
// 이번에는 좀 막막했다. 큰 틀에서 보자면 다음과 같다.

// 1. 강의들을 시작시간을 기준으로 오름차순 정렬한다.
// 2. 가장 첫 강의의 끝나는 시간을 우선순위 큐에 넣는다.
// 3. 그 이후의 강의들을 순회하며 끝나는 시간을 우선순위 큐에 넣되, 시작시간을 큐의 맨 앞값(가장 빨리 끝나는 강의실의 끝나는 시간)과
// 비교하여 크거나 같다면(이 강의실을 쓸수 있다면) 큐의 맨 앞값을 지운다.

// 좀 더 설명하자면

// 1. 맨 앞과 현재 시작시간을 비교하는 것은 맨 앞값이 현재 강의실중 가장 빨리 끝나는 시간이기 때문이다.
// 이 시간보다 작다면 그 어떤 강의실에서도 연결되지 못하며, 새로운 강의실을 추가해야한다.
// 2. 맨 앞보다 현재 시작시간이 크거나 같다면 가장 빨리 끝나는 강의실에서 그 강의가 끝난 후 이어서 강의가 가능하므로
// 새로운 강의실을 찾을 필요없이 같은 강의실을 사용하면 된다.

// 위 방식을 사용하면 시작시간과 끝나는 시간을 우선순위 큐를 이용하여 2가지 모두 따로 정렬할수 있다.
// 이 방식을 잘 기억해둬야겠다.

// 자세한 설명은 주석으로 남긴다.

pair<int, int> board[200000]; // 끝나는 시간, 시작하는 시간.
int N;

void MakeAnswer()
{
    // 시작시간을 기준으로 정렬한다.
    sort(board, board + N);
    priority_queue<int> que;
    que.push(-board[0].second);

    for (int i = 1; i < N; ++i)
    {
        que.push(-board[i].second);
        // 위 상술하였듯 맨 앞값(가장 빨리 끝나는 강의실의 끝나는 시간)보다 같거나 크다면 이 강의실을 그대로 이용할수 있고,
        // 그렇지 않다면 그 어떤 강의실도 그대로 이용할수 없기에 새로운 강의실을 찾아야한다(que의 크기가 늘어난다).
        if (-que.top() <= board[i].first)
            que.pop();
    }

    cout << que.size() << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}
#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 가장 큰 수부터 1씩 뺏어가며 1번 득표수가 가장 커질때까지 반복한다.

priority_queue<int> que;
int N, cur;

void MakeAnswer()
{
    int answer = 0;
    if (N == 1)
    {
        cout << answer << '\n';
        return;
    }
    while (true)
    {
        int next = que.top();
        if (cur > next)
        {
            cout << answer << '\n';
            break;
        }
        que.pop();
        ++cur;
        --next;
        ++answer;
        que.push(next);
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> cur;
    for (int i = 0; i < N - 1; ++i)
    {
        int here;
        cin >> here;
        que.push(here);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}